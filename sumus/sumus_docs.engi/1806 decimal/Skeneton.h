#pragma once

#include <stddef.h>

// 64-bit integer support
// If your compiler does not have stdint.h, add appropriate defines for these macros.
#if defined(_MSC_VER) && (_MSC_VER < 1600)
#  define R128_S32 __int32
#  define R128_U32 unsigned __int32
#  define R128_S64 __int64
#  define R128_U64 unsigned __int64
#  define R128_LIT_S64(x) x##i64
#  define R128_LIT_U64(x) x##ui64
#else
#  include <stdint.h>
#  define R128_S32 int32_t
#  define R128_U32 uint32_t
#  define R128_S64 int64_t
#  define R128_U64 uint64_t
#  define R128_LIT_S64(x) x##ll
#  define R128_LIT_U64(x) x##ull
#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct BIG_FIX_POINT {
		R128_U64 lo;
		R128_U64 hi;

#ifdef __cplusplus
		BIG_FIX_POINT();
		BIG_FIX_POINT(double);
		BIG_FIX_POINT(int);
		BIG_FIX_POINT(R128_S64);
		BIG_FIX_POINT(R128_U64 low, R128_U64 high);

		operator double() const;
		operator R128_S64() const;
		operator int() const;
		operator bool() const;

		bool operator!() const;
		BIG_FIX_POINT operator~() const;
		BIG_FIX_POINT operator-() const;
		BIG_FIX_POINT &operator|=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator&=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator^=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator+=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator-=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator*=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator/=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator%=(const BIG_FIX_POINT &rhs);
		BIG_FIX_POINT &operator<<=(int amount);
		BIG_FIX_POINT &operator>>=(int amount);
#endif   //__cplusplus
	} BIG_FIX_POINT;

	// Type conversion
	 void BIG_FIX_POINT_FromInt(BIG_FIX_POINT *dst, R128_S64 v);
	 void BIG_FIX_POINT_FromFloat(BIG_FIX_POINT *dst, double v);
	 R128_S64 BIG_FIX_POINT_ToInt(const BIG_FIX_POINT *v);
	 double BIG_FIX_POINT_ToFloat(const BIG_FIX_POINT *v);

	

}









