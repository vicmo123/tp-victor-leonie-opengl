#ifndef FIRST3D_CAMERA_H
#define FIRST3D_CAMERA_H

#include "math.h"
#include <cmath>

#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Direction.h"
#include "Input.h"

// Default camera values
const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
private:
    // camera Attributes
    hmg::vect3f position;
    hmg::vect3f front;
    hmg::vect3f up;
    hmg::vect3f right;
    hmg::vect3f worldUp;

    // euler Angles
    float yaw;
    float pitch;

    // camera options
    float movementSpeed;
    float mouseSensitivity;
    float zoom;
    bool isDebug;

    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
public:
    Camera(hmg::vect3f initialPosition, bool isDebug);
    // returns the view matrix calculated using Euler Angles(gluLookAt())
    void setView();
    // processes input received from any keyboard-like input system. Accepts input parameter in the form of Direction ENUM
    void processKeyboard(Direction direction, float deltaTime);
    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void processMouseMovement(float xOffset, float yOffset);
    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void processMouseScroll(float yOffset);
    void setPosition(hmg::vect3f pos);
    hmg::vect3f getPosition() const;
    hmg::vect3f getTargetPosition() const;
    const hmg::vect3f &getFront() const;
    const hmg::vect3f &getRight() const;
    float getYaw() const;
    virtual ~Camera();
};

#endif //FIRST3D_CAMERA_H
