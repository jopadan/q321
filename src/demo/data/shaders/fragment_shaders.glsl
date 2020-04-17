uniform vec4 Time, Cam;
uniform sampler2D Texture0, Texture1;

in vec3 Pos, Nor, Ref;
in vec2 UV, LUV;
in vec4 Clr;

out vec4 FCol;

////////////////////////////////////////////////////////////////

#define smoothen(x) ((x)*(x)*(3.-2.*(x)))
#define sqr(x)		(x)*(x)
#define sat(x)		clamp(x, 0., 1.)
#define RGB(r,g,b)	(vec3(r,g,b)/255.)

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

////////////////////////////////////////////////////////////////

float tri(float center, float max_dist, float x) {
	return 1. - sat(abs(x - center) / max_dist);
}

float ls(float lo, float hi, float x) {
	return sat((x - lo) / (hi - lo));
}

////////////////////////////////////////////////////////////////

vec2 sc(float x) {
	return vec2(sin(x), cos(x));
}

mat2 rot(float x) {
	vec2 v = sc(radians(x));
	return mat2(v.y, v.x, -v.x, v.y);
}

////////////////////////////////////////////////////////////////

// uint Hu(uvec4 u) {
//     u *= 0x45d9f3bu;
//     uint r = u.x;
// 	r ^= u.y + 0x9e3779b9u + (r << 6) + (r >> 2);
// 	r ^= u.z + 0x9e3779b9u + (r << 6) + (r >> 2);
// 	r ^= u.w + 0x9e3779b9u + (r << 6) + (r >> 2);
//     // xorshift step
//     //r ^= r << 13;
//     //r ^= r >> 17;
//     //r ^= r << 5;
//     return r;
// }

// float Hu(vec4 v) {
//     uint k = 4095u, u = Hu(floatBitsToUint(v)) & k;
//     return float(u & k) / float(k);
// }

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

float HT(float x, float p) {
	return H(mod(x, p));
}

float N(float x) {
	float i;
	return mix(H(i = floor(x)), H(i + 1.), smoothen(x - i));
}

float NT(float x, float p) {
	float i;
	return mix(HT(i = floor(x), p), HT(i + 1., p), x - i);
}

////////////////////////////////////////////////////////////////
//  Cellular noise code by Brian Sharpe
//  https://briansharpe.wordpress.com/
//  https://github.com/BrianSharpe/GPU-Noise-Lib
//
//  Modified to add tiling
////////////////////////////////////////////////////////////////

//
//	FAST32_hash
//	A very fast hashing function.  Requires 32bit support.
//	http://briansharpe.wordpress.com/2011/11/15/a-fast-and-simple-32bit-floating-point-hash-function/
//
//	The 2D hash formula takes the form....
//	hash = mod( coord.x * coord.x * coord.y * coord.y, SOMELARGEfloat ) / SOMELARGEfloat
//	We truncate and offset the domain to the most interesting part of the noise.
//	SOMELARGEfloat should be in the range of 400.0->1000.0 and needs to be hand picked.  Only some give good results.
//	A 3D hash is achieved by offsetting the SOMELARGEfloat value by the Z coordinate
//

// const vec2
//     F32OFS = vec2( 26, 161 ),
//     F32SLF = vec2( 951.135664, 642.949883 );

// void F32HT( vec2 gridcell, vec2 gridsize, out vec4 h0, out vec4 h1 ) {
//     //    gridcell is assumed to be an integer coordinate
//     vec4 p = mod(gridcell.xyxy + vec4(0, 0, 1, 1), gridsize.xyxy) + F32OFS.xyxy;
//     p *= p;
//     p = p.xzxz * p.yyww;
//     h0 = fract( p / F32SLF.x );
//     h1 = fract( p / F32SLF.y );
// }

// vec4 F32HT( vec2 gridcell, vec2 gridsize ) {
//     //    gridcell is assumed to be an integer coordinate
//     vec4 p = mod(gridcell.xyxy + vec4(0, 0, 1, 1), gridsize.xyxy) + F32OFS.xyxy;
//     p *= p;
//     return fract( p.xzxz * p.yyww / F32SLF.y );
// }

// float F32NT(vec2 p, vec2 grid) {
//     p *= grid;
//     vec2 i = floor(p), f = smoothen(p - i);
//     vec4 h = F32HT(i, grid);
//     return mix(mix(h.x, h.y, f.x), mix(h.z, h.w, f.x), f.y);
// }

// float FBMT(vec2 p, vec2 scale, float gain, float lac, int lyrs) {
//     float acc = F32NT(p, scale), ow = 1., tw = 1.;
// 	for (int i=0; i<lyrs; ++i) {
// 		scale *= lac; ow *= gain;
// 		acc += F32NT(p, scale) * ow;
// 		tw += ow;
// 	}
//     return acc / tw;
// }

// float FBMT(vec2 p, vec2 scale, float gain, float lac) {
//     return FBMT(p, scale, gain, lac, 3);
// }

////////////////////////////////////////////////////////////////

// Dave Hoskins/Hash without Sine
// https://www.shadertoy.com/view/4djSRW

// Based on ^^^
// float H(vec4 p4) {
//     p4 = fract(p4 * 3.1031);
//     p4 += dot(p4, p4.wzxy + 33.33);
//     return fract((p4.x + p4.y) * p4.z);
// }

// const vec4 HASHSCALE = vec4(.1031, .1030, .0973, .1099);

// float H(vec2 p) {
// 	vec3 q = fract(p.xyx * HASHSCALE.x);
// 	q += dot(q, q.yzx + 19.19);
// 	return fract((q.x + q.y) * q.z);
// }

// vec3 H3(vec3 p) {
// 	p = fract(p * HASHSCALE.xyz);
// 	p += dot(p, p.yxz + 19.19);
// 	return fract((p.xxy + p.yxx) * p.zyx);
// }

// vec3 H3(vec2 p) {
// 	vec3 q = fract(p.xyx * HASHSCALE.xyz);
// 	q += dot(q, q.yxz + 19.19);
// 	return fract((q.xxy + q.yzz) * q.zyx);
// }

// vec3 H3(float p) {
// 	vec3 q = fract(p * HASHSCALE.xyz);
// 	q += dot(q, q.yzx + 19.19);
// 	return fract((q.xxy + q.yzz) * q.zyx); 
// }

// vec4 H4(float p) {
// 	vec4 q = fract(p * HASHSCALE);
// 	q += dot(q, q.wzxy + 19.19);
// 	return fract((q.xxyz + q.yzzw) * q.zywx);
// }

// vec4 H4(vec2 p) {
// 	vec4 q = fract(p.xyxy * HASHSCALE);
// 	q += dot(q, q.wzxy + 19.19);
// 	return fract((q.xxyz + q.yzzw) * q.zywx);
// }

////////////////////////////////////////////////////////////////



// float N(vec2 p) {
// 	vec2 i = floor(p);
// 	p -= i;
// 	p *= p * (3. - 2.*p);
// 	float	s00 = H(i),
// 			s01 = H(i + vec2(1, 0)),
// 			s10 = H(i + vec2(0, 1)),
// 			s11 = H(i + vec2(1, 1));
// 	return mix(mix(s00, s01, p.x), mix(s10, s11, p.x), p.y);
// }

// float FBM(vec2 p, float g, float lac) {
// 	float acc = N(p), ow = g, tw = 1.;
// 	for (int i=0; i<3; ++i) {
// 		p *= lac; ow *= g;
// 		acc += N(p) * ow;
// 		tw += ow;
// 	}
// 	return acc / tw;
// }

////////////////////////////////////////////////////////////////

// float HT(vec2 p, vec2 s) {
//     p *= TAU / s;
//     return H(vec4(sc(p.x), sc(p.y)));
// }

float HT(vec2 p, vec2 s) {
	return H(mod(p, s));
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

float FBMT(vec2 p, vec2 scale, float gain, float lac) {
	return FBMT(p, scale, gain, lac, 4);
}

#define ridged(v) tri(.5,.5,v)

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

////////////////////////////////////////////////////////////////

vec2 seg(vec2 p, vec2 a, vec2 b) {
	vec2 ab = b-a, ap = p-a;
	float t = sat(dot(ap, ab)/dot(ab, ab));
	return ab*t + a;
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

float elips(vec2 p, vec2 r) {
	return (length(p/r) - 1.) / min(r.x, r.y);
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

vec2 mirr(vec2 v, float m) {
	return vec2(m - abs(v.x - m), v.y);
}

////////////////////////////////////////////////////////////////

// "Asymmetric Blocks" by Shane
// https://www.shadertoy.com/view/Ws3GRs

vec3 pattern(vec2 p, float sc, float bv) {
	vec3 e = vec3(-1, 0, 1), r = vec3(1e5);
	vec2 ip = floor(p*sc), tileID = e.yy;
	p -= (ip + .5) / sc; 

	float h11 = .5 * HT(ip + e.yy, vec2(sc));
	float h10 = .5 * HT(ip + e.xy, vec2(sc));
	float h01 = .5 * HT(ip + e.yz, vec2(sc));
	float h12 = .5 * HT(ip + e.zy, vec2(sc));
	float h21 = .5 * HT(ip + e.yx, vec2(sc));
	float h00 = .5 * HT(ip + e.xz, vec2(sc));
	float h02 = .5 * HT(ip + e.zz, vec2(sc));
	float h22 = .5 * HT(ip + e.zx, vec2(sc));
	float h20 = .5 * HT(ip + e.xx, vec2(sc));

	vec2[4] ctr, l;
	if (mod((ip.x + ip.y), 2.) < .5) { 
		l[0] = 1. + vec2(h01 - h10, h00 - h11);
		l[1] = 1. + vec2(-h01 + h12, h02 - h11);
		l[2] = 1. + vec2(-h21 + h12, -h22 + h11);
		l[3] = 1. + vec2(h21 - h10, -h20 + h11);
		ctr[0] = vec2(h01, h11) + l[0]*vec2(-.5, .5);
		ctr[1] = vec2(h01, h11) + l[1]*vec2(.5, .5);
		ctr[2] = vec2(h21, h11) + l[2]*vec2(.5, -.5);
		ctr[3] = vec2(h21, h11) + l[3]*vec2(-.5, -.5); 
	} else { 
		l[0] = 1. + vec2(-h00 + h11, h01 - h10);
		l[1] = 1. + vec2(h02 - h11, h01 - h12);
		l[2] = 1. + vec2(h22 - h11, -h21 + h12);
		l[3] = 1. + vec2(-h20 + h11, -h21 + h10);
		ctr[0] = vec2(h11, h10) + l[0]*vec2(-.5, .5);
		ctr[1] = vec2(h11, h12) + l[1]*vec2(.5, .5);
		ctr[2] = vec2(h11, h12) + l[2]*vec2(.5, -.5);
		ctr[3] = vec2(h11, h10) + l[3]*vec2(-.5, -.5); 
	}

	for (int i=0; i<4; i++) {
		l[i] /= sc;
		float bx = box1(p - ctr[i]/sc, l[i]/2. - bv/sc);
		if (bx < r.x)
			r = vec3(bx, ip + ctr[i]);
	}

	return r;
}

vec2 voro1(vec2 p, vec2 grid) {
	p *= grid;
	vec2 n = floor(p), f = p - n, mr, g, o, r;

	float md = 8.0, d;
	for (int i=0; i<9; ++i) {
		g = vec2(i % 3 - 1, i / 3 - 1);
		o = H2(mod(n + g, grid));
		r = g + o - f;
		d = sum(abs(r));

		if (d < md) {
			md = d;
			mr = r;
		}
	}

	return mr;
}

float env(vec3 p) {
	p = normalize(p);
	vec3 a = mod(degrees(atan(p, p.yzx)), 360.);
	return NT(a.x / 8., 45.) * ls(.9, .0, abs(p.z)) + NT(a.y / 8., 45.) * ls(.7, .0, abs(p.x));
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

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

vec3 Light() {
	vec3 d = Cam.xyz - Pos;
	float
		b = FBMT(d.xy/256.*rot(Cam.w), vec2(3), .7, 3., 4),
		l = 1. - ls(14., -6., length(d.xy) - b * 8.) * ls(128., 48., d.z) * step(.1, Nor.z);
	return texture(Texture1, LUV).xyz * 3. * l;
}

// $protect ^void[ \t]+([_a-zA-Z][_a-zA-Z0-9]*)\(\)
// $protect ^TEX[A]?\(([a-z][_a-z0-9]*)\)

#define TEX(name)	vec3 name(vec2); void name() { FCol = vec4(name(UV), 1); } vec3 name(vec2 uv)
#define TEXA(name)	vec4 name(vec2); void name() { FCol = name(UV); } vec4 name(vec2 uv)

TEX(cmet52) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3 c = mix(RGB(48, 41, 33), RGB(103, 101, 104), b);
	return c;
}

TEX(ptrshn) {
	float b = FBMT(uv, vec2(3), .9, 3., 4);
	vec3 c = mix(RGB(49, 45, 43), RGB(81, 75, 78), b * b);
	return c;
}

TEX(dmnd2c) {
	float b = FBMT(uv, vec2(7), .9, 3.);
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

TEX(dmnd2cow) {
	float b = FBMT(uv, vec2(7), .9, 3.);
	vec3 c = dmnd2c(uv);
	float r = length(uv - .5);
	c = mix(c, c * RGB(70, 61, 53), ls(.5, .2, r + b*b*b));
	return c;
}

TEXA(dmnd2pnt) {
	vec3 c = dmnd2cow(uv);
	uv = fract(uv) - .5;
	float b = FBMT(uv, vec2(3), .9, 3.), d = abs(length(uv) - .4), i = 0.;
	for (/**/; i < 5.; ++i) {
		vec2 p = vec2(0, -.35) * rot(i * 72.);
		d = min(d, length(uv - seg(uv, p, p * rot(144.))));
	}
	return vec4(c, msk(d - .02 + b * .02, .01));
}

void dmnd2pnt_m() {
	vec4 c = texture(Texture0, UV);
	FCol = vec4(c.xyz * Light() + RGB(111, 55, 0) * c.w * (sin(Time.x * PI) * .5 + .5), 1);
}

TEX(dmnd2cjp) {
	float b = FBMT(uv, vec2(7), .9, 3., 4);
	vec3 c = dmnd2c(uv);
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

vec2 knob(vec2 uv, float s) {
	return vec2(1. - length(uv) / s, msk(length(uv) - s));
}

TEXA(lpdmnd) {
	float b = FBMT(uv, vec2(5), .9, 3.), t, o, k, r;
	vec3 c = dmnd2c(uv);
	vec2 u, v;
	u.x = abs(uv.x - .5);
	u.y = min(uv.y, .4);
	r = length(u - vec2(0, .4)) - (.18 - .06 * ls(.4, 1., uv.y));
	k = .25
		- .15 * ls(.9, .96, uv.y)
		+ .03 * sqr(ls(.82, .86, uv.y))
		+ .07 * ls(.8, .2, uv.y)
		+ .07 * sqr(ls(.35, .22, uv.y))
		- .07 * ls(.22, .0, uv.y);
	o = box(uv - vec2(.5, .5), vec2(k, .46));
	o = max(o, -box(u, vec2(.15, .03)) + .06);
	c = mix(c, vec3(.6, .55, .55) - uv.y * .3 + b * .2, msk(o));
	c *= 1. - .7 * tri(.0, .013, o);
	c *= 1. - (r / .5 - .1) * msk(o);
	t = max(r, uv.y - .96);
	o = abs(t - .02) - .03;
	o = max(o, uv.y - 1. + u.x * .5);
	o = max(o, uv.y - .96);
	c = mix(c, vec3(1, 1, .9) - uv.y * .55, tri(-.01, .01, o));
	c = mix(c, vec3(.2 * b + .1), msk(t, .01));
	c *= 1. - .2 * tri(.0, .05, t) * msk(o);
	v = knob(u = uv - vec2(.5, .4), .02);
	c *= 1. + RGB(111, 80, 70) * tri(.03, .01, length(u));
	//c *= 1. - ls(.04, .02, length(u)) * clamp(u.y / .02, -1., 1.);
	c *= 1. - .5 * tri(.02, .01, length(u));
	c = mix(c, RGB(111, 66, 44) * (v.x * 1.5 + .2), v.y);
	return vec4(c, msk(t - .03, .02));
}

void lpdmnd_m() {
	vec4 c = texture(Texture0, UV);
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

TEX(mtlfw10) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3 c = mix(RGB(44, 14, 16), RGB(93, 63, 63), b * b);
	return c;
}

// xy = tile id, z = edge
vec3 mtlfw15_d(vec2 uv) {
	float e = 3e-3, a = 0.;
	vec2 g = vec2(6), r = voro1(uv, g);
	for (int i=0; i<9; ++i)
		a += sum(abs(voro1(vec2(i % 3 - 1, i / 3 - 1) * e + uv, g) - r));
	return vec3(uv + r.xy / g, a);
}

TEX(mtlfw15) {
	float b = FBMT(uv, vec2(3), .9, 3., 4);
	vec3 c = mix(RGB(80, 70, 72), RGB(128, 120, 120), b * b);
	vec3 v = mtlfw15_d(uv);
	c *= mix(.95, 1.1, NT(v.xy, vec2(6)));
	c = mix(c, RGB(168, 128, 120), ls(.5, 1., v.z) * b * .7);
	return c;
}

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

void mtlfw15ow_m() {
	vec4 c = texture(Texture0, UV);
	FCol = vec4(c.xyz * Light() + tri(.5, .125, fract(UV.y * .5 + Time.x * .5)) * c.w * .3, 1);
}

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

TEX(mtlt12f) {
	float b = FBMT(uv, vec2(5), .9, 3., 4), l;
	vec3 c = mix(RGB(51, 46, 43), RGB(165, 147, 143), b * b), d = mtltech_d(uv);
	l = 1. - .5 * (d.y - d.x) * tri(.5, 3., d.z) * ls(1., .0, d.z);
	return c * l * .8;
}

TEX(mtlt6f) {
	float b = FBMT(uv, vec2(3), 1.1, 3., 4), l;
	vec3 c = mix(RGB(51, 46, 43), RGB(165, 147, 143), b * b), d = mtltech_d(uv);
	l = 1. - .5 * (d.y - d.x) * tri(.5, 3., d.z) * ls(1., .0, d.z);
	return c * l;
}

TEX(mtlbk03) {
	float b = FBMT(uv, vec2(5), .9, 3., 4);
	vec3 c = mix(RGB(36, 35, 33), RGB(56, 54, 52), b * b);
	return c;
}

TEX(gmtlbg6) {
	float b = FBMT(uv, vec2(13), 1., 3., 4);
	vec3 c = mix(RGB(36, 35, 31), RGB(132, 132, 132), b);
	return c;
}

TEX(glrgbk3b) {
	float b = FBMT(uv, vec2(13), 1., 3., 4);
	vec3 c = mix(RGB(67, 37, 27), RGB(152, 117, 85), b);
	return c;
}

TEX(gblks15) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4),
		t = FBMT_ridged(uv + sin(uv.yx * PI * 4.) * .01, vec2(5), 1., 2., 5),
		n = NT(uv + sin(uv.yx * PI * 4.) * .05, vec2(9)),
		id, e;
	vec3
		pt = pattern(uv, 4., .1 + n * t * .05),
		c;
	vec2 d = grad(pt.x);
	id = H(fract(pt.yz));
	c = RGB(91, 67, 61) * (.8 + b * b * .8);
	c += tri(.6, .3, n) * ls(.3, .9, b * t) * .3;
	c *= 1. - tri(.5, .4, n) * ls(.5, .7, t) * .2;
	c = mix(c, RGB(86, 74, 78), tri(.5, .1, b) * tri(.7, .3, id) * .7);
	c = mix(c, RGB(105, 90, 70), tri(.3, .1, t) * tri(.3, .3, id) * .3);
	e = max(tri(.02, .007, pt.x), tri(.4, .03, n * t));
	c *= 1. - b * t * ls(.015, .022, pt.x) + e * b * d.y * .6;
	c *= .9 + .2 * id;
	return c;
}

TEX(gtprst3) {
	float
		b = FBMT(uv, vec2(13), .9, 3., 4),
		n = NT(uv + sin(uv.yx * PI * 4.) * .05, vec2(9));
	vec3 c = mix(RGB(56, 48, 49), RGB(100, 50, 40), .7 * (n + b) * .5) * (.875 + b * b);
	return c;
}

TEX(cable) {
	float
		b = FBMT(uv, vec2(5), .9, 3., 4),
		h = fract(uv.y * 10.);
	vec3 c = mix(RGB(53, 48, 42), RGB(38, 38, 36), b);
	c *= .6 + b * .8;
	c *= 1. - .5 * sqr(tri(.5, .5, h));
	c *= 1. + .5 * sqr(tri(.25, .25, h));
	c *= 1. + .5 * sqr(tri(.65, .35, h));
	return c;
}

TEX(bmtsprt) {
	float
		b = FBMT(uv, vec2(7, 3), .9, 3., 4),
		h = uv.y + b * .04,
		l = 1. - .15;
	vec3 c = mix(RGB(59, 48, 40), RGB(110, 108, 102), b*b);
	l = mix(l, .5, tri(.34, .05, uv.y));
	l = mix(l, .5, ls(.08, .05, abs(uv.y-.7)));
	l = mix(l, .3, tri(.7, .03, uv.y));
	l = mix(l, 1.5, tri(.01, .03, uv.y));
	l = mix(l, 2.2, tri(.89, .1, h));
	l = mix(l, 1.6, ls(.07, .04, abs(uv.y-.44)));
	l = mix(l, 2.5, tri(.5, .04, h));
	l = mix(l, 1.7, tri(.18, .04, h));
	return c * l;
}

TEX(brdr11b) {
	float b = FBMT(uv, vec2(5, 3), .9, 3., 4);
	vec3 c = mix(RGB(74, 66, 55), RGB(99, 90, 78), b*b);
	uv.x *= 2.;
	vec2 p = seg(uv, vec2(.5, .625), vec2(1.5, .625));
	float
		d = length(p - uv),
		m = ls(.22, .20, d),
		l = 1. - .15 * m;
	l = mix(l, .5, ls(.7, .9, uv.y) * m);
	l = mix(l, 1. - grad(d).y * .5, tri(.22, .04, d));
	l = mix(l, .6, sqr(tri(.19, .05, d)));
	l = mix(l, .5, ls(.05, 0., uv.y));
	l = mix(l, .5, tri(.26, .05, uv.y));
	l = mix(l, 1.7, ls(.93, 1., uv.y));
	l = mix(l, 1.7, tri(.23, .04, uv.y));
	return c * l;
}

TEXA(blt414k) {
	float b = FBMT(uv, vec2(1, 5), .4, 3., 4);
	vec3 c = mix(RGB(56, 49, 43), RGB(142, 136, 136), b);
	uv = .5 - abs(uv - .5);
	uv.y *= 4.;
	float
		a = tri(.0, .1, length(uv - seg(uv, vec2(.41, .5), vec2(.42, 3.5)))),
		d = mn(uv),
		l = 1. - .7 * max(0., 1. - d / .15);
	l *= 1. - .8 * ls(.24, .31, min(d, uv.y - .1));
	c += RGB(80, 80, 20) * a;
	return vec4(c * mix(l, 2.7, a), a);
}

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

TEXA(icon) {
	uv.y -= .57;
	uv.x = abs(uv.x - .48);
	float d = elips(uv, vec2(.31, .12)) / 50.;
	d = max(d, -elips(uv - vec2(0, .01), vec2(.28, .07)) / 120.);
	d = max(d, -box(uv - vec2(.0, .1), vec2(.22, .12)));
	d = max(d, -box(uv - vec2(.0, .1), vec2(.09, .31)));
	d = min(d, box1(uv - vec2(.0, -.09), vec2(tri(-.09, .32, uv.y)*.04, .32)));
	d = min(d, box1(uv - vec2(.11, -.21), vec2(tri(-.07, .3, uv.y)*.03, .15)));
	uv.y += .07;
	float b = length(uv) - .47, m = msk(b);
	vec3 c = 1. - vec3(.7, 1, 1) * msk(max(.007 - d, b + .04));
	return vec4(c * m, m);
}

TEXA(q3bnr) {
	uv *= vec2(256, 64);
	uv.y += 2.;

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
	d = min(d, box(mirr(uv, 111.) - vec2(105. + ls(23., 50., uv.y) * 3., 43), vec2(3.5, 19)));
	d = min(d, box(uv - vec2(111, 32), vec2(4, 3)));
	// K
	d = min(d, box(uv - vec2(126, 37), vec2(3, 13)));
	d = min(d, box(uv - vec2(125.5 + ls(23., 50., uv.y) * 10., 44), vec2(3.5, 6)));
	d = min(d, box(uv - vec2(136.5 - ls(23., 50., uv.y) * 9., 32), vec2(3.5, 8)));
	// E
	d = min(d, box(uv - vec2(148.5, 37), vec2(7, 13)));
	d = max(d, -box(uv - vec2(155, 33), vec2(6, 3)));
	d = max(d, -box(uv - vec2(155, 43), vec2(6, 2)));
	// III
	d = min(d, box(uv - vec2(168, 37), vec2(3.5, 13)));
	d = min(d, box(uv - vec2(178., 37), vec2(3.5, 13)));
	d = min(d, box(uv - vec2(188, 37), vec2(3.5, 13)));

	d = max(d, uv.y - 50.);
	return vec4(msk(d, .8), 0, 0, H(uv * 511.));
}

void q3bnr_m() {
	vec3 c = texture(Texture0, UV * 2.).xyz * step(.5, fract(Time.x * .5));
	c = mix(c * Light(), vec3(.5, 0, 0), tri(fract(Time.x * 2.), 1./64., fract(UV.y)));
	FCol = vec4(c + env(Ref) * .25 + texture(Texture0, UV + H(Time.xx)).w * .1, 1);
}

void beam() {
	vec2 uv = fract(uvmap(Pos.xyz, dom(Nor)) / 128.);
	uv.x += Time.x / 33.;
	float b = FBMT(uv, vec2(7), .9, 2.), f = fract(Pos.z/128.-.375);
	FCol = vec4(2. * RGB(95, 85, 80) * f*f*f*f * mix(1., b, .5), 0.);
}

void Generic() {
	float l = dot(Nor, normalize(vec3(2,0,8)));
	l = l * .4 + .7;
	vec2 uv = uvmap(Pos, dom(Nor));
	vec3 c = vec3(.5);
	c *= hsv(vec3(fract(PHI * Time.w + .25), 1., 1.));
	FCol = vec4(c * l, 1);
}

void fixture() {
	vec4 c = texture(Texture0, UV);
	FCol = vec4(c.xyz * mix(Light(), vec3(1), c.w), 1);
}

void dmnd2cjp_m() {
	vec4 c = texture(Texture0, UV);
	float r = length(fract(UV) - .5);
	float s = mix(.4, 8., fract(Time.x * 1.5));
	FCol = vec4(c.xyz * Light() + RGB(240, 130, 5) * tri(.1, .05, r / s) * ls(.37, .32, r), 1);
}

void Lmapped() {
	vec3 c = texture(Texture0, UV).xyz;
	FCol = vec4(c * Light(), 1);
}

void shiny() {
	vec4 c = texture(Texture0, UV);
	c.xyz *= 1. + c.w * env(Ref);
	FCol = vec4(c.xyz * Light(), 1);
}

void timhel() {
	vec3 d = normalize(Pos - Cam.xyz);
	d.z = d.z * 4. + 2.;
	vec2 uv = normalize(d).xy * 2.;
	float b = FBMT(uv - Time.x * vec2(.1, .2), vec2(5), .5, 2., 4);
	uv.y *= 1.5;
	float s = ls(.3, 1., FBMT(uv - Time.x * vec2(.1, .18), vec2(5), .6, 2., 4));
	FCol = vec4(vec3(b, 0, 0) + RGB(80, 30, 8) * s * s * 2., 1);
}

void Loading() {
	FCol = texture(Texture0, (.5 + UV * 127.) / 128., 2.5);
	FCol.xyz *= .7 + .3 * NT(UV, .5/fwidth(UV));
}

void UI() {
	FCol = texture(Texture0, UV) * Clr;
}
