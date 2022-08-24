#include <gtest/gtest.h>
#include <math/matrix/mat4f.hpp>
#include <math/core/transform.hpp>

TEST(TransformCase, shouldReturnIdentityMatrix) {
    // Arrange
    gooapi::math::Tmat4f tmp {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    // Act
    gooapi::math::Tmat4f I = gooapi::math::identity();
    bool isEqual = gooapi::math::isEqual(I, tmp); 
    // Assert
    ASSERT_TRUE(isEqual);
}

TEST(TransformCase, shouldReturnScaleFloatsMatrix) {
    // Arrange
    float x{8.9f}, y{9.1f}, z{1.3f};
    gooapi::math::Tmat4f scaleMat {
          x,  0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    // Act
    gooapi::math::Tmat4f out = gooapi::math::scale(x, y, z);
    bool isEqual = gooapi::math::isEqual(out, scaleMat);
    // Assert
    ASSERT_TRUE(isEqual);
}