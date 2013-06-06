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

#ifndef __CVERROR_H_
#define __CVERROR_H_

#include "cverror.h"

typedef struct _CvContext
{
    CVStatus        CVLastStatus;
    int             CVErrMode;
    CVErrorCallBack CVErrorFunc;
    CvStackRecord*  CVStack;
    int             CVStackSize;
    int             CVStackCapacity;
    
} CvContext;

OPENCVAPI void icvInitContext(CvContext* context);
OPENCVAPI void icvDestroyContext(CvContext* context);
OPENCVAPI CvContext* icvGetContext();


#define CV_ERROR_FROM_STATUS( result )                \
    CV_ERROR( icvErrorFromStatus( result ), "OpenCV function failed" )

#define IPPI_CALL( Func )                                              \
{                                                                      \
      CvStatus  ippi_call_result;                                      \
      CV_START_CALL( #Func, __FILE__, __LINE__ );                      \
      ippi_call_result = Func;                                         \
      CV_END_CALL( __FILE__, __LINE__ );                               \
                                                                       \
      if( ippi_call_result < 0 )                                       \
            CV_ERROR_FROM_STATUS( (ippi_call_result));                 \
}

#define icvUnsupportedFormat  "Unsupported format"
#define icvCvErrMsg "icv function failed"

#endif/*__CVERROR_H_*/

/* End of file. */

