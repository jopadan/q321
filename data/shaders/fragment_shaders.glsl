#define smoothen(x)	((x)*(x)*(3.-2.*(x)))
#define sqr(x)		((x)*(x))
#define lsq(x)		dot(x, x)
#define sat(x)		clamp(x, 0., 1.)
#define RGB(r,g,b)	(vec3(r,g,b)/255.)

#define ridged(v)	tri(.5,.5,v)

// $protect ^void[ \t]+([_a-zA-Z][_a-zA-Z0-9]*)\(\)
// $protect ^TEX[A]?\(([a-z][_a-z0-9]*)\)
#define TEX(name)	vec3 name(vec2); void name() { FCol = vec4(name(UV), 1); } vec3 name(vec2 uv)
#define TEXA(name)	vec4 name(vec2); void name() { FCol = name(UV); } vec4 name(vec2 uv)

#define T0(x)		texture(Texture0, x)

////////////////////////////////////////////////////////////////

// Hardware derivates are computed at half resolution (pixel quads).
// To get full-resolution results, we need to evaluate 3 taps.
// The macro below helps automate that process a bit.
//
// Arguments:
// - res = name of vec3 output variable to receive the results:
//   .xy = normalized gradient
//   .z  = function value
// - uv  = 2d point where function is to be evaluated

#define EVAL_GRAD(res, uv, code)								 	\
	{																\
		vec2 p[3];													\
	 	float r[3];													\
		p[0] = uv;													\
		p[1] = uv + dFdx(uv);										\
		p[2] = uv + dFdy(uv);										\
	for (int i = 0; i < 3; ++i)										\
		r[i] = code;												\
		res = vec3(safe_normalize(vec2(r[1], r[2]) - r[0]), r[0]);	\
	}

////////////////////////////////////////////////////////////////

// Computes a SDF and a top light/shadow value
//
// Arguments:
// - uv = 2d point where function is to be evaluated
// - s  = shadow size
// - d  = name of float distance output variable
// - l  = name of float light output variable

#define EVAL_TOP_LIGHT(uv,s,d,l,code)	\
	{									\
		vec2 p = uv;					\
		d = code;						\
		p.y -= s;						\
		l = (d - code) / s;				\
	}

////////////////////////////////////////////////////////////////

uniform sampler2D Texture0, Texture1;
uniform vec4 Cam, Time, Extra, LightColor, Ambient, LightDir;

in vec3 Pos, Nor, WNor, Ref;
in vec2 UV, LUV;
in vec4 Clr;

out vec4 FCol;

////////////////////////////////////////////////////////////////

float
	PI		= 3.1415927,
	TAU		= 2. * PI,
	PHI		= 1.618034;

// http://extremelearning.com.au/unreasonable-effectiveness-of-quasirandom-sequences/
vec2 R2(float i) {
	float G = 1.324718;
	return fract(.5 + i / vec2(G, G * G));
}

float R1(float i) {
	return fract(.5 + i * PHI);
}

// smooth R1
float SR1(float f) {
	float i = floor(f);
	return mix(R1(i), R1(i+1.), smoothen(f - i));
}

////////////////////////////////////////////////////////////////

float mn(vec2 v) {
	return min(v.x, v.y);
}

float mn(vec3 v) {
	return min(v.x, min(v.y, v.z));
}

float mn(vec4 v) {
	return min(min(v.x, v.y), min(v.z, v.w));
}

float mx(vec2 v) {
	return max(v.x, v.y);
}

float mx(vec3 v) {
	return max(v.x, max(v.y, v.z));
}

float mx(vec4 v) {
	return max(max(v.x, v.y), max(v.z, v.w));
}

float sum(vec2 v) {
	return v.x + v.y;
}

float sum(vec3 v) {
	return v.x + v.y + v.z;
}

float minabs(float a, float b) {
	return abs(a) < abs(b) ? a : b;
}

float onion(float x, float s) {
	return abs(x) - s;
}

float elongate(float x, float s) {
	return sign(x) * max(0., abs(x) - s);
}

////////////////////////////////////////////////////////////////

vec2 safe_normalize(vec2 v) {
	float l = dot(v, v);
	return l > 0. ? v/sqrt(l) : v;
}

////////////////////////////////////////////////////////////////

// tent
float tri(float center, float max_dist, float x) {
	return 1. - sat(abs(x - center) / max_dist);
}

// antialiased tent funtion
float triaa(float c, float s, float x) {
	float a = max(fwidth(x) * 2. / s, 1.);
	return tri(c, s * a, x) / a;
}

// linear step (like smoothstep, but linear)
float ls(float lo, float hi, float x) {
	return sat((x - lo) / (hi - lo));
}

// asymmetric tent
float tri(float a, float b, float c, float x) {
	return min(ls(a, b, x), ls(c, b, x));
}

////////////////////////////////////////////////////////////////

vec2 sc(float x) {
	return vec2(sin(x), cos(x));
}

mat2 rot(float x) {
	vec2 v = sc(radians(x));
	return mat2(v.y, v.x, -v.x, v.y);
}

// Normalized angle [0..1]
float nang(vec2 p) {
	return fract(atan(p.y, p.x) / TAU);
}

// Polar mod
vec2 pmod(vec2 p, float n) {
	return p * rot(360. / n * (floor(nang(p) * n + 1.5) - 1.));
}

// UV distortions //////////////////////////////////////////////

// p = integral number of half periods
// s = scale
vec2 wavy(vec2 uv, float p, float s) {
	return uv + sin(uv.yx * PI * p) * s;
}

// t = time offset
vec2 wavy(vec2 uv, float t, float p, float s) {
	return uv + sin(uv.yx * PI * p + t) * s;
}

float mirr(float v, float m) {
	return m - abs(v - m);
}

vec2 mirr(vec2 v, float m) {
	v.x = mirr(v.x, m);
	return v;
}

// x = variable to repeat
// p = period
// l = low limit
// h = high limit
float repeat(float x, float p, float l, float h) {
	return x - p * clamp(floor(x / p + .5), l, h);
}

// Running bond: s = (rows, columns)
vec2 brick(vec2 uv, vec2 s) {
	uv.x += floor(uv.y * s.y) * (.5 / s.x);
	return fract(uv) * s;
}

// Inputs:
//   - uv in [0..1]
//   - r = radius, in [0..1]
// Output:
//   - xy = offset
//   - z  = edge ratio in [0..1]
vec3 brick_edge(vec2 uv, float r) {
	return vec3(uv -= clamp(uv, r, 1. - r), length(uv) / r);
}

// Inputs:
//   - uv in [0..1]
//   - s = (rows, columns)
//   - r = radius, in [0..1]
// Output:
//   - xy = offset
//   - z  = edge ratio in [0..1]
vec3 brick_edge(vec2 uv, vec2 s, float r) {
	s = s.yx / mn(s);
	uv *= s;
	return vec3(uv -= clamp(uv, vec2(r), s - r), length(uv) / r);
}

////////////////////////////////////////////////////////////////
// Noise ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

// Dave Hoskins/Hash without Sine
// https://www.shadertoy.com/view/4djSRW

float H(vec2 p) {
	vec3 q = fract(p.xyx * .09153);
	q += dot(q, q.yzx + 19.19);
	return fract((q.x + q.y) * q.z);
}

float H(float p) {
	p = fract(p * .1031);
	p *= p + 33.33;
	p *= p + p;
	return fract(p);
}

vec3 H3(float p) {
	vec3 p3 = fract(vec3(p) * vec3(.1031, .1030, .0973));
	p3 += dot(p3, p3.yzx+33.33);
	return fract((p3.xxy+p3.yzz)*p3.zyx);
}

vec2 H2(vec2 p) {
	vec3 p3 = fract(vec3(p.xyx) * vec3(.1031, .1030, .0973));
	p3 += dot(p3, p3.yzx+33.33);
	return fract((p3.xx+p3.yz)*p3.zy);
}

vec4 H4(float p) {
	vec4 p4 = fract(vec4(p) * vec4(.1031, .1030, .0973, .1099));
	p4 += dot(p4, p4.wzxy + 33.33);
	return fract((p4.xxyz + p4.yzzw) * p4.zywx);
}

vec4 H4(vec2 p) {
	vec4 p4 = fract(vec4(p.xyxy) * vec4(.1031, .1030, .0973, .1099));
	p4 += dot(p4, p4.wzxy+33.33);
	return fract((p4.xxyz+p4.yzzw)*p4.zywx);
}

float HT(float p, float s) {
	return H(mod(p, s));
}

float HT(vec2 p, vec2 s) {
	return H(mod(p, s));
}

// FIXME: 1D noise should take a normalized value, like its 2D counterpart!
float N(float p) {
	float i;
	return mix(H(i = floor(p)), H(i + 1.), smoothen(p - i));
}

// FIXME: 1D noise should take a normalized value, like its 2D counterpart!
float NT(float p, float s) {
	float i;
	// FIXME: linear, not smooth
	return mix(HT(i = floor(p), s), HT(i + 1., s), p - i);
}

float NT(vec2 p, vec2 s) {
	p *= s;
	vec2 i = floor(p);
	p -= i;
	p *= p * (3. - 2. * p);
	float s00 = HT(i + vec2(0, 0), s);
	float s01 = HT(i + vec2(0, 1), s);
	float s11 = HT(i + vec2(1, 1), s);
	float s10 = HT(i + vec2(1, 0), s);
	return mix(mix(s00, s10, p.x), mix(s01, s11, p.x), p.y);
}

float FBMT(vec2 p, vec2 scale, float gain, float lac, int lyrs) {
	float acc = NT(p, scale), ow = 1., tw = 1.;
	for (int i=0; i<lyrs; ++i) {
		p = fract(p + PHI);
		scale *= lac; ow *= gain;
		acc += NT(p, scale) * ow;
		tw += ow;
	}
	return acc / tw;
}

// FIXME: 1D noise should take a normalized value, like its 2D counterpart!
float FBMT(float p, float scale, float gain, float lac, int lyrs) {
	float acc = NT(p * scale, scale), ow = 1., tw = 1.;
	for (int i=0; i<lyrs; ++i) {
		p = fract(p + PHI);
		scale *= lac; ow *= gain;
		acc += NT(p * scale, scale) * ow;
		tw += ow;
	}
	return acc / tw;
}

float FBMT_ridged(vec2 p, vec2 scale, float gain, float lac, int lyrs) {
	float acc = ridged(NT(p, scale)), ow = 1., tw = 1.;
	for (int i=0; i<lyrs; ++i) {
		p = fract(p + PHI);
		scale *= lac; ow *= gain;
		acc += ridged(NT(p, scale)) * ow;
		tw += ow;
	}
	return acc / tw;
}

// Env mapping /////////////////////////////////////////////////

// s = detail scale (integral values only)
// 45.0 is very shiny, 9.0 less so
float env(vec3 p, float s) {
	p = normalize(p);
	vec3 a = fract(degrees(atan(p, p.yzx)) / 360.);
	return NT(a.x * s, s) * ls(.9, .0, abs(p.z)) + NT(a.y * s, s) * ls(.7, .0, abs(p.x));
}

float env(vec3 p) {
	return env(p, 45.);
}

////////////////////////////////////////////////////////////////

vec3 Light() {
	vec3 d = Cam.xyz - Pos;
	float
		b = FBMT(d.xy/256.*rot(Cam.w), vec2(3), .7, 3., 4),
		l = 1. - ls(14., -6., length(d.xy) - b * 8.) * ls(128., 48., d.z) * step(.1, Nor.z);
	return texture(Texture1, LUV).xyz * 2. * l;
}

////////////////////////////////////////////////////////////////

vec2 seg(vec2 p, vec2 a, vec2 b) {
	vec2 ab = b-a, ap = p-a;
	float t = sat(dot(ap, ab)/dot(ab, ab));
	return ab*t + a;
}

float half_plane(vec2 uv, vec2 d) {
	return dot(uv, rot(90.) * normalize(d));
}

float box(vec2 p, vec2 b) {
	vec2 d = abs(p) - b;
	return min(max(d.x, d.y), 0.) + length(max(d, 0.));
}

float box1(vec2 p, vec2 b) {
	return mx(abs(p) - b);
}

float circ(vec2 p, float r) {
	return length(p) - r;
}

float seg(vec2 p, vec2 a, vec2 b, float r) {
	return circ(p - seg(p, a, b), r);
}

float elips(vec2 p, vec2 r) {
	return circ(p/r, 1.) / min(r.x, r.y);
}

float exclude(float a, float b) {
	return max(a, -b);
}

// polynomial smooth min
// http://www.iquilezles.org/www/articles/smin/smin.htm
float smin(float a, float b, float k) {
	float h = sat(.5 + 0.5 * (b - a) / k);
	return mix(b, a, h) - k * h * (1. - h);
}

vec2 grad(float x) {
	vec2 d = vec2(dFdx(x), dFdy(x));
	return d / max(length(d), 1e-8);
}

float msk(float s, float d) {
	return sat(1. - s/d);
}

float msk(float s) {
	return sat(1. - s/fwidth(s));
}

////////////////////////////////////////////////////////////////

// Output: xyz = normal, w = unclamped normalized distance
vec4 rivet(vec2 uv, float s) {
	return vec4(uv/=s, sqrt(sat(1.-lsq(uv))), length(uv) - 1.);
}

float top_light(vec3 n) {
	float l = sum(n.yz) * .7;
	return pow(sat(l), 4.) + l;
}

float rivet_shadow(vec2 uv, float s) {
	uv /= s;
	uv.y += .06;
	uv.x *= 2.;
	return ls(.3, .0, length(uv));
}

// c = base color
// l = light intensity (default: 0.5)
// d = shadow intensity (default 0.3)
vec3 add_rivet(vec3 c, vec2 uv, float s, float l, float d) {
	vec4 b = rivet(uv, s);
	c *= 1. + top_light(b.xyz) * msk(b.w, s + s) * l;
	c *= 1. - sqr(rivet_shadow(uv, 20. * s)) * (1. - msk(b.w, s + s)) * d;
	return c;
}

vec3 add_rivet(vec3 c, vec2 uv, float s) {
	return add_rivet(c, uv, s, .5, .3);
}

////////////////////////////////////////////////////////////////

// p = point where function is to be evaluated
// c = flare center
// s = flare size
// i = core intensity
float flare(vec2 p, vec2 c, float s, float i) {
	p -= c;
	float a = ls(.3, .5, abs(fract(nang(p /= s) * 8. + H(fract(c))) - .5));
	return ls(.9, i, pow(lsq(p), .0625) - a * a * .006);
}

// horizontally-wrapped flare
float wrapped_flare(vec2 p, vec2 c, float s, float i) {
	float d = flare(p, c, s, i);
	c.x += p.x < c.x ? -1. : 1.;
	return d + flare(p, c, s, i);
}

// uv in [-0.5..0.5]
float pentagram(vec2 uv, float s) {
	float d = 1e6, i = 0.;
	for (/**/; i < 5.; ++i) {
		vec2 p = vec2(0, -s) * rot(i * 72.);
		d = min(d, length(uv - seg(uv, p, p * rot(144.))));
	}
	return d;
}

////////////////////////////////////////////////////////////////
#pragma section patterns
////////////////////////////////////////////////////////////////

// Quake 3 logo SDF
// t = 0.0 : app icon (chunky)
// t = 1.0 : background logo (slim)
float icon_sdf(vec2 uv, float t) {
	uv.x = abs(uv.x);
	uv.y -= .07;
	float d = elips(uv, vec2(.31, .12 - t * .02)) / 50.; // base ellipse
	d = max(d, -elips(uv - vec2(0, .01 + .01 * t), vec2(.28 + t * .01, .07)) / 75.); // negative inner ellipse
	d = max(d, -box(uv - vec2(0, .1), vec2(.22 - .02 * t, .12))); // cut off far part
	d = max(d, -box(uv - vec2(0, .1), vec2(.084 - .012 * t, .31))); // cut off mid part
	d = min(d, box1(uv - vec2(0, -.09), vec2(tri(-.09, .32, uv.y)*(.04 - .015 * t), .32))); // middle rhombus
	d = min(d, box1(uv - vec2(.11 - .02 * t, -.21 + .01 * t), vec2(tri(-.07, .3, uv.y)*(.03 - .01 * t), .15))); // outer rhombi
	return d;
}

// Quake 1 logo SDF
float sdf_Q(vec2 uv) {
	float d = circ(uv - vec2(0, .17), .32);
	d = exclude(d, circ(uv - vec2(0, .235), .27));
	d = exclude(d, circ(uv - vec2(0, .5), .15));

	// nail
	uv.y -= .09;
	vec2 s = vec2(.09, .52);
	float h = sat(-uv.y / s.y);
	s *= .5;
	s.x *= ls(1.05, .6, h) + sqr(ls(.1, .02, h));
	uv.y += s.y;
	d = min(d, box(uv, s));

	return d;
}

////////////////////////////////////////////////////////////////

// "Asymmetric Blocks" by Shane
// https://www.shadertoy.com/view/Ws3GRs

vec3 pattern(vec2 p, float sc, float bv) {
	vec3 e = vec3(-1, 0, 1), r = vec3(1e5);
	vec2 ip = floor(p*sc), tileID = e.yy;
	p -= (ip + .5) / sc;

	float
		h11 = .5 * HT(ip + e.yy, vec2(sc)),
		h10 = .5 * HT(ip + e.xy, vec2(sc)),
		h01 = .5 * HT(ip + e.yz, vec2(sc)),
		h12 = .5 * HT(ip + e.zy, vec2(sc)),
		h21 = .5 * HT(ip + e.yx, vec2(sc)),
		h00 = .5 * HT(ip + e.xz, vec2(sc)),
		h02 = .5 * HT(ip + e.zz, vec2(sc)),
		h22 = .5 * HT(ip + e.zx, vec2(sc)),
		h20 = .5 * HT(ip + e.xx, vec2(sc));

	vec2[4] ctr, l;
	if (mod(ip.x + ip.y, 2.) < .5) {
		l[0] = 1. + vec2(h21 - h10, h11 - h20);
		l[1] = 1. + vec2(h12 - h21, h11 - h22);
		l[2] = 1. + vec2(h01 - h10, h00 - h11);
		l[3] = 1. + vec2(h12 - h01, h02 - h11);
		ctr[0] = vec2(h21, h11);
		ctr[1] = vec2(h21, h11);
		ctr[2] = vec2(h01, h11);
		ctr[3] = vec2(h01, h11);
	} else {
		l[0] = 1. + vec2(h11 - h20, h10 - h21);
		l[1] = 1. + vec2(h22 - h11, h12 - h21);
		l[2] = 1. + vec2(h11 - h00, h01 - h10);
		l[3] = 1. + vec2(h02 - h11, h01 - h12);
		ctr[0] = vec2(h11, h10);
		ctr[1] = vec2(h11, h12);
		ctr[2] = vec2(h11, h10);
		ctr[3] = vec2(h11, h12);
	}

	for (int i=0; i<4; i++) {
		ctr[i] += l[i] * (vec2(i&1, i/2) - .5);
		l[i] /= sc;
		float bx = box1(p - ctr[i]/sc, l[i]/2. - bv/sc);
		if (bx < r.x)
			r = vec3(bx, ip + ctr[i]);
	}

	return r;
}

////////////////////////////////////////////////////////////////

// Voronoi diagram
// xy = offset; z = edge distance
#define VORO_FUNC(name, norm)										\
	vec3 name(vec2 p, vec2 grid) {									\
		p *= grid;													\
		vec2 n = floor(p), f = p - n, mr, g, o, r;					\
																	\
		float md = 8., sd = md, d;									\
		for (int i = 0; i < 9; ++i) {								\
			g = vec2(i % 3 - 1, i / 3 - 1);							\
			o = H2(mod(n + g, grid));								\
			r = g + o - f;											\
			d = norm;												\
																	\
			if (d < md) {											\
				sd = md;											\
				md = d;												\
				mr = r;												\
			} else if (d < sd) {									\
				sd = d;												\
			}														\
		}															\
																	\
		return vec3(mr, sd - md);									\
	}

VORO_FUNC(voro1, sum(abs(r))) // L1 (Manhattan) norm
VORO_FUNC(voro, length(r)) // L2 norm

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

// base_wall/c_met5_2
TEX(cmet52) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3 c = mix(RGB(48, 41, 33), RGB(103, 101, 104), b);
	return c;
}

// base_trim/pewter_shiney
TEX(ptrshn) {
	float b = FBMT(uv, vec2(3), .9, 3., 4);
	vec3 c = mix(RGB(49, 45, 43), RGB(81, 75, 78), b * b);
	return c;
}

////////////////////////////////////////////////////////////////
#pragma section diamond2c
////////////////////////////////////////////////////////////////

// base_floor/diamond2c
TEX(dmnd2c) {
	float b = FBMT(uv, vec2(7), .9, 3., 4);
	uv.x *= -1.5;
	uv.y += uv.x * .5;
	uv.x = 1. - uv.x + uv.y;
	uv = fract(uv * 28.);
	float f = sat(1. - length(.1 - uv));
	f *= ls(.6, .2, length(.6 - uv));
	f *= ls(.6, .8, length(.1 - uv));
	f *= ls(.2, .6, b) * 2. + 1.;
	float l = 1. - ls(.2, b + 2., mx(abs(uv - .5)));
	return vec3((f + 1.) * mix(.21, .29, b * b) * l);
}

// base_floor/diamond2c_ow (texture)
TEXA(dmnd2cow) {
	vec3 c = T0(uv).xyz;
	float
		b = FBMT(uv = wavy(uv, 7., .01), vec2(5), .7, 3., 4),
		n = FBMT(uv, vec2(7), .5, 2., 4),
		r = length(uv -= .5),
		a = nang(uv),
		d = r + n * .8 - .33
	;
	c = mix(c, mix(RGB(21, 17, 14), RGB(70, 59, 51), b), ls(.5, .2, r + b*b*b));
	c *=
		ls(.1, .11, d)
		+ 2. * pow(tri(.4, .12, .1, d), 8.)
		;
	return vec4(c, 1. - sqrt(ls(.11, .06, d)));
}

// base_floor/diamond2c_ow (map shader)
void dmnd2cow_m() {
	float b = FBMT(UV * .5 + Time.x * vec2(9, 5), vec2(7), .6, 2., 4);
	b *= 1. + .5 * tri(.5, .05, b);
	vec4 c = T0(UV);
	FCol = vec4(mix(RGB(66, 111, 155) * (.8 + 2. * b * b), c.xyz * Light(), c.w), 1);
}

// sfx/diamond2cjumppad (texture)
TEX(dmnd2cjp) {
	float b = FBMT(uv, vec2(7), .9, 3., 4);
	vec3 c = T0(uv).xyz;
	float r = length(uv - .5);
	float m = ls(.46, .45, r);
	float l = 1.5 - 1.5 * ls(.0, .3, r * r);
	l = mix(l, 2.5, tri(.42, .07, r));
	l = mix(l, 3.5, tri(.44, .05, r));
	l = mix(l, 2.6, tri(.36, .03, r));
	float n = .3 + .2 * ls(.35, .30, r);
	l *= 1. - n * ls(.3, .7, b);
	l *= 1. - .3 * sqr(ls(.13, .05, r));
	l = mix(l, 2.5, ls(.04, .01, r));
	l -= l * tri(.03, .01, r) * .7;
	c = mix(c, RGB(68, 66, 54) * l, m);
	c *= 1.-sqr(tri(.34, .02, r));
	c *= 1.-sqr(tri(.46, .03, r));
	c *= 1.-tri(.41, .03, r) * .7;
	return c;
}

// sfx/diamond2cjumppad (map shader)
void dmnd2cjp_m() {
	vec4 c = T0(UV);
	float r = length(fract(UV) - .5);
	float s = mix(.4, 8., fract(Time.x * 1.5));
	FCol = vec4(c.xyz * Light() + RGB(240, 130, 5) * tri(.1, .05, r / s) * ls(.37, .32, r), 1);
}

// textures/sfx/pentfloor_diamond2c (texture)
TEXA(dmnd2pnt) {
	vec3 c = dmnd2cjp(uv);
	uv = fract(uv) - .5;
	float b = FBMT(uv, vec2(3), .9, 3., 4), d = min(abs(length(uv) - .4), pentagram(uv, .35));
	return vec4(c, msk(d - .02 + b * .02, .01));
}

// textures/sfx/pentfloor_diamond2c (map shader)
void dmnd2pnt_m() {
	vec4 c = T0(UV);
	FCol = vec4(c.xyz * Light() + RGB(111, 55, 0) * c.w * (sin(Time.x * PI) * .5 + .5), 1);
}

vec2 knob(vec2 uv, float s) {
	return vec2(1. - length(uv) / s, msk(length(uv) - s));
}

// sfx/launchpad_diamond (texture)
TEXA(lpdmnd) {
	vec3 c = T0(uv).xyz; // base texture
	float
		b = FBMT(uv, vec2(5), .9, 3., 4), // base FBM
		t, o, k, r, h, d;
	vec2 u, v;
	u.x = abs(uv.x - .5);
	u.y = uv.y;

	// large middle panel underneath
	c = mix(c, vec3(.2 + .3 * b * b), r = msk(k = box(u - vec2(0, .5), vec2(.33 - uv.y * .1, .15)) - .05, .004)); // base color
	c *= 1.
		- .5 * tri(.0, .01, k) // outer edge shadow
		+ .2 * tri(-.01, .01, k) // outer edge highlight
	;

	// bottom attachment
	c = mix(c, vec3(.22 + .22 * b * b), r = msk(k = box(u, vec2(.2)), .004)); // base color
	c *= 1.
		+ .3 * tri(.0, .01, k) // outer edge highlight
		+ .5 * sqr(tri(.05, .03, uv.y)) * r // crease highlight
	;

	// bottom slots
	u = mirr(u, .11);
	c *= 1.
		- .3 * msk(k = box(u - vec2(.07, -.03), vec2(0, .05)) - .015, .004) // darken interior
		- .3 * tri(.0, .007, k) // darken edges
	;

	u.x = abs(uv.x - .5);
	u.y = min(uv.y, .4);
	r = length(u - vec2(0, .4)) - (.18 - .06 * ls(.4, 1., uv.y));
	k = .25
		- .15 * ls(.9, .96, uv.y)
		+ .03 * sqr(ls(.82, .86, uv.y))
		+ .07 * ls(.8, .2, uv.y)
		+ .07 * sqr(ls(.35, .22, uv.y))
		- .07 * ls(.22, .0, uv.y)
	;
	o = box(uv - vec2(.5, .5), vec2(k, .46));
	o = max(o, -box(u, vec2(.15, .03)) + .06);
	c = mix(c, vec3(.6, .55, .55) - uv.y * .3 + b * .2, msk(o, .004)); // base metal color
	c *= 1. - .7 * tri(.0, .013, o); // black outer edge
	c *= 1. - (r / .5 - .1) * msk(o, .004); // darken metal away from center
	t = max(r, uv.y - .96);
	o = abs(t - .02) - .03;
	o = max(o, uv.y - 1. + u.x * .5);
	o = max(o, uv.y - .96);
	c = mix(c, vec3(1, 1, .9) - uv.y * .55, tri(-.01, .01, o)); // lane edge highlight
	c = mix(c, vec3(.2 * b + .1), msk(t, .01)); // inner lane color

	// lane traces
	k = .2 - .05 * ls(.8, .5, uv.y) - .15 * ls(.5, .3, uv.y);
	d = msk(t, .004);
	r = box(vec2(u.x, uv.y) - vec2(.25, .6), vec2(k, .2));
	r = min(r, box(uv - vec2(.5, .21), vec2(.02, .05)) - .09);
	c *= 1.
		+ .3 * d * tri(.01, .01, r) // light interior line
		- .3 * d * tri(.0, .01, r) // dark interior line
	;
	c *= 1. - .2 * tri(.0, .05, t) * msk(o, .004); // inner lane shadow
	
	// central knob
	v = knob(u = uv - vec2(.5, .37), .02);
	d = length(u);
	c = mix(c, RGB(222, 155, 144) * (b * .4 + .3), tri(.03, .01, d)); // knob exterior bevel highlight
	//c *= 1. - .5 * tri(.04, .03, .0, d) * clamp(u.y / .02, -1., 1.);
	c *= 1. - .5 * tri(.02, .01, d); // sunken knob exterior
	c = mix(c, RGB(111, 66, 44) * (v.x * 1.5 + .2), v.y); // knob interior

	// metal clamps
	u.x = abs(uv.x - .5);
	u.y = uv.y - .3;
	u = u.x > .06 ? u * rot(50.) - vec2(.08, -.11) : u + vec2(0, .07);
	h = sat(u.y / .09 + .5); // vertical clamp coordinate, normalized [0..1]
	r = box(u, vec2(.04 - .02 * h, .04)) - .01;
	c = mix(c, vec3(.6, .55, .55) * (1. + .4 * b - .5 * h), msk(r, .007) * ls(.21, .18, d)); // base clamp color
	c *= 1. - .5 * h * tri(.02, .008, .0, r); // clamp shadow

	return vec4(c, msk(t - .025, .03));
}

// sfx/launchpad_diamond (map shader)
void lpdmnd_m() {
	vec4 c = T0(UV);
	vec2 uv = fract(UV);
	uv.x = abs(.5 - uv.x);
	float
		t = fract(-Time.x),
		r = length(uv - vec2(0, .4)),
		l = t * pow(max(0., 1. - r), 4.) * c.w;
	if (t > .75)
		l += ls(.03, .01, abs(fract(uv.y + uv.x * .5 + t * 2.) - .45)) * ls(.1, .08, uv.x);
	FCol = vec4(c.xyz * Light() + RGB(180, 150, 5) * l, 1);
}

////////////////////////////////////////////////////////////////
#pragma section metal : patterns
////////////////////////////////////////////////////////////////

// base_wall/metalfloor_wall_10
TEX(mtlfw10) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3 c = mix(RGB(44, 14, 16), RGB(93, 63, 63), b * b);
	return c;
}

// xy = tile id, z = edge
vec3 mtlfw15_d(vec2 uv) {
	float e = 3e-3, a = 0.;
	vec2 g = vec2(6), r = voro1(uv, g).xy;
	for (int i=0; i<9; ++i)
		a += sum(abs(voro1(vec2(i % 3 - 1, i / 3 - 1) * e + uv, g).xy - r));
	return vec3(uv + r.xy / g, a);
}

// base_wall/metalfloor_wall_15
TEX(mtlfw15) {
	float b = FBMT(uv, vec2(3), .9, 3., 4);
	vec3 c = mix(RGB(80, 70, 72), RGB(128, 120, 120), b * b);
	vec3 v = mtlfw15_d(uv);
	c *= mix(.95, 1.1, NT(v.xy, vec2(6)));
	c = mix(c, RGB(168, 128, 120), ls(.5, 1., v.z) * b * .7);
	return c;
}

// base_wall/metalfloor_wall_15ow (texture)
TEXA(mtlfw15ow) {
	float b = FBMT(uv, vec2(3), .9, 3., 4);
	vec3 c = mix(RGB(80, 70, 72), RGB(128, 120, 120), b * b);
	vec3 v = mtlfw15_d(uv);
	float m = ls(.5, 1., v.z);
	float r = ls(.4, .2, length(.5 - fract(v.xy)));
	c *= mix(.95, 1.1, NT(v.xy, vec2(6))) - 2. * r * b * b;
	c = mix(c, RGB(168, 128, 120), m * b * .7);
	return vec4(c, m * r);
}

// base_wall/metalfloor_wall_15ow (map shader)
void mtlfw15ow_m() {
	vec4 c = T0(UV);
	FCol = vec4(c.xyz * Light() + tri(.5, .125, fract(UV.y * .5 + Time.x * .5)) * c.w * .3, 1);
}

// base_wall/metfloor_block_3
TEX(mtlfb3) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3 pt = pattern(uv, 8., .31);
	vec3 c = mix(RGB(66, 58, 55), RGB(118, 107, 105), b);
	float l = 1. - .5 * ls(.034, .036, pt.x);
	l = mix(l, 1.4, tri(.033, .004, pt.x));
	return c * l;
}

// Base SDF
float mtltech(vec2 uv) {
	float b = NT(uv, vec2(64)), f = 0., d = 1e6;
	for (/**/; f < 11.; ++f)
		d = smin(d, abs(length(.5 - abs(uv - R2(f))) - mix(.36, .29, R1(f + .7))) - mix(.015, .03, b), .01);
	return d * 1e2;
}

// Gradient (xy) + SDF (z)
vec3 mtltech_d(vec2 uv) {
	vec3 s, p;
	for (int i=0; i<3; ++i) {
		p = vec3(uv, 0);
		p[i] += 1e-4;
		s[i] = mtltech(p.xy);
	}
	return vec3(normalize(s.xy - s.z), s.z);
}

// base_wall/metaltech12final
TEX(mtlt12f) {
	float b = FBMT(uv, vec2(5), .9, 3., 4), l;
	vec3 c = mix(RGB(51, 46, 43), RGB(165, 147, 143), b * b), d = mtltech_d(uv);
	l = 1. - .5 * (d.y - d.x) * tri(.5, 3., d.z) * ls(1., .0, d.z);
	return c * l * .8;
}

// base_wall/metaltech06final
TEX(mtlt6f) {
	float b = FBMT(uv, vec2(3), 1.1, 3., 4), l;
	vec3 c = mix(RGB(51, 46, 43), RGB(165, 147, 143), b * b), d = mtltech_d(uv);
	l = 1. - .5 * (d.y - d.x) * tri(.5, 3., d.z) * ls(1., .0, d.z);
	return c * l;
}

// base_wall/metalblack03
TEX(mtlbk03) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4),
		l = .18 * (.7 + b * b);
	vec3 g;
	uv = wavy(uv, 13., .007);
	EVAL_GRAD(
		g, uv,
		sqr(ls(.3 + b * .2, .9, FBMT(p[i], vec2(23), .5, 2., 4)))
	);
	return vec3(l * (1. - g.y * g.z));
}

// gothic_wall/iron01_e
TEX(giron01e) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3
		c = mix(RGB(77, 55, 53), RGB(62, 48, 48), NT(uv, vec2(128, 13))) * (.7 + b * b),
		g;
	uv = wavy(uv, 13., .007);
	EVAL_GRAD(
		g, uv,
		sqr(ls(.4 + b * .4, .95, NT(p[i], vec2(63, 43))))
	);
	c *= ls(1.3, .9, g.z);
	return vec3(c * (1. + g.y * g.z));
}

float fender(vec2 uv, vec2 s) {
	uv.y = max(uv.y, 0.);
	return elips(uv, s);
}

vec3 add_techpipe(vec3 c, vec3 b, vec2 uv, float h, float s) {
	float
		y = (uv.y - h) / s,
		p = 1. - y * y;
	c *= 1. - tri(-1., 1., y);
	if (p > 0.)
		c = b * (p * (.8 + .2 * tri(.5, .25, fract(uv.x / s)))) *
			(.7 + sqr(tri(.2, .7, y)));
	return c;
}

vec3 add_all_techpipes(vec3 c, vec2 uv, float b) {
	vec2 p = uv, q = p;

	q.y += tri(.1, .01, mod(q.x, .33)) / 2e2;
	c = add_techpipe(c, 2. * b * RGB(93, 84, 79), uv, .185, .015);
	c = add_techpipe(c, 2. * b * RGB(138, 77, 48), uv, .13, .025);
	c = add_techpipe(c, 2. * b * RGB(112, 71, 51), uv, .09, .015);
	c = add_techpipe(c, 2. * b * RGB(138, 77, 48), q, .05, .015);

	// rectangular gizmos on top of cables
	p.x = abs(fract(uv.x * 6. - .5) - .5) / 6.;
	c *= 1.+ .5 * ls(.04, .03, p.x) * tri(.18, .03, p.y);
	float r = box1(p - vec2(0, .12), vec2(.03, .01));
	r = exclude(r, box1(p - vec2(0, .11), vec2(.01)));
	c *= 1. - sqr(tri(.0, .04, r));
	c = mix(c, RGB(166, 99, 77) * 2. * b * (.75 + .5 * sqr(tri(.125, .01, uv.y))), msk(r, .004));

	// transformer coils?
	q = p;
	q.y -= .07;
	r = circ(q, .03);
	c *= 1. - sqr(tri(.0, .07, r)); // outer shadow
	c = mix(c, RGB(127, 83, 72) * b * 2. * ls(.01, -.005, r), ls(.005, .0, r));
	q.y -= .004;
	r = circ(q, .015);
	c *= sqr(ls(-.01, .01, r)); // inner shadow
	q.y += .013;
	r = circ(q, .05);
	c += RGB(67, 38, 30) * 4. * sqrt(b) * sqr(tri(-.02, .015, r) * tri(.023, .02, uv.y)); // specular?

	return c;
}

// TODO: PCB/chips?
vec3 techno(vec2 uv, float n) {
	return vec3(n * n * .4);
}

// gothic_wall/iron01_ntech3
TEX(giron01nt3) {
	uv.x *= .5; // fix aspect ratio (texture is 128 x 256)

	float
		b = FBMT(uv * vec2(2, 1), vec2(3, 5), .9, 3., 4), // base FBM, tileable
		n = .75 + b * b, // texture intensity
		t = uv.y + .2 * min(.4, tri(.5, .33, fract(uv.x * 4.))), // top alternating pattern
		f1 = fender(uv - vec2(.25, .62), vec2(3, 2) / 32.),
		f2 = fender(uv - vec2(.25, .55), vec2(3, 2) / 48.),
		r;

	vec3
		c = mix(RGB(66, 50, 51), RGB(111, 66, 44), sqrt(tri(.31, .01, uv.y))),
		c2;

	vec2 p = uv, q;
	p.x = fract(p.x * 4.);
	if (uv.y > .3)
		c = add_rivet(c, vec2(4. * abs(p.x - .5) - 1.6, fract(uv.y * 16.) - .5), .07);
	r = abs(p.x - .5);
	// panel shadow/highlight
	c *= 1. - .3 * ls(.31, .32, uv.y) * ls(.87, .86, uv.y) *
		(ls(.035, .03, .5 - r) + tri(.48, .01, r) - tri(.46, .02, r));

	// techno jumble
	c = mix(c * n, techno(uv, b), max(ls(.31, .3, uv.y), msk(f2)));
	c *= ls(1.5, .7, uv.y);
	if (uv.y < .306)
		c *= 1. - tri(.3, .05, uv.y) * msk(-f2 + 10., 20.); // panel shadow
	c *= 1. - tri(.316, .004, uv.y) * msk(-f2);

	// bottom part - cables?
	if (uv.y < .1)
		c *= .0;
	c = add_all_techpipes(c, uv, b);

	// fender?
	r = exclude(f1, f2);
	r = exclude(r, (uv.y - .3) * 3e2);
	c *= 1. - .5 * tri(-2., 17., f2) * ls(.26, .3, uv.y); // inner fender shadow

	c2 = RGB(67, 39, 17) * n;
	c2 = mix(c2, vec3(n * .2), tri(0., 4., r) * b); // desaturate edges
	c2 *= 1. - .4 * pow(tri(.0, 3., r), 4.); // darken outer edge
	c2 += (c2 + .6) * sqrt(b) * sqr(tri(-6., 8., r) * tri(.66, .04, uv.y)) * msk(r); // specular
	if (uv.y < .56)
		c2 = add_rivet(c2, vec2(24. * abs(uv.x - .25) - 1.85, fract(uv.y * 24. + .5) - .5), .15);

	// top part - we also fill in the bottom row to avoid bilinear artifacts
	// (even if the original texture doesn't)
	c = mix(c, T0(uv).xyz, ls(.85, .9, t) + step(uv.y, 1./256.));
	c *= 1. + tri(.88, .015, t) - sqr(tri(.87, .03, t));

	return mix(c, c2, ls(1., .1, r));
}

vec3 gmtlbg6_layer(vec3 c, vec3 k, vec2 uv, int w, int h) {
	float b = FBMT(uv, vec2(w, h), .5, 2., 2);
	c *= .9 - .3 * ls(.15, .1, abs(b - .5));
	return mix(c, k, tri(.5, .1, b));
}

// gothic_floor/metalbridge06
TEX(gmtlbg6) {
	uv = wavy(uv, 9., .005);
	int i = 0, l[] = int[](13, 43, 17, 47, 23, 59, 27, 63);
	float b = FBMT(uv, vec2(19), .7, 2., 4);
	vec3 c = mix(RGB(40, 50, 60), RGB(46, 33, 27), b) * (.5 + b);
	for (/**/; i < 8; i += 2)
		c = gmtlbg6_layer(c, mix(RGB(145, 140, 137), RGB(132, 123, 116), b), uv, l[i], l[i+1]);
	return c;
}

// gothic_floor/metalbridge06broke
TEX(gmtlbg6brk) {
	vec3 c = T0(uv).xyz; // base texture
	uv = fract(uv * 2. + .5); // hack: repeat 2x + offset
	float
		b = FBMT(uv, vec2(7), .7, 2., 4), // base FBM
		n = NT(uv, vec2(33)) - .5, // distortion noise
		d = circ(uv - vec2(.7, .5), .13); // big right disk
	d = min(d, circ(uv - vec2(.44, .66), .08)); // add smaller center disk
	d = min(d, circ(uv - vec2(.33, .4), .06)); // add smaller left disk
	d += .04 * n; // SDF distortion
	c += b * b * tri(.0, .03, d); // bright edges
	c *= 1.
		- b * tri(.03, .02, d) // outer edge shadow
		- b * tri(-.04, .05, d) * .5 // inner edge shadow
		- b * ls(.0, .02, -d) // interior shadow
	;
	return c;
}

vec3 gblks17f2_layer(vec3 c, vec3 k, vec2 uv, int w, int h) {
	float b = FBMT(uv, vec2(w, h), .5, 2., 2);
	c *= 1. - .15 * sqr(ls(.15, .1, abs(b - .5)));
	return mix(c, k, tri(.5, .1, b));
}

// gothic_floor/blocks17floor2
TEX(gblks17f2) {
	float
		b = FBMT(uv, vec2(13), .9, 3., 4),
		n = FBMT(uv, vec2(7), .9, 3., 4);
	vec3
		c = mix(RGB(111, 66, 55), RGB(80, 55, 52), sqr(ls(.8, .2, n))) * (.8 + .8 * b * b),
		k = c; // layer color
	uv = wavy(uv, 13., .01);
	int i = 0, l[] = int[](13, 43, 17, 47, 23, 59, 27, 63); // same values as in gmtlbg6
	b = FBMT(uv, vec2(19), .7, 2., 4);
	for (/**/; i < 6; i += 2) // note: not using all layers!
		c = gblks17f2_layer(c, k, uv, l[i], l[i+1]);
	return c;
}

////////////////////////////////////////////////////////////////
#pragma section arena : patterns
////////////////////////////////////////////////////////////////

vec3 gkarnclma2r_layer(vec3 c, vec3 k, vec2 uv, int w, int h) {
	float b = FBMT(uv, vec2(w, h), .5, 2., 1);
	c *= .9 - .3 * sqr(ls(.15, .1, abs(b - .5)));
	return mix(c, k, tri(.5, .1, b));
}

// gothic_door/km_arena1columna2R
TEX(gkarnclma2r) {
	float
		b = FBMT(uv, vec2(3,29), .9, 2., 4), // base FBM
		t = .8 + .8 * b * b, // base texture intensity (remapped FBM)
		d = abs(uv.y - .61), // distance from vertical center of helixy part
		o = ls(.25, .24, d), // mask for flat part
		m; // mask for threads
	vec3
		c = RGB(140, 127, 127), // base color
		k = c; // branchy layer color
	vec2
		p = uv;

	c *= 1. - .1 * ls(.85, .86, uv.y); // darken top part
	c = t * mix(c, RGB(110, 55, 50), ls(.33, .32, uv.y)); // vary intensity, colorize bottom

	p.y += p.x * .11 + b * .007; // skew
	p.y = fract(p.y * 9.) - .5; // repeat vertically
	m = ls(.0, .1, abs(p.y) - .2); // mask

	// branchy part between the threads
	int i = 0, l[] = int[](3, 29, 5, 37, 9, 63, 27, 63);
	for (/**/; i < 6; i += 2)
		c = mix(c, gkarnclma2r_layer(c, k, uv, l[i], l[i+1]), m * o); // branchy layer

	c *= 1. + t * o * (
		+ .6 * tri(.1, .1, p.y) // helix highlight
		- .7 * tri(-.25, .3, p.y) // shadow underneath helix
		- .5 * tri(.2, .1, p.y) // shadow above helix
	);
	c = mix(c, RGB(99, 66, 51) * t, tri(-.15, .1, p.y) * o); // colored reflection

	// bevels at both ends of the helixy part
	c *= 1.
		+ tri(.36, .005, uv.y) // highlight
		+ tri(.34, .005, uv.y) // highlight
		+ tri(.865, .005, uv.y) // highlight
		+ tri(.89, .01, uv.y) // highlight
		- .5 * sqr(tri(.245, .01, d)) // shadow
		- .7 * sqr(tri(.35, .01, uv.y)) // shadow
		- .5 * sqr(tri(.325, .02, uv.y)) // shadow
		- .8 * sqr(tri(.875, .02, uv.y)) // shadow
		- .3 * sqr(tri(.9, .02, uv.y)) // shadow
		;

	c *= .3 + sqrt(ridged(uv.x)); // darken left/right sides

	return c;
}

vec3 gkarnarcfnl_layer(vec3 c, vec2 p, float s, float m) {
	s = voro1(p, vec2(s)).z / s * 1e2;
	c *= 1.
		+ .5 * m * ls(.9, .2, s)
		- .5 * m * tri(2.5, .5, .3, s)
		;
	return c;
}

vec3 gothic_metal(float b) {
	return RGB(133, 100, 100. - 12. * b) * (.8 + .8 * b * b);
}

// Used by
// - gothic_door/km_arena1archfinald_mid
// - gothic_block/killblockgeomtrn
// - gothic_block/demon_block15fx
vec3 gkarnarcfnl_inner_gear(vec3 c, vec2 uv, float shadow_bias) {
	float
		b = FBMT(uv, vec2(4, 9), .9, 3., 4), // base FBM
		t = .8 + .8 * b * b, // base texture intensity (remapped FBM)
		a, // angle
		d, // distance
		m, // mask
		s, // segment
		k, i, v, r, z; // ugh...
	vec3
		mt = gothic_metal(b); // metal color
	vec2
		p, q;

	p = q = uv;
	q.x = abs(q.x); // symmetry
	d = circ(p, .31);
	v = nang(q); // relative angle; note: uses symmetric coords!
	m = ls(.01, .0, d);
	c = mix(c * ls(.0, .05, d + shadow_bias), vec3(.13 * t), m); // background color + outer shadow
	c = gkarnarcfnl_layer(c, p, 37., ls(.04, .02, abs(d + .07))); // random lines
	a = v * 22.;
	i = floor(a); // segment id
	s = a - i; // segment fraction
	k = ls(.23, .22, abs(v - .25)) + R1(i) * ls(.0, .1, q.y);
	d -= r = (d * .3 + .005) * k; // extra thickness for top part
	m = ls(.0, .1, q.y) * msk(abs(d + .015) - .015);
	c = mix(c, mt, sat(1.5 * tri(-.015, .0, .01 - .003 * k, d))); // highlight
	c = mix(c, RGB(130, 75, 44) * t, tri(-.02, .005, d) * ls(.0, .1, q.y)); // colored reflection
	c *= 1.
		- .3 * ls(.025, .03, -d) // darken interior
		- .5 * ls(.4, .5, abs(s - .5)) * m // dark edge between top segments
		+ .2 * tri(.5, .3, abs(s - .5)) * m // top segment edge highlight
		- .5 * tri(-.015, .007, d) // dark edge
		- .5 * tri(-.03, .007, d) // dark edge
		- .5 * tri(-.1, .005, d + r) // dark edge
		- .5 * tri(-.115, .005, d + r) // dark edge
		- .5 * tri(-.125, .015, d + r) // dark edge
		- .5 * tri(-.145, .005, d + r) // dark edge
		+ .9 * tri(-.11, .007, d + r) // highlight
		+ .5 * tri(-.14, .005, d + r) // highlight
		- b * tri(.225, .005, abs(v - .25)) * msk(abs(d + .015) - .015) // dark edge
		;
	a = v * 72.;
	i = floor(a); // segment id
	s = a - i; // segment fraction
	k = step(.7, H(i)) // 30% of segments
		* step(q.y, .0) // below horizon
		* ls(.02, .0, abs(d + .02)) // distance from circle between [-0.4 and 0]
		;
	c = mix(c, vec3(mt * .6), k * ls(.4, .3, abs(s - .5))); // background color
	c *= 1.
		- .7 * k * tri(.4, .1, abs(s - .5)) // dark segment edge
		;

	return c;
}

// (256 x 576) Combination of:
// - gothic_door/km_arena1archfinalc_top (256 x 64)
// - gothic_door/km_arena1archfinald_mid (256 x 256)
// - gothic_door/km_arena1archfinald_bot (256 x 256)
vec3 gkarnarcfnl(vec2 uv) {
	float
		b = FBMT(uv, vec2(4, 9), .9, 3., 4), // base FBM
		t = .8 + .8 * b * b, // base texture intensity (remapped FBM)
		a, // angle
		d, // distance
		m, // mask
		s, // segment
		k, i, v, r, z; // ugh...
	vec3
		mt = gothic_metal(b), // metal color
		c = vec3(.3 * b); // base color
	vec2
		p, q;

	/* bottom arch */
	p.x = uv.x - .5;
	p.y = max(uv.y - .2, 0.) * 1.89;
	v = atan(p.y, abs(p.x)) / PI; // relative angle [-1..1]
	d = circ(p, .48); // arch distance
	k = ls(.3, .31, v); // mid mask
	d *= 1. - .2 * ls(.3, .31, v) - .1 * ls(.43, .44, v); // thicken middle parts
	a = v * (v > .44 ? 2. : v > .3 ? 63. : 31.); // number of segments
	c = mix(c, mt, ls(.03, .01, abs(d))); // arch background color
	m = msk(abs(d - .01) - .02);
	i = floor(a);
	s = a - i;
	if (v > .33 && v < .44)
		s = fract(s + H(i) * .6 - .3); // non-uniform segments
	c *= 1.
		//- .5 * m * tri(.435, .005, v) // dark edge
		- .5 * m * tri(.307, .01, v) // dark edge
		- t * m * tri(.5, .1 + k * .2, s) // dark edge between segments
		+ b * m * tri(.52, .2 + k * .2, s) // segment edge highlight
		;
	c *= 1.
		- .9 * tri(-.015, .015, d) // black inner edge
		- .5 * tri(.0, .01, d) // dark inner edge
		- .7 * tri(.03, .02, d) // black outer edge
		+ tri(.01, .015, d) // highlight
		;

	/* top gothic arch */
	q = p;
	q.y -= .5;
	q.x = abs(q.x) + .6;
	d = circ(q, 1.13);
	m = ls(.03, .02, abs(d)) * ls(.5, .6, q.y);
	c = mix(c, mt * sat(1. - abs(d - .015) / .03), m); // background color
	c *= 1.
		- .5 * m * tri(.005, .01, d)
		+ .5 * m * tri(.017, .005, d)
		;

	/* small top gears */
	q.x = abs(uv.x - .5) - .35;
	q.y = uv.y * 9./4. - 2.1;
	d = circ(q, .13) * 10.;
	a = nang(q) * 49.;
	i = floor(a);
	s = a - i;
	v = ls(.85, .9, H(i));
	for (int j = 0; j < 2; ++j, d += .3) {
		c = mix(c, mt * (b * .5 + .2), ls(.09, .03, abs(d)));
		c *= 1.
			+ .7 * sqr(tri(.01, .05, d))
			;
	}

	/* large outer gear above arch */
	p.y = (uv.y - .7) * 9./4.;
	d = circ(p, .43);
	a = atan(p.y, abs(p.x)) / PI; // relative angle [-1..1]
	a = max(a, -.48); // remove lower mid space spoke
	r = a;
	i = floor(a *= 23.); // segment id
	s = a - i; // segment fraction
	k = R1(i) * .2 - .1 * ls(.0, .1, -d);
	v = ls(.1, .2, abs(s - .5) - k);
	d += v * .007; // offset spokes
	r = (1. - v) * sqr(tri(.5, .3, r)) * ls(.25, .05, abs(s - .5)); // top spikes
	d -= .17 * r;
	m = tri(.04, .0, -.4, d); // mask
	c = mix(c, mt * (b * .4 + .4), m); // background color
	c = gkarnarcfnl_layer(c, p, 31., ls(.1, .05, abs(d + .15)) * v); // random lines between spokes
	c *= mix(1., 1. - tri(.1, .2, .4, abs(s - .5) - k), m * b); // spoke shadows
	c *= 1.
		- .7 * sqr(tri(.03, .03, d)) // black outer edge
		- .7 * sqr(tri(.03, .03, d + .05)) * v // dark shadow between 1st and 2nd circles
		- .7 * sqr(tri(.0, .02, d + .05)) * v // dark shadow under 2nd circle
		- .3 * ls(.04, .06, -d) * v // darken space between spokes
		+ .5 * tri(.02, .0, -.1, d) // smooth highlight
		+ tri(.0, .01 + .07 * r, d) // sharp highlight
		+ tri(.0, .01, d + .03) * v // sharp highlight
		;

	/* smaller inner gear above arch */
	p.y -= .05;
	c = gkarnarcfnl_inner_gear(c, p, 0.);

	return c;
}

// gothic_door/km_arena1archfinalc_top
TEX(gkarnarcfnltp) {
	uv.y = (uv.y + 8.) / 9.;
	return gkarnarcfnl(uv);
}

// gothic_door/km_arena1archfinald_mid
TEX(gkarnarcfnlmd) {
	uv.y = (uv.y * 4. + 4.) / 9.;
	return gkarnarcfnl(uv);
}

// gothic_door/km_arena1archfinald_bot
TEX(gkarnarcfnlbt) {
	// Hack: reduce bilinear artifacts at the top by changing
	// the bottom row of pixels to match the bottom row in _mid
	if (uv.y < .01)
		++uv.y;
	uv.y = uv.y * 4. / 9.;
	return gkarnarcfnl(uv);
}

////////////////////////////////////////////////////////////////
#pragma section blocks : arena metal
////////////////////////////////////////////////////////////////

// gothic_block/blocks15
TEX(gblks15) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4), // base FBM
		t = FBMT_ridged(wavy(uv, 4., .01), vec2(7), .5, 3., 5), // ridged FBM
		n = NT(wavy(uv, 4., .05), vec2(9)), // smooth noise
		id, e;
	vec3
		c = RGB(74, 65, 62) * (.8 + .8 * b * b), // base color
		pt = pattern(uv, 4., .07 + b * .04); // asymmetric block pattern
	vec2 d = grad(pt.x);
	id = H(fract(pt.yz)); // tile id
	c += tri(.6, .3, n) * ls(.3, .9, b * t) * .2; // bright splotches
	c *= 1. - tri(.5, .4, n) * ls(.5, .7, t) * .1; // some medium-frequency variation
	c = mix(c, RGB(86, 74, 78), tri(.5, .1, b) * tri(.7, .3, id) * .7); // subtle splash of color
	c = mix(c, RGB(105, 90, 70), tri(.3, .1, t) * tri(.3, .3, id) * .3); // another subtle splash of color
	e = tri(.015, .015 * b, pt.x) + tri(.4, .1, n * t) * .4; // edge size
	c *= 1. - .2 * t * ls(.015, .017, pt.x); // mortar
	c *= 1. + e * b * (d.y - .3); // bevel
	c *= .9 + .2 * id; // per-tile brightness variation
	c *= .9 + .2 * ridged(NT(uv - pt.yx, vec2(5))); // some medium-frequency variation

	vec3 g;
	EVAL_GRAD(
		g, uv,
		tri(.7, .5, NT(p[i], vec2(23))) *
		sat(tri(.7, .4, NT(p[i], vec2(53))) * 4.);
	);
	c *= 1.
		+ g.y * g.z * b * b * (.8 - id) // scratches
		- pow(ls(.5, .0, b), 3.) // dirt/mold
	;

	return c;
}

// gothic_block/killblockgeomtrn
TEX(gkblkgmtrn) {
	vec3 c = T0(uv).xyz;
	uv -= .5;
	c = gkarnarcfnl_inner_gear(c, uv * .9, .02);
	return c;
}

// Simple skull shape
// x = light intensity
// y = SDF
vec2 skull(vec2 p) {
	p.x = abs(p.x); // symmetry
	vec2 q = p, v;
	q.y -= .5;
	float
		d = circ(q, .35),
		e, // secondary sdf
		c; // light intensity
	v = q / .35;
	q.y += .22;
	q.x -= .15; // eye offset
	d = min(d, box(q, vec2(.09, .05)) - .1); // cheekbones
	e = elips(q, vec2(.15, .1)) / 5e1; // eye socket sdf
	c = .1
		+ dot(vec2(v.y, sqrt(sat(1. - lsq(v)))), vec2(.3))  // base intensity
		- .05 * tri(.44, .1, p.y) // slight eyebrow indentation
		- .1 * smoothstep(.3, .22, length(p - .5)) // darken temples
	;
	q.y += .2;
	q.x = p.x; // recenter
	c = max(c, sat(.4 - length(q))); // brigten up bottom
	c +=
		.15 * tri(.0, .1, e) // highlight eye socket edge
		- .1 * msk(e + .12, .15) // darken eye socket interior
		;
	d = min(d, box(q, vec2(.15 - ls(-.15, .15, q.y) * .07, .03)) - .09); // nose
	c *= 1. - ls(.05, .25, q.x) * ls(.2, .1, abs(q.y + .12)); // maxilla gradient
	q.y -= .06;
	c -= .5 * msk(elips(q, vec2(.05 - ls(-.1, .1, q.y) * .03, .06)) / 1e3 + .03, .05); // darken nose
	//q.y += .15;
	//d = min(d, box(q, vec2(.1 - sqr(ls(.1, -.1, q.y)) * .03, .05)) - .05);
	return vec2(sat(c), d);
}

// gothic_block/demon_block15fx
TEX(gdmnblk15fx) {
	vec3 c = T0(uv).xyz;

	uv -= vec2(.5, .66);
	float
		b = FBMT(uv, vec2(5), .5, 3., 4),
		t = .8 + .8 * b * b,
		k = sqr(1. - tri(-.35, .2, uv.y)),
		r, d, l;

	EVAL_TOP_LIGHT(uv, .02, d, l, min(seg(p, vec2(0), vec2(0, -.44), .12), circ(p, .25)));
	c = mix(c, mix(RGB(188, 133, 66), RGB(133, 127, 119), ls(.6, .2, -uv.y)) * t, msk(d, .01)); // base metal color
	c *= 1.
		+ .6 * (l * .6 - .4) * sat(1.5 * tri(.2 + .1 * k, -.1 * k, -.2 * k - .03, d * 10.)) // outer bevel
		+ 1.5 * tri(.0, .08, uv.x) * tri(.02, .01, -d) // lower edge highlight
	;
	//c = mix(c, vec3(.27), tri(.0, .15, uv.x) * tri(.0, .01, d) * sat(-l)); // grey bottom edge reflection; too subtle?

	/* skull */
	vec2
		p = uv * 8. + vec2(0, 2.5),
		q = skull(p);
	l = (skull(p + vec2(0, .2)).y - q.y) / .2;
	c *= 1.
		- (l * .6 + .2) * tri(.05, .1, q.y) // skull bevel
		- (.5 - 2. * q.x) * msk(q.y, .05) // skull interior
	;

	/* crescent under skull */
	EVAL_TOP_LIGHT(uv, .01, r, l, exclude(circ(p + vec2(0, .26), .09), circ(p, .255)));
	c *= 1. - (l * .6 + .2) * tri(.0, .01, r) * msk(.1 - q.y, .1);

	c = mix(c, gkarnarcfnl_inner_gear(c, uv * 1.4, .05), msk(.15 - q.y, .05));

	p.x = abs(uv.x);
	p.y = repeat(uv.y + .37, .06, -1., 1.);
	c = add_rivet(c, p - vec2(.095, .015), .011, .2, .4); // knobs

	return c;
}

vec3 gklblki_vent(vec3 c, vec2 uv, float b) {
	float
		t = .75 + b * b, // base texture intensity (remapped FBM)
		d, o, i;

	vec2 p = uv;
	p.y -= .21;

	d = circ(vec2(.75 * p.x, elongate(p.y, .1)), .033);
	o = msk(d, .005); // outer part
	d = circ(vec2(.75 * p.x, elongate(p.y + .005, .09)), .033);
	i = msk(d + .015, .004); // inner part
	c = mix(c, RGB(83, 81, 66) * t, (o - i) * ls(.1, .3, uv.y)); // base metallic color
	c *= 1. - ls(.17, .25, uv.y) * i; // inner shadow
	c += sqr(tri(.0, .015, d)) * tri(.32, .03, uv.y); // top specular
	c *= 1. + 3. * pow(tri(-.01, .03, d), 4.) * tri(.09, .03, uv.y); // bottom specular

	d = circ(vec2(.75 * p.x, elongate(p.y + .03, .1)), .033); // shadow distance
	c *= 1. - msk(d + .01, .02) * (1. - o); // outer shadow

	if (uv.y > .09 && uv.y < .3)
		c = add_rivet(c, vec2((abs(p.x) - .035) * 36., fract(uv.y * 36.) - .5), .1);

	return c;
}

// gothic_trim/baseboard09_e
TEX(gtbsbrd09e) {
	float
		b = FBMT(uv, vec2(9, 3), .9, 3., 4), // base FBM
		n = FBMT(uv, vec2(11, 5), .5, 3., 4), // slightly smoother FBM
		t = .75 + b * b, // base texture intensity (remapped noisy FBM)
		l, m;
	vec3 c = mix(RGB(48, 44, 44), RGB(77, 55, 44), ls(.3, .7, n)) * t;
	vec2 p, q, s;

	p.x = mod(uv.x + .14, .28) - .22;
	p.y = uv.y * .4 - .09;

	// top slots
	q.x = mod(uv.x - .014, .14);
	q.y = uv.y;
	c = mix(c, RGB(133, 122, 122) * t, tri(.9, .91, 1., uv.y) * ls(.03, .033, abs(q.x - .07)));
	c = mix(c, RGB(88, 73, 70) * t * ls(1., .96, uv.y), ls(.86, .87, uv.y) * ls(.033, .03, abs(q.x - .07)));

	// stadium-shaped vents between skulls
	c = gklblki_vent(c, p * 1.2, b);

	// cables
	c *= ls(.2, .3, uv.y);
	c = add_all_techpipes(c, uv * vec2(1.5, .75), b);

	// skulls
	t = .8 + .8 * n * n; // smoother base texture intensity
	p.x += .133;
	p.y = p.y * 1.1 - .09;
	m = step(abs(uv.x - .5), .4); // 3 skull limit
	s = skull(p * 5.); // skull grayscale intensity + SDF
	l = (skull(p * 5. + vec2(0, .1)) - s).y / .1; // skull light/shadow
	c = mix(c, 2.5 * mix(RGB(122, 99, 95), RGB(99, 66, 50), b) * t * s.x, msk(s.y, .02) * m); // skulls
	c *= 1. - (.5 - l * .3) * tri(.02, .07 + .13 * sat(-l), s.y) * m; // skull shadows, larger below

	return c;
}

// gothic_trim/baseboard09_e2
TEXA(gtbsbrd09e2) {
	return T0(uv);
}

// (384 x 384) Combination of:
// - gothic_door/skull_door_a ( 64 x 256 - bottom right)
// - gothic_door/skull_door_b (256 x 256 - bottom mid)
// - gothic_door/skull_door_c ( 64 x 256 - bottom left)
// - gothic_door/skull_door_d ( 64 x 128 - top right)
// - gothic_door/skull_door_e (256 x 128 - top mid)
// - gothic_door/skull_door_f ( 64 x 128 - top left)
vec3 gskdr(vec2 uv) {
	uv *= 1.5;

	float
		b = FBMT(wavy(uv, 7., .02), vec2(9), .7, 3., 2), // base FBM
		t = b, // base texture intensity (remapped FBM)
		n = NT(uv, vec2(13)), // smooth noise
		a, // angle
		s, // segment fraction [0..1]
		d; // SDF
	vec3 c = T0(uv).xyz;
	vec2 p;

	p.x = abs(uv.x - .75);
	p.y = max(uv.y - .58, 0.) * 1.15;
	a = atan(p.x, p.y) / PI; // angle [-1..1]
	s = fract(a * 7. + .5); // segments
	d = circ(p, .45); // base arch
	d -= .06 * ls(.4, .33, uv.y); // outer buttress
	d -= .05 * ls(.15, .07, abs(s - .5)) * step(.63, uv.y);
	d = exclude(d, uv.y - .107); // bilinear filtering hack: exclude bottom pixel row
	if (uv.y < .6)
		d = exclude(d, abs(p.x - .493) - .113); // bilinear filtering hack
	d = exclude(d,
		circ(p, .6) // carve out interior
		+ .044 * ls(.48, .43, uv.y) // inner buttress
	);
	c = mix(c, RGB(144, 125, 115) * t, msk(d - .1, .005));
	c *= 1.
		- .3 * tri(.12, .11, .1, d) // outer shadow
		+ .5 * tri(.1, .005 + .015 * n * n, d) // highlight
		;

	return c;
}

// gothic_door/skull_door_a ( 64 x 256 - bottom right)
TEX(gskdr_a) {
	return gskdr(vec2(5, 0) / 6. + uv * vec2(1, 4) / 6.);
}

// gothic_door/skull_door_b (256 x 256 - bottom mid)
TEX(gskdr_b) {
	return gskdr(vec2(1, 0) / 6. + uv * vec2(4) / 6.);
}

// gothic_door/skull_door_c ( 64 x 256 - bottom left)
TEX(gskdr_c) {
	return gskdr(uv * vec2(1, 4) / 6.);
}

// gothic_door/skull_door_d ( 64 x 128 - top right)
TEX(gskdr_d) {
	return gskdr(vec2(5, 4) / 6. + uv * vec2(1, 2) / 6.);
}

// gothic_door/skull_door_e (256 x 128 - top mid)
TEX(gskdr_e) {
	return gskdr(vec2(1, 4) / 6. + uv * vec2(4, 2) / 6.);
}

// gothic_door/skull_door_f ( 64 x 128 - top left)
TEX(gskdr_f) {
	return gskdr(vec2(0, 4) / 6. + uv * vec2(1, 2) / 6.);
}

// gothic_block/blocks18c
TEX(gblks18c) {
	float b = FBMT(uv, vec2(13, 1), .7, 2., 3); // mostly vertical noise
	vec3 c = T0(uv).xyz * .7; // base texture, slightly darkened
	c *= 1. - sqr(ls(.4, 1., b)); // dark drip stains
	return c;
}

// s.x = specular size
// s.y = specular intensity
vec3 gklblki_base(vec2 uv, vec2 s) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4), // base FBM
		n = FBMT(uv, vec2(31, 3), .5, 3., 3), // mostly vertical noise (for drip stains)
		t = .75 + b * b; // base texture intensity (remapped FBM)

	vec2 p = uv;
	vec3 c = T0(uv).xyz;

	if (uv.y < .38)
		c = mix(RGB(92, 43, 15), RGB(66, 44, 33), ls(.1, .05, uv.y)) // base color
			* t * (.5 + .5 * ls(.0, .35, uv.y)) // intensity
			;
	c +=
		b * s.y * sqr(tri(.32, s.x * .015, uv.y)) // highlight edge
		+ .3 * b * tri(.34, .05, uv.y) // highlight top
		;
	c *= 1.
		- tri(.38, .005 + b * b * .03, uv.y) // shadow under blocks
		+ 3. * tri(.15, .2, uv.y) * (n - .5) // dark drip stains
		;

	return c;
}

// gothic_block/killblock_i
TEX(gklblki) {
	float b = FBMT(uv, vec2(5), .9, 3., 4); // base FBM
	vec3 c = gklblki_base(uv, vec2(1));
	uv.x = mod(uv.x, 1./7.) - .07; // repeat 7x horizontally
	return gklblki_vent(c, uv, b);
}

// gothic_block/killblock_i4
TEX(gklblki4) {
	float
		b = FBMT(uv, vec2(9), .7, 2., 4), // base FBM
		t = .75 + b * b, // base texture intensity (remapped FBM)
		l;
	vec3 c = gklblki_base(uv, vec2(4, .3));
	vec2 p = uv, s;
	p.x = mod(p.x, .2); // repeat x5 horizontally
	p -= .1;
	s = skull(p * 5.); // skull grayscale intensity + SDF
	l = (skull(p * 5. + vec2(0, .1)) - s).y / .1; // skull light/shadow
	c = mix(c, mix(vec3(.5, .4, .3), vec3(.95, .8, .55), t) * t * s.x, msk(s.y, .02)); // skulls
	c *= 1. - (.5 - l * .3) * tri(.02, .07 + .13 * sat(-l), s.y); // skull shadows, larger below
	return c;
}

////////////////////////////////////////////////////////////////
#pragma section largerblock
////////////////////////////////////////////////////////////////

// gothic_floor/largerblock3b 
TEX(glrgbk3b) {
	uv.y -= 1./32.; // hack to avoid storing UV offsets for this texture in the map...
	vec2
		p = brick(uv.yx, vec2(8)), // brick layout
		q = fract(p), // position inside brick [0..1]
		v = wavy(uv, 31., .002), // wavy uv, for bumps
		id = p - q; // brick id
	float
		b = FBMT(wavy(uv, 5., .02), vec2(7), 1., 3., 4), // base FBM
		t = .8 + .8 * b * b, // base intensity (remapped FBM)
		n = NT(uv + R2(H(id) * 64.), vec2(23)), // smooth noise, for brick edge size variation
		m = FBMT(uv, vec2(9), .7, 3., 4), // another FBM, for dark splotches
		d = FBMT(v, vec2(63), .7, 3., 4), // bump FBM
		r = FBMT(v - vec2(0, .002), vec2(63), .7, 3., 4), // offset bump FBM, for lighting
		l = d - r, // lighting
		e = brick_edge(q, .03 + .03 * ridged(n)).z, // edge intensity: 1 = on edge, 0 = inside brick
		h = H(id); // hashed brick id
	vec3 c = mix(RGB(91, 61, 42), RGB(70, 30, 15), e * b); // base colors
	c = mix(c, RGB(70, 48, 35), ls(.5, .6, m)) // add dark splotches
		* t // and vary intensity
		;
	c *= 1.
		+ l * (.1 + n + tri(.6, .1, m)) * (1. - e) // bump lighting
		- t * ls(.7, 1., e) * NT(uv, vec2(13)) // dark brick edges
		+ .5 * b * tri(.3, .3, e) // brick edge highlights
		;
	d = FBMT(v, vec2(23), .5, 2., 4); // hole FBM
	c *= 1.
		- .2 * ls(.6, .7, d) * h // darken interior
		+ .3 * tri(.6, .05, d) * h * n // highlight edges
		;
	c *= .9 + .2 * h * (1. - e); // vary intensity per brick
	c *= .9 + .4 * pow(FBMT_ridged(uv - H(id / 8.), vec2(5), .6, 2., 4), 4.); // some ridge-like intensity variation
	return c;
}

// gothic_floor/largerblock3b_ow (texture)
TEXA(glrgbk3bow) {
	vec3 c = T0(uv).xyz; // differs from the shadertoy - don't overwrite!
	uv = fract(uv * 2. + vec2(8, 3) / 32.); // HACK - manual uv offset
	float
		n = NT(uv, vec2(19)),
		m, r
	;
	vec2
		p = uv - .5,
		q = vec2(3, 17) * vec2(nang(p), length(p) + (n - .5) * .03),
		e
	;
	q.x += floor(q.y) * PHI;
	q.x *= floor(q.y);
	r = length(e = fract(q) - .5);
	m = tri(.5, 1., 4.5, q.y) * n;
	c *= 1.
		- m * sqr(tri(.3, .2, r)) * 5. * e.y // cell bevel
		- m * ls(.4, .5, r) // dark edge borders
		;
	c *= ls(.9, 1.2, q.y);
	return ls(.5, 1.1, q.y) * vec4(c, 1);
}

// gothic_floor/largerblock3b_ow (map shader)
void glrgbk3bow_m() {
	vec2 p = UV - H2(Time.x * vec2(3, 5));
	float b = FBMT(p, vec2(13), .6, 2., 4);
	vec4 c = T0(UV);
	FCol = vec4(mix(b * b * vec3(3, .4, 0), c.xyz, c.w) * Light(), 1);
}

// gothic_block/largerblock3blood (texture)
TEXA(glrgbk3bbld) {
	vec3 c = T0(uv).xyz; // differs from the shadertoy - don't overwrite!
	uv = fract(uv * 2. + 7. / 32.); // HACK - manual uv offset
	float
		b = FBMT(uv, vec2(5), .6, 3., 4),
		r = length(uv - .5) + b * b,
		m = ls(.2, .6, r)
	;
	return vec4(mix(b * vec3(.5, .2, .0), c, m), m);
}

// gothic_block/largerblock3blood (map shader)
void glrgbk3bbld_m() {
	vec4 c = T0(UV);
	float b = FBMT(wavy(UV - Time.x * vec2(1, 3) / 2e2, Time.x * .4, 4., .03), vec2(7), .6, 3., 4);
	c.xyz = mix(b * RGB(99, 9, 5) + ls(.78, 1.5, b), c.xyz, c.w);
	FCol = vec4((c.xyz + (1. - c.w) * env(Ref) * .2) * Light() , 1);
}

////////////////////////////////////////////////////////////////
#pragma section center2trn
////////////////////////////////////////////////////////////////

// gothic_floor/center2trn (texture)
TEXA(gcntr2trn) {
	float
		b = FBMT(uv -= .5, vec2(5), .9, 3., 4), // base fbm
		t = .75 + b * b, // base texture intensity (remapped fbm)
		n = NT(wavy(uv, 7., .02), vec2(17)), // low-frequency variation
		r = length(uv), // distance from center
		k = r > .4 ? 38. : r > .32 ? 28. : 16., // number of bricks in circle
		a = fract(atan(uv.y, uv.x) / TAU), // angle [0..1]
		i = floor(a * k), // brick number [0..k)
		r2 = abs(abs(r - .41 - n * .002) * 1e2 - 6.),
		m = ls(1.5, 1.4, r2), // mask
		rl[] = float[](1., 3., -.145, -1., 2., .166), // 2 rhombus lines: x0, y0, dist0, x1, y1, dist1
		d, ld, s;

	vec2 p = uv;
	vec3 c = RGB(78, 68, 63); // outer color
	c *= 1. + .5 * sqr(tri(.49, .005 + .015 * n * n + .015 * b, r)); // highlight outer edge
	c = mix(c, RGB(83, 52, 47) * (.6 + .4 * n * n), m) * t;

	c *= 1.
		- .5 * tri(1.5, .5, r2) // dark outer edge
		+ b * tri(1., .5 + .5 * n, abs(r - .418) * 1e2 - 5.) // edge highlight
		- b * tri(.5, .08, fract(a * k + .5)) * m // dark edge between bricks in circle
		+ b * tri(.5, .1, fract(a * k + .55)) * m // lit edge between bricks in circle
		;

	// inner 3 brick rows
	m = ls(.34, .33, r); // mask
	c = mix(c * (1. - .5 * m), RGB(83, 52, 47) * t, n * b * m); // base color
	c = mix(c, RGB(112, 86, 31) * t, m * sqr(tri(.1, .15, .45, b)));
	c = mix(c, RGB(77, 66, 77) * t, m * ls(.5, .8, b) * .5);
	c *= 1. - .7 * tri(.27, .34, .35, r); // soft shadow

	r2 = r + n * .004; // slight distortion
	m = r > .21 && r < .31 ? 1. : 0.;
	c *= 1.
		- tri(.325, .005, r2) // dark edge
		- tri(.31, .005, r2) // dark edge
		- b * sqr(tri(.29, .005, r2)) // dark edge
		- b * sqr(tri(.23, .01, r2)) // dark edge
		- .5 * sqr(tri(.21, .02, r2)) // dark edge
		+ sqr(tri(.3, .01, r2)) * b // highlight
		+ sqr(tri(.22, .01, r2)) * b // highlight
		- b * tri(.5, .07, fract(a * k + .5)) * m // dark edge between bricks in circle
		;
	// separate ids for each row of bricks
	if (r < .23) i += 37.;
	if (r < .31) i += 73.;
	if (r < .31) i += 91.;
	c *= mix(1., .9 + .2 * R1(i), m); // vary intensity based on brick id

	// rhombus ring
	m = ls(.01, .0, abs(r - .411) - .039); // mask
	i = floor(a * 72.); // base id
	p *= rot(i * 5.); // polar mod: 360/72 = 5
	s = 0.;
	d = 1e6;
	int j = 0;
	for (/**/; j < 6; j += 3) { // for each line
		d = minabs(d, ld = dot(p, normalize(vec2(rl[j], rl[j+1]))) + rl[j+2]); // distance to line
		s += s + float(ld > 0.); // which side of line 1 we're on
	}
	// find rhombus id
	if (s == 3.)
		++i;
	else
		i += 66. * s;
	i = R1(i);
	c = mix(c, t * RGB(90, 80, 75), m);
	c = mix(c, t * RGB(127, 111, 88), i * b * m);
	c *= mix(1., .7 + .6 * H(i), m); // per-tile variation
	c *= 1.
		- m * sqr(tri(.0, .006, d)) * b // shadow
		+ m * sqr(tri(.006, .006, abs(d))) * b * .5 // highlight
		;

	// inner grill
	i = floor(a * 4.); // base id
	p = abs(uv * rot(i * 90. + 45.)); // polar mod + reflection
	d = 1e6;
	for (j = 0; j < 2; ++j, p = abs(p * rot(45.)))
		d = minabs(d, abs(length(p - vec2(0, .12)) - .16));
	m = ls(.21, .2, r);
	r2 = onion(onion(d, .012), .001); // grill outline
	c *= 1.
		- ls(.21, .2, r) * msk(.012 - d) // dark void under grill
		+ b * m * sqr(tri(.005, .005, d)) // highlight
		- .5 * m * sqr(msk(r2 - .001, .001)) // darken grill edges
		;

	// note: last factor tapers alpha a bit to avoid some ugly aliased corners
	return vec4(c, (1. - ls(.21, .15, r) * msk(.028 - d, .02)) * ls(.07, .087, r));
}

// gothic_floor/center2trn (map shader)
TEXA(gcntr2trn_m) {
	vec2 p = fract(UV) - .5;
	float b = FBMT(rot(Time.x * 333.) * p / (.8 + .2 * sin(Time.x * 61.)), vec2(53), .7, 2., 4); // 61 ~= TAU * 9.7
	vec4
		c = vec4(1. - b * vec3(0, .3, 1), 1),
		c2 = T0((rot(Time.x * 30.) * p / (.8 + .2 * sin(Time.x * 1.26))) + .5); // 1.26 ~= TAU * .2
	c.xyz = mix(c.xyz, c2.xyz, c2.w);
	c2 = T0(UV);
	c.xyz = mix(c.xyz, c2.xyz, c2.w) * Light();
	return c;
}

////////////////////////////////////////////////////////////////
#pragma section computer_blocks17 : patterns
////////////////////////////////////////////////////////////////

float scmpblk17_sdf(vec2 p) {
	p = pmod(p, 8.);
	float d = circ(p, .41);
	d = min(d, box((p - vec2(.34, 0)) * rot(45.), vec2(.1)));
	d = max(d, p.x - .45);
	return d;
}

// sfx/computer_blocks17 (texture)
TEX(scmpblk17) {
	vec2
		p = uv - .5,
		q;
	float
		b = FBMT(uv, vec2(9), .7, 2., 4), // base FBM
		t = .8 + .8 * b * b, // base texture intensity (remapped FBM)
		r = circ(p, .41), // outer ring SDF
		d = scmpblk17_sdf(p), // base SDF
		l = dFdy(d) / .004, // top light
		m = msk(d + .01, .007), // SDF mask
		a = nang(p), // normalized angle
		e, n, x, z;
	vec3
		c = T0(uv).xyz, // base color (stone blocks)
		k = RGB(155, 135, 115) * t; // metallic color
	c *= 1.
		- (.5 * -l + .5) * ls(.03, .0, d) // outer shadow
		;
	c = mix(c, k, m); // metallic background
	e = length(p) * 9.;
	q.x = a * floor(e + 1.) * 3.;
	q.y = fract(e);
	n = tri(.5, .2, NT(wavy(uv, 7., .03), vec2(41)));
	n = FBMT(q, vec2(3, 9), .5, 2., 4) * tri(.5, .5 + .5 * n, q.y); // polar noise
	c = mix(c, RGB(100, 85, 80) * ridged(n) * b, msk(r + .15, .02)); // inner vortex

	q = p;
	q.x = abs(p.x);
	e = max(max(d, half_plane(q, -vec2(.08, .4))), abs(r + .06) - .09); // top clamp
	z = box(q - vec2(0, .3), vec2(.01, .03));
	e = exclude(e, z - .02);
	x = msk(-e, .01); // mask that excludes the top clamp

	c *= 1.
		+ l * m * ls(.02, .0, -d) * ls(.01, .0, -r) // outer edge lighting
		+ x * tri(.035, .015, -r) // outer ring highlight
		+ .5 * x * tri(.13, .01, -r) // inner ring highlight
		+ .7 * tri(.08, .007, z) * (1. - x) // top clamp highlight
		- .7 * x * sqr(tri(.01, .04, -r)) // outer ring outer shadow
		- .6 * x * sqr(tri(.13, .06, .03, -r)) // outer ring inner shadow
		- .5 * x * sqr(tri(.12, .02, -r)) * m // inner ring outer shadow
		- .9 * sqr(tri(.12, .15, .2, -r)) * m // inner ring inner shadow
		- .5 * sqr(tri(.0, .05, e)) // top clamp outer shadow
		;

	c += vec3(.8, .8, 1) * pow(sat(1. - length(uv - vec2(.41, .59)) / .35), 8.); // specular

	/* ring wires */
	q.x = a;
	q.y = ls(.05, .12, -r);
	e = voro1(q, vec2(37, 1)).z; // polar voronoi with manhattan distance
	m = tri(.085, .035, -r) * x; // interior mask, excluding the top clamp

	c *= 1.
		+ .5 * m * tri(.0, .2, e) // wire highlight
		- .3 * m * tri(.3, .3, e) // wire shadow
		;

	/* bottom clamp */
	e = box(p + vec2(0, .33), vec2(.01, .03)) - .03; // SDF
	l = dFdy(e) / .004; // top light
	c = mix(c, k * (.4 + .8 * ls(.25, .41, -p.y)), z = msk(e, .01)); // base color
	c *= 1.
		+ .7 * tri(.005, .01, e) * l // edge lighting
		- .5 * tri(.0, .01, .05, e) // outer shadow
		;

	/* led box */
	e = box(q = p + vec2(0, .35), vec2(.01, .015)) - .01; // SDF
	l = dFdy(e) / .004; // top light
	c *= 1.
		+ .5 * tri(.005, .01, e)
		- .5 * sqr(tri(.0, .01, e))
		;
	c += vec3(1, .7, .5) * pow(sat(1. - length(q) / .11), 8.); // light glow

	return c;
}

// sfx/computer_blocks17 (map shader)
void scmpblk17_m() {
	vec3 c = T0(UV).xyz * Light();

	vec2
		uv = fract(UV) - .5,
		p = uv;
	float
		t = mod(Time.x * 2., 7.),
		i = floor(t),
		d = 1e6;

	if (i == 0.)
		d = sdf_Q(p * 2.4 + vec2(0, .05));

	if (i == 1.) {
		p.x = repeat(p.x, .1, -1., 1.); // repeat x3
		d = box(p, vec2(.02, .15)) * 2.;
	}

	if (i == 2.) {
		// A
		d = min(d, box(mirr(p, .0) + vec2(.13 - ls(-.3, .3, uv.y) * .17, 0), vec2(.02, .15)));
		d = min(d, box(p + vec2(0, .07), vec2(.07, .02))) * 2.;
	}

	if (i == 4.)
		d = icon_sdf(p * 1.8, .5);
	else
		d = onion(d, .005);

	FCol = vec4(c + msk(d, .02) * fract(-t) * vec3(.5, .05, .05), 1);
}

////////////////////////////////////////////////////////////////
#pragma section organic : patterns
////////////////////////////////////////////////////////////////

// gothic_trim/skullsvertgray02b
TEX(gsklvtg02b) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3
		c = RGB(67, 64, 63) * (.6 + .5 * b),
		g;

	uv = wavy(uv, 31., .003);
	EVAL_GRAD(
		g, uv,
		sqrt(NT(p[i], vec2(53, 93)))
	);

	c *= 1. - .3 * g.y * g.z * g.z;

	return c;
}

// skin/chapthroat
TEXA(skcpthrt) {
	uv = wavy(uv, 7., .01);
	float
		b = FBMT(uv, vec2(9), .7, 2., 4),
		n = FBMT(uv, vec2(13), .5, 2., 4),
		m = ls(.6, .9, FBMT(wavy(uv, 5., .03), vec2(11), .6, 2., 4))
		;
	vec3 c = RGB(127, 70, 55) * (.85 + .3 * b);
	c *= 1.
		- .2 * sqr(ls(.3, .0, b * b))
		- .2 * m
		- .3 * ls(.6, .77, n)
		+ .3 * ls(.5, .9, b)
		;
	c += .5 * sqr(ls(.5, 1., FBMT(uv, vec2(17), 1., 2., 3)));
	return vec4(c, 1. - m);
}

// skin/chapthroatooz
void skcpthrtooz() {
	vec4 c = T0(UV);
	vec2 uv = fract(UV);
	uv.y -= .2 * Time.x;
	float b = FBMT(wavy(uv, 7., .02), vec2(5), .9, 2., 4);
	FCol = vec4(mix(RGB(25, 10, 8) * b, c.xyz, c.w) * Light(), 1);
}

// skin/chapthroat2
TEX(skcpthrt2) {
	vec2 p = uv - .5;
	p = wavy(p, 17., .007);
	p.x *= 2. - uv.y * 1.5;
	float
		b = FBMT(uv, vec2(9), .7, 2., 4),
		n = NT(uv, vec2(7)),
		d = length(p),
		s;
	vec3 c = skcpthrt(uv).xyz;
	s = fract(d *= 13.);
	if (d <= 6.) {
		c *= 1.
			- pow(ls(6., .5, d + b * b), 6.) // darken interior
			;
		n = ls(.3, .7, n); // remap noise
		c *= 1.
			- n * b * tri(.4, .2, s) // darken edges
			+ n * b * tri(.6, .4, s) // highlight edges
			;
	}
	return c;
}

// skin/tongue_trans
TEX(sktongue) {
	uv = wavy(uv, 13., .003);
	float
		b = FBMT(uv, vec2(7), .9, 3., 4), // base FBM
		n = FBMT(uv, vec2(5), .5, 2., 4), // smoother FBM
		t = .5 + b // base texture intensity (remapped fbm)
		;
	vec3
		c = RGB(80, 38, 34), // base color
		v = voro(uv, vec2(23));
	c = mix(c, mix(RGB(180, 125, 118), RGB(165, 78, 51), n), b * tri(.0, .4 + n * .4, v.z)) * t;
	return c;
}

// skin/surface8
TEX(sksurf8) {
	float
		b = FBMT(uv, vec2(7), .9, 3., 4), // base FBM
		t = .8 +.4 * b, // base texture intensity (remapped FBM)
		i, // cell ID
		r = .7, // radius
		l, // light intensity
		m // mask
		;
	vec3
		c, // base color
		v = voro(uv, vec2(23)); // voronoi diagram
	vec2
		p = v.xy / r,
		q = uv + v.xy / 23.;

	i = H(fract(q) * 3.3);
	c = mix(RGB(155, 55, 55), RGB(200, 166, 155), ls(.75, .45, q.y)) * t;
	m = tri(.5, .5, length(p));
	l = dot(vec2(-p.y, sqrt(sat(1. - lsq(p)))), vec2(.6 + i * .3, .3));
	c *= 1.
		- b * .8 * ls(.5, .1, v.z)
		+ b * m * l
		;
	c *= t * t * t * t; // add some noise

	return c;
}

// gothic_wall/skull4
TEX(gskull4) {
	float
		b = FBMT(uv, vec2(13), .9, 3., 4), // base FBM
		t = .4 + b * b, // base texture intensity (remapped FBM)
		n = ridged(NT(wavy(uv, 12., .02), vec2(48))),
		i, r, l, m;
	vec3
		c = RGB(60, 50, 46) * t, // base color
		v = voro(uv, vec2(17)); // voronoi diagram

	i = H(fract(uv + v.xy / 17.)); // cell ID
	r = .4 + .3 * i; // skull size (varies per cell)
	vec2 p = v.xy / r; // normalized offset from skull center
	m = min(ls(1.1, 1., length(p)), ls(.0, .15, v.z)); // skull region mask
	l = dot(vec2(-p.y, sqrt(sat(1. - lsq(p)))), vec2(.1 + i * .2, .3)); // light intensity (varies per cell)
	c += b * m * l * n;

	n = ridged(FBMT(wavy(uv, 13., .01), vec2(23, 43), .5, 2., 3)); // stretched, wavy noise
	c *= 1. + (1. - m) * tri(.4, .4, n); // light variation between skulls (simulating bones)

	return c;
}

// gothic_trim/pitted_rust3
TEX(gtprst3) {
	float
		b = FBMT(uv, vec2(13), .9, 3., 4),
		n = FBMT(uv, vec2(7), .9, 3., 4);
	vec3
		c = mix(RGB(60, 50, 50), RGB(87, 47, 37), sqr(ls(.7, .25, n))) * (.7 + .8 * b * b),
		g;

	uv = wavy(uv, 31., .003);
	EVAL_GRAD(
		g, uv,
		sqrt(ls(.0, .9, NT(p[i], vec2(93))))
	);

	c *= 1. - (g.y + .4) * sqr(b * g.z) * g.z;
	return c;
}

// gothic_trim/metalsupsolid
TEX(gmtlspsld) {
	float
		b = FBMT(uv, vec2(7), .9, 3., 4),
		n = FBMT(uv, vec2(3), .5, 3., 4);
	vec3 c = mix(RGB(103, 56, 53), RGB(73, 58, 71), ls(.1, .7, n)) * (.75 + b * b);
	return c;
}

// gothic_trim/metalsupport4b
TEX(gmtlsp4b) {
	float
		b = FBMT(uv, vec2(13), .9, 3., 4),
		n = NT(wavy(uv, 5., .05), vec2(9)),
		d = ridged(fract(uv.x * 4.)),
		m = ls(.1, .15, d) * ls(1., .99, uv.y);
	vec3 c = RGB(51, 44, 44);
	c = mix(c, RGB(73, 55, 52), ls(.2, .2, b) * n * m);
	c = mix(c, RGB(69, 60, 66), ls(.7, .1, b) * b * m);
	c = mix(c, RGB(99, 77, 77), ls(.1, .5, n) * n * m * b * b * .3);
	c *= .6 + .3 * b + .3 * b * b;
	c *= 1. + .9 * sqr(tri(.21, .02 + .1 * n, d + b * .05)) * m * b;
	c *= 1. - sqr(ls(.49, .5, abs(uv.y - .5)));
	c *= 1. - ls(.05, .2, d) * ls(.16, .1, d);
	c *= 1. + tri(.99, .007, uv.y);
	return add_rivet(c, vec2(d - .4, fract(uv.y * 8.) - .5), .07);
}

vec3 gspbdrbb_v(vec2 uv, float s)  {
	float
		b = FBMT(uv, vec2(3, 1. + s + s), .7, 2., 4),
		d = ridged(uv.x),
		m;
	uv.y *= 2.;
	vec3 c = mix(RGB(71, 60, 58), RGB(110, 88, 77), ls(.1, .05, d)) * (.7 + .6 * b);
	c *= 1. - ls(.05, .0, uv.x) * (1. - b * b);
	c *= 1. + .5 * tri(.05, .02, uv.x);
	vec2 p = vec2(d - .35, fract(uv.y * s) - .5);
	vec4 k = rivet(p, .11);
	m = msk(k.w);
	c *= 1. - .7 * rivet_shadow(p, 1.1) * (1. - m);
	c = mix(c,
			(k.y > .0 ? RGB(128, 105, 88) : RGB(200,111,66) * ls(-.2, .7, k.z)) *
			(.4 + 2. * b * pow(sat(sum(k.yz * .7)), 4.)) *
			(1. - .6 * tri(-.1, .4, k.y)),
			m);
	return c;
}

// gothic_wall/supportborder_blue_b
TEX(gspbdrbb) {
	return gspbdrbb_v(uv, 4.);
}

// gothic_trim/km_arena1tower4_a
TEX(gkarntwr4a) {
	return gspbdrbb(uv.yx);
}

// gothic_trim/km_arena1tower_short
TEX(gkarntwrst) {
	return gspbdrbb_v(uv, 1.);
}

// gothic_floor/xstairtop4
TEX(gxstrtop4) {
	float b = FBMT(uv, vec2(40, 5), .9, 3., 4);
	vec3 c = RGB(110, 110, 98) * (.8 + .8 * b * b);
	if (uv.y < 1./4.)
		c *= .5;
	c *= 1.
		- .4 * ls(.4, .0, b)
		+ .5 * ls(.02, .0, uv.y)
		+ .2 * tri(.24, .01, uv.y)
		;
	return c;
}

// gothic_floor/xstairtop4bbrn
TEX(gxstrtop4bbrn) {
	float
		e = step(.25, uv.y),
		b = FBMT(uv, vec2(40, 5), .7 + .2 * e, 2. + e, 4);
	vec3 c = (RGB(96, 64, 44) - e * RGB(8, 4, 4)) * mix(.5, 1.5, b);
	c *= 1.
		+ 1.5 * ls(.03, .01, uv.y) // highlight
		- .7 * sqr(tri(.24, .25, .35, uv.y)) // shadow
	;
	return c;
}

// gothic_floor/xstepborder3brn
TEX(gxstpbrdr3brn) {
	float b = FBMT(uv, vec2(40, 5), .7, 2., 4);
	vec3 c = RGB(88, 60, 40) * mix(.5, 1.5, b);
	c *= 1.
		+ 3. * sqr(ls(.9, .99, uv.y)) // strong top highlight
		+ .2 * tri(.04, .02, uv.y) // subtle bottom highlight
		- .3 * ls(.03, .0, uv.y) // bottom shadow
	;
	return c;
}

// gothic_ceiling/woodceiling1a
TEX(gwdclg1a) {
	vec2 p = uv, q;
	p.y *= 22.;
	q = fract(p);
	float
		b = FBMT(uv, vec2(3, 23), 1., 2., 6),
		n = FBMT(uv, vec2(3, 33), .7, 3., 4),
		id = H(p.y - q.y);
	vec3 c = RGB(92, 67, 53) * (.8 + .8 * b * b);
	c *= 1. - sqr(ls(.1, .0, min(q.y, 1. - q.y))) * b;
	c *= 1. - .2 * smoothstep(.3, .7, n);
	//c *= 1. - .5 * sqr(tri(.5, .01, fract(p.x + id))) * b;
	c *= .8 + .3 * b * id;
	return c;
}

// gothic_ceiling/woodceiling1b_dark
TEX(gwdclg1bd) {
	float
		b = FBMT(uv, vec2(13), .9, 3., 4),
		x = uv.x * 16./3.;
	vec3 c = T0(uv).xyz * ls(.15, .21, uv.x);
	if (x < 1.)
		c = RGB(59, 48, 49) * (.7 + .6 * b);
	c *= 1. + .5 * tri(.05, .05, ridged(x));
	return add_rivet(c, vec2(abs(uv.x - 3./32.) - .07, mod(uv.y, .1) - .05), .004);
}

// gothic_wall/slateroofc
TEX(gsltrfc) {
	vec2
		p = brick(uv, vec2(6, 4)),
		q = fract(p),
		u = q;
	float
		b = FBMT(wavy(uv -= .5, 5., .03), vec2(13), .9, 2., 3), // base fbm
		n = NT(uv, vec2(73, 7)),
		t = (.75 + b * b) * (.8 + .4 * SR1(uv.x * 93.)), // base texture intensity (remapped fbm)
		r
		;

	vec3 c = vec3(.25 * t);
	u.y += u.y * 2. -.01 - .03 * n;
	r = length(u -= clamp(u, vec2(.49, .5), vec2(.51, 3)));
	c *= 1.
		- .7 * b * sqr(ls(.07, .03, abs(r - .5)))
		+ .5 * b * tri(.35, .1, r) * sqr(ls(.2, .1, q.y))
		- .3 * sqr(ls(.8, 1., q.y))
		- .3 * (ls(.3, .1, q.y)) * ls(.4, .6, r)
		+ .2 * sqr(ls(.5, .1, q.y)) * ls(.45, .4, r)
		;

	return c;
}

// base_support/cable
TEX(cable) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4),
		h = fract(uv.y * 10.);
	vec3 c = mix(RGB(53, 48, 42), RGB(38, 38, 36), b) * (.6 + b * .8);
	c *= 1.
		+ .5 * sqr(tri(.25, .25, h))
		+ .5 * sqr(tri(.65, .35, h))
		- .6 * sqr(tri(.5, .5, h))
	;
	return c;
}

// base_trim/basemetalsupport
TEX(bmtsprt) {
	float
		b = FBMT(uv, vec2(7, 3), .9, 3., 4),
		h = uv.y + b * .04;
	vec3 c = mix(RGB(50, 40, 34), RGB(93, 92, 88), b * b);
	c *= 1.
		+ .9 * ls(.07, .04, abs(uv.y - .44))
		- .4 * ls(.08, .05, abs(uv.y - .7))
		- .5 * tri(.34, .05, uv.y)
		- .3 * tri(.7, .04, uv.y)
		+ .7 * tri(.01, .03, uv.y)
		+ 1.5 * tri(.89, .1, h)
		+ 1.3 * tri(.5, .04, h)
		+ .9 * tri(.18, .04, h)
		;
	return c;
}

// base_trim/border11b
TEX(brdr11b) {
	float b = FBMT(uv, vec2(5, 3), .9, 3., 4);
	vec3 c = mix(RGB(74, 66, 55), RGB(99, 90, 78), b*b);
	uv.x *= 2.;
	vec2 p = seg(uv, vec2(.5, .625), vec2(1.5, .625));
	float
		d = length(p - uv),
		m = ls(.22, .20, d),
		l = 1.
		- .15 * m
		- .5 * ls(.7, .9, uv.y) * m
		- .3 * (grad(d).y - .5) * tri(.2, .03, d)
		- .3 * sqr(tri(.17, .03, d))
		- .5 * ls(.05, 0., uv.y)
		- .3 * tri(.33, .05, uv.y)
		+ .7 * ls(.93, 1., uv.y)
		+ .7 * tri(.31, .04, uv.y)
		;
	return c * l;
}

////////////////////////////////////////////////////////////////
#pragma section lights
////////////////////////////////////////////////////////////////

void fixture() {
	vec4 c = T0(UV);
	FCol = vec4(c.xyz * mix(Light(), vec3(1), c.w), 1);
}

// base_light/baslt4_1_4k
TEXA(blt414k) {
	float b = FBMT(uv, vec2(1, 5), .4, 3., 4); // base FBM
	vec3 c = mix(RGB(56, 49, 43), RGB(142, 136, 136), b); // base color
	uv = .5 - abs(uv - .5); // mirror horizontally and vertically
	uv.y *= 4.; // aspect ratio correction
	float
		a = tri(.0, .1, length(uv - seg(uv, vec2(.41, .5), vec2(.42, 3.5)))), // neon light mask
		d = mn(uv), // edge distance
		l = 1. - .7 * max(0., 1. - d / .15); // darken edges
	l *= 1. - .8 * ls(.24, .31, min(d, uv.y - .1)); // darken inner area around neons
	uv.y = mod(uv.y, .875); // repeat vertically
	c = add_rivet(c, uv - vec2(.17, .25), .04, .2, .5); // knobs
	c += RGB(80, 80, 20) * a; // yellow neon lights
	return vec4(c * mix(l, 2.7, a), a);
}

// base_light/light5_5k
TEXA(light5) {
	float b = FBMT(uv, vec2(1, 5), .4, 3., 4);
	vec3 c = mix(RGB(56, 49, 43), RGB(142, 136, 136), b);
	uv = .5 - abs(uv - .5);
	uv.y *= 8.;
	float
		d = length(uv - seg(uv, vec2(.27, .3), vec2(.27, 7.7))),
		a = tri(.0, .17, d),
		l = 1. - .5 * tri(.17, .07, d);
	c += RGB(80, 80, 20) * a;
	return vec4(c * mix(l, 2.7, a), a);
}

// base_light/lt2_2000
// base_light/lt2_8000
TEXA(lt2) {
	vec2 p = abs(uv - .5);
	float
		b = FBMT(uv, vec2(1), .4, 3., 4),
		r = length(p),
		a = ls(.37, .33, r) * (.5 + 2. * b),
		l = 1. + .0 * ls(.08, .03, abs(r - .41));
	vec3 c = mix(RGB(56, 49, 43), RGB(142, 136, 136), b);
	l = mix(l, 7., ls(.44, .1 * b, r));
	l *= 1. - .5 * sqr(tri(.46, .04, r));
	l *= 1. - .4 * sqr(tri(.36, .04, r));
	return vec4(c * l, a);
}

// gothic_light/pentagram_light1_1k
TEXA(gpntgmlt1k) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4),
		d = smin(pentagram(uv-=.5, .35), abs(circ(uv, .4)), .02),
		a = pow(msk(d - .02, .15), 8.),
		o = min(max(box(uv, vec2(.46)), -circ(uv, .51)), abs(circ(uv, .44)));
	vec3 c = RGB(76, 62, 47) * (.8 + .8 * b * b);
	c *= 1. + (b + .5) * msk(abs(o) - .01, .01);
	c *= 1. - ls(.1, .05, d) * msk(circ(uv, .4));
	return vec4(c + 1.*vec3(1, 1, .3) * a, a);
}

////////////////////////////////////////////////////////////////
#pragma section banner : patterns
////////////////////////////////////////////////////////////////

float banner_fold(vec2 uv, float s, float i, float amp) {
	i = (uv.y - sqr(abs(uv.x - .5)) * amp) * s - i;
	return 2. * tri(.5, .4, i) * (fract(i) - .5);
}

// base_wall/protobanner (texture)
TEXA(bwprtbnr) {
	float
		b = FBMT(uv, vec2(5, 9), .9, 3., 4), // base FBM
		t = .8 + .8 * b * b, // base texture intensity (remapped FBM)
		n = FBMT(uv, vec2(5, 9), .9, 3., 2), // noise (for ragged edges)
		x = abs(uv.x - .5), // distance from center
		d; // sdf
	vec3 c = RGB(77, 60, 44) * t; // base color
	vec2 p = uv * vec2(1, 2) - vec2(.5, .7);
	c *= 1. - .55 * msk(exclude(circ(p, .3), icon_sdf(rot(45.) * p * .8, 0.) - .01)); // logo
	c *= 1.
		+ sqr(ls(.6, .9, b)) // noisy highlights
		+ tri(.2, .5, uv.y) * tri(.2, .3, x) * banner_fold(uv, 4., .2, 4.) // bottom fold
		;
	// TODO: eliminate loop
	for (float f = 6.; f < 9.; ++f)
		c *= 1. + tri(.8, .5, uv.y) * tri(.2, .3, x) * banner_fold(uv, 12., f, 1.); // top fold
	d = uv.y - .81 - sqr(sat(x * 4.)) * .09;
	c = mix(c, RGB(82, 66, 60) * t, ls(.0, .01, d));
	c *= 1.
		- .5 * (tri(.01, .02, d)) // support shadow
		+ .5 * (tri(.02, .01, d)) // support highlight
		;
	d = .15 * (1. - uv.y); // corner rounding amount; it should be 0.3, but the lightmapper doesn't do alpha testing
	d = box(uv - .5, vec2(.49) - d) + n * .1 * sqrt(1. - uv.y) - d; // box with y-varying raggedness
	return vec4(c * sqr(msk(d + .01, .05)), msk(d));
}

// base_wall/protobanner (map shader)
TEXA(bwprtbnr_m) {
	vec4 c = T0(uv);
	if (c.a < .5)
		discard;
	c.xyz *= sqr(Light() * .5);
	return c;
}

// QUAKE III sdf
float quakeiii_sdf(vec2 uv) {
	uv *= vec2(256, 64);
	// Q
	float d = circ(uv - vec2(81, 30), 11.);
	d = max(d, uv.x - 80.);
	d = max(d, -circ(uv - vec2(84, 26), 9.));
	d = min(d, box(uv - vec2(73, 37), vec2(4, 9)) - 4.);
	d = max(d, -box(uv - vec2(73, 37), vec2(0, 7)) + 1.);
	// U
	d = min(d, box(uv - vec2(91.5, 47), vec2(4, 19)) - 4.);
	d = max(d, -box(uv - vec2(91.5, 47), vec2(0, 17.5)) + 1.);
	// A
	d = min(d, box1(mirr(uv, 111.) - vec2(105. + ls(23., 50., uv.y) * 3., 43), vec2(3.5, 19)));
	d = min(d, box1(uv - vec2(111, 32), vec2(6, 3)));
	// K
	d = min(d, box1(uv - vec2(126, 37), vec2(3, 13)));
	d = min(d, box1(uv - vec2(125.5 + ls(23., 50., uv.y) * 10., 44), vec2(3.5, 6)));
	d = min(d, box1(uv - vec2(136.5 - ls(23., 50., uv.y) * 9., 32), vec2(3.5, 8)));
	// E
	d = min(d, box1(uv - vec2(148.5, 37), vec2(7, 13)));
	d = max(d, -box1(uv - vec2(155, 33), vec2(6, 3)));
	d = max(d, -box1(uv - vec2(155, 43), vec2(6, 2)));
	// III
	d = min(d, box1(uv - vec2(168, 37), vec2(3.5, 13)));
	d = min(d, box1(uv - vec2(178, 37), vec2(3.5, 13)));
	d = min(d, box1(uv - vec2(188, 37), vec2(3.5, 13)));

	return max(d, uv.y - 50.);
}

// ARENA sdf
// s = scale
float arena_sdf(vec2 uv, float s) {
	uv *= vec2(256. * s, 64);
	float d = 1e6;
	// R
	uv.x -= s * 106.;
	d = min(d, max(-uv.x - 1., onion(box(uv - vec2(-.5, 19.25), vec2(2, .5)) - .75, .5)));
	d = min(d, box1(uv - vec2(1. + (18. - uv.y) * .5, 16.5), vec2(.5, 1.5)));
	d = min(d, box1(uv - vec2(-1, 18), vec2(.5, 3)));
	// E
	uv.x -= s * 24.;
	d = min(d, box1(uv - vec2(0, 18), vec2(2, 3)));
	d = max(d, -box1(uv - vec2(1.5, 19.5), vec2(2.5, 1)));
	d = max(d, -box1(uv - vec2(1.5, 17), vec2(2.5, 1)));
	// N
	uv.x -= s * 24.;
	d = min(d, box1(uv - vec2(-2, 18), vec2(.5, 3)));
	d = min(d, box1(uv - vec2(2, 18), vec2(.5, 3)));
	d = min(d, box1(uv - vec2((18. - uv.y) * .5, 18), vec2(.7, 3)));
	// A
	uv.x = mirr(uv.x + s * 68., s * 46.);
	d = min(d, box1(mirr(uv, 0.) - vec2((uv.y - 21.) * .33, 18), vec2(.5, 3)));
	d = min(d, box1(uv - vec2(0, 16.5), vec2(1, .25)));
	return d;
}

// base_wall/main_q3abanner
TEXA(q3bnr) {
	return vec4(msk(min(quakeiii_sdf(uv), arena_sdf(uv, 1.)), .8), 0, 0, H(uv * 511.));
}

// base_wall/main_q3abanner (map shader)
void q3bnr_m() {
	vec3 c = T0(UV * 2.).xyz * step(.5, fract(Time.x * .5));
	c = mix(c * Light(), vec3(.5, 0, 0), tri(fract(Time.x * 2.), 1./64., fract(UV.y)));
	FCol = vec4(c + env(Ref, 90.) * .25 + T0(UV + H(Time.xx)).w * .1, 1);
}

// main menu banner (texture)
TEX(menubnr) {
	float d = quakeiii_sdf(uv);
	vec2 p = grad(d) * rot(90.);
	vec2 q = sign(p) * uv * vec2(133, 33) + Time.x * 4.;
	p *= p;
	return vec3(
		(1. - 1.4 * abs(d)) * ((N(q.x) * p.x + N(q.y) * p.y) / sum(p + .01) * .7 + .3),
		sat(3. - 6. * arena_sdf(uv, .7)) * FBMT(uv - vec2(.2 * N(Time.x), Time.x), vec2(7, 3), .7, 2., 4),
		0
	);
}

// main menu banner (menu shader)
void menubnr_m() {
	vec2 uv = UV - .5;
	vec2 r = vec2(dFdx(uv.x), dFdy(uv.y));
	uv /= r / mx(r); // correct aspect ratio
	uv *= .5;

	uv.y = (uv.y - .16) * 7.;
	FCol = mx(abs(uv + vec2(0, .23)) / vec2(.55, .2)) > .4 ?
			vec4(0) :
			T0(uv + .51).y
			* vec4(2, 1, .3, 0)
	;
	if (mx(abs(uv - vec2(0, .15)) / vec2(.77, 1)) > .4)
		return; // out of bounds

	float
		n = H(uv * 133.7 + Time.x),
		k = 1./48.,
		s = pow(1.2, k),
		i = n * k
	;
	uv /= mix(1., s, n);
	for (; i < 1.; i += k) {
		uv.x += (N(Time.x * .37) - .5) * k / 48.;
		uv.y += (N(Time.x * .21) - .5) * k / 32.;
		r = uv /= s;
		r.y -= i * .15;
		r.x *= 1. + r.y * .15;
		vec4 c = T0(r + .5);
		FCol += c.x * (1. - i) * k * vec4(32, 16, 4, 0);
	}
}

vec2 uvmap(vec3 p, int ax) {
	return (ax==0) ? p.yz : (ax==1) ? p.xz : p.xy;
}

int dom(vec3 n) {
	n = abs(n) + vec3(.01, .02, .03);
	float m = mx(n);
	return (m==n.x) ? 0 : (m==n.y) ? 1 : 2;
}

// https://www.shadertoy.com/view/MsS3Wc
vec3 hsv(vec3 c) {
	vec3 rgb = sat(abs(mod(c.x * 6. + vec3(0, 4, 2), 6.) - 3.) - 1.);
	rgb *= rgb * (3. - 2. * rgb); // cubic smoothing
	return c.z * mix(vec3(1.), rgb, c.y);
}

void Generic() {
	float l = dot(Nor, normalize(vec3(2,0,8)));
	l = l * .4 + .7;
	vec2 uv = uvmap(Pos, dom(Nor));
	vec3 c = vec3(.5);
	c *= hsv(vec3(fract(PHI * Time.w + .25), 1., 1.));
	FCol = vec4(c * l, 1);
}

void Lmapped() {
	vec3 c = T0(UV).xyz;
	FCol = vec4(c * Light(), 1);
}

////////////////////////////////////////////////////////////////
#pragma section elemental
////////////////////////////////////////////////////////////////

// sfx/beam
void beam() {
	vec2 uv = fract(UV);
	uv.x += Time.x / 13.;
	float b = FBMT(uv, vec2(3, 7), .9, 2., 4), f = uv.y;
	FCol = vec4(2. * RGB(95, 85, 80) * f*f*f*f * mix(1., b, .5), 0.);
}

// Single-speed flame layer (s = speed)
float simple_flame(vec2 uv, float s) {
	vec2 p = uv;
	p.y += p.y - Time.x * s;
	uv.x += (N(p.y * 5.) - .5) * 1.5 * sqr(uv.y);
	float
		n = FBMT(wavy(p, 7., .02), vec2(9), .7, 2., 4),
		h = ls(.9, .03, uv.y),
		b = box(uv - vec2(.5, .15), vec2(0, .3));
	return sqr(msk(b + n * sqr(1.2 - h) - .13, .15));
}

void complex_flame(float s) {
	vec2 uv = fract(UV);
	FCol = (simple_flame(uv, s * .6) + simple_flame(uv, s)) * vec4(2.5, 1, .35, 0);
}

void flame() {
	complex_flame(2.5);
}

void flame_large() {
	complex_flame(1.);
}

void shiny() {
	vec4 c = T0(UV);
	c.xyz *= 1. + c.w * env(Ref);
	FCol = vec4(c.xyz * Light(), 1);
}

// skies/blacksky
void blacksky() {
	FCol = vec4(0);
}

// skies/tim_hell
void timhel() {
	vec3 d = normalize(Pos - Cam.xyz);
	d.z = d.z * 4. + 2.;
	vec2 uv = normalize(d).xy * 2.;
	float b = ls(.2, 1., FBMT(uv - Time.x * vec2(.1, .2), vec2(5), .5, 2., 6));
	uv.y *= 1.5;
	float s = ls(.3, 1., FBMT(uv - Time.x * vec2(.1, .18), vec2(5), .6, 2., 6));
	FCol = vec4(vec3(b, 0, 0) + RGB(80, 30, 8) * s * s * 2., 1);
}

void lava() {
	vec2 uv = wavy(UV / 8., Time.x * .5, 2., .05);
	float b = FBMT(uv, vec2(7), .9, 2., 4);
	vec3 c = RGB(91, 22, 14) * (.2 + 1.6 * b);
	c = mix(c, RGB(144, 44, 0), tri(.6, .2, FBMT(uv, vec2(3), .7, 3., 4)));
	c = mix(c, RGB(244, 144, 66) * b * 2., sqr(tri(.55, .25, FBMT(uv, vec2(11), .5, 2., 4))));
	FCol = vec4(c * sat(mx(Light())), 1);
}

void lavaf() {
	lava();
}

////////////////////////////////////////////////////////////////
#pragma section models
////////////////////////////////////////////////////////////////

vec3 ModelLight() {
	return mix(Ambient.xyz, LightColor.xyz, sat(dot(LightDir.xyz, WNor)));
}

vec4 triplanar(vec3 p, vec3 n, float s) {
	p *= s / float(textureSize(Texture0, 0).x);
	n *= n;
	vec4 c = vec4(0);
	for (int i = 0; i < 3; ++i, p = p.yzx)
		c += T0(p.yz) * n[i];
	return c / sum(n);
}

vec4 triplanar(vec3 p, float s) {
	return triplanar(p, Nor, s);
}

vec4 triplanar(float s) {
	return triplanar(Pos, s);
}

// models/mapobjects/kmlamp_white
void kmlampwt() {
	FCol = vec4(env(Ref) * RGB(133, 111, 111), 0);
}

// models/mapobjects/lamps/bot_flare2.tga (texture)
TEXA(botflare2) {
	float
		b = FBMT(uv, vec2(3, 4), .5, 2., 4),
		d;
	uv.x = abs(uv.x - .5) * 1.7;
	d = lsq(uv - vec2(0, 1)) + b * .3;
	return vec4(.44, .3, .3, 0) / (333. * d * d * d + .1) * ls(.5, .4, d);
}

// models/mapobjects/lamps/bot_flare2.tga (model shader)
TEXA(botflare2_m) {
	return T0(uv);
}

// models/mapobjects/lamps/flare03
void flare03() {
	FCol = vec4(2, 2, 2, 0) * pow(flare(UV, vec2(.5), 1., .6), 2.);
}

// models/mapobjects/lamps/bot_flare
void botflare() {
	vec2 uv = (UV - .5) * rot(20. * Time.x);
	float
		b = NT(uv, vec2(256)),
		k = 2.2 - length(uv) * 3.;
	FCol = vec4(k, k, 2, 0) * pow(flare(uv, vec2(0), 1.5, .4) + b * .01, 2.2);
}

void miscmodel() {
	float n = normalize(Nor).z;
	FCol = triplanar(4.) * 1.5 * (.5 * n * n * n * n * sign(n) + Clr);
}

void miscmodel2s() {
	miscmodel();
}

void item() {
	FCol = triplanar(16.);
	FCol.xyz += pow(sat(normalize(Nor).z), mix(2., 8., FCol.y)) * sqr(FCol.xyz); // fake baked specular
	FCol.xyz *= ModelLight() * vec3(1, .95, .9);
}

void itemshiny() {
	FCol = vec4((env(Ref, 15.) * 1.4 + .3) * Time.yzw, 1);
}

void ammobox() {
	float
		d = min(box(Pos.yz - vec2(0, 12), vec2(5, 9)) - 3., box(Pos.xz, vec2(7)));
	FCol = vec4(
		mix(vec3(env(Ref, 15.) * .25), 2. * sqrt(triplanar(16.).xyz) * Time.yzw * ModelLight(), .3 + .5 * sat(d + d))
		* (1. + .5 * triaa(.5, .5, d) - .2 * triaa(0., 1., d)),
		1
	);
}

// models/powerups/ammo/rockammo2.tga
void ammoboxicon() {
	FCol = T0((sat((abs(Nor.z) > .5 ? Pos.xy : Pos.xz) / 12. + .5) * Extra.zw + Extra.xy) / 1024.);
}

void healthsphere() {
	vec3 r = Ref;
	float s = 17.;
	// HACK: medium health bubble has sharper, stationary reflection
	if (Time.y < 1.) {
		s = 9.;
		mat2 a = rot(Time.x * 90.);
		r.xy *= a;
		r.yz *= a;
	}
	s = env(r, s);
	FCol = vec4(sqr(ls(.1, .9, s)) * 1.5 * fract(Time.yzw) + .5 * sqr(ls(.9, 1., s)), 0);
}

// models/weapons2/plasma/plasma_glass
void plasma_gls() {
	vec3 r = Ref;
	r.xz *= rot(Time.x * 9.);
	FCol = vec4(env(r));
}

// models/weapons2/shotgun/shotgun_laser
void shotgun_lzr() {
	vec2 uv = vec2(Pos.x / 24. - .5, length(Pos.yz));
	FCol = NT(uv, vec2(3)) * ls(1., .9, uv.x) * vec4(.25, 0, 0, 0);
}

// b = base
// a = amplitude
// f = frequency
// p = phase
float triwave(float b, float a, float f, float p) {
	return (abs(fract(Time.x * f + p - .25) - .5) * 4. - 1.) * a + b;
}

// models/powerups/armor/energy_grn1
void energy_grn1() {
	vec3 r = Ref;
	mat2 a = rot(Time.x * 90.);
	r.xy *= a;
	r.yz *= a;
	FCol = env(r, 22.) * sat(triwave(-.3, 1.3, .3, 0.)) * vec4(.3, .55, .25, 0);
}

// models/weapons2/plasma/plasma_glo.tga (texture)
TEX(plasma_glo) {
	float
		b = FBMT(uv, vec2(7), .5, 2., 4),
		t = .8 + .8 * b * b,
		n = NT(uv, vec2(2))
	;
	return
		mix(RGB(5, 77, 55), RGB(8, 122, 188), ls(.5, .1, n))
		* sqr(1. - n) * t * 2. *
		(1. + tri(.2, .05, b * b));
}

// models/weapons2/plasma/plasma_glo (model shader)
void plasma_glo_m() {
	vec3
		p = Pos - vec3(4.5, 0, 2),
		r = Ref,
		n = Nor
	;
	r.xz *= rot(Time.x * 9.);
	p.xy *= rot(Time.x * 33.);
	n.xy *= rot(Time.x * 33.);
	FCol = triplanar(p - Time.x * 16., n, 16.) + env(r);
}

void armor() {
	vec3
		n = normalize(Nor),
		p = Pos;
	p.z -= 24.;
	float
		e = tri(
				(FBMT(Pos.y / 48. + Time.x * 7.4, 13., .6, 2., 4) - .5) * .15, // vertical noise
				.03, // line thickness
				fract(ls(-8., 32., Pos.z) - Time.x * 1.3) - .5 // looping line offset
			);
	FCol = vec4((triplanar(16.).xyz * (n.z * .5 + .5) * (.2 + .8 * ls(4.5, 6.5, length(p))) + e * e) * Time.yzw * 2., 1);
	//FCol.xyz = mix(FCol.xyz, env(Ref, 3.) * vec3(1), ls(12., 10., d));
}

// models/mapobjects/storch/storch_tall.tga
void storchtl() {
	miscmodel();
	vec3 p = Pos, q;
	p.y = abs(p.y); // symmetry
	q = p - vec3(7, 3.5, -21); // eye position
	q.z *= 1.3; // squash vertically
	float r = length(q);
	FCol.xyz *=
		1.
		+ sat(p.z + 30.) * ls(4., 5., length(p.xy)) // brighten up skull
		+ .5 * sat(p.z + 15.) // brighten up top part even more
		+ .3 * tri(3., .5, r) // eye socket edge highlight
		+ .7 * triaa(-15., .5, p.z) // skull top edge highlight
		- triaa(-14.5, .5, p.z) // darken skull top edge
		- ls(3., 2.5, r) * (.6 + .4 * q.z / r) // darken eye socket interior
	;
	q = p - vec3(8, 0, -23); // nasal cavity position
	q.z *= .7; // stretch vertically
	r = length(q);
	FCol.xyz *=
		1.
		- ls(2., 1., r) * (.6 + .4 * q.z / r) // darken nasal cavity interior
		;
}

// models/mapobjects/gratelamp/gratetorch2b.tga (texture)
TEXA(gr8torch2b) {
	uv.y *= 2.;
	float
		b = FBMT(uv, vec2(5), .9, 2., 4), // base FBM, tileable
		k = .5 + b, // remapped b with 1.0 mean
		t = .8 + b * .4, // texture intensity
		d = uv.y - 1.05; // distance field
	vec3 c = RGB(55, 44, 37) * t; // base color
	vec2 p = uv;

	d = smin(d, box((uv - vec2(.5, 1.5)) * rot(45.), vec2(.2)) - .1, .3); // smin with rotated rounded square
	d = max(d, .03 - p.y); // bilinear hack: cut off bottom

	c = mix(c, add_rivet(c, uv - vec2(.5, 1.5), .1), 8. * b); // large top knob

	p.x = min(p.x, 1. - p.x); // mirror around center
	if (p.y > .5)
		p.y -= .5; // repeat once vertically
	c = mix(c, add_rivet(c, p - vec2(.22, .31), .04), 2. * t); // smaller knobs

	c *= 1.
		+ sqr(ls(.5, 1., b)) // ligher dirt
		+ grad(d).y * tri(.0, .05, d) * (1. + 11. * ls(1.5, 2., uv.y)) * b // edge lighting
		+ k * tri(.93, .05, uv.y)
		+ k * tri(.4, .05, uv.y)
		+ k * tri(.1, .05, uv.y)
		- .5 * tri(.97, .05, uv.y)
		- .5 * sqr(tri(.7, .05, uv.y))
		- .5 * sqr(tri(.2, .05, uv.y))
		- .5 * tri(.66, .1, uv.y)
		- .5 * tri(.45, .03, uv.y)
		- .5 * tri(.15, .1, uv.y)
		- tri(.01, .03, uv.y)
		;
	return vec4(c, msk(d, .03));
}

// models/mapobjects/gratelamp/gratetorch2b.tga (map shader)
void gr8torch2b_m() {
	//vec3 p = Pos;
	//--p.x;
	//vec2 uv = vec2(nang(p.xy) * 4., ls(-2., 29., p.z));
	//FCol = textureGrad(Texture0, uv, dFdx(uv.yy), dFdx(uv.yy));
	FCol = T0(UV);
	if (FCol.w < 0.5)
		discard;
	FCol *= Clr * 1.5 + .3;
}

// models/mapobjects/teleporter/energy.tga
void tlpnrg() {
	vec2 uv = vec2(2. * nang(Pos.xy), 3. * ls(8., 128., Pos.z));

	vec2 p = uv;
	p.x = fract(uv.x - Time.x * 3.);
	float f =
		(wrapped_flare(p, vec2(0, .3), 1., .6) + flare(p, vec2(.5, .4), 2., .66))
		* ls(.1, .2, uv.y) * (.5 + abs(fract(Time.x * 5.3) - .5))
	;
	FCol = f * f * vec4(.9, .77, .77, 0);

	p.x = fract(uv.x * .5 - Time.x * 4.4);
	p.y = mod(uv.y * .5 - Time.x * 2.6, 3.);
	f = wrapped_flare(p, vec2(0, .5), 1.1, .5) + flare(p, vec2(.5, .6), 1., .6);
	FCol += f * f * vec4(.9, .77, .77, 0);

	p.x = fract(uv.x * .5 + Time.x * 2.);
	p.y = mod(uv.y * .5 - Time.x * 2., 3.);
	f = wrapped_flare(p, vec2(0, .5), 1.1, .5) + flare(p, vec2(.5, .6), 1., .6);
	FCol += f * f * vec4(.9, .77, .77, 0);
}

// models/mapobjects/teleporter/transparency.tga (texture)
TEXA(tlptrns) {
	float b = FBMT(wavy(uv, 5., .03), vec2(7), .5, 3., 2);
	return
		(b * 1.4 + .3) * vec4(1.2, .54, .06, 0)
		+ .5 * tri(.7, .2, b) * vec4(1, 1, 1, 0)
	;
}

// models/mapobjects/teleporter/transparency.tga (map shader)
void tlptrns_m() {
	vec3 p = Pos;
	p -= Time.x * 6.4 * sign(p.z - 72.);
	FCol = triplanar(p, 8.);
}

// models/weapons2/rocketl/rocketl.tga
TEX(rocketl) {
	uv = wavy(uv, 5., .02);
	float
		b = FBMT(uv, vec2(6), .8, 2., 4), // base FBM, tileable
		m = FBMT(uv, vec2(2), .6, 2., 4),
		t = .8 + .6 * b * b // texture intensity
		;
	vec3 c = mix(RGB(36, 33, 30), RGB(168, 177, 168), .3 + .7 * m) * t;
	c *= 1.
		+ .2 * ls(.4, .6, m)
		- .2 * tri(.3, .1, m)
		;
	return c;
}

////////////////////////////////////////////////////////////////
#pragma section ui : patterns
////////////////////////////////////////////////////////////////

// Window icon
TEXA(icon) {
	uv -= vec2(.48, .5);
	float
		d = icon_sdf(uv, 0.),
		b = length(uv) - .47;
	vec3 c = 1. - vec3(.5, 1, 1) * msk(max(.007 - d, b + .04));
	return vec4(c, 1) * msk(b);
}

// sfx/logo512
TEX(bglogo) {
	uv -= .5;

	vec2 r = vec2(dFdx(uv.x), dFdy(uv.y));
	uv /= r / mx(r); // correct aspect ratio
	uv *= .8; // scale up a bit
	uv.y -= .03; // move up a bit

	float
		x = abs(uv.x),
		b = FBMT(uv, vec2(31, 5), .7, 2., 3), // base FBM - mostly vertical noise
		t = .8 + .8 * b * b, // intensity variation (remapped FBM)
		d = icon_sdf(uv, 1.), // logo SDF
		e = icon_sdf(uv + vec2(0, .002), 1.), // offset logo SDF, for lighting
		l = (e - d) * 5e2 + .5 // lighting
		;
	vec3 c = vec3(.3 * t, 0, 0) * msk(d, .004); // base color
	c *= 1.
		- sqr(ls(.0, .3, x)) // horizontal gradient
		- .5 * ls(.1, .3, abs(uv.y - .1)) // vertical gradient
		;
	c +=
		+ t * .2 * tri(.0, .01 - .01 * x, d) * tri(.1, .2, uv.y) * ls(.3, .2, x) * l // top light
		+ t * .5 * ls(.004, .0, d) * ls(.07, .1, uv.y) * tri(.23, .1, x) * vec3(.9, .9, 1) // back light
		+ t * .4 * tri(.005, .005, d) * ls(.2, -.1, uv.y) * ls(.3, .2, x) * sat(-l) // bottom light
		;

	return c;
}

// menu/art/addbotframe.tga
void uiframe() {
	vec2 uv = UV - .5;
	vec2 r = vec2(dFdx(uv.x), dFdy(uv.y));
	uv /= r / mx(r); // correct aspect ratio
	uv /= Time.yz;

	float
		n = NT(uv, vec2(7)) * .8 + .6,
		d = circ(uv, .48),
		m = msk(d, .005),
		i = msk(elips(uv, vec2(.42, .47)), .03);
	vec3 c = RGB(144, 88, 66) * n;
	m *= 1. - i * .5;
	c *= 1. - i;
	c *= 1.
		- 2. * sqrt(tri(.0, .45, uv.y))
		+ 4. * (uv.y + .5)
		+ .5 * tri(.0, .01, d) * uv.x
		;
	FCol = vec4(c * m, m);
}

void Loading() {
	FCol = vec4(textureLod(Texture0, (.5 + UV * 127.) / 128., 1.5).xyz * (.7 + .3 * NT(UV, .5/fwidth(UV))), 1);
}

void UI() {
	FCol = T0(UV) * Clr;
}

void teleport() {
	FCol = Time.y * .25 * smoothen(tri(.5, .1 + .7 * Time.y, fract(UV.y + Time.y))) * vec4(1, 1, .5, 0);
}

// menu/art/maps_select.tga
void mapselect() {
	float d = box((UV - .5) * 256., vec2(98));
	FCol = vec4(1, 0, 0, 1) * (.3 * ls(24., .0, d) * step(.0, d)  + step(abs(d + 1.), 1.));
}

////////////////////////////////////////////////////////////////
// Item icons
////////////////////////////////////////////////////////////////

// 
void icon_health() {
	vec2 uv = pmod(UV - .5, 4.);
	FCol = vec4(1, 1, 0, 1) * msk(min(onion(length(uv) - .4, .04), box(uv, vec2(.25, .06))), .01);
}

// 
void icon_shard() {
	FCol = vec4(.4, .7, .3, 1) * msk(dot(abs(UV - .5), vec2(4, 3) / 5.) - .2, .01);
}

// 
void icon_armor() {
	vec2 uv = UV - .5;
	uv.x = abs(uv.x);
	float
		w = .15 * sqrt(ls(-.32, -.29, uv.y))
			+ .05 * ls(-.3, -.12, uv.y)
			+ .1 * sqrt(ls(-.12, .07, uv.y))
			+ .14 * step(.07, uv.y)
			- .1 * sqr(ls(.07, .31, uv.y)),
		d = exclude(box(uv, vec2(w, .3)), circ(uv - vec2(0, .777), .5))
	;
	FCol = vec4(1, 1, 0, 1) * msk(d - .01, .01);
}

// 
void icon_machinegun() {
	vec2 uv = UV;
	float d = box(uv - vec2(.35, .5), vec2(.1, .4));
	uv.y = mod(uv.y - .06, .28) - .16;
	d = min(d, box(uv - vec2(.51, 0), vec2(.34, .04 * ls(.85, .7, uv.x))));
	d = exclude(d, box(uv - vec2(.65, 0), vec2(.02, 1)));
	FCol = vec4(1, 1, 0, 1) * msk(d, .01);
}

// 
void icon_shotgun() {
	vec2 uv = UV;
	uv.x = mod(uv.x, .33) - .16;
	float d = box(uv - vec2(0, .52), vec2(.1, .4));
	d = exclude(d, box(uv - vec2(0, .65), vec2(.05, .23)));
	d = exclude(d, abs(uv.y - .2) - .02);
	FCol = vec4(1, .5, 0, 1) * msk(d, .01);
}

// 
void icon_rocketl() {
	vec2
		uv = (UV - vec2(.55, .45)) * rot(-45.);
	float
		d = seg(uv, vec2(-.4, 0), vec2(.2, 0), .1);
	d = max(d, -.3 - uv.x);
	uv.y = abs(uv.y);
	d = min(d, box(uv + vec2(.37, 0), vec2(.05, .005)));
	d = min(d, box(uv + vec2(uv.y + .1, -.18), vec2(.1, .05)));
	FCol = vec4(1, 0, 0, 1) * msk(d, .01);
}

// 
void icon_railgun() {
	vec2 uv = (UV - .5) * rot(45.);
	float
		d = box(uv, vec2(.6, .03)),
		p = uv.x * 12.6 + 1.55,
		h = sin(p) * .15,
		q = ridged(fract(h))
		;
	d = min(d, max(onion(uv.y - h, .05 - .1 * q) * (1. + q + q), abs(uv.x) - .6));
	FCol = vec4(0, 1, 0, 1) * msk(d, .01);
}

// 
void icon_plasma() {
	vec2 uv = pmod(UV - .5, 5.);
	float
		d = length(uv) - .18,
		r = uv.x - .33,
		h = .04 * tri(.0, .3, r);
	uv.x -= .33;
	uv *= rot(-15.);
	d = min(d, box(uv, vec2(.04, 2. * h)));
	d = min(d, box(uv - vec2(0, h * sign(r)), vec2(.14, h)));
	FCol = vec4(.77, 0, 1, 1) * msk(d + .01, .01);
}

// 
void icon_quad() {
	vec2 uv = UV - .5;
	float d = icon_sdf(uv + vec2(0, .05), 0.) - .01;
	d = min(d, box(pmod(uv * rot(45.), 4.) - vec2(.45 , .0), vec2(.11, .02)));
	FCol = vec4(0, .88, .95, 1) * msk(d, .01);
}

// gfx/2d/crosshaira
void crosshaira() {
	float d = length(UV - .5) * 32.;
	FCol = vec4(.5 * ls(1., .0, abs(d - 14.)) + ls(1., .5, d));
}

// gfx/2d/crosshairb
void crosshairb() {
	vec2 uv = abs(UV - .5) * 32.;
	FCol = vec4(step(mn(uv), 1.) * step(mx(uv), 6.));
}

// gfx/2d/crosshairc
void crosshairc() {
	vec2 uv = abs(UV - .5) * 32.;
	FCol = vec4(step(mn(uv), 1.) * step(mx(uv), 6.) * step(3., mx(uv)));
}