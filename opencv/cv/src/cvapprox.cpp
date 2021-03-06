/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                        Intel License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000, Intel Corporation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of Intel Corporation may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/
#include "_cv.h"
#include <limits.h>
#include "_cvwrap.h"
#include "_cvdatastructs.h"

/****************************************************************************************\
*                                  Chain Approximation                                   *
\****************************************************************************************/

typedef struct _CvPtInfo
{
    CvPoint pt;
    int k;                      /* support region */
    int s;                      /* curvature value */
    struct _CvPtInfo *next;
}
_CvPtInfo;


/* curvature: 0 - 1-curvature, 1 - k-cosine curvature. */
CvStatus
icvApproximateChainTC89( CvChain*               chain,
                         int                    header_size,
                         CvMemStorage*          storage, 
                         CvSeq**                contour, 
                         CvChainApproxMethod    method )
{
    static const int abs_diff[] = { 1, 2, 3, 4, 3, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1 };

    char            local_buffer[1 << 16];
    char*           buffer = local_buffer;
    int             buffer_size;

    _CvPtInfo       temp;
    _CvPtInfo       *array, *first = 0, *current = 0, *prev_current = 0;
    int             i, j, i1, i2, s, len;
    int             count;

    CvChainPtReader reader;
    CvSeqWriter     writer;
    CvPoint         pt = chain->origin;
   
    assert( chain && contour && buffer );

    buffer_size = (chain->total + 8) * sizeof( _CvPtInfo );

    *contour = 0;

    if( !CV_IS_SEQ_CHAIN_CONTOUR( chain ))
        return CV_BADFLAG_ERR;

    if( header_size < (int)sizeof(CvContour) )
        return CV_BADSIZE_ERR;
    
    cvStartWriteSeq( (chain->flags & ~CV_SEQ_ELTYPE_MASK) | CV_SEQ_ELTYPE_POINT,
                     header_size, sizeof( CvPoint ), storage, &writer );
    
    if( chain->total == 0 )
    {        
        CV_WRITE_SEQ_ELEM( pt, writer );
        goto exit_function;
    }

    cvStartReadChainPoints( chain, &reader );

    if( method > CV_CHAIN_APPROX_SIMPLE && buffer_size > (int)sizeof(local_buffer))
    {
        buffer = (char *) icvAlloc( buffer_size );
        if( !buffer )
            return CV_OUTOFMEM_ERR;
    }

    array = (_CvPtInfo *) buffer;
    count = chain->total;

    temp.next = 0;
    current = &temp;

    /* Pass 0.
       Restores all the digital curve points from the chain code.
       Removes the points (from the resultant polygon)
       that have zero 1-curvature */
    for( i = 0; i < count; i++ )
    {
        int s, prev_code = *reader.prev_elem;

        reader.prev_elem = reader.ptr;
        CV_READ_CHAIN_POINT( pt, reader );

        /* calc 1-curvature */
        s = abs_diff[reader.code - prev_code + 7];

        if( method <= CV_CHAIN_APPROX_SIMPLE )
        {
            if( method == CV_CHAIN_APPROX_NONE || s != 0 )
            {
                CV_WRITE_SEQ_ELEM( pt, writer );
            }
        }
        else
        {
            if( s != 0 )
                current = current->next = array + i;
            array[i].s = s;
            array[i].pt = pt;
        }
    }

    //assert( pt.x == chain->origin.x && pt.y == chain->origin.y );

    if( method <= CV_CHAIN_APPROX_SIMPLE )
        goto exit_function;

    current->next = 0;

    len = i;
    current = temp.next;

    assert( current );

    /* Pass 1.
       Determines support region for all the remained points */
    do
    {
        CvPoint pt0;
        int k, l = 0, d_num = 0;

        i = current - array;
        pt0 = array[i].pt;

        /* determine support region */
        for( k = 1;; k++ )
        {
            int lk, dk_num;
            int dx, dy;
            int di;
            float d;

            assert( k <= len );

            /* calc indices */
            i1 = i - k;
            i1 += i1 < 0 ? len : 0;
            i2 = i + k;
            i2 -= i2 >= len ? len : 0;

            dx = array[i2].pt.x - array[i1].pt.x;
            dy = array[i2].pt.y - array[i1].pt.y;

            /* distance between p_(i - k) and p_(i + k) */
            lk = dx * dx + dy * dy;

            /* distance between p_i and the line (p_(i-k), p_(i+k)) */
            dk_num = (pt0.x - array[i1].pt.x) * dy - (pt0.y - array[i1].pt.y) * dx;
            d = (float) (((double) d_num) * lk - ((double) dk_num) * l);
            di = *(int *) &d;

            if( k > 1 && (l >= lk || (d_num > 0 && di <= 0 || d_num < 0 && di >= 0)))
                break;

            d_num = dk_num;
            l = lk;
        }

        current->k = --k;

        /* determine cosine curvature if it should be used */
        if( method == CV_CHAIN_APPROX_TC89_KCOS )
        {
            /* calc k-cosine curvature */
            for( j = k, s = 0; j > 0; j-- )
            {
                double temp_num;
                float temp;
                int sk;
                int dx1, dy1, dx2, dy2;

                i1 = i - j;
                i1 += i1 < 0 ? len : 0;
                i2 = i + j;
                i2 -= i2 >= len ? len : 0;

                dx1 = array[i1].pt.x - pt0.x;
                dy1 = array[i1].pt.y - pt0.y;
                dx2 = array[i2].pt.x - pt0.x;
                dy2 = array[i2].pt.y - pt0.y;

                if( (dx1 | dy1) == 0 || (dx2 | dy2) == 0 )
                    break;

                temp_num = dx1 * dx2 + dy1 * dy2;
                temp_num =
                    (float) (temp_num /
                             sqrt( (dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) ));
                temp = (float) (temp_num + 1.1);
                sk = *((int *) &temp);

                assert( 0 <= temp && temp <= 2.2 );
                if( j < k && sk <= s )
                    break;

                s = sk;
            }
            current->s = s;
        }
        current = current->next;
    }
    while( current != 0 );

    prev_current = &temp;
    current = temp.next;

    /* Pass 2.
       Performs non-maxima supression */
    do
    {
        int k2 = current->k >> 1;

        s = current->s;
        i = current - array;

        for( j = 1; j <= k2; j++ )
        {
            i2 = i - j;
            i2 += i2 < 0 ? len : 0;

            if( array[i2].s > s )
                break;

            i2 = i + j;
            i2 -= i2 >= len ? len : 0;

            if( array[i2].s > s )
                break;
        }

        if( j <= k2 )           /* exclude point */
        {
            prev_current->next = current->next;
            current->s = 0;     /* "clear" point */
        }
        else
            prev_current = current;
        current = current->next;
    }
    while( current != 0 );

    /* Pass 3.
       Removes non-dominant points with 1-length support region */
    current = temp.next;
    assert( current );
    prev_current = &temp;

    do
    {
        if( current->k == 1 )
        {
            s = current->s;
            i = current - array;

            i1 = i - 1;
            i1 += i1 < 0 ? len : 0;

            i2 = i + 1;
            i2 -= i2 >= len ? len : 0;

            if( s <= array[i1].s || s <= array[i2].s )
            {
                prev_current->next = current->next;
                current->s = 0;
            }
            else
                prev_current = current;
        }
        else
            prev_current = current;
        current = current->next;
    }
    while( current != 0 );

    if( method == CV_CHAIN_APPROX_TC89_KCOS )
        goto copy_vect;

    /* Pass 4.
       Cleans remained couples of points */
    assert( temp.next );

    if( array[0].s != 0 && array[len - 1].s != 0 )      /* specific case */
    {
        for( i1 = 1; i1 < len && array[i1].s != 0; i1++ )
        {
            array[i1 - 1].s = 0;
        }
        if( i1 == len )
            goto copy_vect;     /* all points survived */
        i1--;

        for( i2 = len - 2; i2 > 0 && array[i2].s != 0; i2-- )
        {
            array[i2].next = 0;
            array[i2 + 1].s = 0;
        }
        i2++;

        if( i1 == 0 && i2 == len - 1 )  /* only two points */
        {
            i1 = array[0].next - array;
            array[len] = array[0];      /* move to the end */
            array[len].next = 0;
            array[len - 1].next = array + len;
        }
        temp.next = array + i1;
    }

    current = temp.next;
    first = prev_current = &temp;
    count = 1;

    /* do last pass */
    do
    {
        if( current->next == 0 || current->next - current != 1 )
        {
            if( count >= 2 )
            {
                if( count == 2 )
                {
                    int s1 = prev_current->s;
                    int s2 = current->s;

                    if( s1 > s2 || s1 == s2 && prev_current->k <= current->k )
                        /* remove second */
                        prev_current->next = current->next;
                    else
                        /* remove first */
                        first->next = current;
                }
                else
                    first->next->next = current;
            }
            first = current;
            count = 1;
        }
        else
            count++;
        prev_current = current;
        current = current->next;
    }
    while( current != 0 );

  copy_vect:

    /* gather points */
    current = temp.next;
    assert( current );

    do
    {
        CvPoint pt = current->pt;

        CV_WRITE_SEQ_ELEM( pt, writer );
        current = current->next;
    }
    while( current != 0 );

exit_function:

    *contour = cvEndWriteSeq( &writer );

    assert( writer.seq->total > 0 );

    if( buffer != local_buffer )
        icvFree( &buffer );
    return CV_OK;
}


/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name: cvApproxChains
//    Purpose:
//      Applies some approximation algorithm to chain-coded contour(s) and
//      converts it/them to polygonal representation.
//    Context:
//    Parameters:
//      src_seq  - pointer to source contour(s).
//                 Each contour is chain-coded or "vertex-coded".
//      storage  - storage to store approximated contours
//      dst_seq  - pointer to resultant contour(s) pointer.
//                 Each resultant contour is coded by sequence of vertices.
//      contours - pointer to output contour object.
//      method   - approximation method (see CvChainApproxMethod
//                                       declaration for details).
//      parameter - some parameter for approximation method
//                  (is not used by existing methods)
//      minimal_perimeter - it is the limit below which a chain 
//                          together with its children is not
//                          translated to contours (i.e. skipped )
//      recursive - if != 0, process not only the passed contour but all the tree.
//    Returns:
//      CV_OK or error code
//    Notes:
//F*/
CV_IMPL CvSeq*
cvApproxChains( CvSeq*              src_seq,
                CvMemStorage*       storage,
                CvChainApproxMethod method,
                double              /*parameter*/, 
                int                 minimal_perimeter, 
                int                 recursive )
{
    CvSeq *prev_contour = 0, *parent = 0;
    CvSeq *dst_seq = 0;
    
    CV_FUNCNAME( "cvApproxChains" );

    __BEGIN__;

    if( !src_seq || !storage )
        CV_ERROR_FROM_STATUS( CV_NULLPTR_ERR );
    if( method > CV_CHAIN_APPROX_TC89_KCOS || method <= 0 || minimal_perimeter < 0 )
        CV_ERROR_FROM_STATUS( CV_BADRANGE_ERR );

    while( src_seq != 0 )
    {
        int len = src_seq->total;

        if( len >= minimal_perimeter )
        {
            CvSeq *contour;
            
            switch( method )
            {
            case CV_CHAIN_APPROX_NONE:
            case CV_CHAIN_APPROX_SIMPLE:
            case CV_CHAIN_APPROX_TC89_L1:
            case CV_CHAIN_APPROX_TC89_KCOS:
                IPPI_CALL( icvApproximateChainTC89( (CvChain *) src_seq,
                                                    sizeof( CvContour ), storage,
                                                    (CvSeq**)&contour, method ));
                break;
            default:
                assert(0);
                CV_ERROR_FROM_STATUS( CV_BADRANGE_ERR );
            }

            assert( contour );

            if( contour->total > 0 )
            {
                cvContourBoundingRect( contour, 1 );

                contour->v_prev = parent;
                contour->h_prev = prev_contour;

                if( prev_contour )
                    prev_contour->h_next = contour;
                else if( parent )
                    parent->v_next = contour;
                prev_contour = contour;
                if( !dst_seq )
                    dst_seq = prev_contour;
            }
            else                /* if resultant contour has zero length, skip it */
            {
                len = -1;
            }
        }

        if( !recursive )
            break;

        if( src_seq->v_next && len >= minimal_perimeter )
        {
            assert( prev_contour != 0 );
            parent = prev_contour;
            prev_contour = 0;
            src_seq = src_seq->v_next;
        }
        else
        {
            while( src_seq->h_next == 0 )
            {
                src_seq = src_seq->v_prev;
                if( src_seq == 0 )
                    break;
                prev_contour = parent;
                if( parent )
                    parent = parent->v_prev;
            }
            if( src_seq )
                src_seq = src_seq->h_next;
        }
    }

    __END__;

    return dst_seq;
}


/****************************************************************************************\
*                               Polygonal Approximation                                  *
\****************************************************************************************/


/* Ramer-Douglas-Peucker algorithm for polygon simplification */
static CvStatus
icvApproxPolyDP( CvSeq*             src_contour,
                 int                header_size, 
                 CvMemStorage*      storage, 
                 CvSeq**            dst_contour, 
                 float              eps )
{
    const int       init_iters = 2;
    CvSlice         slice = {0, 0}, right_slice = {0, 0};
    CvSeqReader     reader;
    CvSeqWriter     writer;
    CvPoint         start_pt = {INT_MIN, INT_MIN}, end_pt = { 0, 0 }, pt;
    int             count;
    int             i = 0;
    int             is_closed;
    int             max_dist = 0;
    CvMemStorage*   temp_storage = 0;
    CvSeq*          stack = 0;    
    
    if( !src_contour || !dst_contour || !storage )
        return CV_NULLPTR_ERR;

    if( !CV_IS_SEQ_POLYLINE( src_contour ))
        return CV_BADFLAG_ERR;

    if( src_contour->total == 0  )
        return CV_BADSIZE_ERR;

    if( eps < 0 )
        return CV_BADRANGE_ERR;

    if( header_size < (int)sizeof(CvContour) )
        return CV_BADSIZE_ERR;

    temp_storage = cvCreateChildMemStorage( storage );

    cvStartWriteSeq( src_contour->flags, header_size, 
                     sizeof( CvPoint ), storage, &writer );

    assert( src_contour->first != 0 );
    stack = cvCreateSeq( 0, sizeof( CvSeq ), sizeof( CvSlice ), temp_storage );
    eps *= eps;
    
    cvStartReadSeq( src_contour, &reader, 0 );
    count = src_contour->total;
    is_closed = CV_IS_SEQ_CLOSED( src_contour );
    
    if( is_closed )
    {
        /* 1. Find approximately the two farthest points of the contour */
        right_slice.startIndex = 0;

        for( i = 0; i < init_iters; i++ )
        {
            int j;

            cvSetSeqReaderPos( &reader, right_slice.startIndex, 1 );
            CV_READ_SEQ_ELEM( start_pt, reader );   /* read the first point */

            max_dist = 0;
            for( j = 1; j < count; j++ )
            {
                int dx, dy, dist;

                CV_READ_SEQ_ELEM( pt, reader );
                dx = pt.x - start_pt.x;
                dy = pt.y - start_pt.y;

                dist = dx * dx + dy * dy;

                if( dist > max_dist )
                {
                    max_dist = dist;
                    right_slice.startIndex = j;
                }
            }
        }

        /* 2. initialize the stack */
        if( max_dist > eps )
        {
            slice.startIndex = cvGetSeqReaderPos( &reader );
            slice.endIndex = right_slice.startIndex += slice.startIndex;

            right_slice.startIndex -= right_slice.startIndex >= count ? count : 0;
            right_slice.endIndex = slice.startIndex;
            if( right_slice.endIndex < right_slice.startIndex )
                right_slice.endIndex += count;

            cvSeqPush( stack, &right_slice );
            cvSeqPush( stack, &slice );
        }
        else
        {
            CV_WRITE_SEQ_ELEM( start_pt, writer );        
        }
    }
    else
    {
        int dx, dy; 
        
        right_slice.startIndex = count;
        end_pt = *(CvPoint*)(reader.ptr);
        start_pt = *(CvPoint*)cvGetSeqElem( src_contour, -1, 0 );

        dx = end_pt.x - start_pt.x;
        dy = end_pt.y - start_pt.y;
        max_dist = dx * dx + dy * dy;

        if( max_dist > eps )
        {
            slice.startIndex = 0;
            slice.endIndex = count - 1;
            cvSeqPush( stack, &slice );
        }
    }

    /* 3. run recursive process */
    while( stack->total != 0 )
    {
        int dx, dy;
        int lt_eps;

        max_dist = 0;

        cvSeqPop( stack, &slice );

        assert( slice.startIndex < slice.endIndex );

        if( slice.endIndex - slice.startIndex != 1 )
        {
            cvSetSeqReaderPos( &reader, slice.endIndex );
            CV_READ_SEQ_ELEM( end_pt, reader );

            cvSetSeqReaderPos( &reader, slice.startIndex );
            CV_READ_SEQ_ELEM( start_pt, reader );

            dx = end_pt.x - start_pt.x;
            dy = end_pt.y - start_pt.y;

            assert( (dx | dy) != 0 );

            for( i = slice.startIndex + 1; i < slice.endIndex; i++ )
            {
                int dist;

                CV_READ_SEQ_ELEM( pt, reader );

                dist = (pt.y - start_pt.y) * dx - (pt.x - start_pt.x) * dy;
                dist = CV_IABS( dist );

                if( dist > max_dist )
                {
                    max_dist = dist;
                    right_slice.startIndex = i;
                }
            }

            lt_eps = (double)max_dist * max_dist <= eps * ((double)dx * dx + (double)dy * dy);
        }
        else
        {
            lt_eps = 1;
            /* read starting point */
            cvSetSeqReaderPos( &reader, slice.startIndex );
            CV_READ_SEQ_ELEM( start_pt, reader );
        }

        assert( stack->total < src_contour->total * 2 );

        if( lt_eps )
        {
            CV_WRITE_SEQ_ELEM( start_pt, writer );
        }
        else
        {
            right_slice.endIndex = slice.endIndex;
            slice.endIndex = right_slice.startIndex;
            cvSeqPush( stack, &right_slice );
            cvSeqPush( stack, &slice );
        }
    }

    if( !is_closed )
    {
        CV_WRITE_SEQ_ELEM( end_pt, writer );
    }

    *dst_contour = cvEndWriteSeq( &writer );
    cvReleaseMemStorage( &temp_storage );

    return CV_OK;
}


CV_IMPL CvSeq*
cvApproxPoly( CvSeq*  src_seq, int  header_size,
              CvMemStorage*  storage,
              CvPolyApproxMethod  method, 
              double  parameter, int recursive)
{
    CvSeq* dst_seq = 0;
    CvSeq *prev_contour = 0, *parent = 0;
    
    CV_FUNCNAME( "cvApproxPoly" );

    __BEGIN__;

    if( !src_seq || !storage )
        CV_ERROR_FROM_STATUS( CV_NULLPTR_ERR );

    if( method != CV_POLY_APPROX_DP )
        CV_ERROR_FROM_STATUS( CV_BADRANGE_ERR );

    while( src_seq != 0 )
    {
        CvSeq *contour = 0;

        switch (method)
        {
        case CV_POLY_APPROX_DP:
            IPPI_CALL( icvApproxPolyDP( src_seq, header_size,
                                        storage, &contour, (float)parameter ));
            break;
        default:
            assert(0);
            CV_ERROR( IPL_StsBadArg, "Invalid approximation method" );
        }

        assert( contour );

        if( contour->total > 0 )
        {
            cvContourBoundingRect( contour, 1 );

            contour->v_prev = parent;
            contour->h_prev = prev_contour;

            if( prev_contour )
                prev_contour->h_next = contour;
            else if( parent )
                parent->v_next = contour;
            prev_contour = contour;
            if( !dst_seq )
                dst_seq = prev_contour;
        }

        if( !recursive )
            break;

        if( src_seq->v_next && contour->total > 0 )
        {
            assert( prev_contour != 0 );
            parent = prev_contour;
            prev_contour = 0;
            src_seq = src_seq->v_next;
        }
        else
        {
            while( src_seq->h_next == 0 )
            {
                src_seq = src_seq->v_prev;
                if( src_seq == 0 )
                    break;
                prev_contour = parent;
                if( parent )
                    parent = parent->v_prev;
            }
            if( src_seq )
                src_seq = src_seq->h_next;
        }
    }

    __END__;

    return dst_seq;
}

/* End of file. */
