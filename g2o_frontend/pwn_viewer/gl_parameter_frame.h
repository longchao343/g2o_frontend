#pragma once

#include "gl_parameter.h"
#include "gl_parameter_points.h"
#include "gl_parameter_normals.h"
#include "gl_parameter_covariances.h"
#include "gl_parameter_correspondences.h"

namespace pwn {

  class GLParameterFrame : public GLParameter {
  public: 
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
  
    GLParameterFrame(int step = 1);
    virtual ~GLParameterFrame();
  
    virtual void applyGLParameter() {}

    GLParameterPoints* parameterPoints() { return _parameterPoints; }
    void setParameterPoints(GLParameterPoints *parameterPoints_) { _parameterPoints = parameterPoints_; }

    GLParameterNormals* parameterNormals() { return _parameterNormals; }
    void setParameterNormals(GLParameterNormals *parameterNormals_) { _parameterNormals = parameterNormals_; }

    GLParameterCovariances* parameterCovariances() { return _parameterCovariances; }
    void setParameterCovariances(GLParameterCovariances *parameterCovariances_) { _parameterCovariances = parameterCovariances_; }

    GLParameterCorrespondences* parameterCorrespondences() { return _parameterCorrespondences; }
    void setParameterCorrespondences(GLParameterCorrespondences *parameterCorrespondences_) { _parameterCorrespondences = parameterCorrespondences_; }

  protected:
    GLParameterPoints *_parameterPoints;
    GLParameterNormals *_parameterNormals;
    GLParameterCovariances *_parameterCovariances;
    GLParameterCorrespondences *_parameterCorrespondences;
  };

}
