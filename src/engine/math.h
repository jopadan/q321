#pragma once

#include <emmintrin.h>

#ifndef FLT_MAX
#define FLT_MAX          3.402823466e+38F        // max value
#endif // ndef FLT_MAX

#if defined(_M_IX86_FP) && _M_IX86_FP == 0
#define __vectorcall
#endif

namespace Math {
	FORCEINLINE int ftoi(float f) {
		float posf = f < 0.f ? -f : f;
		int i = (int)posf;
		i -= float(i) > posf;
		return f < 0.f ? -i : i;
	}

	inline namespace constants {
		static constexpr float
			PI			= 3.1415927f,
			PI_2		= PI * 0.5f,
			PI_4		= PI * 0.25f,
			TAU			= 2.f * PI,
			DEG2RAD		= PI / 180.f,
			RAD2DEG		= 180.f / PI;
	}

	inline namespace CRT {
		constexpr FORCEINLINE bool isnan(float x) {
			return x != x;
		}

		template <typename T>
		constexpr FORCEINLINE const T& min(const T& a, const T& b) {
			return a < b ? a : b;
		}

		template <typename T>
		constexpr FORCEINLINE const T& max(const T& a, const T& b) {
			return a < b ? b : a;
		}

		template <typename T, typename Other>
		constexpr FORCEINLINE T& assign_max(T& a, const Other& b) {
			if (a < b)
				a = b;
			return a;
		}

		template <typename T, typename Other>
		constexpr FORCEINLINE T& assign_min(T& a, const Other& b) {
			if (b < a)
				a = b;
			return a;
		}

		template <typename T>
		constexpr FORCEINLINE const T& clamp(const T& x, const T& minval, const T& maxval) {
			return min(max(x, minval), maxval);
		}

		NOINLINE float floor(float f) {
			float i = float(int(f));
			return i - (i > f);
		}

		inline float fract(float f) {
			return f - floor(f);
		}

		NOINLINE float mod(float f, float interval) {
			return fract(f / interval) * interval;
		}

		NOINLINE float ceil(float f) {
			float i = float(int(f));
			return i + (i < f);
		}

		inline float max(float a, float b) {
			//return _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(a), _mm_set_ss(b)));
			return a > b ? a : b;
		}

		inline float min(float a, float b) {
			//return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a), _mm_set_ss(b)));
			return a < b ? a : b;
		}

		inline float clamp(float x, float minval, float maxval) {
			return max(min(x, maxval), minval);
		}

		FORCEINLINE float abs(float x) {
			return x < 0.f ? -x : x;
			//u32 u = (*(u32*)&x) & 0x7fff'ffffu;
			//return *(float*)&u;
		}

		NOINLINE i32 abs(i32 i) {
			return i < 0 ? -i : i;
		}

		FORCEINLINE float sign_nonzero(float x) {
			return x < 0.f ? -1.f : 1.f;
		}

		FORCEINLINE float clamp_to_zero(float x) {
			i32 v = *(i32*)&x;
			v &= ~(v >> 31);
			return *(float*)&v;
		}
		
		FORCEINLINE float copysign(float x, float y) {
			u32 vx = *(u32*)&x;
			u32 vy = *(u32*)&y;
			vx ^= (vx ^ vy) & 0x8000'0000u;
			return *(float*)&vx;
		}

		FORCEINLINE bool signbit(float x) {
			return (*(u32*)&x) >> 31;
		}

#if PP_USE_INLINE_ASM
		__declspec(naked) float __fastcall sqrt(float x) {
			__asm {
				fld dword ptr [esp+4]
				fsqrt
				ret 4
			}
		}

		__declspec(naked) float __fastcall sin(float x) {
			__asm {
				fld dword ptr [esp+4]
				fsin
				ret 4
			}
		}

		__declspec(naked) float __fastcall cos(float x) {
			__asm {
				fld dword ptr [esp+4]
				fcos
				ret 4
			}
		}

		__declspec(naked) float __fastcall tan(float x) {
			__asm {
				fld dword ptr [esp+4]
				fptan
				fstp st(0)
				ret 4
			}
		}

		__declspec(naked) float __fastcall atan(float z) {
			__asm {
				fld dword ptr [esp+4]
				fld1
				fpatan
				ret 4
			}
		}

		__declspec(naked) float __fastcall atan2(float y, float x) {
			__asm {
				fld dword ptr [esp+4]
				fld dword ptr [esp+8]
				fpatan
				ret 8
			}
		}
#else
		float sqrt(float x) {
			return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(x)));
		}

		NOINLINE float sin(float x) {
			x *= 0.63661977f; // 2/PI
			if (abs(x) > 1.f) {
				x = fract(x * .25f + .25f) * 4.f;
				x = min(3.f - x, x - 1.f);
			}
			float x2 = x * x;
			float result = -0.004324993f;
			result = result * x2 + 0.07942155f;
			result = result * x2 + -0.64588755f;
			result = result * x2 + 1.57079064f;
			return clamp(result * x, -1.f, 1.f);
		}

		FORCEINLINE float cos(float x) {
			return sin(PI*.5f + x);
		}

		NOINLINE float tan(float x) {
			if (abs(x) > PI * 0.5f)
				x = fract(x * (1.f/PI) + 0.5f) * PI - (PI * 0.5f);
			float s = sign_nonzero(x);
			x *= s;
			bool flip = x > PI * 0.25f;
			if (flip)
				x = PI * 0.5f - x;
			float x2 = x * x;
			float result = (17.f/315.f);
			result = result * x2 + (2.f/15.f);
			result = result * x2 + (1.f/3.f);
			result = result * (x2 * x) + x;
			if (flip)
				result = 1.f / result;
			return result * s;
		}

		float atan(float z) {
			// https://www.dsprelated.com/showarticle/1052.php
			const float K1 = 0.97239411f, K2 = -0.19194795f;
			return (K1 + K2 * z * z) * z;
		}

		float atan2(float y, float x) {
			if (x != 0.f) {
				float scale, bias;
				if (abs(x) > abs(y)) {
					scale = 1.f;
					if (x > 0.f)
						bias = 0.f;
					else if (y >= 0.f)
						bias = Math::PI;
					else
						bias = -Math::PI;
					y /= x;
				} else {
					scale = -1.f;
					bias = (y > 0.f) ? Math::PI_2 : -Math::PI_2;
					y = x / y;
				}
				return atan(y) * scale + bias;
			}
			if (y > 0.f)
				return Math::PI_2;
			if (y < 0.f)
				return -Math::PI_2;
			return 0.f;
		}
#endif
	} // inline namespace CRT
} // namespace Math

////////////////////////////////////////////////////////////////

struct vec2 {
	union {
		float data[2];
		struct { float x, y; };
	};

	vec2() = default;
	constexpr vec2(float x, float y) : x(x), y(y) { }
	constexpr vec2(float scalar) : x(scalar), y(scalar) { }

	constexpr float&		operator[](size_t i) { return data[i]; }
	constexpr const float&	operator[](size_t i) const { return data[i]; }

	constexpr vec2& operator+=(const vec2& rhs) { x+=rhs.x; y+=rhs.y; return *this; }
	constexpr vec2& operator-=(const vec2& rhs) { x-=rhs.x; y-=rhs.y; return *this; }
	constexpr vec2& operator*=(const vec2& rhs) { x*=rhs.x; y*=rhs.y; return *this; }
	constexpr vec2& operator/=(const vec2& rhs) { x/=rhs.x; y/=rhs.y; return *this; }

	constexpr vec2 operator-() const { return vec2(-x, -y); }
	constexpr vec2 operator+() const { return *this; }
};

constexpr vec2 operator+(const vec2& lhs, const vec2& rhs) { return vec2(lhs.x+rhs.x, lhs.y+rhs.y); }
constexpr vec2 operator-(const vec2& lhs, const vec2& rhs) { return vec2(lhs.x-rhs.x, lhs.y-rhs.y); }
constexpr vec2 operator*(const vec2& lhs, const vec2& rhs) { return vec2(lhs.x*rhs.x, lhs.y*rhs.y); }
constexpr vec2 operator/(const vec2& lhs, const vec2& rhs) { return vec2(lhs.x/rhs.x, lhs.y/rhs.y); }

constexpr bool operator==(const vec2& lhs, const vec2& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
constexpr bool operator!=(const vec2& lhs, const vec2& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y; }

vec2 floor(const vec2& v)	{ return vec2(Math::floor(v.x), Math::floor(v.y)); }
vec2 ceil(const vec2& v)	{ return vec2(Math::ceil(v.x), Math::ceil(v.y)); }

constexpr FORCEINLINE float cross(const vec2& a, const vec2& b) {
	return a.x * b.y - b.x * a.y;
}

////////////////////////////////////////////////////////////////

struct vec3 {
	union {
		float data[3];
		struct { float x, y, z; };
		struct { float r, g, b; };
		vec2 xy;
	};

	vec3() = default;
	constexpr vec3(float x, float y, float z) : x(x), y(y), z(z) { }
	constexpr vec3(float scalar) : x(scalar), y(scalar), z(scalar) { }

	vec3& operator=(const vec3& copy) { return *MemCopy(this, &copy); }
	vec3& operator=(float scalar) { x = scalar; y = scalar; z = scalar; return *this; }

	constexpr float& operator[](size_t i) { return data[i]; }
	constexpr const float& operator[](size_t i) const { return data[i]; }

	NOINLINE constexpr vec3& operator+=(const vec3& rhs) { x+=rhs.x; y+=rhs.y; z+=rhs.z; return *this; }
	NOINLINE constexpr vec3& operator-=(const vec3& rhs) { x-=rhs.x; y-=rhs.y; z-=rhs.z; return *this; }
	NOINLINE constexpr vec3& operator*=(const vec3& rhs) { x*=rhs.x; y*=rhs.y; z*=rhs.z; return *this; }
	NOINLINE constexpr vec3& operator*=(float rhs)       { x*=rhs;   y*=rhs;   z*=rhs  ; return *this; }
	NOINLINE constexpr vec3& operator/=(const vec3& rhs) { x/=rhs.x; y/=rhs.y; z/=rhs.z; return *this; }
	NOINLINE constexpr vec3& operator/=(float rhs)       { x/=rhs;   y/=rhs;   z/=rhs  ; return *this; }

	NOINLINE constexpr vec3 operator-() const { return vec3(-x, -y, -z); }
	constexpr vec3 operator+() const { return *this; }
};

NOINLINE constexpr vec3 operator+(const vec3& lhs, const vec3& rhs) { return vec3(lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z); }
NOINLINE constexpr vec3 operator-(const vec3& lhs, const vec3& rhs) { return vec3(lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z); }
NOINLINE constexpr vec3 operator*(const vec3& lhs, const vec3& rhs) { return vec3(lhs.x*rhs.x, lhs.y*rhs.y, lhs.z*rhs.z); }
NOINLINE constexpr vec3 operator*(const vec3& lhs, float rhs)       { return vec3(lhs.x*rhs,   lhs.y*rhs,   lhs.z*rhs  ); }
NOINLINE constexpr vec3 operator/(const vec3& lhs, const vec3& rhs) { return vec3(lhs.x/rhs.x, lhs.y/rhs.y, lhs.z/rhs.z); }
NOINLINE constexpr vec3 operator/(const vec3& lhs, float rhs)       { return vec3(lhs.x/rhs,   lhs.y/rhs,   lhs.z/rhs  ); }

NOINLINE constexpr bool operator==(const vec3& lhs, const vec3& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z; }
NOINLINE constexpr bool operator!=(const vec3& lhs, const vec3& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z; }

NOINLINE vec3 floor(const vec3& v)	{ return vec3(Math::floor(v.x), Math::floor(v.y), Math::floor(v.z)); }
NOINLINE vec3 ceil(const vec3& v)	{ return vec3(Math::ceil(v.x), Math::ceil(v.y), Math::ceil(v.z)); }

////////////////////////////////////////////////////////////////

struct vec4 {
	union {
		float data[4];
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
		vec3 xyz;
		struct { vec2 xy, zw; };
	};

	vec4() = default;
	constexpr vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
	constexpr vec4(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }

	vec4& operator=(const vec4& copy) { return *MemCopy(this, &copy); }
	vec4& operator=(float scalar) { x = scalar; y = scalar; z = scalar; w = scalar; return *this; }

	constexpr float& operator[](size_t i) { return data[i]; }
	constexpr const float& operator[](size_t i) const { return data[i]; }

	NOINLINE constexpr vec4& operator+=(const vec4& rhs) { x+=rhs.x; y+=rhs.y; z+=rhs.z; w+=rhs.w; return *this; }
	NOINLINE constexpr vec4& operator-=(const vec4& rhs) { x-=rhs.x; y-=rhs.y; z-=rhs.z; w+=rhs.w; return *this; }
	NOINLINE constexpr vec4& operator*=(const vec4& rhs) { x*=rhs.x; y*=rhs.y; z*=rhs.z; w*=rhs.w; return *this; }
	NOINLINE constexpr vec4& operator*=(float rhs)       { x*=rhs;   y*=rhs;   z*=rhs;   w*=rhs  ; return *this; }
	NOINLINE constexpr vec4& operator/=(const vec4& rhs) { x/=rhs.x; y/=rhs.y; z/=rhs.z; w/=rhs.w; return *this; }
	NOINLINE constexpr vec4& operator/=(float rhs)       { x/=rhs;   y/=rhs;   z/=rhs;   w/=rhs  ; return *this; }

	NOINLINE constexpr vec4 operator-() const { return vec4(-x, -y, -z, -w); }
	NOINLINE constexpr vec4 operator+() const { return *this; }
};

NOINLINE constexpr vec4 operator+(const vec4& lhs, const vec4& rhs) { return vec4(lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z, lhs.w+rhs.w); }
NOINLINE constexpr vec4 operator-(const vec4& lhs, const vec4& rhs) { return vec4(lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z, lhs.w-rhs.w); }
NOINLINE constexpr vec4 operator*(const vec4& lhs, const vec4& rhs) { return vec4(lhs.x*rhs.x, lhs.y*rhs.y, lhs.z*rhs.z, lhs.w*rhs.w); }
NOINLINE constexpr vec4 operator*(const vec4& lhs, float rhs)       { return vec4(lhs.x*rhs,   lhs.y*rhs,   lhs.z*rhs,   lhs.w*rhs  ); }
NOINLINE constexpr vec4 operator/(const vec4& lhs, const vec4& rhs) { return vec4(lhs.x/rhs.x, lhs.y/rhs.y, lhs.z/rhs.z, lhs.w/rhs.w); }
NOINLINE constexpr vec4 operator/(const vec4& lhs, float rhs)       { return vec4(lhs.x/rhs,   lhs.y/rhs,   lhs.z/rhs,   lhs.w/rhs  ); }

NOINLINE constexpr bool operator==(const vec4& lhs, const vec4& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w; }
NOINLINE constexpr bool operator!=(const vec4& lhs, const vec4& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z || lhs.w != rhs.w; }

NOINLINE vec4 floor(const vec4& v)	{ return vec4(Math::floor(v.x), Math::floor(v.y), Math::floor(v.z), Math::floor(v.w)); }
NOINLINE vec4 ceil(const vec4& v)	{ return vec4(Math::ceil(v.x), Math::ceil(v.y), Math::ceil(v.z), Math::ceil(v.z)); }

////////////////////////////////////////////////////////////////

// Using overloaded operators to express a multiply-and-add as y = a * x + b
// appears to increase code size compared to the explicit component-wise form.
// The helpers below are meant to alleviate the problem.

NOINLINE void mul(vec3& dst, const vec3& a, float b) {
	dst[0] = a[0] * b;
	dst[1] = a[1] * b;
	dst[2] = a[2] * b;
}

NOINLINE void mul(vec3& dst, const vec3& a, const vec3& b) {
	dst[0] = a[0] * b[0];
	dst[1] = a[1] * b[1];
	dst[2] = a[2] * b[2];
}

NOINLINE void mul(vec3& dst, float s) {
	dst[0] *= s;
	dst[1] *= s;
	dst[2] *= s;
}

NOINLINE void mul(vec3& dst, vec3& s) {
	dst[0] *= s[0];
	dst[1] *= s[1];
	dst[2] *= s[2];
}

NOINLINE void mad(vec3& dst, const vec3& a, float b) {
	dst[0] += a[0] * b;
	dst[1] += a[1] * b;
	dst[2] += a[2] * b;
}

NOINLINE void mad(vec3& dst, const vec3& a, const vec3& b) {
	dst[0] += a[0] * b[0];
	dst[1] += a[1] * b[1];
	dst[2] += a[2] * b[2];
}

NOINLINE void mix_into(vec3& dst, const vec3& v, float f) {
	dst.x += (v.x - dst.x) * f;
	dst.y += (v.y - dst.y) * f;
	dst.z += (v.z - dst.z) * f;
}

void mix_into(vec2& dst, const vec2& v, float f) {
	dst.x += (v.x - dst.x) * f;
	dst.y += (v.y - dst.y) * f;
}

// When all else fails, resort to old-school (Q3A-style) macros...

#define V3MULS(vdst,va,b)\
	vdst.x = (b) * va.x,\
	vdst.y = (b) * va.y,\
	vdst.z = (b) * va.z

#define V3MUL(vdst,va,vb)\
	vdst.x = va.x * vb.x,\
	vdst.y = va.y * vb.y,\
	vdst.z = va.z * vb.z

#define V3MSAD(vdst,va,b)\
	vdst.x += (b) * va.x,\
	vdst.y += (b) * va.y,\
	vdst.z += (b) * va.z

#define V3MAD(vdst,va,vb)\
	vdst.x += vb.x * va.x,\
	vdst.y += vb.y * va.y,\
	vdst.z += vb.z * va.z

////////////////////////////////////////////////////////////////

constexpr NOINLINE float dot(const vec2& a, const vec2& b)	{ return a.x*b.x + a.y*b.y; }
constexpr NOINLINE float dot(const vec3& a, const vec3& b)	{ return a.x*b.x + a.y*b.y + a.z*b.z; }
constexpr NOINLINE float dot(const vec4& a, const vec4& b)	{ return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w; }

constexpr NOINLINE float length_squared(const vec2& v)		{ return dot(v, v); }
constexpr NOINLINE float length_squared(const vec3& v)		{ return dot(v, v); }
NOINLINE float length(const vec2& v)						{ return Math::sqrt(dot(v, v)); }
NOINLINE float length(const vec3& v)						{ return Math::sqrt(dot(v, v)); }
NOINLINE vec2 normalize(const vec2& p)						{ return p / length(p); }
NOINLINE vec3 normalize(const vec3& p)						{ return p / length(p); }

NOINLINE void safe_normalize(const vec3& src, vec3& dst) {
	dst = src;
	float len = length(src);
	if (len > 0.f)
		dst /= len;
}

FORCEINLINE void safe_normalize(vec3& dst) {
	float len = length(dst);
	if (len > 0.f)
		dst /= len;
}

constexpr NOINLINE vec3 cross(const vec3& a, const vec3& b) {
	return vec3
	(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	);
}

constexpr NOINLINE void cross(const vec3& a, const vec3& b, vec3& dst) {
	dst.x = a.y*b.z - a.z*b.y;
	dst.y = a.z*b.x - a.x*b.z;
	dst.z = a.x*b.y - a.y*b.x;
}

////////////////////////////////////////////////////////////////

vec2 abs(const vec2& v) { return {Math::abs(v.x), Math::abs(v.y)}; }
vec3 abs(const vec3& v) { return {Math::abs(v.x), Math::abs(v.y), Math::abs(v.z)}; }
vec4 abs(const vec4& v) { return {Math::abs(v.x), Math::abs(v.y), Math::abs(v.z), Math::abs(v.w)}; }

vec2 min(const vec2& a, const vec2& b) { return {Math::min(a.x, b.x), Math::min(a.y, b.y)}; }
vec3 min(const vec3& a, const vec3& b) { return {Math::min(a.x, b.x), Math::min(a.y, b.y), Math::min(a.z, b.z)}; }
vec4 min(const vec4& a, const vec4& b) { return {Math::min(a.x, b.x), Math::min(a.y, b.y), Math::min(a.z, b.z), Math::min(a.w, b.w)}; }

vec2 max(const vec2& a, const vec2& b) { return {Math::max(a.x, b.x), Math::max(a.y, b.y)}; }
vec3 max(const vec3& a, const vec3& b) { return {Math::max(a.x, b.x), Math::max(a.y, b.y), Math::max(a.z, b.z)}; }
vec4 max(const vec4& a, const vec4& b) { return {Math::max(a.x, b.x), Math::max(a.y, b.y), Math::max(a.z, b.z), Math::max(a.w, b.w)}; }

float min_component(const vec2& v) { return Math::min(v.x, v.y); }
float min_component(const vec3& v) { return Math::min(v.x, Math::min(v.y, v.z)); }
float min_component(const vec4& v) { return Math::min(v.x, Math::min(v.y, Math::min(v.z, v.w))); }

float max_component(const vec2& v) { return Math::max(v.x, v.y); }
float max_component(const vec3& v) { return Math::max(v.x, Math::max(v.y, v.z)); }
float max_component(const vec4& v) { return Math::max(v.x, Math::max(v.y, Math::max(v.z, v.w))); }

template <typename T>
FORCEINLINE T mix(const T& a, const T& b, float t) { return a + (b-a) * t; }

////////////////////////////////////////////////////////////////

FORCEINLINE u8 dominant_axis(const vec3& nor) {
	vec3 absnor = abs(nor);
	float max_comp = max_component(absnor);
	return (max_comp == absnor.z) ? 2 : (max_comp == absnor.x) ? 0 : 1;
}

////////////////////////////////////////////////////////////////

struct mat4;

struct mat3 {
	union {
		float data[9];
		vec3 m[3];
		struct { vec3 x, y, z; };
	};

	mat3() = default;
	explicit constexpr mat3(float diag) : x(diag, 0.f, 0.f), y(0.f, diag, 0.f), z(0.f, 0.f, diag) { }
	constexpr mat3(const vec3& x, const vec3& y, const vec3& z) : x(x), y(y), z(z) { }

	constexpr mat3(
		float xx, float xy, float xz,
		float yx, float yy, float yz,
		float zx, float zy, float zz
	) : x(xx, xy, xz),
		y(yx, yy, yz),
		z(zx, zy, zz)
	{ }

	constexpr explicit mat3(const mat4& m);

	mat3& operator=(const mat3& copy) { return *MemCopy(this, &copy); }

	constexpr vec3& operator[](size_t i) { return m[i]; }
	constexpr const vec3& operator[](size_t i) const { return m[i]; }

	constexpr mat3& SetRow(int row, const vec3& v) { m[0][row] = v.x; m[1][row] = v.y; m[2][row] = v.z; return *this; }
};

static constexpr mat3 o3x3(0.f);
static constexpr mat3 i3x3(1.f);

NOINLINE void transpose(const mat3& m, mat3& out) {
	const u32 ORDER =
		/*******/ (3<< 0) | (6<< 4) |
		(1<< 8) | (4<<12) | (7<<16) |
		(2<<20) | (5<<24) | (8<<28) ;

	out.data[0] = m.data[0];
	for (u32 i=0; i<8; ++i)
		out.data[i + 1] = m.data[(ORDER >> (i<<2)) & 15];
}

FORCEINLINE mat3 transpose(const mat3& m) {
	mat3 out;
	transpose(m, out);
	return out;
}

NOINLINE mat3 operator*(const mat3& lhs, const mat3& rhs) {
#if 0
	mat3 out;
	for (u16 col = 0; col < 3; ++col) {
		for (u16 row = 0; row < 3; ++row) {
			out[col][row] =
				lhs[0][row] * rhs[col][0] + 
				lhs[1][row] * rhs[col][1] + 
				lhs[2][row] * rhs[col][2] ;
		}
	}
	return out;
#else
#	define MUL(col, row)	lhs.x.row*rhs.col.x + lhs.y.row*rhs.col.y + lhs.z.row*rhs.col.z
#	define COL(n)			MUL(n, x), MUL(n, y), MUL(n, z)

	return mat3(COL(x), COL(y), COL(z));

#	undef COL
#	undef MUL
#endif
}

vec3 operator*(const mat3& lhs, const vec3& rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

float determinant(const mat3& m) {
	return
		m.x.x * m.y.y * m.z.z +
		m.x.y * m.y.z * m.z.x +
		m.x.z * m.y.x * m.z.y -
		m.x.z * m.y.y * m.z.x -
		m.x.y * m.y.x * m.z.z -
		m.x.x * m.y.z * m.z.y ;
}

NOINLINE void invert(const mat3& m, mat3& out) {
	float det = determinant(m);
	if (det != 0.f) {
		out.x.x = (m.y.y*m.z.z-m.z.y*m.y.z) /  det;
		out.x.y = (m.x.y*m.z.z-m.z.y*m.x.z) / -det;
		out.x.z = (m.x.y*m.y.z-m.y.y*m.x.z) /  det;
	
		out.y.x = (m.y.x*m.z.z-m.z.x*m.y.z) / -det;
		out.y.y = (m.x.x*m.z.z-m.z.x*m.x.z) /  det;
		out.y.z = (m.x.x*m.y.z-m.y.x*m.x.z) / -det;
	
		out.z.x = (m.y.x*m.z.y-m.z.x*m.y.y) /  det;
		out.z.y = (m.x.x*m.z.y-m.z.x*m.x.y) / -det;
		out.z.z = (m.x.x*m.y.y-m.y.x*m.x.y) /  det;
	} else {
		out = o3x3;
	}
}

FORCEINLINE mat3 inverse(const mat3& m) {
	mat3 out;
	invert(m, out);
	return out;
}

////////////////////////////////////////////////////////////////

struct mat4 {
	union {
		float data[16];
		vec4 m[4];
		struct { vec4 x, y, z, w; };
	};

	mat4() = default;
	explicit constexpr mat4(float diag) : x(diag, 0.f, 0.f, 0.f), y(0.f, diag, 0.f, 0.f), z(0.f, 0.f, diag, 0.f), w(0.f, 0.f, 0.f, diag) { }
	constexpr mat4(const vec4& x, const vec4& y, const vec4& z, const vec4& w) : x(x), y(y), z(z), w(w) { }

	constexpr mat4(
		float xx, float xy, float xz, float xw,
		float yx, float yy, float yz, float yw,
		float zx, float zy, float zz, float zw,
		float wx, float wy, float wz, float ww
	) : x(xx, xy, xz, xw),
		y(yx, yy, yz, yw),
		z(zx, zy, zz, zw),
		w(wx, wy, wz, ww)
	{ }

	constexpr mat4(const mat3& m) :
		x(m.x.x, m.x.y, m.x.z, 0.f),
		y(m.y.x, m.y.y, m.y.z, 0.f),
		z(m.z.x, m.z.y, m.z.z, 0.f),
		w(0.f,   0.f,   0.f,   1.f)
	{ }

	mat4& operator=(const mat4& copy) { return *MemCopy(this, &copy); }

	/* column access */
	constexpr vec4&			operator[](size_t i) { return m[i]; }
	constexpr const vec4&	operator[](size_t i) const { return m[i]; }

	mat4&					SetRow(size_t row, const vec4& v)	{ m[0][row] = v.x; m[1][row] = v.y; m[2][row] = v.z; m[3][row] = v.w; return *this; }
	constexpr vec4			GetRow(size_t row) const			{ return vec4{m[0][row], m[1][row], m[2][row], m[3][row]}; }

	mat4&					SetPosition(const vec3& pos)		{ w.xyz = pos; return *this; }
	constexpr vec3&			GetPosition()						{ return w.xyz; }
	constexpr const vec3&	GetPosition() const					{ return w.xyz; }

	mat4&					SetAxis(size_t i, const vec3& v)	{ m[i].xyz = v; return *this; }
	constexpr vec3&			GetAxis(size_t i)					{ return m[i].xyz; }
	constexpr const vec3&	GetAxis(size_t i) const				{ return m[i].xyz; }
};

constexpr mat4 o4x4(0.f);
constexpr mat4 i4x4(1.f);

constexpr mat3::mat3(const mat4& m) :
	x(m.x.x, m.x.y, m.x.z),
	y(m.y.x, m.y.y, m.y.z),
	z(m.z.x, m.z.y, m.z.z)
{ }

NOINLINE void transpose(const mat4& m, mat4& out) {
	// Note: for loop would have been inlined.
	// We don't want that, hence the wacky do/while.
	u16 i = 0;
	do {
		out[i & 3][i >> 2] = m.data[i];
	} while (++i < 16);
}

FORCEINLINE mat4 transpose(const mat4& m) {
	mat4 out;
	transpose(m, out);
	return out;
}

NOINLINE mat4 operator*(const mat4& lhs, const mat4& rhs) {
#if 1
	mat4 out;
	for (u16 col = 0; col < 4; ++col) {
		for (u16 row = 0; row < 4; ++row) {
			out[col][row] =
				lhs[0][row] * rhs[col][0] + 
				lhs[1][row] * rhs[col][1] + 
				lhs[2][row] * rhs[col][2] + 
				lhs[3][row] * rhs[col][3] ;
		}
	}
	return out;
#else
	#define MUL(col, row)	lhs.x.row*rhs.col.x + lhs.y.row*rhs.col.y + lhs.z.row*rhs.col.z + lhs.w.row*rhs.col.w
	#define COL(n)			vec4(MUL(n, x), MUL(n, y), MUL(n, z), MUL(n, w))

	return mat4(COL(x), COL(y), COL(z), COL(w));

	#undef COL
	#undef MUL
#endif
}

NOINLINE constexpr vec4 operator*(const mat4& lhs, const vec4& rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z + lhs.w*rhs.w;
}

NOINLINE constexpr vec3 operator*(const mat4& lhs, const vec3& rhs) {
	return lhs.x.xyz*rhs.x + lhs.y.xyz*rhs.y + lhs.z.xyz*rhs.z + lhs.w.xyz;
}

////////////////////////////////////////////////////////////////

FORCEINLINE float ScaleFov(float fov_radians, float scale) {
	return Math::atan(Math::tan(fov_radians * 0.5f) * scale) * 2.f;
}

NOINLINE mat4 MakeRotation(const vec3& angles) {
	float sy = Math::sin(angles.x);
	float sp = Math::sin(angles.y);
	float sr = Math::sin(angles.z);
	float cy = Math::cos(angles.x);
	float cp = Math::cos(angles.y);
	float cr = Math::cos(angles.z);

	if constexpr (1) {
		// https://www.symbolab.com/solver/matrix-multiply-calculator FTW!

		return {
			cy*cp,				sy*cp,				sp,		0.f,	// column 0
			-cy*sp*sr - cr*sy,	cr*cy - sy*sp*sr,	cp*sr,	0.f,	// column 1
			sy*sr - cr*cy*sp,	-cy*sr - cr*sy*sp,	cr*cp,	0.f,	// column 2
			0.f,				0.f,				0.f,	1.f,	// column 3
		};
	} else {
		mat4 yaw = i4x4;
		mat4 pitch = i4x4;
		mat4 roll = i4x4;

		yaw[0][0] = cy;
		yaw[0][1] = sy;
		yaw[1][0] = -sy;
		yaw[1][1] = cy;

		pitch[0][0] = cp;
		pitch[0][2] = sp;
		pitch[2][0] = -sp;
		pitch[2][2] = cp;

		roll[1][1] = cr;
		roll[1][2] = sr;
		roll[2][1] = -sr;
		roll[2][2] = cr;

		return yaw * pitch * roll;
	}
}

NOINLINE void MakeRotation(const vec3& angles, mat3& out) {
	float sy = Math::sin(angles.x);
	float sp = Math::sin(angles.y);
	float sr = Math::sin(angles.z);
	float cy = Math::cos(angles.x);
	float cp = Math::cos(angles.y);
	float cr = Math::cos(angles.z);

	if constexpr (1) {
		// https://www.symbolab.com/solver/matrix-multiply-calculator FTW!

		out = {
			cy*cp,				sy*cp,				sp,			// column 0
			-cy*sp*sr - cr*sy,	cr*cy - sy*sp*sr,	cp*sr,		// column 1
			sy*sr - cr*cy*sp,	-cy*sr - cr*sy*sp,	cr*cp,		// column 2
		};
	} else {
		mat3 yaw = i3x3;
		mat3 pitch = i3x3;
		mat3 roll = i3x3;

		yaw[0][0] = cy;
		yaw[0][1] = sy;
		yaw[1][0] = -sy;
		yaw[1][1] = cy;

		pitch[0][0] = cp;
		pitch[0][2] = sp;
		pitch[2][0] = -sp;
		pitch[2][2] = cp;

		roll[1][1] = cr;
		roll[1][2] = sr;
		roll[2][1] = -sr;
		roll[2][2] = cr;

		out = yaw * pitch * roll;
	}
}

FORCEINLINE void MakePerspective(vec2 fov, float znear, float zfar, mat4& out) {
	MemSet(&out);

	float zrange = zfar - znear;
	for (u32 i=0; i<2; ++i)
		out.data[i*5] = 1.f / Math::tan(fov.data[i] * 0.5f);

	out.z.z = -(zfar + znear) / zrange;
	out.z.w = -1.f;
	out.w.z = -2.f * zfar * znear / zrange;
}

////////////////////////////////////////////////////////////////

float GetTriangleArea(float ab, float bc, float ca) {
	float p = (ab + bc + ca) * 0.5f;
	return Math::sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

float GetTriangleArea(const vec2& a, const vec2& b, const vec2& c) {
	return GetTriangleArea(length(b - a), length(c - b), length(a - c));
}

float GetTriangleArea(const vec3& a, const vec3& b, const vec3& c) {
	return GetTriangleArea(length(b - a), length(c - b), length(a - c));
}

////////////////////////////////////////////////////////////////

FORCEINLINE void IntersectPlanes(const vec4& p0, const vec4& p1, vec3& origin, vec3& direction) {
	cross(p0.xyz, p1.xyz, direction);
	direction /= length(direction);

	/*
	x*p0.x  + y*p0.y  + z*p0.z  + p0.w = 0
	x*p1.x  + y*p1.y  + z*p1.z  + p1.w = 0
	x*dir.x + y*dir.y + z*dir.z + 0    = 0

	[p0.x  p0.y  p0.z ]   [x]   [-p0.w]
	[p1.x  p1.y  p1.z ] * [y] = [-p1.w]
	[dir.x dir.y dir.z]   [z]   [    0]
	*/

	mat3 coeff(p0.xyz, p1.xyz, direction), tmp;
	transpose(coeff, tmp);
	invert(tmp, coeff);
	mul(origin, coeff[0], -p0.w);
	mad(origin, coeff[1], -p1.w);
}

FORCEINLINE void IntersectPlanes(const vec4& p0, const vec4& p1, const vec4& p2, vec3& origin) {
	/*
	x*p0.x + y*p0.y + z*p0.z + p0.w = 0
	x*p1.x + y*p1.y + z*p1.z + p1.w = 0
	x*p2.x + y*p2.y + z*p2.z + p2.w = 0

	[p0.x  p0.u  p0.z ]   [x]   [-p0.w]
	[p1.x  p1.u  p1.z ]   [x]   [-p1.w]
	[p2.x  p2.u  p2.z ]   [x]   [-p2.w]
	*/

	mat3 coeff(p0.xyz, p1.xyz, p2.xyz), tmp;
	transpose(coeff, tmp);
	invert(tmp, coeff);
	origin = coeff * vec3(-p0.w, -p1.w, -p2.w);
}

FORCEINLINE void ClipSegmentByPlane(const vec3& origin, const vec3& dir, const vec4& plane, float& tmin, float& tmax, float epsilon = 0.f) {
	float align = dot(plane.xyz, dir);
	float t = dot(origin, plane.xyz) + plane.w;
	if (align == 0.f) {
		if (t > epsilon) {
			tmin = FLT_MAX;
			tmax = -FLT_MAX;
		}
		return;
	}
	t /= -align;
	if (align > 0.f)
		Math::assign_min(tmax, t);
	else
		Math::assign_max(tmin, t);
}

struct BrushEdge {
	vec3		first_point;
	i32			first_plane;
	vec3		second_point;
	i32			second_plane;
};

// Template, because we want it to work not only with arrays of vec4's, but also Map::Planes (derived from vec4's) without slicing
template <typename Plane>
FORCEINLINE u32 EnumerateBrushEdges(const Plane* planes, u32 num_planes, BrushEdge* edges, u32 max_num_edges, float epsilon = (1.f/32.f)) {
	u32 num_edges = 0;

	for (u32 i = 0; i < num_planes - 1; ++i) {
		auto& p0 = planes[i];
		
		for (u32 j = i + 1; j < num_planes; ++j) {
			auto& p1 = planes[j];

			float align = Math::abs(dot(p0.xyz, p1.xyz));
			if (align > 1.f - 0x1p-10f)
				continue;
			
			vec3 origin, dir;
			IntersectPlanes(p0, p1, origin, dir);

			float d0 = dot(origin, p0.xyz) + p0.w;
			float d1 = dot(origin, p1.xyz) + p1.w;
			assert(Math::abs(d0) < .1f);
			assert(Math::abs(d1) < .1f);

			float tmin = -FLT_MAX;
			float tmax =  FLT_MAX;
			for (u32 k = 0; k < num_planes; ++k) {
				if (k == i || k == j)
					continue;
				ClipSegmentByPlane(origin, dir, planes[k], tmin, tmax, epsilon);
				if (tmax <= tmin + epsilon)
					break;
			}
	
			if (tmax <= tmin + epsilon)
				continue;

			if (edges) {
				auto& edge = edges[num_edges++];
				assert(num_edges <= max_num_edges);
				edge.first_point	= origin + dir * tmin;
				edge.first_plane	= i;
				edge.second_point	= origin + dir * tmax;
				edge.second_plane	= j;
			} else {
				++num_edges;
			}
		}
	}

	return num_edges;
}

////////////////////////////////////////////////////////////////

// http://jcgt.org/published/0003/02/01/paper.pdf

FORCEINLINE vec2 signNotZero(const vec2& v) {
	return vec2((v.x >= 0.f) ? +1.f : -1.f, (v.y >= 0.f) ? +1.f : -1.f);
}

// Assume normalized input. Output is on [-1, 1] for each component.
FORCEINLINE vec2 vec3_to_oct(const vec3& v) {
	// Project the sphere onto the octahedron, and then onto the xy plane
	vec2 p = v.xy * (1.f / (Math::abs(v.x) + Math::abs(v.y) + Math::abs(v.z)));
	// Reflect the folds of the lower hemisphere over the diagonals
	return (v.z <= 0.f) ? ((1.f - vec2(Math::abs(p.y), Math::abs(p.x))) * signNotZero(p)) : p;
}

FORCEINLINE vec3 oct_to_vec3(const vec2& e) {
	vec3 v{e.x, e.y, 1.f - Math::abs(e.x) - Math::abs(e.y)};
	if (v.z < 0.f)
		v.xy = (1.f - vec2(Math::abs(v.y), Math::abs(v.x))) * signNotZero(v.xy);
	return normalize(v);
}
