#include "blaswrap.h"
#include "f2c.h"

/* Subroutine */ int cgehrd_(integer *n, integer *ilo, integer *ihi, complex *
	a, integer *lda, complex *tau, complex *work, integer *lwork, integer 
	*info)
{
/*  -- LAPACK routine (version 3.0) --   
       Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,   
       Courant Institute, Argonne National Lab, and Rice University   
       June 30, 1999   


    Purpose   
    =======   

    CGEHRD reduces a complex general matrix A to upper Hessenberg form H   
    by a unitary similarity transformation:  Q' * A * Q = H .   

    Arguments   
    =========   

    N       (input) INTEGER   
            The order of the matrix A.  N >= 0.   

    ILO     (input) INTEGER   
    IHI     (input) INTEGER   
            It is assumed that A is already upper triangular in rows   
            and columns 1:ILO-1 and IHI+1:N. ILO and IHI are normally   
            set by a previous call to CGEBAL; otherwise they should be   
            set to 1 and N respectively. See Further Details.   
            1 <= ILO <= IHI <= N, if N > 0; ILO=1 and IHI=0, if N=0.   

    A       (input/output) COMPLEX array, dimension (LDA,N)   
            On entry, the N-by-N general matrix to be reduced.   
            On exit, the upper triangle and the first subdiagonal of A   
            are overwritten with the upper Hessenberg matrix H, and the   
            elements below the first subdiagonal, with the array TAU,   
            represent the unitary matrix Q as a product of elementary   
            reflectors. See Further Details.   

    LDA     (input) INTEGER   
            The leading dimension of the array A.  LDA >= max(1,N).   

    TAU     (output) COMPLEX array, dimension (N-1)   
            The scalar factors of the elementary reflectors (see Further   
            Details). Elements 1:ILO-1 and IHI:N-1 of TAU are set to   
            zero.   

    WORK    (workspace/output) COMPLEX array, dimension (LWORK)   
            On exit, if INFO = 0, WORK(1) returns the optimal LWORK.   

    LWORK   (input) INTEGER   
            The length of the array WORK.  LWORK >= max(1,N).   
            For optimum performance LWORK >= N*NB, where NB is the   
            optimal blocksize.   

            If LWORK = -1, then a workspace query is assumed; the routine   
            only calculates the optimal size of the WORK array, returns   
            this value as the first entry of the WORK array, and no error   
            message related to LWORK is issued by XERBLA.   

    INFO    (output) INTEGER   
            = 0:  successful exit   
            < 0:  if INFO = -i, the i-th argument had an illegal value.   

    Further Details   
    ===============   

    The matrix Q is represented as a product of (ihi-ilo) elementary   
    reflectors   

       Q = H(ilo) H(ilo+1) . . . H(ihi-1).   

    Each H(i) has the form   

       H(i) = I - tau * v * v'   

    where tau is a complex scalar, and v is a complex vector with   
    v(1:i) = 0, v(i+1) = 1 and v(ihi+1:n) = 0; v(i+2:ihi) is stored on   
    exit in A(i+2:ihi,i), and tau in TAU(i).   

    The contents of A are illustrated by the following example, with   
    n = 7, ilo = 2 and ihi = 6:   

    on entry,                        on exit,   

    ( a   a   a   a   a   a   a )    (  a   a   h   h   h   h   a )   
    (     a   a   a   a   a   a )    (      a   h   h   h   h   a )   
    (     a   a   a   a   a   a )    (      h   h   h   h   h   h )   
    (     a   a   a   a   a   a )    (      v2  h   h   h   h   h )   
    (     a   a   a   a   a   a )    (      v2  v3  h   h   h   h )   
    (     a   a   a   a   a   a )    (      v2  v3  v4  h   h   h )   
    (                         a )    (                          a )   

    where a denotes an element of the original matrix A, h denotes a   
    modified element of the upper Hessenberg matrix H, and vi denotes an   
    element of the vector defining H(i).   

    =====================================================================   


       Test the input parameters   

       Parameter adjustments */
    /* Table of constant values */
    static complex c_b2 = {1.f,0.f};
    static integer c__1 = 1;
    static integer c_n1 = -1;
    static integer c__3 = 3;
    static integer c__2 = 2;
    static integer c__65 = 65;
    
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4;
    complex q__1;
    /* Local variables */
    static integer i__;
    static complex t[4160]	/* was [65][64] */;
    extern /* Subroutine */ int cgemm_(char *, char *, integer *, integer *, 
	    integer *, complex *, complex *, integer *, complex *, integer *, 
	    complex *, complex *, integer *);
    static integer nbmin, iinfo;
    extern /* Subroutine */ int cgehd2_(integer *, integer *, integer *, 
	    complex *, integer *, complex *, complex *, integer *);
    static integer ib;
    static complex ei;
    static integer nb, nh;
    extern /* Subroutine */ int clarfb_(char *, char *, char *, char *, 
	    integer *, integer *, integer *, complex *, integer *, complex *, 
	    integer *, complex *, integer *, complex *, integer *), clahrd_(integer *, integer *, integer *, 
	    complex *, integer *, complex *, complex *, integer *, complex *, 
	    integer *);
    static integer nx;
    extern /* Subroutine */ int xerbla_(char *, integer *);
    extern integer ilaenv_(integer *, char *, char *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    static integer ldwork, lwkopt;
    static logical lquery;
    static integer iws;
#define a_subscr(a_1,a_2) (a_2)*a_dim1 + a_1
#define a_ref(a_1,a_2) a[a_subscr(a_1,a_2)]


    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --tau;
    --work;

    /* Function Body */
    *info = 0;
/* Computing MIN */
    i__1 = 64, i__2 = ilaenv_(&c__1, "CGEHRD", " ", n, ilo, ihi, &c_n1, (
	    ftnlen)6, (ftnlen)1);
    nb = min(i__1,i__2);
    lwkopt = *n * nb;
    work[1].r = (real) lwkopt, work[1].i = 0.f;
    lquery = *lwork == -1;
    if (*n < 0) {
	*info = -1;
    } else if (*ilo < 1 || *ilo > max(1,*n)) {
	*info = -2;
    } else if (*ihi < min(*ilo,*n) || *ihi > *n) {
	*info = -3;
    } else if (*lda < max(1,*n)) {
	*info = -5;
    } else if (*lwork < max(1,*n) && ! lquery) {
	*info = -8;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("CGEHRD", &i__1);
	return 0;
    } else if (lquery) {
	return 0;
    }

/*     Set elements 1:ILO-1 and IHI:N-1 of TAU to zero */

    i__1 = *ilo - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	tau[i__2].r = 0.f, tau[i__2].i = 0.f;
/* L10: */
    }
    i__1 = *n - 1;
    for (i__ = max(1,*ihi); i__ <= i__1; ++i__) {
	i__2 = i__;
	tau[i__2].r = 0.f, tau[i__2].i = 0.f;
/* L20: */
    }

/*     Quick return if possible */

    nh = *ihi - *ilo + 1;
    if (nh <= 1) {
	work[1].r = 1.f, work[1].i = 0.f;
	return 0;
    }

    nbmin = 2;
    iws = 1;
    if (nb > 1 && nb < nh) {

/*        Determine when to cross over from blocked to unblocked code   
          (last block is always handled by unblocked code).   

   Computing MAX */
	i__1 = nb, i__2 = ilaenv_(&c__3, "CGEHRD", " ", n, ilo, ihi, &c_n1, (
		ftnlen)6, (ftnlen)1);
	nx = max(i__1,i__2);
	if (nx < nh) {

/*           Determine if workspace is large enough for blocked code. */

	    iws = *n * nb;
	    if (*lwork < iws) {

/*              Not enough workspace to use optimal NB:  determine the   
                minimum value of NB, and reduce NB or force use of   
                unblocked code.   

   Computing MAX */
		i__1 = 2, i__2 = ilaenv_(&c__2, "CGEHRD", " ", n, ilo, ihi, &
			c_n1, (ftnlen)6, (ftnlen)1);
		nbmin = max(i__1,i__2);
		if (*lwork >= *n * nbmin) {
		    nb = *lwork / *n;
		} else {
		    nb = 1;
		}
	    }
	}
    }
    ldwork = *n;

    if (nb < nbmin || nb >= nh) {

/*        Use unblocked code below */

	i__ = *ilo;

    } else {

/*        Use blocked code */

	i__1 = *ihi - 1 - nx;
	i__2 = nb;
	for (i__ = *ilo; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
/* Computing MIN */
	    i__3 = nb, i__4 = *ihi - i__;
	    ib = min(i__3,i__4);

/*           Reduce columns i:i+ib-1 to Hessenberg form, returning the   
             matrices V and T of the block reflector H = I - V*T*V'   
             which performs the reduction, and also the matrix Y = A*V*T */

	    clahrd_(ihi, &i__, &ib, &a_ref(1, i__), lda, &tau[i__], t, &c__65,
		     &work[1], &ldwork);

/*           Apply the block reflector H to A(1:ihi,i+ib:ihi) from the   
             right, computing  A := A - Y * V'. V(i+ib,ib-1) must be set   
             to 1. */

	    i__3 = a_subscr(i__ + ib, i__ + ib - 1);
	    ei.r = a[i__3].r, ei.i = a[i__3].i;
	    i__3 = a_subscr(i__ + ib, i__ + ib - 1);
	    a[i__3].r = 1.f, a[i__3].i = 0.f;
	    i__3 = *ihi - i__ - ib + 1;
	    q__1.r = -1.f, q__1.i = 0.f;
	    cgemm_("No transpose", "Conjugate transpose", ihi, &i__3, &ib, &
		    q__1, &work[1], &ldwork, &a_ref(i__ + ib, i__), lda, &
		    c_b2, &a_ref(1, i__ + ib), lda);
	    i__3 = a_subscr(i__ + ib, i__ + ib - 1);
	    a[i__3].r = ei.r, a[i__3].i = ei.i;

/*           Apply the block reflector H to A(i+1:ihi,i+ib:n) from the   
             left */

	    i__3 = *ihi - i__;
	    i__4 = *n - i__ - ib + 1;
	    clarfb_("Left", "Conjugate transpose", "Forward", "Columnwise", &
		    i__3, &i__4, &ib, &a_ref(i__ + 1, i__), lda, t, &c__65, &
		    a_ref(i__ + 1, i__ + ib), lda, &work[1], &ldwork);
/* L30: */
	}
    }

/*     Use unblocked code to reduce the rest of the matrix */

    cgehd2_(n, &i__, ihi, &a[a_offset], lda, &tau[1], &work[1], &iinfo);
    work[1].r = (real) iws, work[1].i = 0.f;

    return 0;

/*     End of CGEHRD */

} /* cgehrd_ */

#undef a_ref
#undef a_subscr


