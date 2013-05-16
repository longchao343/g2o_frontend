#include "se3_prior.h"

SE3Prior::SE3Prior(const Eigen::Isometry3f& priorMean_, const Matrix6f& priorInformation_):
  _priorMean(priorMean_), _priorInformation(priorInformation_){
}

Vector6f SE3Prior::error(const Eigen::Isometry3f& invT) const {
    return t2v(invT*_priorMean);
  }

Matrix6f SE3Prior::jacobian(const Eigen::Isometry3f& invT) const {
    Matrix6f J;
    float epsilon = 1e-3;
    float iEpsilon = .5/epsilon;
    Vector6f incrementsUp=Vector6f::Zero();
    Vector6f incrementsDown=Vector6f::Zero();
    
    for (int i=0; i<J.cols(); i++){
      incrementsUp(i)=epsilon;
      incrementsDown(i)=-epsilon;
      J.col(i) = 
	iEpsilon *
	(error(v2t(incrementsUp)*invT)-error(v2t(incrementsDown)*invT));
      incrementsUp(i)=0;
      incrementsDown(i)=0;
    }
    return J;
  }

Matrix6f SE3Prior::jacobianZ(const Eigen::Isometry3f& invT) const {
  Matrix6f J;
  float epsilon = 1e-3;
  float iEpsilon = .5/epsilon;
  Vector6f incrementsUp=Vector6f::Zero();
  Vector6f incrementsDown=Vector6f::Zero();
  Eigen::Isometry3f savedPrior = _priorMean;
  for (int i=0; i<J.cols(); i++){
    incrementsUp(i)=epsilon;
    _priorMean = savedPrior * v2t(incrementsUp);
    Vector6f eUp = error(invT);
    
    incrementsDown(i)=-epsilon;
    _priorMean = savedPrior * v2t(incrementsDown);
    Vector6f eDown = error(invT);
    J.col(i) = iEpsilon*(eUp - eDown);
    incrementsUp(i)=0;
    incrementsDown(i)=0;
  }
  _priorMean = savedPrior;
  return J;
}


Matrix6f SE3Prior::errorInformation(const Eigen::Isometry3f& invT) const {
  Matrix6f Jz=jacobianZ(invT);
  Matrix6f iJz = Jz.inverse();
  return iJz.transpose()*_priorInformation*iJz;
}