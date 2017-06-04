/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision$
 ***********************************************************************EHEADER*/



#include "hypre_lapack.h"
#include "f2c.h"

#define log10e 0.43429448190325182765

#ifdef KR_headers
HYPRE_Real log();
HYPRE_Real d_lg10(x) doublereal *x;
#else
/*
#undef abs
#include "math.h"
*/
/*FIXME: need to figure out how log calls to optimize this part*/
#include "math.h"					 
//HYPRE_Real log(HYPRE_Real); /* declaration added 2/17/00 */
HYPRE_Real d_lg10(doublereal *x)
#endif
{
return( log10e * log(*x) );
}
#include "f2c.h"

#ifdef KR_headers
HYPRE_Real d_sign(a,b) doublereal *a, *b;
#else
HYPRE_Real d_sign(doublereal *a, doublereal *b)
#endif
{
HYPRE_Real x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}

#include "f2c.h"

#ifdef KR_headers
HYPRE_Real pow_di(ap, bp) doublereal *ap; integer *bp;
#else
HYPRE_Real pow_di(doublereal *ap, integer *bp)
#endif
{
HYPRE_Real pow, x;
integer n;

pow = 1;
x = *ap;
n = *bp;

if(n != 0)
	{
	if(n < 0)
		{
		n = -n;
		x = 1/x;
		}
	for( ; ; )
		{
		if(n & 01)
			pow *= x;
		if(n >>= 1)
			x *= x;
		else
			break;
		}
	}
return(pow);
}
#include "f2c.h"

#ifdef KR_headers
HYPRE_Real pow();
HYPRE_Real pow_dd(ap, bp) doublereal *ap, *bp;
#else
#undef abs
#include "math.h"
HYPRE_Real pow_dd(doublereal *ap, doublereal *bp)
#endif
{
return(pow(*ap, *bp) );
}

#include "f2c.h"

#ifdef KR_headers
HYPRE_Int s_cat(lp, rpp, rnp, np, ll) char *lp, *rpp[]; ftnlen rnp[], *np, ll;
#else
HYPRE_Int s_cat(char *lp, char *rpp[], ftnlen rnp[], ftnlen *np, ftnlen ll)
#endif
{
ftnlen i, n, nc;
char *f__rp;

n = (HYPRE_Int)*np;
for(i = 0 ; i < n ; ++i)
	{
	nc = ll;
	if(rnp[i] < nc)
		nc = rnp[i];
	ll -= nc;
	f__rp = rpp[i];
	while(--nc >= 0)
		*lp++ = *f__rp++;
	}
while(--ll >= 0)
	*lp++ = ' ';
return 0;
}
