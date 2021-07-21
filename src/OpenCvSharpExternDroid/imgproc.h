#ifndef _CPP_IMGPROC_H_
#define _CPP_IMGPROC_H_

#include "include_opencv.h"

// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

CVAPI(cv::Mat*) imgproc_getGaussianKernel(int ksize, double sigma, int ktype)
{
    cv::Mat ret = cv::getGaussianKernel(ksize, sigma, ktype);
    return new cv::Mat(ret);
}

CVAPI(void) imgproc_getDerivKernels(cv::_OutputArray *kx, cv::_OutputArray *ky,
    int dx, int dy, int ksize, int normalize, int ktype)
{
    cv::getDerivKernels(*kx, *ky, dx, dy, ksize, normalize != 0, ktype);
}

CVAPI(cv::Mat*) imgproc_getGaborKernel(MyCvSize ksize, double sigma, double theta, 
    double lambd, double gamma, double psi, int ktype)
{
    cv::Mat ret = cv::getGaborKernel(cpp(ksize), sigma, theta, lambd, gamma, psi, ktype);
    return new cv::Mat(ret);
}

CVAPI(cv::Mat*) imgproc_getStructuringElement(int shape, MyCvSize ksize, MyCvPoint anchor)
{
    cv::Mat ret = cv::getStructuringElement(shape, cpp(ksize), cpp(anchor));
    return new cv::Mat(ret);
}

CVAPI(void) imgproc_copyMakeBorder(cv::_InputArray *src, cv::_OutputArray *dst, 
    int top, int bottom, int left, int right, int borderType, MyCvScalar value)
{
    cv::copyMakeBorder(*src, *dst, top, bottom, left, right, borderType, cpp(value));
}

CVAPI(void) imgproc_medianBlur(cv::_InputArray *src, cv::_OutputArray *dst, int ksize)
{
    cv::medianBlur(*src, *dst, ksize);
}

CVAPI(void) imgproc_GaussianBlur(cv::_InputArray *src, cv::_OutputArray *dst, 
    CvSize ksize, double sigmaX, double sigmaY, int borderType)
{
    cv::GaussianBlur(*src, *dst, ksize, sigmaX, sigmaY, borderType);
}

CVAPI(void) imgproc_bilateralFilter(cv::_InputArray *src, cv::_OutputArray *dst, 
    int d, double sigmaColor, double sigmaSpace, int borderType)
{
    cv::bilateralFilter(*src, *dst, d, sigmaColor, sigmaSpace, borderType);
}

/*
CVAPI(void) imgproc_adaptiveBilateralFilter(cv::_InputArray *src, cv::_OutputArray *dst, 
    CvSize ksize, double sigmaSpace, double maxSigmaColor, CvPoint anchor, int borderType)
{
    cv::adaptiveBilateralFilter(*src, *dst, ksize, sigmaSpace, maxSigmaColor, anchor, borderType);
}*/

CVAPI(void) imgproc_boxFilter(cv::_InputArray *src, cv::_OutputArray *dst, int ddepth, 
    CvSize ksize, CvPoint anchor, int normalize, int borderType)
{
    cv::boxFilter(*src, *dst, ddepth, ksize, anchor, normalize != 0, borderType);
}

CVAPI(void) imgproc_blur(cv::_InputArray *src, cv::_OutputArray *dst, CvSize ksize, CvPoint anchor, int borderType)
{
    cv::blur(*src, *dst, ksize, anchor, borderType);
}

CVAPI(void) imgproc_filter2D(cv::_InputArray *src, cv::_OutputArray *dst, int ddepth,
    cv::_InputArray *kernel, CvPoint anchor, double delta, int borderType)
{
    cv::filter2D(*src, *dst, ddepth, *kernel, anchor, delta, borderType);
}

CVAPI(void) imgproc_sepFilter2D(cv::_InputArray *src, cv::_OutputArray *dst, int ddepth,
    cv::_InputArray *kernelX, cv::_InputArray *kernelY,
    CvPoint anchor,    double delta, int borderType)
{
    cv::sepFilter2D(*src, *dst, ddepth, *kernelX, *kernelY, anchor, delta, borderType);
}

CVAPI(void) imgproc_Sobel(cv::_InputArray *src, cv::_OutputArray *dst, int ddepth,
    int dx, int dy, int ksize, double scale, double delta, int borderType)
{
    cv::Sobel(*src, *dst, ddepth, dx, dy, ksize, scale, delta, borderType);
}

CVAPI(void) imgproc_Scharr(cv::_InputArray *src, cv::_OutputArray *dst, int ddepth,
    int dx, int dy, double scale, double delta,    int borderType)
{
    cv::Scharr(*src, *dst, ddepth, dx, dy, scale, delta, borderType);
}

CVAPI(void) imgproc_Laplacian(cv::_InputArray *src, cv::_OutputArray *dst, int ddepth,
    int ksize, double scale, double delta, int borderType)
{
    cv::Laplacian(*src, *dst, ddepth, ksize, scale, delta, borderType);
}

CVAPI(void) imgproc_Canny(cv::_InputArray *src, cv::_OutputArray *edges,
    double threshold1, double threshold2, int apertureSize, int L2gradient)
{
    cv::Canny(*src, *edges, threshold1, threshold2, apertureSize, L2gradient != 0);
}

CVAPI(void) imgproc_cornerMinEigenVal(cv::_InputArray *src, cv::_OutputArray *dst,
    int blockSize, int ksize, int borderType)
{
    cv::cornerMinEigenVal(*src, *dst, blockSize, ksize, borderType);
}

CVAPI(void) imgproc_cornerHarris(cv::_InputArray *src, cv::_OutputArray *dst, 
    int blockSize, int ksize, double k, int borderType)
{
    cv::cornerHarris(*src, *dst, blockSize, ksize, k, borderType);
}

CVAPI(void) imgproc_cornerEigenValsAndVecs(cv::_InputArray *src, cv::_OutputArray *dst,
    int blockSize, int ksize, int borderType)
{
    cv::cornerEigenValsAndVecs(*src, *dst, blockSize, ksize, borderType);
}

CVAPI(void) imgproc_preCornerDetect(cv::_InputArray *src, cv::_OutputArray *dst, int ksize,    int borderType)
{
    cv::preCornerDetect(*src, *dst, ksize, borderType);
}

CVAPI(void) imgproc_cornerSubPix(cv::_InputArray *image, std::vector<cv::Point2f> *corners,
    CvSize winSize, CvSize zeroZone, CvTermCriteria criteria)
{
    cv::cornerSubPix(*image, *corners, winSize, zeroZone, criteria);
}

CVAPI(void) imgproc_goodFeaturesToTrack(cv::_InputArray *src, std::vector<cv::Point2f> *corners,
    int maxCorners, double qualityLevel, double minDistance,
    cv::_InputArray *mask, int blockSize, int useHarrisDetector, double k)
{
    cv::goodFeaturesToTrack(*src, *corners, maxCorners, qualityLevel, minDistance, entity(mask), blockSize, useHarrisDetector != 0, k);
}

CVAPI(void) imgproc_HoughLines(cv::_InputArray *src, std::vector<cv::Vec2f> *lines,
    double rho, double theta, int threshold,
    double srn, double stn)
{
    cv::HoughLines(*src, *lines, rho, theta, threshold, srn, stn);
}

CVAPI(void) imgproc_HoughLinesP(cv::_InputArray *src, std::vector<cv::Vec4i> *lines,
    double rho, double theta, int threshold,
    double minLineLength, double maxLineGap)
{
    cv::HoughLinesP(*src, *lines, rho, theta, threshold, minLineLength, maxLineGap);
}

CVAPI(void) imgproc_HoughCircles(cv::_InputArray *src, std::vector<cv::Vec3f> *circles,
    int method, double dp, double minDist,
    double param1, double param2, int minRadius, int maxRadius)
{
    cv::HoughCircles(*src, *circles, method, dp, minDist, param1, param2, minRadius, maxRadius);
}


CVAPI(void) imgproc_erode(cv::_InputArray *src, cv::_OutputArray *dst, cv::_InputArray *kernel,
    CvPoint anchor, int iterations,    int borderType,    CvScalar borderValue)
{
    cv::erode(*src, *dst, entity(kernel), anchor, iterations, borderType, borderValue);
}
CVAPI(void) imgproc_dilate(cv::_InputArray *src, cv::_OutputArray *dst, cv::_InputArray *kernel,
    CvPoint anchor, int iterations, int borderType, CvScalar borderValue)
{
    cv::dilate(*src, *dst, entity(kernel), anchor, iterations, borderType, borderValue);
}
CVAPI(void) imgproc_morphologyEx(cv::_InputArray *src, cv::_OutputArray *dst, int op, cv::_InputArray *kernel,
    CvPoint anchor, int iterations, int borderType, CvScalar borderValue)
{
    cv::morphologyEx(*src, *dst, op, entity(kernel), anchor, iterations, borderType, borderValue);
}

CVAPI(void) imgproc_resize(cv::_InputArray* src, cv::_OutputArray* dst, CvSize dsize, double fx, double fy, int interpolation)
{
    cv::resize(*src, *dst, dsize, fx, fy, interpolation);
}

CVAPI(void) imgproc_warpAffine(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* M, CvSize dsize, 
    int flags, int borderMode, CvScalar borderValue)
{
    cv::warpAffine(*src, *dst, *M, dsize, flags, borderMode, borderValue);
}

CVAPI(void) imgproc_warpPerspective_MisInputArray(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* m, CvSize dsize, 
    int flags, int borderMode, CvScalar borderValue)
{
    cv::warpPerspective(*src, *dst, *m, dsize, flags, borderMode, borderValue);
}

CVAPI(void) imgproc_warpPerspective_MisArray(cv::_InputArray* src, cv::_OutputArray* dst, float* m, int mRow, int mCol, CvSize dsize,
    int flags, int borderMode, CvScalar borderValue)
{
    cv::Mat mmat(mRow, mCol, CV_32FC1, m);
    cv::warpPerspective(*src, *dst, mmat, dsize, flags, borderMode, borderValue);
}

CVAPI(void) imgproc_remap(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* map1, cv::_InputArray* map2, 
    int interpolation, int borderMode, CvScalar borderValue)
{
    cv::remap(*src, *dst, *map1, *map2, interpolation, borderMode, borderValue);
}

CVAPI(void) imgproc_convertMaps(cv::_InputArray* map1, cv::_InputArray* map2, cv::_OutputArray* dstmap1, cv::_OutputArray* dstmap2, 
    int dstmap1type, int nninterpolation)
{
    cv::convertMaps(*map1, *map2, *dstmap1, *dstmap2, dstmap1type, nninterpolation != 0);
}

CVAPI(cv::Mat*) imgproc_getRotationMatrix2D(MyCvPoint2D32f center, double angle, double scale)
{
    cv::Mat ret = cv::getRotationMatrix2D(cpp(center), angle, scale);
    return new cv::Mat(ret);

}
CVAPI(void) imgproc_invertAffineTransform(cv::_InputArray* M, cv::_OutputArray *iM)
{
    cv::invertAffineTransform(*M, *iM);
}

CVAPI(cv::Mat*) imgproc_getPerspectiveTransform1(cv::Point2f *src, cv::Point2f *dst)
{
    cv::Mat ret = cv::getPerspectiveTransform(src, dst);
    return new cv::Mat(ret);
}
CVAPI(cv::Mat*) imgproc_getPerspectiveTransform2(cv::_InputArray *src, cv::_InputArray *dst)
{
    cv::Mat ret = cv::getPerspectiveTransform(*src, *dst);
    return new cv::Mat(ret);
}

CVAPI(cv::Mat*) imgproc_getAffineTransform1(cv::Point2f *src, cv::Point2f *dst)
{
    cv::Mat ret = cv::getAffineTransform(src, dst);
    return new cv::Mat(ret);
}
CVAPI(cv::Mat*) imgproc_getAffineTransform2(cv::_InputArray *src, cv::_InputArray *dst)
{
    cv::Mat ret = cv::getAffineTransform(*src, *dst);
    return new cv::Mat(ret);
}

CVAPI(void) imgproc_getRectSubPix(cv::_InputArray *image, CvSize patchSize, MyCvPoint2D32f center, cv::_OutputArray *patch, int patchType)
{
    cv::getRectSubPix(*image, patchSize, cpp(center), *patch, patchType);
}

CVAPI(void) imgproc_logPolar(cv::_InputArray *src, cv::_OutputArray *dst,
    MyCvPoint2D32f center, double M, int flags)
{
    cv::logPolar(*src, *dst, cpp(center), M, flags);
}

CVAPI(void) imgproc_linearPolar(cv::_InputArray *src, cv::_OutputArray *dst,
    MyCvPoint2D32f center, double maxRadius, int flags)
{
    cv::linearPolar(*src, *dst, cpp(center), maxRadius, flags);
}

CVAPI(void) imgproc_integral1(cv::_InputArray *src, cv::_OutputArray *sum, int sdepth)
{
    cv::integral(*src, *sum, sdepth);
}
CVAPI(void) imgproc_integral2(cv::_InputArray *src, cv::_OutputArray *sum, cv::_OutputArray *sqsum, int sdepth)
{
    cv::integral(*src, *sum, *sqsum, sdepth);
}
CVAPI(void) imgproc_integral3(cv::_InputArray *src, cv::_OutputArray *sum, cv::_OutputArray *sqsum, cv::_OutputArray *tilted, int sdepth)
{
    cv::integral(*src, *sum, *sqsum, *tilted, sdepth);
}

CVAPI(void) imgproc_accumulate(cv::_InputArray *src, cv::_InputOutputArray *dst, cv::_InputArray *mask)
{
    cv::accumulate(*src, *dst, entity(mask));
}
CVAPI(void) imgproc_accumulateSquare(cv::_InputArray* src, cv::_InputOutputArray *dst, cv::_InputArray *mask)
{
    cv::accumulateSquare(*src, *dst, entity(mask));
}
CVAPI(void) imgproc_accumulateProduct(cv::_InputArray *src1, cv::_InputArray *src2, cv::_InputOutputArray *dst, cv::_InputArray *mask)
{
    cv::accumulateProduct(*src1, *src2, *dst, entity(mask));
}
CVAPI(void) imgproc_accumulateWeighted(cv::_InputArray *src, cv::_InputOutputArray *dst, double alpha, cv::_InputArray *mask)
{
    cv::accumulateWeighted(*src, *dst, alpha, entity(mask));
}

CVAPI(double) imgproc_PSNR(cv::_InputArray *src1, cv::_InputArray *src2)
{
    return cv::PSNR(*src1, *src2);
}

CVAPI(CvPoint2D64f) imgproc_phaseCorrelate(cv::_InputArray *src1, cv::_InputArray *src2,
                                  cv::_InputArray *window)
{
    cv::Point2d p = cv::phaseCorrelate(*src1, *src2, entity(window));
    return cvPoint2D64f(p.x, p.y);
}
CVAPI(CvPoint2D64f) imgproc_phaseCorrelateRes(cv::_InputArray *src1, cv::_InputArray *src2,
                                    cv::_InputArray *window, double* response)
{
    cv::Point2d p = cv::phaseCorrelate(*src1, *src2, *window, response);
    return cvPoint2D64f(p.x, p.y);
}
CVAPI(void) imgproc_createHanningWindow(cv::_OutputArray *dst, CvSize winSize, int type)
{
    cv::createHanningWindow(*dst, winSize, type);
}

CVAPI(double) imgproc_threshold(cv::_InputArray *src, cv::_OutputArray *dst,
    double thresh, double maxval, int type)
{
    return cv::threshold(*src, *dst, thresh, maxval, type);
}
CVAPI(void) imgproc_adaptiveThreshold(cv::_InputArray *src, cv::_OutputArray *dst,
    double maxValue, int adaptiveMethod,
    int thresholdType, int blockSize, double C)
{
    cv::adaptiveThreshold(*src, *dst, maxValue, adaptiveMethod, thresholdType, blockSize, C);
}

CVAPI(void) imgproc_pyrDown(cv::_InputArray *src, cv::_OutputArray *dst, CvSize dstsize, int borderType)
{
    cv::pyrDown(*src, *dst, dstsize, borderType);
}
CVAPI(void) imgproc_pyrUp(cv::_InputArray *src, cv::_OutputArray *dst, CvSize dstsize, int borderType)
{
    cv::pyrUp(*src, *dst, dstsize, borderType);
}

CVAPI(void) imgproc_undistort(cv::_InputArray *src, cv::_OutputArray *dst,
    cv::_InputArray *cameraMatrix, cv::_InputArray *distCoeffs, cv::_InputArray *newCameraMatrix)
{
    cv::undistort(*src, *dst, *cameraMatrix, entity(distCoeffs), entity(newCameraMatrix));
}
CVAPI(void) imgproc_initUndistortRectifyMap(cv::_InputArray *cameraMatrix, cv::_InputArray *distCoeffs,
    cv::_InputArray *r, cv::_InputArray *newCameraMatrix, CvSize size, int m1type,
    cv::_OutputArray *map1, cv::_OutputArray *map2)
{
    cv::initUndistortRectifyMap(*cameraMatrix, *distCoeffs, *r, *newCameraMatrix, size, m1type, *map1, *map2);
}
CVAPI(float) imgproc_initWideAngleProjMap(cv::_InputArray *cameraMatrix, cv::_InputArray *distCoeffs,
    CvSize imageSize, int destImageWidth, int m1type, cv::_OutputArray *map1, cv::_OutputArray *map2, int projType, double alpha)
{
    return cv::initWideAngleProjMap(*cameraMatrix, *distCoeffs, imageSize, destImageWidth, m1type, *map1, *map2, projType, alpha);
}
CVAPI(cv::Mat*) imgproc_getDefaultNewCameraMatrix(cv::_InputArray *cameraMatrix, CvSize imgSize, int centerPrincipalPoint)
{
    cv::Mat ret = cv::getDefaultNewCameraMatrix(*cameraMatrix, imgSize, centerPrincipalPoint != 0);
    return new cv::Mat(ret);
}
CVAPI(void) imgproc_undistortPoints(cv::_InputArray *src, cv::_OutputArray *dst,
    cv::_InputArray *cameraMatrix, cv::_InputArray *distCoeffs,
    cv::_InputArray *R, cv::_InputArray *P)
{
    cv::undistortPoints(*src, *dst, *cameraMatrix, entity(distCoeffs), entity(R), entity(P));
}
CVAPI(void) imgproc_calcHist1(cv::Mat **images, int nimages,
    const int* channels, cv::_InputArray *mask,
    cv::_OutputArray *hist, int dims, const int* histSize,
    const float** ranges, int uniform, int accumulate)
{
    std::vector<cv::Mat> imagesVec(nimages);
    for (int i = 0; i < nimages; i++)
        imagesVec[i] = *(images[i]);
    cv::calcHist(&imagesVec[0], nimages, channels, entity(mask), *hist, dims, histSize, ranges, uniform != 0, accumulate != 0);
}

CVAPI(void) imgproc_calcBackProject(cv::Mat **images, int nimages,
    const int* channels, cv::_InputArray *hist, cv::_OutputArray *backProject, 
    const float** ranges, int uniform)
{
    std::vector<cv::Mat> imagesVec(nimages);
    for (int i = 0; i < nimages; i++)
        imagesVec[i] = *(images[i]);
    cv::calcBackProject(&imagesVec[0], nimages, channels, *hist, *backProject, ranges, uniform != 0);
}


CVAPI(double) imgproc_compareHist1(cv::_InputArray *h1, cv::_InputArray *h2, int method)
{
    return cv::compareHist(*h1, *h2, method);
}
CVAPI(void) imgproc_equalizeHist(cv::_InputArray *src, cv::_OutputArray *dst)
{
    cv::equalizeHist(*src, *dst);
}

CVAPI(float) imgproc_EMD(cv::_InputArray *signature1, cv::_InputArray *signature2,
    int distType, cv::_InputArray *cost, float* lowerBound, cv::_OutputArray *flow)
{
    return cv::EMD(*signature1, *signature2, distType, entity(cost), lowerBound, entity(flow));
}
CVAPI(void) imgproc_watershed(cv::_InputArray *image, cv::_InputOutputArray *markers)
{
    cv::watershed(*image, *markers);
}
CVAPI(void) imgproc_pyrMeanShiftFiltering(cv::_InputArray *src, cv::_InputOutputArray *dst,
    double sp, double sr, int maxLevel, CvTermCriteria termcrit)
{
    cv::pyrMeanShiftFiltering(*src, *dst, sp, sr, maxLevel, termcrit);
}
CVAPI(void) imgproc_grabCut(cv::_InputArray *img, cv::_InputOutputArray *mask, CvRect rect,
    cv::_InputOutputArray *bgdModel, cv::_InputOutputArray *fgdModel,
                           int iterCount, int mode )
{
    cv::grabCut(*img, *mask, rect, *bgdModel, *fgdModel, iterCount, mode);
}

CVAPI(void) imgproc_distanceTransformWithLabels(cv::_InputArray *src, cv::_OutputArray *dst,
                                     cv::_OutputArray *labels, int distanceType, int maskSize,
                                     int labelType)
{
    cv::distanceTransform(*src, *dst, *labels, distanceType, maskSize, labelType);
}

CVAPI(void) imgproc_distanceTransform(cv::_InputArray *src, cv::_OutputArray *dst,
                                     int distanceType, int maskSize )
{
    cv::distanceTransform(*src, *dst, distanceType, maskSize);
}

CVAPI(int) imgproc_floodFill1(cv::_InputOutputArray *image,
                          MyCvPoint seedPoint, MyCvScalar newVal, MyCvRect *rect,
                          MyCvScalar loDiff, MyCvScalar upDiff, int flags)
{
    cv::Rect rect0;
    int ret = cv::floodFill(*image, cpp(seedPoint), cpp(newVal), &rect0, cpp(loDiff), cpp(upDiff), flags);
    *rect = c(rect0);
    return ret;
}
CVAPI(int) imgproc_floodFill2(cv::_InputOutputArray *image, cv::_InputOutputArray *mask,
                            MyCvPoint seedPoint, MyCvScalar newVal, MyCvRect *rect,
                            MyCvScalar loDiff, MyCvScalar upDiff, int flags)
{
    cv::Rect rect0;
    int ret = cv::floodFill(*image, *mask, cpp(seedPoint), cpp(newVal), &rect0, cpp(loDiff), cpp(upDiff), flags);
    *rect = c(rect0);
    return ret;
}

CVAPI(void) imgproc_cvtColor(cv::_InputArray *src, cv::_OutputArray *dst, int code, int dstCn)
{
    cv::cvtColor(*src, *dst, code, dstCn); 
}

CVAPI(MyCvMoments) imgproc_moments(cv::_InputArray *arr, int binaryImage )
{
    cv::Moments m = cv::moments(*arr, binaryImage != 0);
    return c(m);
}


CVAPI(void) imgproc_matchTemplate(cv::_InputArray *image, cv::_InputArray *templ,
    cv::_OutputArray *result, int method, cv::_InputArray *mask)
{
    cv::matchTemplate(*image, *templ, *result, method, entity(mask));
}

CVAPI(int) imgproc_connectedComponents(cv::_InputArray *image, cv::_OutputArray *labels,
    int connectivity, int ltype)
{
    return cv::connectedComponents(entity(image), entity(labels), connectivity, ltype);
}

CVAPI(int) imgproc_connectedComponentsWithStats(cv::_InputArray *image, cv::_OutputArray *labels,
    cv::_OutputArray *stats, cv::_OutputArray *centroids, int connectivity, int ltype)
{
    return cv::connectedComponentsWithStats(entity(image), entity(labels), entity(stats), entity(centroids), connectivity, ltype);
}

CVAPI(void) imgproc_findContours1_vector(cv::_InputOutputArray *image, std::vector<std::vector<cv::Point> > **contours,
    std::vector<cv::Vec4i> **hierarchy, int mode, int method, MyCvPoint offset)
{
    *contours = new std::vector<std::vector<cv::Point> >;
    *hierarchy = new std::vector<cv::Vec4i>;
    cv::findContours(*image, **contours, **hierarchy, mode, method, cpp(offset));
}
CVAPI(void) imgproc_findContours1_OutputArray(cv::_InputOutputArray *image, std::vector<cv::Mat> **contours,
    cv::_OutputArray *hierarchy, int mode, int method, CvPoint offset)
{
    *contours = new std::vector<cv::Mat>;
    cv::findContours(*image, **contours, *hierarchy, mode, method, offset);
}
CVAPI(void) imgproc_findContours2_vector(cv::_InputOutputArray *image, std::vector<std::vector<cv::Point> > **contours,
    int mode, int method, CvPoint offset)
{
    *contours = new std::vector<std::vector<cv::Point> >;
    cv::findContours(*image, **contours, mode, method, offset);
}
CVAPI(void) imgproc_findContours2_OutputArray(cv::_InputOutputArray *image, std::vector<cv::Mat> **contours,
    int mode, int method, CvPoint offset)
{
    *contours = new std::vector<cv::Mat>;
    cv::findContours(*image, **contours, mode, method, offset);
}

CVAPI(void) imgproc_approxPolyDP_InputArray(cv::_InputArray *curve, cv::_OutputArray *approxCurve, double epsilon, int closed)
{
    cv::approxPolyDP(*curve, *approxCurve, epsilon, closed != 0);
}
CVAPI(void) imgproc_approxPolyDP_Point(cv::Point *curve, int curveLength, std::vector<cv::Point> **approxCurve, double epsilon, int closed)
{
    cv::Mat_<cv::Point> curveMat(curveLength, 1, curve);
    *approxCurve = new std::vector<cv::Point>;
    cv::approxPolyDP(curveMat, **approxCurve, epsilon, closed != 0);
}
CVAPI(void) imgproc_approxPolyDP_Point2f(cv::Point2f *curve, int curveLength, std::vector<cv::Point2f> **approxCurve, double epsilon, int closed)
{
    cv::Mat_<cv::Point2f> curveMat(curveLength, 1, curve);
    *approxCurve = new std::vector<cv::Point2f>;
    cv::approxPolyDP(curveMat, **approxCurve, epsilon, closed != 0);
}

CVAPI(double) imgproc_arcLength_InputArray(cv::_InputArray *curve, int closed)
{
    return cv::arcLength(*curve, closed != 0);
}
CVAPI(double) imgproc_arcLength_Point(cv::Point *curve, int curveLength, int closed)
{
    cv::Mat_<cv::Point> curveMat(curveLength, 1, curve);
    return cv::arcLength(curveMat, closed != 0);
}
CVAPI(double) imgproc_arcLength_Point2f(cv::Point2f *curve, int curveLength, int closed)
{
    cv::Mat_<cv::Point2f> curveMat(curveLength, 1, curve);
    return cv::arcLength(curveMat, closed != 0);
}

CVAPI(MyCvRect) imgproc_boundingRect_InputArray(cv::_InputArray *curve)
{
    return c(cv::boundingRect(*curve));
}
CVAPI(MyCvRect) imgproc_boundingRect_Point(cv::Point *curve, int curveLength)
{
    cv::Mat_<cv::Point> curveMat(curveLength, 1, curve);
    return c(cv::boundingRect(curveMat));
}
CVAPI(MyCvRect) imgproc_boundingRect_Point2f(cv::Point2f *curve, int curveLength)
{
    cv::Mat_<cv::Point2f> curveMat(curveLength, 1, curve);
    return c(cv::boundingRect(curveMat));
}

CVAPI(double) imgproc_contourArea_InputArray(cv::_InputArray *contour, int oriented)
{
    return cv::contourArea(*contour, oriented != 0);
}
CVAPI(double) imgproc_contourArea_Point(cv::Point *contour, int contourLength, int oriented)
{
    cv::Mat_<cv::Point> contourMat(contourLength, 1, contour);
    return cv::contourArea(contourMat, oriented != 0);
}
CVAPI(double) imgproc_contourArea_Point2f(cv::Point2f *contour, int contourLength, int oriented)
{
    cv::Mat_<cv::Point2f> contourMat(contourLength, 1, contour);
    return cv::contourArea(contourMat, oriented != 0);
}

CVAPI(MyCvBox2D) imgproc_minAreaRect_InputArray(cv::_InputArray *points)
{
    return c(cv::minAreaRect(*points));
}
CVAPI(MyCvBox2D) imgproc_minAreaRect_Point(cv::Point *points, int pointsLength)
{
    cv::Mat_<cv::Point> pointsMat(pointsLength, 1, points);
    return c(cv::minAreaRect(pointsMat));
}
CVAPI(MyCvBox2D) imgproc_minAreaRect_Point2f(cv::Point2f *points, int pointsLength)
{
    cv::Mat_<cv::Point2f> pointsMat(pointsLength, 1, points);
    return c(cv::minAreaRect(pointsMat));
}

CVAPI(void) imgproc_minEnclosingCircle_InputArray(cv::_InputArray *points, cv::Point2f *center, float *radius)
{
    cv::Point2f center0;
    float radius0;
    cv::minEnclosingCircle(*points, center0, radius0);
    *center = center0;
    *radius = radius0;
}
CVAPI(void) imgproc_minEnclosingCircle_Point(cv::Point *points, int pointsLength, cv::Point2f *center, float *radius)
{
    cv::Mat_<cv::Point> pointsMat(pointsLength, 1, points);
    cv::Point2f center0;
    float radius0;
    cv::minEnclosingCircle(pointsMat, center0, radius0);
    *center = center0;
    *radius = radius0;
}
CVAPI(void) imgproc_minEnclosingCircle_Point2f(cv::Point2f *points, int pointsLength, cv::Point2f *center, float *radius)
{
    cv::Mat_<cv::Point2f> pointsMat(pointsLength, 1, points);
    cv::Point2f center0;
    float radius0;
    cv::minEnclosingCircle(pointsMat, center0, radius0);
    *center = center0;
    *radius = radius0;
}

CVAPI(double) imgproc_matchShapes_InputArray(cv::_InputArray *contour1, cv::_InputArray *contour2, int method, double parameter)
{
    return cv::matchShapes(*contour1, *contour2, method, parameter);
}
CVAPI(double) imgproc_matchShapes_Point(cv::Point *contour1, int contour1Length, cv::Point *contour2, int contour2Length, 
    int method, double parameter)
{
    cv::Mat_<cv::Point> contour1Mat(contour1Length, 1, contour1);
    cv::Mat_<cv::Point> contour2Mat(contour2Length, 1, contour2);
    return cv::matchShapes(contour1Mat, contour2Mat, method, parameter);
}

CVAPI(void) imgproc_convexHull_InputArray(cv::_InputArray *points, cv::_OutputArray *hull, int clockwise, int returnPoints)
{
    cv::convexHull(*points, *hull, clockwise != 0, returnPoints != 0);
}
CVAPI(void) imgproc_convexHull_Point_ReturnsPoints(cv::Point *points, int pointsLength, std::vector<cv::Point> **hull, int clockwise)
{
    cv::Mat_<cv::Point> pointsMat(pointsLength, 1, points);
    *hull = new std::vector<cv::Point>;
    cv::convexHull(pointsMat, **hull, clockwise != 0, true);
}
CVAPI(void) imgproc_convexHull_Point2f_ReturnsPoints(cv::Point2f *points, int pointsLength, std::vector<cv::Point2f> **hull, int clockwise)
{
    cv::Mat_<cv::Point2f> pointsMat(pointsLength, 1, points);
    *hull = new std::vector<cv::Point2f>;
    cv::convexHull(pointsMat, **hull, clockwise != 0, true);
}
CVAPI(void) imgproc_convexHull_Point_ReturnsIndices(cv::Point *points, int pointsLength, std::vector<int> **hull, int clockwise)
{
    cv::Mat_<cv::Point> pointsMat(pointsLength, 1, points);
    *hull = new std::vector<int>;
    cv::convexHull(pointsMat, **hull, clockwise != 0, false);
}
CVAPI(void) imgproc_convexHull_Point2f_ReturnsIndices(cv::Point2f *points, int pointsLength, std::vector<int> **hull, int clockwise)
{
    cv::Mat_<cv::Point2f> pointsMat(pointsLength, 1, points);
    *hull = new std::vector<int>;
    cv::convexHull(pointsMat, **hull, clockwise != 0, false);
}

CVAPI(void) imgproc_convexityDefects_InputArray(cv::_InputArray *contour, cv::_InputArray *convexHull, 
                                           cv::_OutputArray *convexityDefects)
{
    cv::convexityDefects(*contour, *convexHull, *convexityDefects);
}
CVAPI(void) imgproc_convexityDefects_Point(cv::Point *contour, int contourLength, int *convexHull, int convexHullLength, 
    std::vector<cv::Vec4i> **convexityDefects)
{
    cv::Mat_<cv::Point> contourMat(contourLength, 1, contour);
    cv::Mat_<int> convexHullMat(convexHullLength, 1,  convexHull);
    *convexityDefects = new std::vector<cv::Vec4i>;
    cv::convexityDefects(contourMat, convexHullMat, **convexityDefects);
}
CVAPI(void) imgproc_convexityDefects_Point2f(cv::Point2f *contour, int contourLength, int *convexHull, int convexHullLength,
    std::vector<cv::Vec4i> **convexityDefects)
{
    cv::Mat_<cv::Point2f> contourMat(contourLength, 1, contour);
    cv::Mat_<int> convexHullMat(convexHullLength, 1, convexHull);
    *convexityDefects = new std::vector<cv::Vec4i>;
    cv::convexityDefects(contourMat, convexHullMat, **convexityDefects);
}

CVAPI(int) imgproc_isContourConvex_InputArray(cv::_InputArray *contour)
{
    return cv::isContourConvex(*contour) ? 1 : 0;
}
CVAPI(int) imgproc_isContourConvex_Point(cv::Point *contour, int contourLength)
{
    cv::Mat_<cv::Point> contourMat(contourLength, 1, contour);
    return cv::isContourConvex(contourMat) ? 1 : 0;
}
CVAPI(int) imgproc_isContourConvex_Point2f(cv::Point2f *contour, int contourLength)
{
    cv::Mat_<cv::Point2f> contourMat(contourLength, 1, contour);
    return cv::isContourConvex(contourMat) ? 1 : 0;
}

CVAPI(float) imgproc_intersectConvexConvex_InputArray(cv::_InputArray *p1, cv::_InputArray *p2,
                                                      cv::_OutputArray *p12, int handleNested)
{
    return cv::intersectConvexConvex(*p1, *p2, *p12, handleNested != 0);
}
CVAPI(float) imgproc_intersectConvexConvex_Point(cv::Point *p1, int p1Length, cv::Point *p2, int p2Length,
    std::vector<cv::Point> **p12, int handleNested)
{
    cv::Mat_<cv::Point> p1Vec(p1Length, 1, p1);
    cv::Mat_<cv::Point> p2Vec(p2Length, 1, p2);
    *p12 = new std::vector<cv::Point>;
    return cv::intersectConvexConvex(p1Vec, p2Vec, **p12, handleNested != 0);
}
CVAPI(float) imgproc_intersectConvexConvex_Point2f(cv::Point2f *p1, int p1Length, cv::Point2f *p2, int p2Length,
    std::vector<cv::Point2f> **p12, int handleNested)
{
    cv::Mat_<cv::Point2f> p1Vec(p1Length, 1, p1);
    cv::Mat_<cv::Point2f> p2Vec(p2Length, 1, p2);
    *p12 = new std::vector<cv::Point2f>;
    return cv::intersectConvexConvex(p1Vec, p2Vec, **p12, handleNested != 0);
}

CVAPI(MyCvBox2D) imgproc_fitEllipse_InputArray(cv::_InputArray *points)
{
    return c(cv::fitEllipse(*points));
}
CVAPI(MyCvBox2D) imgproc_fitEllipse_Point(cv::Point *points, int pointsLength)
{
    cv::Mat_<cv::Point> pointsVec(pointsLength, 1, points);
    return c(cv::fitEllipse(pointsVec));
}
CVAPI(MyCvBox2D) imgproc_fitEllipse_Point2f(cv::Point2f *points, int pointsLength)
{
    cv::Mat_<cv::Point2f> pointsVec(pointsLength, 1, points);
    return c(cv::fitEllipse(pointsVec));
}

CVAPI(void) imgproc_fitLine_InputArray(cv::_InputArray *points, cv::_OutputArray *line, 
                                       int distType, double param, double reps, double aeps)
{
    cv::fitLine(*points, *line, distType, param, reps, aeps);
}
CVAPI(void) imgproc_fitLine_Point(cv::Point *points, int pointsLength, float *line, int distType,
    double param, double reps, double aeps)
{
    cv::Mat_<cv::Point> pointsVec(pointsLength, 1, points);
    cv::Mat_<float> lineVec(4, 1, line);
    cv::fitLine(pointsVec, lineVec, distType, param, reps, aeps);
}
CVAPI(void) imgproc_fitLine_Point2f(cv::Point2f *points, int pointsLength, float *line, int distType,
    double param, double reps, double aeps)
{
    cv::Mat_<cv::Point2f> pointsVec(pointsLength, 1, points);
    cv::Mat_<float> lineVec(4, 1, line);
    cv::fitLine(pointsVec, lineVec, distType, param, reps, aeps);
}
CVAPI(void) imgproc_fitLine_Point3i(cv::Point3i *points, int pointsLength, float *line, int distType,
    double param, double reps, double aeps)
{
    cv::Mat_<cv::Point3i> pointsVec(pointsLength, 1, points);
    cv::Mat_<float> lineVec(6, 1, line);
    cv::fitLine(pointsVec, lineVec, distType, param, reps, aeps);
}
CVAPI(void) imgproc_fitLine_Point3f(cv::Point3f *points, int pointsLength, float *line, int distType,
    double param, double reps, double aeps)
{
    cv::Mat_<cv::Point3f> pointsVec(pointsLength, 1, points);
    cv::Mat_<float> lineVec(6, 1, line);
    cv::fitLine(pointsVec, lineVec, distType, param, reps, aeps);
}

CVAPI(double) imgproc_pointPolygonTest_InputArray(cv::_InputArray *contour, MyCvPoint2D32f pt, int measureDist)
{
    return cv::pointPolygonTest(*contour, cpp(pt), measureDist != 0);
}
CVAPI(double) imgproc_pointPolygonTest_Point(cv::Point *contour, int contourLength, MyCvPoint2D32f pt, int measureDist)
{
    cv::Mat_<cv::Point> contourVec(contourLength, 1, contour);
    return cv::pointPolygonTest(contourVec, cpp(pt), measureDist != 0);
}
CVAPI(double) imgproc_pointPolygonTest_Point2f(cv::Point2f *contour, int contourLength, MyCvPoint2D32f pt, int measureDist)
{
    cv::Mat_<cv::Point2f> contourVec(contourLength, 1, contour);
    return cv::pointPolygonTest(contourVec, cpp(pt), measureDist != 0);
}

CVAPI(int) imgproc_rotatedRectangleIntersection_OutputArray(
    MyCvBox2D rect1, MyCvBox2D rect2, cv::_OutputArray *intersectingRegion)
{
    return cv::rotatedRectangleIntersection(cpp(rect1), cpp(rect2), *intersectingRegion);
}
CVAPI(int) imgproc_rotatedRectangleIntersection_vector(
    MyCvBox2D rect1, MyCvBox2D rect2, std::vector<cv::Point2f> *intersectingRegion)
{
    return cv::rotatedRectangleIntersection(cpp(rect1), cpp(rect2), *intersectingRegion);
}

CVAPI(void) imgproc_applyColorMap(cv::_InputArray *src, cv::_OutputArray *dst, int colormap)
{
    cv::applyColorMap(*src, *dst, colormap);
}

#pragma region Drawing

CVAPI(void) imgproc_line(
    cv::_InputOutputArray *img, MyCvPoint pt1, MyCvPoint pt2, MyCvScalar color,
    int thickness, int lineType, int shift)
{
    cv::line(*img, cpp(pt1), cpp(pt2), cpp(color), thickness, lineType, shift);
}

CVAPI(void) imgproc_arrowedLine(
    cv::_InputOutputArray *img, MyCvPoint pt1, MyCvPoint pt2, MyCvScalar color,
    int thickness, int line_type, int shift, double tipLength)
{
    cv::arrowedLine(*img, cpp(pt1), cpp(pt2), cpp(color), thickness, line_type, shift, tipLength);
}

CVAPI(void) imgproc_rectangle_InputOutputArray(
    cv::_InputOutputArray *img, MyCvPoint pt1, MyCvPoint pt2,
    MyCvScalar color, int thickness, int lineType, int shift)
{
    cv::rectangle(*img, cpp(pt1), cpp(pt2), cpp(color), thickness, shift);
}
CVAPI(void) imgproc_rectangle_Mat(
    cv::Mat *img, MyCvRect rect,
    MyCvScalar color, int thickness, int lineType, int shift)
{
    cv::rectangle(*img, cpp(rect), cpp(color), thickness, shift);
}

CVAPI(void) imgproc_circle(
    cv::_InputOutputArray *img, MyCvPoint center, int radius,
    MyCvScalar color, int thickness, int lineType, int shift)
{
    cv::circle(*img, cpp(center), radius, cpp(color), thickness, lineType, shift);
}

CVAPI(void) imgproc_ellipse1(
    cv::_InputOutputArray *img, MyCvPoint center, MyCvSize axes,
    double angle, double startAngle, double endAngle,
    MyCvScalar color, int thickness, int lineType, int shift)
{
    cv::ellipse(*img, cpp(center), cpp(axes), angle, startAngle, endAngle, cpp(color), thickness, lineType, shift);
}
CVAPI(void) imgproc_ellipse2(
    cv::_InputOutputArray *img, MyCvBox2D box, MyCvScalar color, int thickness, int lineType)
{
    cv::ellipse(*img, cpp(box), cpp(color), thickness, lineType);
}

CVAPI(void) imgproc_fillConvexPoly_Mat(
    cv::Mat *img, cv::Point *pts, int npts,    MyCvScalar color, int lineType, int shift)
{
    cv::fillConvexPoly(*img, pts, npts, cpp(color), lineType, shift);
}
CVAPI(void) imgproc_fillConvexPoly_InputOutputArray(
    cv::_InputOutputArray *img, cv::_InputArray *points, MyCvScalar color, int lineType, int shift)
{
    cv::fillConvexPoly(*img, *points, cpp(color), lineType, shift);
}

CVAPI(void) imgproc_fillPoly_Mat(cv::Mat *img, const cv::Point **pts, const int *npts,
    int ncontours, MyCvScalar color, int lineType, int shift, MyCvPoint offset)
{
    cv::fillPoly(*img, pts, npts, ncontours, cpp(color), lineType, shift, cpp(offset));
}
CVAPI(void) imgproc_fillPoly_InputOutputArray(cv::_InputOutputArray *img, cv::_InputArray *pts,
    MyCvScalar color, int lineType, int shift, MyCvPoint offset)
{
    cv::fillPoly(*img, *pts, cpp(color), lineType, shift, cpp(offset));
}

CVAPI(void) imgproc_polylines_Mat(
    cv::Mat *img, const cv::Point **pts, const int *npts,
    int ncontours, int isClosed, MyCvScalar color,
    int thickness, int lineType, int shift)
{
    cv::polylines(
        *img, pts, npts, ncontours, isClosed != 0, cpp(color), thickness, lineType, shift);
}
CVAPI(void) imgproc_polylines_InputOutputArray(
    cv::_InputOutputArray *img, cv::_InputArray *pts, int isClosed, MyCvScalar color,
    int thickness, int lineType, int shift)
{
    cv::polylines(*img, *pts, isClosed != 0, cpp(color), thickness, lineType, shift);
}

CVAPI(void) imgproc_drawContours_vector(cv::_InputOutputArray *image,
    cv::Point **contours, int contoursSize1, int *contoursSize2,
    int contourIdx, MyCvScalar color, int thickness, int lineType,
    cv::Vec4i *hierarchy, int hiearchyLength, int maxLevel, MyCvPoint offset)
{
    std::vector<std::vector<cv::Point> > contoursVec;
    for (int i = 0; i < contoursSize1; i++)
    {
        std::vector<cv::Point> c1(contours[i], contours[i] + contoursSize2[i]);
        contoursVec.push_back(c1);
    }
    std::vector<cv::Vec4i> hiearchyVec;
    if (hierarchy != NULL)
    {
        hiearchyVec = std::vector<cv::Vec4i>(hierarchy, hierarchy + hiearchyLength);
    }

    cv::drawContours(*image, contoursVec, contourIdx, cpp(color), thickness, lineType, hiearchyVec, maxLevel, cpp(offset));
}
CVAPI(void) imgproc_drawContours_InputArray(cv::_InputOutputArray *image,
    cv::Mat **contours, int contoursLength,
    int contourIdx, MyCvScalar color, int thickness, int lineType,
    cv::_InputArray *hierarchy, int maxLevel, MyCvPoint offset)
{
    std::vector<std::vector<cv::Point> > contoursVec(contoursLength);
    for (int i = 0; i < contoursLength; i++)
        contoursVec[i] = *contours[i];
    cv::drawContours(*image, contoursVec, contourIdx, cpp(color), thickness, lineType, entity(hierarchy), maxLevel, cpp(offset));
}

CVAPI(int) imgproc_clipLine1(MyCvSize imgSize, MyCvPoint *pt1, MyCvPoint *pt2)
{
    cv::Point pt1c = cpp(*pt1), pt2c = cpp(*pt2);
    bool result = cv::clipLine(cpp(imgSize), pt1c, pt2c);
    *pt1 = c(pt1c);
    *pt2 = c(pt2c);
    return result ? 1 : 0;
}
CVAPI(int) imgproc_clipLine2(MyCvRect imgRect, MyCvPoint *pt1, MyCvPoint *pt2)
{
    cv::Point pt1c = cpp(*pt1), pt2c = cpp(*pt2);
    bool result = cv::clipLine(cpp(imgRect), pt1c, pt2c);
    *pt1 = c(pt1c);
    *pt2 = c(pt2c);
    return result ? 1 : 0;
}

CVAPI(void) imgproc_ellipse2Poly(MyCvPoint center, MyCvSize axes, int angle, int arcStart, int arcEnd,
    int delta, std::vector<cv::Point> *pts)
{
    cv::ellipse2Poly(cpp(center), cpp(axes), angle, arcStart, arcEnd, delta, *pts);
}

CVAPI(void) core_putText(cv::_InputOutputArray *img, const char *text, MyCvPoint org,
    int fontFace, double fontScale, MyCvScalar color,
    int thickness, int lineType, int bottomLeftOrigin)
{
    cv::putText(*img, text, cpp(org), fontFace, fontScale, cpp(color), thickness, lineType, bottomLeftOrigin != 0);
}

CVAPI(MyCvSize) core_getTextSize(const char *text, int fontFace,
    double fontScale, int thickness, int *baseLine)
{
    return c(cv::getTextSize(text, fontFace, fontScale, thickness, baseLine));
}

#pragma endregion

#endif