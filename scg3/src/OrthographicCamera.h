/**
 * \file OrthographicCamera.h
 * \brief A camera with orthographic projection(leaf node).
 *
 * \author Volker Ahlers\n
 *         volker.ahlers@fh-hannover.de
 */

#ifndef ORTHOGRAPHICCAMERA_H_
#define ORTHOGRAPHICCAMERA_H_

#include "scg_glew.h"
#include "Camera.h"

namespace scg {


/**
 * \brief A camera with orthographic projection(composite node).
 *
 * See Camera base class for further information.
 *
 * Initial parameters:\n
 * - left border: -1.0\n
 * - right border: 1.0\n
 * - bottom border: -1.0\n
 * - top border: 1.0\n
 * - near distance: -1.0\n
 * - far distance: 1.0\n
 */
class OrthographicCamera: public Camera {

public:

  OrthographicCamera();

  virtual ~OrthographicCamera();

  /**
   * Create shared pointer.
   */
  static OrthographicCameraSP create();

  /**
   * Initialize orthographic projection.
   * Aspect ratio is determined in updateProjection() from current viewport dimensions,
   * left and right borders are adjusted to comply with aspect ratio.
   *
   * \param left left border
   * \param right right border
   * \param bottom bottom border
   * \param top top border
   * \param near near distance
   * \param far far distance
   */
  void init(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top,
      GLfloat near, GLfloat far);

  /**
   * Update projection matrix from current viewport dimensions,
   * called by Renderer::render() (or derived class) if window has been resized.
   */
  virtual void updateProjection();

protected:

  GLfloat left_;
  GLfloat right_;
  GLfloat bottom_;
  GLfloat top_;
  GLfloat near_;
  GLfloat far_;

};


} /* namespace scg */

#endif /* ORTHOGRAPHICCAMERA_H_ */
