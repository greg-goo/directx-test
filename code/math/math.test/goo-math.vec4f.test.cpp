#include <gtest/gtest.h>
#include <math/vector/vec4f.hpp>

TEST(StructTvec4fCase, shouldVectorHaveSixteenBytes) {
    ASSERT_EQ(sizeof(gooapi::math::Tvec4f), 4 * sizeof(float));
}

TEST(StructTvec4fCase, shouldVectorsEquals) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    gooapi::math::Tvec4f v{2.5f, 5.6f, 4.5f, 1.4f};
    // Act
    bool isEual = gooapi::math::isEqual(u, v);
    // Assert
    ASSERT_TRUE(isEual);
}

TEST(StructTvec4fCase, shouldVectorAddVector) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    gooapi::math::Tvec4f v{6.3f, 2.7f, 1.9f, 5.7f};
    // Act
    gooapi::math::Tvec4f uaddv = gooapi::math::add(u, v);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(uaddv.v[i], u.v[i] + v.v[i]);
}

TEST(StructTvec4fCase, shouldVectorMulScalar) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    float s = 6.2f;
    // Act
    gooapi::math::Tvec4f umuls = gooapi::math::mul(u, s);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(umuls.v[i], u.v[i] * s);
}

TEST(StructTvec4fCase, shouldVectorSubVector) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    gooapi::math::Tvec4f v{6.3f, 2.7f, 1.9f, 5.7f};
    // Act
    gooapi::math::Tvec4f usubs = gooapi::math::sub(u, v);
    gooapi::math::Tvec4f tmp = gooapi::math::add(u, gooapi::math::mul(v, -1));
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_FLOAT_EQ(usubs.v[i], tmp.v[i]);
}

TEST(StructTvec4fCase, shouldVectorIsZeroVector) {
    // Arrange
    gooapi::math::Tvec4f u{0.0f, 0.0f, 0.0f, 0.0f};
    // Act
    bool isZero = gooapi::math::isZero(u);
    // Assert
    ASSERT_TRUE(isZero);
}

TEST(StructTvec4fCase, shouldComputeVectorMagnitude) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    // Act
    float m = gooapi::math::mag(u);
    // Assert
    ASSERT_NEAR(m, std::sqrt(u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w), 0.01f);
}

TEST(StructTvec4fCase, shouldComputeVectorMagnitudeSqr) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    // Act
    float mag = gooapi::math::magsqr(u);
    // Assert
    ASSERT_NEAR(mag, u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w, 0.01f);
}

TEST(StructTvec4fCase, shouldNormalizeVector) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    // Act
    gooapi::math::Tvec4f n = gooapi::math::normalize(u);
    float mag = gooapi::math::mag(n);
    // Assert
    ASSERT_NEAR(mag, 1.0f, 0.01f);
}

TEST(StructTvec4fCase, shouldComputeDotProduct) {
    // Arrange
    gooapi::math::Tvec4f u{2.5f, 5.6f, 4.5f, 1.4f};
    gooapi::math::Tvec4f v{6.3f, 2.7f, 1.9f, 5.7f};
    // Act
    float d = gooapi::math::dot(u, v);
    // Assert
    ASSERT_NEAR(d, u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w, 0.01f);
}
