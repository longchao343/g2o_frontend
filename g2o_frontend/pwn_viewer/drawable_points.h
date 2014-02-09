#pragma once

#include "g2o_frontend/pwn_core/homogeneousvector4f.h"
#include "drawable.h"
#include "gl_parameter_points.h"

using namespace pwn;

namespace pwn_viewer {

  class DrawablePoints : public Drawable {
  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    DrawablePoints();
    DrawablePoints(const Eigen::Isometry3f& transformation_, GLParameter *parameter_, PointVector *points_, NormalVector *normals_);
    virtual ~DrawablePoints() { glDeleteLists(_pointDrawList, 1); }

    virtual GLParameter* parameter() { return _parameter; };
    virtual PointVector* points() { return _points; }
    virtual NormalVector* normals() { return _normals; }
    inline GLuint pointDrawList() { return _pointDrawList; }
  
    virtual bool setParameter(GLParameter *parameter_);
    virtual void setPoints(PointVector *points_) { 
      _points = points_;
      updatePointDrawList();
    }
    virtual void setNormals(NormalVector *normals_) { 
      _normals = normals_; 
      updatePointDrawList();
    }  
    virtual void setPointsAndNormals(PointVector *points_, NormalVector *normals_) {
      _points = points_;
      _normals = normals_; 
      updatePointDrawList();
    }

    void setStep(int step_) {
      _parameter->setStep(step_);
      updatePointDrawList();
    }
    void setPointSize(float pointSize_) {
      _parameter->setPointSize(pointSize_);
      updatePointDrawList();
    }

    virtual void draw();
    virtual void updatePointDrawList();

  protected:
    GLParameterPoints *_parameter;
    PointVector *_points;
    NormalVector *_normals;
    std::vector<int> *_traversabilityVector;
    GLuint _pointDrawList; 
  };  

}
