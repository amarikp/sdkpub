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

#ifndef __OPTCV_H_
#define __OPTCV_H_

/****************************************************************************************\
*                               Allocation/Deallocation                                  *
\****************************************************************************************/

IPCVAPI( void*, icvAllocEx, ( int size, const char* file, int line  ))
IPCVAPI( CVStatus, icvFreeEx, ( void** ptr, const char* file, int line ))

/****************************************************************************************\
*                                         AbsDiff                                        *
\****************************************************************************************/

#define IPCV_ABS_DIFF( flavor, arrtype, scalartype )                                \
IPCVAPI( CvStatus, icvAbsDiffC_##flavor##_C1R,                                      \
    ( const arrtype* src, int srcstep, arrtype* dst, int dststep,                   \
      CvSize size, const scalartype* scalar ))

IPCV_ABS_DIFF( 8u, uchar, int )
IPCV_ABS_DIFF( 32f, float, float )
IPCV_ABS_DIFF( 64f, double, double )

#undef IPCV_ABS_DIFF

/****************************************************************************************/
/*                               Flood Filling functions                                */
/****************************************************************************************/

IPCVAPI(CvStatus,  icvFloodFillGetSize,(CvSize roi, int* bufferSize))

IPCVAPI(CvStatus,   icvFloodFillGetSize_Grad,(CvSize roi, int* bufferSize))

/////////// Flood fill functions /////////////////

#define IPCV_FLOODFILL( flavor, arrtype, scalartype, connectivity, cn )     \
IPCVAPI(CvStatus, icvFloodFill_##connectivity##Con_##flavor##_C##cn##IR,    \
        ( arrtype* pImage, int step, CvSize roi, CvPoint seed,              \
          scalartype* newVal, CvConnectedComp* region, void* pBuffer ))     \
                                                                            \
IPCVAPI(CvStatus, icvFloodFill_Grad##connectivity##Con_##flavor##_C##cn##IR,\
        ( arrtype* pImage, int step, CvSize roi, CvPoint seed,              \
          scalartype* newVal, scalartype* lo_diff, scalartype* up_diff,     \
          CvConnectedComp* region, void* pBuffer ))

IPCV_FLOODFILL( 8u, uchar, int, 8, 1 )
IPCV_FLOODFILL( 8u, uchar, int, 4, 1 )
IPCV_FLOODFILL( 32f, float, float, 8, 1 )
IPCV_FLOODFILL( 32f, float, float, 4, 1 )

#undef IPCV_FLOODFILL

IPCVAPI(CvStatus, icvEigenValsVecsGetSize, ( int roiWidth,int apertureSize,
                                              int avgWindow, int* bufferSize ))

IPCVAPI(CvStatus, icvEigenValsVecs_8u32f_C1R, ( const unsigned char* pSrc, int srcStep,
                                                 float* pEigenVV, int eigStep,
                                                 CvSize roiSize, int apertureSize,
                                                 int avgWindow, void* pBuffer ))

IPCVAPI(CvStatus, icvEigenValsVecs_8s32f_C1R, ( const char* pSrc, int srcStep,
                                                 float* pEigenVV, int eigStep,
                                                 CvSize roiSize, int apertureSize,
                                                 int avgWindow, void* pBuffer ))

IPCVAPI(CvStatus, icvEigenValsVecs_32f_C1R, ( const float* pSrc, int srcStep,
                                               float* pEigenVV, int eigStep,
                                               CvSize roiSize, int apertureSize,
                                               int avgWindow, void* pBuffer ))

/* //////////////////////////////////////////////////////////////////////////// *\
**********************************************************************************
\* //////////////////////////////////////////////////////////////////////////// */

IPCVAPI(CvStatus, icvMinAreaRect, (CvPoint * points, int n,
                                   int left, int bottom, int right, int top,
                                   CvPoint2D32f * anchor,
                                   CvPoint2D32f * vect1, CvPoint2D32f * vect2) )

IPCVAPI(CvStatus, icvCalcHist8uC1R, (uchar ** img, int step, CvSize size,
                                     CvHistogram * hist, int dont_clear) )

IPCVAPI(CvStatus, icvCalcHist8sC1R, (char **img, int step, CvSize size,
                                     CvHistogram * hist, int dont_clear) )

IPCVAPI(CvStatus, icvCalcHist32fC1R, (float **img, int step, CvSize size,
                                      CvHistogram * hist, int dont_clear) )

IPCVAPI(CvStatus, icvCalcHistMask8uC1R, (uchar ** img, int step,
                                         uchar * mask, int mask_step,
                                         CvSize size,
                                         CvHistogram * hist, int dont_clear) )

IPCVAPI(CvStatus, icvCalcHistMask8sC1R, (char **img, int step,
                                          uchar * mask, int mask_step,
                                          CvSize size,
                                          CvHistogram * hist, int dont_clear) )

IPCVAPI(CvStatus, icvCalcHistMask32fC1R, (float **img, int step,
                                          uchar * mask, int mask_step,
                                          CvSize size,
                                          CvHistogram * hist, int dont_clear) )

IPCVAPI(CvStatus, icvCalcBackProject8uC1R, (uchar ** img, int step,
                                            uchar * dst, int dst_step,
                                            CvSize size, CvHistogram * hist) )

IPCVAPI(CvStatus, icvCalcBackProject8sC1R, (char **img, int step,
                                            char *dst, int dst_step,
                                            CvSize size, CvHistogram * hist) )

IPCVAPI(CvStatus, icvCalcBackProject32fC1R, (float **img, int step,
                                             float *dst, int dst_step,
                                             CvSize size, CvHistogram * hist) )

IPCVAPI(CvStatus, icvCalcBackProjectPatch8uC1R, (uchar ** src, int src_step,
                                                 float *dst, int dst_step,
                                                 CvSize roi,
                                                 CvSize range,
                                                 CvHistogram * hist,
                                                 CvCompareMethod method,
                                                 float norm_factor) )

IPCVAPI(CvStatus, icvCalcBackProjectPatch8sC1R, (char **src, int src_step,
                                                 float *dst, int dst_step,
                                                 CvSize roi,
                                                 CvSize range,
                                                 CvHistogram * hist,
                                                 CvCompareMethod method,
                                                 float norm_factor) )

IPCVAPI(CvStatus, icvCalcBackProjectPatch32fC1R, (float **src, int src_step,
                                                  float *dst, int dst_step,
                                                  CvSize roi,
                                                  CvSize range,
                                                  CvHistogram * hist,
                                                  CvCompareMethod method,
                                                  float norm_factor) )

/****************************************************************************************/
/*                               Thresholding functions                                 */
/****************************************************************************************/

IPCVAPI(CvStatus , icvThresh_8u_C1R, ( const uchar*  src, int  src_step,
                                       uchar*  dst, int  dst_step,
                                       CvSize  roi, int  thresh,
                                       uchar   max_val, CvThreshType type ))

IPCVAPI(CvStatus , icvThresh_8s_C1R, ( const char*   src, int  src_step,
                                       char*   dst, int  dst_step,
                                       CvSize  roi, int  thresh,
                                       char    max_val, CvThreshType type ))

IPCVAPI(CvStatus , icvThresh_32f_C1R,( const float*  src, int    src_step,
                                       float*  dst, int    dst_step,
                                       CvSize  roi, float  thresh,
                                       float   max_val, CvThreshType type))

/****************************************************************************************/
/*                                  Detection functions                                 */
/****************************************************************************************/

IPCVAPI( CvStatus, icvPreCornerDetect_8u32f_C1R, ( const uchar* src, int  srcStep,
                                                   float*  corner, int cornerStep,
                                                   CvSize roi, int  apertureSize ))

IPCVAPI( CvStatus, icvPreCornerDetect_8s32f_C1R, ( const char* src, int  srcStep,
                                                   float*  corner, int cornerStep,
                                                   CvSize roi, int  apertureSize ))

IPCVAPI( CvStatus, icvPreCornerDetect_32f_C1R, ( const float* src, int  srcStep,
                                                 float*  corner, int cornerStep,
                                                 CvSize roi, int  apertureSize ))



/****************************************************************************************\
*                                   Color Transforms                                     *
\****************************************************************************************/

#define IPCV_COLORCVT( cvt_case, flavor, arrtype )                                       \
IPCVAPI( CvStatus, icvCvt_##cvt_case##_##flavor,(const arrtype* src, int srcstep,        \
                                                 arrtype* dst, int dststep, CvSize size ))

IPCV_COLORCVT( BGR2RGB, 8u_C3R, uchar )
IPCV_COLORCVT( BGR2BGRA, 8u_C3C4R, uchar )
IPCV_COLORCVT( BGRA2BGR, 8u_C4C3R, uchar )
IPCV_COLORCVT( BGR2RGBA, 8u_C3C4R, uchar )
IPCV_COLORCVT( RGBA2BGR, 8u_C4C3R, uchar )
IPCV_COLORCVT( BGR5652GRAY, 8u_C2C1R, uchar )
IPCV_COLORCVT( BGR2GRAY, 8u_C3C1R, uchar )
IPCV_COLORCVT( RGB2GRAY, 8u_C3C1R, uchar )
IPCV_COLORCVT( BGRA2GRAY, 8u_C4C1R, uchar )
IPCV_COLORCVT( RGBA2GRAY, 8u_C4C1R, uchar )
IPCV_COLORCVT( GRAY2BGR565, 8u_C1C2R, uchar )
IPCV_COLORCVT( GRAY2BGR, 8u_C1C3R, uchar )
IPCV_COLORCVT( GRAY2BGRA, 8u_C1C4R, uchar )
IPCV_COLORCVT( BGR2BGR565, 8u_C3C2R, uchar )
IPCV_COLORCVT( RGB2BGR565, 8u_C3C2R, uchar )
IPCV_COLORCVT( BGRA2BGR565, 8u_C4C2R, uchar )
IPCV_COLORCVT( RGBA2BGR565, 8u_C4C2R, uchar )
IPCV_COLORCVT( BGR5652BGR, 8u_C2C3R, uchar )
IPCV_COLORCVT( BGR5652RGB, 8u_C2C3R, uchar )

IPCV_COLORCVT( BGR2XYZ, 8u_C3R, uchar )
IPCV_COLORCVT( RGB2XYZ, 8u_C3R, uchar )
IPCV_COLORCVT( XYZ2BGR, 8u_C3R, uchar )
IPCV_COLORCVT( XYZ2RGB, 8u_C3R, uchar )

IPCV_COLORCVT( BGR2YCrCb, 8u_C3R, uchar )
IPCV_COLORCVT( RGB2YCrCb, 8u_C3R, uchar )
IPCV_COLORCVT( YCrCb2BGR, 8u_C3R, uchar )
IPCV_COLORCVT( YCrCb2RGB, 8u_C3R, uchar )

IPCV_COLORCVT( BGR2HSV, 8u_C3R, uchar )
IPCV_COLORCVT( RGB2HSV, 8u_C3R, uchar )

IPCV_COLORCVT( BGR2Lab, 8u_C3R, uchar )
IPCV_COLORCVT( RGB2Lab, 8u_C3R, uchar )

#undef IPCV_COLORCVT

/****************************************************************************************/
/*                            Snakes                                                    */
/****************************************************************************************/
IPCVAPI( CvStatus, icvSnakeImage8uC1R, ( uchar*    src,  int  srcStep,
                                       CvSize  roi,  CvPoint* points,
                                       int  length, float* alpha,
                                       float* beta, float* gamma,
                                       CvCoeffType coeffUsage, CvSize  win,
                                       CvTermCriteria criteria ))

IPCVAPI( CvStatus, icvSnakeImageGrad8uC1R,( uchar*    src, int  srcStep,
                                          CvSize  roi, CvPoint* points,
                                          int  length,  float* alpha,
                                          float* beta,  float* gamma,
                                          CvCoeffType coeffUsage, CvSize win,
                                          CvTermCriteria criteria ))


/****************************************************************************************/
/*                                Hough Transform                                       */
/****************************************************************************************/

IPCVAPI( int, icvHoughLines_8uC1R,( uchar* image, int   step,  CvSize size, 
                                    float  rho,   float theta, int threshold, 
                                    float* lines, int   linesNumber))

IPCVAPI( int, icvHoughLinesSDiv_8uC1R,( uchar* image_src, int step, CvSize size, 
                                       float rho, int srn, float theta, int stn,
                                       int threshold, float* lines, int lines_number ))

IPCVAPI( int, icvHoughLinesP_8uC1R,( uchar* image,   int   step,  CvSize size, 
                                     float  rho,     float theta, int threshold, 
                                     int lineLength, int lineGap, int*  lines, int linesNumber ))

/****************************************************************************************\
*                                      Eigen objects                                     *
\****************************************************************************************/

IPCVAPI( CvStatus, icvCalcCovarMatrixEx_8u32fR, ( int nObjects, void* input, int objStep,
                                                 int ioFlags, int ioBufSize,
                                                 uchar* buffer, void* userData,
                                                 float* avg, int avgStep, CvSize size,
                                                 float* covarMatrix ) )

IPCVAPI( CvStatus, icvCalcEigenObjects_8u32fR, ( int nObjects, void* input, int objStep,
                                                   void* output, int eigStep,
                                                   CvSize size, int ioFlags,
                                                   int ioBufSize, void* userData,
                                                   CvTermCriteria* calcLimit,
                                                   float* avg, int avgStep,
                                                   float* eigVals ) )

IPCVAPI(float, icvCalcDecompCoeff_8u32fR, ( uchar* obj,    int objStep,
                                            float* eigObj, int eigStep,
                                            float* avg,    int avgStep, CvSize size ))

IPCVAPI(CvStatus , icvEigenDecomposite_8u32fR, ( uchar* obj, int objStep, int nEigObjs,
                                                   void* eigInput, int eigStep,
                                                   int ioFlags, void* userData,
                                                   float* avg, int avgStep,
                                                   CvSize size, float* coeffs ) )

IPCVAPI(CvStatus, icvEigenProjection_8u32fR,(int nEigObjs, void* eigInput, int eigStep,
                                             int ioFlags, void* userData,
                                             float* coeffs, float* avg, int avgStep,
                                             uchar* rest, int restStep, CvSize size))



////////////////////////////////////// SampleLine ////////////////////////////////////////

#define IPCV_SAMPLE_LINE( flavor, arrtype )                                 \
IPCVAPI( CvStatus, icvSampleLine_##flavor##_C1R,                            \
( CvLineIterator* iterator, arrtype* buffer, int count ))                   \
IPCVAPI( CvStatus, icvSampleLine_##flavor##_C2R,                            \
( CvLineIterator* iterator, arrtype* buffer, int count ))                   \
IPCVAPI( CvStatus, icvSampleLine_##flavor##_C3R,                            \
( CvLineIterator* iterator, arrtype* buffer, int count ))

IPCV_SAMPLE_LINE( 8u, uchar )
IPCV_SAMPLE_LINE( 32f, float )

#undef IPCV_SAMPLE_LINE

/****************************************************************************************\
*                                   Histogram of contrast calculation                    *
\****************************************************************************************/

IPCVAPI ( CvStatus, icvCreateHandMask8uC1R, (CvSeq* numbers, 
                                              uchar* image_mask, int step, CvSize size,
                                              CvRect *roi))

IPCVAPI ( CvStatus, icvCalcImageHomography, (float *line, CvPoint3D32f* center,
                                            float intrinsic[3][3], float homography[3][3]))

IPCVAPI (CvStatus,  icvMaxRect, ( CvRect *rect1, CvRect *rect2, CvRect *max_rect ))

IPCVAPI (CvStatus, icvCalcProbDensity, (CvHistogram* hist, CvHistogram* hist_mask,
                                        CvHistogram* hist_dens))

/****************************************************************************************/
/*                             HMM (Hidden Markov Models)                               */
/****************************************************************************************/

IPCVAPI( CvStatus, icvCreate2DHMM, ( CvEHMM** hmm, 
                                     int* state_number, 
                                     int* num_mix, int obs_size ))

IPCVAPI( CvStatus, icvRelease2DHMM, ( CvEHMM** hmm ))


IPCVAPI( CvStatus, icvCreateObsInfo, ( CvImgObsInfo** obs_info, 
                                       CvSize num_obs, int obs_size ) ) 

IPCVAPI( CvStatus, icvReleaseObsInfo, ( CvImgObsInfo** obs_info ) )


IPCVAPI( CvStatus, icvImgToObs_DCT_8u32f_C1R, ( uchar* img, int imgStep, CvSize roi,
                                                float* obs, CvSize dctSize,
                                                CvSize obsSize, CvSize delta ))


IPCVAPI( CvStatus, icvUniformImgSegm,( CvImgObsInfo* obs_info, CvEHMM* ehmm ) )

IPCVAPI( CvStatus, icvInitMixSegm, ( CvImgObsInfo** obs_info_array, 
                                     int num_img, CvEHMM* hmm  ))

IPCVAPI( CvStatus, icvEstimateHMMStateParams, ( CvImgObsInfo** obs_info_array,
                                                int num_img, CvEHMM* hmm ))

IPCVAPI( CvStatus, icvEstimateTransProb, ( CvImgObsInfo** obs_info_array, 
                                           int num_img, CvEHMM* hmm ))

IPCVAPI( CvStatus, icvEstimateObsProb, ( CvImgObsInfo* obs_info, 
                                         CvEHMM* hmm )) 

IPCVAPI( float, icvEViterbi, (CvImgObsInfo* obs_info, CvEHMM* hmm )) 


IPCVAPI( CvStatus, icvMixSegmL2, ( CvImgObsInfo** obs_info_array, 
                                   int num_img, CvEHMM* hmm  ))


/* end of HMM functions*/  

/* //////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////////////// */

/*    IPPM Group Functions                                                              */

/* //////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////////////// */

/****************************************************************************************/
/*                                Vector operations                                     */
/****************************************************************************************/

#define IPCV_DOTPRODUCT_2D( flavor, arrtype, sumtype )                                  \
IPCVAPI( CvStatus,                                                                      \
icvDotProduct_##flavor##_C1R, ( const arrtype* src1, int step1,                         \
                                const arrtype* src2, int step2,                         \
                                CvSize size, sumtype* _sum ))

IPCV_DOTPRODUCT_2D( 8u, uchar, int64 )
IPCV_DOTPRODUCT_2D( 8s, char, int64 )
IPCV_DOTPRODUCT_2D( 16s, short, int64 )
IPCV_DOTPRODUCT_2D( 32s, int, double )
IPCV_DOTPRODUCT_2D( 32f, float, double )
IPCV_DOTPRODUCT_2D( 64f, double, double )

#undef IPCV_DOTPRODUCT_2D

IPCVAPI( CvStatus, icvCrossProduct2L_32f, ( const float* src1,
                                            const float* src2,
                                            float* dest ))
                                           
IPCVAPI( CvStatus, icvCrossProduct2L_64d, ( const double* src1,
                                            const double* src2,
                                            double* dest ))

IPCVAPI( CvStatus, icvCrossProduct3P_32f, ( CvVect32f src1,
                                            CvVect32f src2,
                                            CvVect32f src3,
                                            CvVect32f dest )) 

/****************************************************************************************/
/*                                    Linear Algebra                                    */
/****************************************************************************************/

IPCVAPI( CvStatus, icvLUDecomp_32f, ( float* A, int stepA, CvSize sizeA, 
                                      float* B, int stepB, CvSize sizeB,
                                      double* _det ))

IPCVAPI( CvStatus, icvLUDecomp_64f, ( double* A, int stepA, CvSize sizeA, 
                                      double* B, int stepB, CvSize sizeB,
                                      double* _det ))

IPCVAPI( CvStatus, icvLUBack_32f, ( float* A, int stepA, CvSize sizeA, 
                                    float* B, int stepB, CvSize sizeB ))

IPCVAPI( CvStatus, icvLUBack_64f, ( double* A, int stepA, CvSize sizeA, 
                                    double* B, int stepB, CvSize sizeB ))


IPCVAPI( CvStatus, icvbTransformVector3x1P_32f, ( CvMatr32f matr,   
                                   CvVect32f srcVec, 
                                   int count,
                                   CvVect32f destVec ))


IPCVAPI( CvStatus, icvMahalanobis_32f,
                          (  CvVect32f srcVec1,
                             CvVect32f srcVec2,  
                             CvMatr32f matr,
                             int matrSize,
                             float* distance
                           ))
/****************************************************************************************/
/*                             Matrix-Matrix operations                                 */
/****************************************************************************************/

#define IPCV_MULTRANS( letter, flavor, arrtype )         \
IPCVAPI( CvStatus, icvMulTransposed##letter##_##flavor,  \
        ( const arrtype* src, int srcstep, arrtype* dst, int dststep, CvSize size ))

IPCV_MULTRANS( R, 32f, float )
IPCV_MULTRANS( R, 64f, double )
IPCV_MULTRANS( L, 32f, float )
IPCV_MULTRANS( L, 64f, double )

/****************************************************************************************/
/*                           Eigenvalues & eigenvectors problem                         */
/****************************************************************************************/

IPCVAPI(CvStatus, icvJacobiEigens_32f, ( CvMatr32f A,
                                           CvMatr32f V,
                                           CvVect32f E,
                                           int n,
                                           float eps ) )

IPCVAPI(CvStatus, icvJacobiEigens_64d, ( CvMatr64d A,
                                           CvMatr64d V,
                                           CvVect64d E,
                                           int n,
                                           double eps ))

IPCVAPI(CvStatus, icvCalcCovarMatrix_8u32f, ( int nObjects, uchar** objects,
                                            float* avg, int length, float* covarMatrix ) )

IPCVAPI(CvStatus, icvCalcCovarMatrix_32f, ( int nObjects, float** objects,
                                            float* avg, int length, float* covarMatrix ) )

/****************************************************************************************/
/*                              Functions, needed for calibration                       */
/****************************************************************************************/

IPCVAPI(CvStatus, icvNormVector_32f, (   CvVect32f    vect,
                                int         length,
                                float*      norm))

IPCVAPI(CvStatus, icvNormVector_64d, (   double*    vect,
                                int         length,
                                double*      norm))


IPCVAPI( CvStatus,  icvComplexMult_32f, (  CvMatr32f srcMatr,
                                CvMatr32f dstMatr,
                                int      width,
                                int      height))

IPCVAPI( CvStatus,  icvComplexMult_64d, (  double*  srcMatr,
                                double*  dstMatr,
                                int      width,
                                int      height))
                                
IPCVAPI(CvStatus, icvRodrigues, (CvMatr32f       rotMatr,
                                CvVect32f       rotVect,
                                CvMatr32f       Jacobian,
                                CvRodriguesType convType))

IPCVAPI(CvStatus, icvRodrigues_64d, (double*         rotMatr,
                                    double*         rotVect,
                                    double*         Jacobian,
                                    CvRodriguesType convType))


IPCVAPI(CvStatus, icvPyrDownBorder_32f_C1R, ( const float* src, int src_step,
                                              float* dst, int dst_step,
                                              CvSize src_size ))

IPCVAPI(CvStatus, icvPyrDownBorder_32f_C3R, ( const float* src, int src_step,
                                              float* dst, int dst_step,
                                              CvSize src_size ))

/****************************************************************************************/
/*                                 Geometrical transforms                               */
/****************************************************************************************/

IPCVAPI( CvStatus, icvResize_NN_8u_C1R, ( const uchar* src, int srcstep, CvSize srcsize,
                                uchar* dst, int dststep, CvSize dstsize, int pix_size ))

#define IPCV_RESIZE_BILINEAR( flavor, cn, arrtype )                     \
IPCVAPI( CvStatus, icvResize_Bilinear_##flavor##_C##cn##R, (            \
                   const arrtype* src, int srcstep, CvSize srcsize,     \
                   arrtype* dst, int dststep, CvSize dstsize ))

IPCV_RESIZE_BILINEAR( 8u, 1, uchar )
IPCV_RESIZE_BILINEAR( 8u, 2, uchar )
IPCV_RESIZE_BILINEAR( 8u, 3, uchar )
IPCV_RESIZE_BILINEAR( 8u, 4, uchar )


/****************************************************************************************/
/*                                 Copy/Set with mask                                   */
/****************************************************************************************/

#define IPCV_COPYSET( flavor, arrtype, scalartype )                                 \
IPCVAPI( CvStatus, icvCopy##flavor,( const arrtype* src, int srcstep,               \
                                             arrtype* dst, int dststep,             \
                                             const uchar* mask, int maskstep,       \
                                             CvSize size ))                         \
IPCVAPI( CvStatus, icvSet##flavor,( arrtype* dst, int dststep,                      \
                                            const uchar* mask, int maskstep,        \
                                            CvSize size, const scalartype* scalar ))

IPCV_COPYSET( _8u_C1MR, uchar, int )
IPCV_COPYSET( _8u_C2MR, ushort, int )
IPCV_COPYSET( _8u_C3MR, uchar, int )
IPCV_COPYSET( _16u_C2MR, int, int )
IPCV_COPYSET( _16u_C3MR, ushort, int )
IPCV_COPYSET( _32s_C2MR, int64, int64 )
IPCV_COPYSET( _32s_C3MR, int, int )
IPCV_COPYSET( _64s_C2MR, int, int )
IPCV_COPYSET( _64s_C3MR, int64, int64 )
IPCV_COPYSET( _64s_C4MR, int64, int64 )

/****************************************************************************************/
/*                                 Canny Edge Detector                                  */
/****************************************************************************************/

IPCVAPI( CvStatus, icvCannyGetSize, ( CvSize roiSize, int* bufferSize ))

IPCVAPI( CvStatus, icvCanny_16s8u_C1R, ( const short* pSrcDx, int srcDxStep,
                                         const short* pSrcDy, int srcDyStep,
                                         uchar*  pDstEdges, int dstEdgeStep, 
                                         CvSize roiSize, float  lowThresh,
                                         float  highThresh, void* pBuffer ))

#endif /*__OPTCV_H_*/

