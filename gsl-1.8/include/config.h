/* config.h.in.  Generated manually from config.h.in for VC.  */

#ifndef CONFIG_H_SEEN
#define CONFIG_H_SEEN

#include <gsl/gsl_types.h>

/* Define to 1 if you have the declaration of `acosh', and to 0 if you don't.
   */
#define HAVE_DECL_ACOSH 0

/* Define to 1 if you have the declaration of `asinh', and to 0 if you don't.
   */
#define HAVE_DECL_ASINH 0

/* Define to 1 if you have the declaration of `atanh', and to 0 if you don't.
   */
#define HAVE_DECL_ATANH 0

/* Define to 1 if you have the declaration of `expm1', and to 0 if you don't.
   */
#define HAVE_DECL_EXPM1 0

/* Define to 1 if you have the declaration of `feenableexcept', and to 0 if
   you don't. */
#define HAVE_DECL_FEENABLEEXCEPT 0

/* Define to 1 if you have the declaration of `fesettrapenable', and to 0 if
   you don't. */
#define HAVE_DECL_FESETTRAPENABLE 0

/* Define to 1 if you have the declaration of `finite', and to 0 if you don't.
   */
#define HAVE_DECL_FINITE 0

/* Define to 1 if you have the declaration of `frexp', and to 0 if you don't.
   */
#define HAVE_DECL_FREXP 1

/* Define to 1 if you have the declaration of `hypot', and to 0 if you don't.
   */
#define HAVE_DECL_HYPOT 1

/* Define to 1 if you have the declaration of `isfinite', and to 0 if you
   don't. */
#define HAVE_DECL_ISFINITE 0

/* Define to 1 if you have the declaration of `isinf', and to 0 if you don't.
   */
#define HAVE_DECL_ISINF 0

/* Define to 1 if you have the declaration of `isnan', and to 0 if you don't.
   */
#define HAVE_DECL_ISNAN 0

/* Define to 1 if you have the declaration of `ldexp', and to 0 if you don't.
   */
#define HAVE_DECL_LDEXP 1

/* Define to 1 if you have the declaration of `log1p', and to 0 if you don't.
   */
#define HAVE_DECL_LOG1P 0

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
#undef HAVE_DOPRNT

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef HAVE_IEEEFP_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the `m' library (-lm). */
#undef HAVE_LIBM

/* Define to 1 if you have the `memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strdup' function. */
#undef HAVE_STRDUP

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the `vprintf' function. */
#define HAVE_VPRINTF 1

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#undef VERSION

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#define inline __inline
#endif

/* Define to `unsigned' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to empty if the keyword `volatile' does not work. Warning: valid
   code using `volatile' can become incorrect without. Disable with care. */
/* #undef volatile */

/* Defined if this is an official release */
#undef RELEASED

/* Define if you have inline - vc does, but want to include all functions in library */
// #undef HAVE_INLINE
// TFB defining this.  Don't understand comment above.  They will be in library.
#define HAVE_INLINE

/* Define if you need to hide the static definitions of inline functions */
//#undef HIDE_INLINE_STATIC
// TFB flipping this for VC6
#define HIDE_INLINE_STATIC

/* Defined if you have ansi EXIT_SUCCESS and EXIT_FAILURE in stdlib.h */
#define HAVE_EXIT_SUCCESS_AND_FAILURE 1

/* Use 0 and 1 for EXIT_SUCCESS and EXIT_FAILURE if we don't have them */
#if !HAVE_EXIT_SUCCESS_AND_FAILURE
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#endif

/* Define this if printf can handle %Lf for long double */
#undef HAVE_PRINTF_LONGDOUBLE

/* Define one of these if you have a known IEEE arithmetic interface */
#undef HAVE_GNUSPARC_IEEE_INTERFACE
#undef HAVE_GNUM68K_IEEE_INTERFACE
#undef HAVE_GNUPPC_IEEE_INTERFACE
#undef HAVE_GNUX86_IEEE_INTERFACE
#undef HAVE_SUNOS4_IEEE_INTERFACE
#undef HAVE_SOLARIS_IEEE_INTERFACE
#undef HAVE_HPUX11_IEEE_INTERFACE
#undef HAVE_HPUX_IEEE_INTERFACE
#undef HAVE_TRU64_IEEE_INTERFACE
#undef HAVE_IRIX_IEEE_INTERFACE
#undef HAVE_AIX_IEEE_INTERFACE
#undef HAVE_FREEBSD_IEEE_INTERFACE
#undef HAVE_OS2EMX_IEEE_INTERFACE
#undef HAVE_NETBSD_IEEE_INTERFACE
#undef HAVE_OPENBSD_IEEE_INTERFACE
#undef HAVE_DARWIN_IEEE_INTERFACE

/* Define this is IEEE comparisons work correctly (e.g. NaN != NaN) */
#define HAVE_IEEE_COMPARISONS 1

/* Define this is IEEE denormalized numbers are available */
#define HAVE_IEEE_DENORMALS 1

/* Define a rounding function which moves extended precision values
   out of registers and rounds them to double-precision. This should
   be used *sparingly*, in places where it is necessary to keep
   double-precision rounding for critical expressions while running in
   extended precision. For example, the following code should ensure
   exact equality, even when extended precision registers are in use,

      double q = GSL_COERCE_DBL(3.0/7.0) ;
      if (q == GSL_COERCE_DBL(3.0/7.0)) { ... } ;

   It carries a penalty even when the program is running in double
   precision mode unless you compile a separate version of the
   library with HAVE_EXTENDED_PRECISION_REGISTERS turned off. */

#undef HAVE_EXTENDED_PRECISION_REGISTERS

#if HAVE_EXTENDED_PRECISION_REGISTERS
#define GSL_COERCE_DBL(x) (gsl_coerce_double(x))
#else
#define GSL_COERCE_DBL(x) (x)
#endif

/* Substitute gsl functions for missing system functions */

#if !HAVE_DECL_HYPOT
#define hypot gsl_hypot
#endif

#if !HAVE_DECL_LOG1P
#define log1p gsl_log1p
#endif

#if !HAVE_DECL_EXPM1
#define expm1 gsl_expm1
#endif

#if !HAVE_DECL_ACOSH
#define acosh gsl_acosh
#endif

#if !HAVE_DECL_ASINH
#define asinh gsl_asinh
#endif

#if !HAVE_DECL_ATANH
#define atanh gsl_atanh
#endif

#if !HAVE_DECL_LDEXP
#define ldexp gsl_ldexp
#endif

#if !HAVE_DECL_FREXP
#define frexp gsl_frexp
#endif

#if !HAVE_DECL_ISINF
#define isinf gsl_isinf
#endif

#if !HAVE_DECL_FINITE
#if HAVE_DECL_ISFINITE
#define finite isfinite
#else
#define finite gsl_finite
#endif
#endif

#if !HAVE_DECL_ISNAN
#define isnan gsl_isnan
#endif

#ifdef __GNUC__
#define DISCARD_POINTER(p) do { ; } while(p ? 0 : 0);
#else
#define DISCARD_POINTER(p) /* ignoring discarded pointer */
#endif

#if defined(GSL_RANGE_CHECK_OFF) || !defined(GSL_RANGE_CHECK)
#define GSL_RANGE_CHECK 0  /* turn off range checking by default internally */
#endif

/* Disable deprecated functions and enums while building */
#define GSL_DISABLE_DEPRECATED 1

#endif  /* CONFIG_H_SEEN */
