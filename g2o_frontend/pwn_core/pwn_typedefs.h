#pragma once

#include <Eigen/Core>
#include "opencv2/core/core.hpp"
#include "../basemath/gaussian.h"

namespace pwn {

  /** \typedef Diagonal3f
   * \brief A 3x3 diagonal matrix.
   */
  typedef Eigen::DiagonalMatrix<float, 3> Diagonal3f;

  /** \typedef UnsignedCharImage
   * \brief An unsigned char cv::Mat.
   */
  typedef cv::Mat_<unsigned char> UnsignedCharImage;
  
  /** \typedef CharImage
   * \brief A char cv::Mat.
   */
  typedef cv::Mat_<char> CharImage;

  /** \typedef UnsignedShortImage
   * \brief An unsigned short cv::Mat.
   */
  typedef cv::Mat_<unsigned short> UnsignedShortImage;
  
  /** \typedef UnsignedIntImage
   * \brief An unsigned int cv::Mat.
   */
  typedef cv::Mat_<unsigned int> UnsignedIntImage;
  
  /** \typedef IntImage
   * \brief An int cv::Mat.
   */
  typedef cv::Mat_<int> IntImage;
  
  /** \typedef FloatImage
   * \brief A float cv::Mat.
   */
  typedef cv::Mat_<float> FloatImage;

  /** \typedef DoubleImage
   * \brief A double cv::Mat.
   */
  typedef cv::Mat_<double> DoubleImage;
  
  /** \typedef RawDepthImage
   * \brief An unsigned char cv::Mat used to for depth images with depth values expressed in millimeters.
   */
  typedef UnsignedShortImage RawDepthImage;
  
  /** \typedef IndexImage
   * \brief An int cv::Mat used to save the indeces of the points of a depth image inside a vector of points.
   */
  typedef IntImage IndexImage;
  
  /** \typedef DepthImage
   * \brief A float cv::Mat used to for depth images with depth values expressed in meters.
   */
  typedef FloatImage DepthImage;

  /** \typedef Gaussian3f
   * \brief A guassian in the 3D dimension.
   */
  typedef struct Gaussian<float, 3> Gaussian3f;

}
