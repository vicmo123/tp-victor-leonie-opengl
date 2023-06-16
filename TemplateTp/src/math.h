#ifndef MONPROJETSDL_MATH_H
#define MONPROJETSDL_MATH_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>

namespace hmg{ //help maths game
    struct vect2f{
        float x,y;
    };
    static float angleBetweenTwoVectors(hmg::vect2f position2, hmg::vect2f position1){
        //distance et direction vers le point2
        hmg::vect2f vectorFullDistance;
        vectorFullDistance .x = position2.x - position1.x;
        vectorFullDistance .y = position2.y - position1.y;
        float temp = vectorFullDistance.x / vectorFullDistance.y;
        //angle
        return (atan(temp)) * 180 /M_PI ;
    }
    static float Clamp(float value, float min, float max) {
        if (value < min)
            value = min;
        else if (value > max)
            value = max;
        return value;
    }

    static float Acos(float f) {
        return (float) acos(f);
    }

    struct vect3f{
        float x,y,z;

        static hmg::vect3f vectorZero(){
            return hmg::vect3f{0.0f, 0.0f, 0.0f};
        }

        static float magnitude(hmg::vect3f *value) {
            return (float) sqrt(value->x * value->x + value->y * value->y + value->z * value->z);
        }

        hmg::vect3f normalized() {
            return hmg::vect3f::normalize(this);
        }


        static hmg::vect3f normalize(hmg::vect3f *value) {
            const float kEpsilon = 0.00001F;

            float mag = magnitude(value);
            if (mag > kEpsilon) {
                return hmg::vect3f{value->x / mag, value->y / mag, value->z / mag};
            } else {
                delete value;
                return vectorZero();
            }
        }

        static hmg::vect3f *cross(hmg::vect3f lhs, hmg::vect3f rhs) {
            return new hmg::vect3f{
                    lhs.y * rhs.z - lhs.z * rhs.y,
                    lhs.z * rhs.x - lhs.x * rhs.z,
                    lhs.x * rhs.y - lhs.y * rhs.x};
        }

        static float dot(hmg::vect3f lhs, hmg::vect3f rhs) {
            return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
        }

        vect3f operator+=(const hmg::vect3f &rhs) {
            return hmg::vect3f{this->x += rhs.x, this->y += rhs.y, this->z += rhs.z};
        }

        vect3f operator-=(const hmg::vect3f &rhs) {
            return hmg::vect3f{this->x -= rhs.x, this->y -= rhs.y, this->z -= rhs.z};
        }

        vect3f operator*(const hmg::vect3f &rhs) {
            return hmg::vect3f{this->x * rhs.x, this->y * rhs.y, this->z * rhs.z};
        }

        vect3f operator*(float scalar) {
            return hmg::vect3f{this->x * scalar, this->y * scalar, this->z * scalar};
        }

        vect3f operator/(const hmg::vect3f &rhs) {
            return hmg::vect3f{this->x / rhs.x, this->y / rhs.y, this->z / rhs.z};
        }

        vect3f operator/(float scalar) {
            return hmg::vect3f{this->x / scalar, this->y / scalar, this->z / scalar};
        }



        static float Angle(hmg::vect3f from, hmg::vect3f to) {
            // sqrt(a) * sqrt(b) = sqrt(a * b) -- valid for real numbers
            float denominator = (float) sqrt(SqrMagnitude(from) * SqrMagnitude(to));
            if (denominator < 1e-15F)
                return 0.0f;

            float dotResult = Clamp(dot(from, to) / denominator, -1.0f, 1.0f);
            return ((float) Acos(dotResult)) * (1.0f / (M_PI * 2.0f / 360.0f));
        }

     static float signedAngle(hmg::vect3f from, hmg::vect3f to, hmg::vect3f axis)
        {
            float unsignedAngle = Angle(from, to);

            float cross_x = from.y * to.z - from.z * to.y;
            float cross_y = from.z * to.x - from.x * to.z;
            float cross_z = from.x * to.y - from.y * to.x;
            float sign = Sign(axis.x * cross_x + axis.y * cross_y + axis.z * cross_z);
            return unsignedAngle * sign;
        }

        static float Sign(float f) { return f >= 0.0f ? 1.0f : -1.0f; }

        static float SqrMagnitude(hmg::vect3f vector) {
            return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
        }

        void Scale(hmg::vect3f scale) {
            x *= scale.x;
            y *= scale.y;
            z *= scale.z;
        }

    };

    struct angles{
        static float toRadians(float degrees){
            return degrees * M_PI / 180.0;
        }

        static float toDegrees(float randians){
            return randians * 180.0 / M_PI;
        }
    };

    struct bounds2D{
        float top, right, bottom, left;
    };

    struct randomNumber{
        static int generateNumber(int minVal, int maxVal){
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(minVal, maxVal);

            return dist(mt);
        }

        static float generateNumberF(float minVal, float maxVal){

            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(minVal, maxVal);

            return dist(mt);
        }
    };

    struct color{
        float r,g,b;
    };
}
#endif //MONPROJETSDL_MATH_H
