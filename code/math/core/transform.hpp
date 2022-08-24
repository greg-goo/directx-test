#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <math/matrix/mat4f.hpp>
#include <math/vector/vec3f.hpp>

namespace gooapi::math {

    Tmat4f identity();
    Tmat4f scale(float, float, float);
    Tmat4f scale(const Tvec3f&);

}

#endif