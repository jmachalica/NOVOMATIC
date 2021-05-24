
#ifndef NOVOMATIC_VEC3_H
#define NOVOMATIC_VEC3_H
#include <cmath>
#include "Exception.h"

//check if floating point value is zero with some epsilon limit
bool isZero(float num, float eps=0.00001)
{

    if(  fabs( num-0)<=eps  )return true;
    return false;

}

struct vec3 {

    float x, y, z;

    vec3(float x = 0, float y = 0, float z = 0) : x{x}, y{y}, z{z} {}

    vec3 operator+(const vec3 v2) const {

        return vec3(v2.x + x, v2.y + y, v2.z + z);

    }

    vec3 operator-(const vec3 v2) const {

        return vec3(x - v2.x, y - v2.y, z - v2.z);

    }

    //vector scaling
    vec3 operator*(float s) const {

        return vec3(x * s, y * s, z * s);

    }

    //dot product
    float operator*(vec3 v2) const {

        return x * v2.x + y * v2.y + z * v2.z;

    }

    //vector scaling
    vec3 operator/(float s) const {

        if (!isZero(s)) { return vec3(x / s, y / s, z / s); }

        throw Exception("Vector division: Division by zero");
    }

    friend std::ostream &operator<<(std::ostream &os, const vec3 &vec) {
        return os << vec.x << " " << vec.y << " " << vec.z << std::endl;
    }

    //l2 norm of vector
    float vectorLength() const {

        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

    }

    // normalize vector -> length ==1
    vec3 normalize() const {

        float l = vectorLength();
        try {
            return *this / l;
        }
        catch (Exception &) {

            throw Exception("Vector length is 0, vector can't be normalized");

        }


    }


};

//center point from 2 points
vec3 center(vec3 v1, vec3 v2) {
    return (v1 + v2) / 2;
};



// sign/signum function
int sign(float n) {
    return (n > 0) - (n < 0);
}



#endif //NOVOMATIC_VEC3_H
