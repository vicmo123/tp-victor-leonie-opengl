#include "Camera.h"

Camera::Camera(hmg::vect3f initialPosition, bool isDebug) : front(hmg::vect3f{0.0f, 0.0f, -1.0f}), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM)
{
    position = initialPosition;
    worldUp = hmg::vect3f{0.0f, 1.0f, 0.0f};
    yaw = YAW;
    pitch = PITCH;
    updateCameraVectors();

    this->isDebug = isDebug;
}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
void Camera::setView()
{
    gluLookAt(position.x, position.y, position.z, position.x + front.x, position.y + front.y, position.z + front.z, up.x, up.y, up.z);
}

// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void Camera::processKeyboard(Direction direction, float deltaTime)
{
    float velocity = movementSpeed * deltaTime;
    if (direction == FORWARD)
        position += front * velocity;
    if (direction == BACKWARD)
        position -= front * velocity;
    if (direction == LEFT)
        position -= right * velocity;
    if (direction == RIGHT)
        position += right * velocity;
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::processMouseMovement(float xOffset, float yOffset)
{
    bool constrainPitch = true;
    xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;
    yaw   += xOffset;
    if(isDebug)
        pitch -= yOffset;
    else
        pitch = 0.0;
    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }
    // update front, right and up Vectors using the updated Euler angles
    updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::processMouseScroll(float yOffset)
{
    zoom -= (float)yOffset;
    if (zoom < 1.0f)
        zoom = 1.0f;
    if (zoom > 45.0f)
        zoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    // calculate the new front vector
    hmg::vect3f newFront;
    newFront.x = cos(hmg::angles::toRadians(yaw)) * cos(hmg::angles::toRadians(pitch));
    newFront.y = sin(hmg::angles::toRadians(pitch));
    newFront.z = sin(hmg::angles::toRadians(yaw)) * cos(hmg::angles::toRadians(pitch));
    front = hmg::vect3f::normalize(&newFront);
    // also re-calculate the right and up vector
    right = hmg::vect3f::normalize(hmg::vect3f::cross(front, worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    up    = hmg::vect3f::normalize(hmg::vect3f::cross(right, front));
}

void Camera::setPosition(hmg::vect3f pos) {
    this->position = pos;
}

hmg::vect3f Camera::getPosition() const {
    return this->position;
}

hmg::vect3f Camera::getTargetPosition() const {
    //for aim in Gun class
    return hmg::vect3f{position.x + (front.x * 0.1f), position.y + front.y, position.z + (front.z * 0.1f)};
}

Camera::~Camera() {
}

float Camera::getYaw() const {
    return yaw;
}

const hmg::vect3f &Camera::getFront() const {
    return front;
}

const hmg::vect3f &Camera::getRight() const {
    return right;
}
