#include <gtest/gtest.h>
#include <math/vector/vec3f.hpp>

TEST(StructTvec3fCase, shouldVectorHaveTwelveBytes) {
    ASSERT_EQ(sizeof(gooapi::math::Tvec3f), 3 * sizeof(float));
}

TEST(StructTvec3fCase, shouldVectorsEquals) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{2.5f, 5.6f, 4.5f};
    // Act
    bool isEual = gooapi::math::isEqual(u, v);
    // Assert
    ASSERT_TRUE(isEual);
}

TEST(StructTvec3fCase, shouldVectorAddVector) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f uaddv = gooapi::math::add(u, v);
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_FLOAT_EQ(uaddv.v[i], u.v[i] + v.v[i]);
}

TEST(StructTvec3fCase, shouldVectorMulScalar) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    float s = 6.2f;
    // Act
    gooapi::math::Tvec3f umuls = gooapi::math::mul(u, s);
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_FLOAT_EQ(umuls.v[i], u.v[i] * s);
}

TEST(StructTvec3fCase, shouldVectorSubVector) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f usubs = gooapi::math::sub(u, v);
    gooapi::math::Tvec3f tmp = gooapi::math::add(u, gooapi::math::mul(v, -1));
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_FLOAT_EQ(usubs.v[i], tmp.v[i]);
}

TEST(StructTvec3fCase, shouldVectorIsZeroVector) {
    // Arrange
    gooapi::math::Tvec3f u{0.0f, 0.0f, 0.0f};
    // Act
    bool isZero = gooapi::math::isZero(u);
    // Assert
    ASSERT_TRUE(isZero);
}

TEST(StructTvec3fCase, shouldComputeVectorMagnitude) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    // Act
    float mag = gooapi::math::mag(u);
    // Assert
    ASSERT_NEAR(mag, std::sqrt(u.x * u.x + u.y * u.y + u.z * u.z), 0.01f);
}

TEST(StructTvec3fCase, shouldComputeVectorMagnitudeSqr) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    // Act
    float mag = gooapi::math::magsqr(u);
    // Assert
    ASSERT_NEAR(mag, u.x * u.x + u.y * u.y + u.z * u.z, 0.01f);
}

TEST(StructTvec3fCase, shouldNormalizeVector) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    // Act
    gooapi::math::Tvec3f n = gooapi::math::normalize(u);
    float mag = gooapi::math::mag(n);
    // Assert
    ASSERT_NEAR(mag, 1.0f, 0.01f);
}

TEST(StructTvec3fCase, shouldComputeDotProduct) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    float dot = gooapi::math::dot(u, v);
    // Assert
    ASSERT_NEAR(dot, u.x * v.x + u.y * v.y + u.z * v.z, 0.01f);
}

TEST(StructTvec3fCase, shouldNormalizedDotProductOfTwoVectorsEqualsCos) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f un = gooapi::math::normalize(u);
    gooapi::math::Tvec3f vn = gooapi::math::normalize(v);
    float magu = gooapi::math::mag(un);
    float magv = gooapi::math::mag(vn);
    float dot = gooapi::math::dot(un, vn);
    // Assert
    ASSERT_NEAR(dot, std::cos(dot / (magu * magv)), 0.1f);
}

TEST(StructTvec3fCase, shouldVectorsIsOrthogonal) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f cross = gooapi::math::cross(u, v);
    bool isOrthoU = gooapi::math::isOrtho(u, cross);
    bool isOrthoV = gooapi::math::isOrtho(v, cross);
    // Assert
    ASSERT_TRUE(isOrthoU && isOrthoV);
}

TEST(StructTvec3fCase, shouldVectorsIsAcuteAngle) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    bool isAcute = gooapi::math::isAcute(u, v);
    // Assert
    ASSERT_TRUE(isAcute);
}

TEST(StructTvec3fCase, shouldVectorsIsObtuseAngle) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    bool isObtuse = gooapi::math::isObtuse(u, v);
    // Assert
    ASSERT_FALSE(isObtuse);
}

TEST(StructTvec3fCase, shouldComputeCrossProduct) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f cross = gooapi::math::cross(u, v);
    gooapi::math::Tvec3f tmp{u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_NEAR(cross.v[i], tmp.v[i], 0.01f);
}

TEST(StructTvec3fCase, shouldComputeProjAndPrep) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f proj = gooapi::math::proj(u, v);
    gooapi::math::Tvec3f prep = gooapi::math::prep(u, v);
    gooapi::math::Tvec3f sum = gooapi::math::add(proj, prep);
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_NEAR(u.v[i], sum.v[i], 0.01f);
}

TEST(StructTvec3fCase, shouldComputeLittleCrossProductProperty) {
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f cross1 = gooapi::math::cross(u, v);
    gooapi::math::Tvec3f cross2 = gooapi::math::cross(gooapi::math::mul(v, -1), u);
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_NEAR(cross1.v[i], cross2.v[i], 0.01f);
}

TEST(StructTvec3fCase, shouldProveCommutativityOfAddition) { // przemienność dodawania
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    // Act
    gooapi::math::Tvec3f uaddv = gooapi::math::add(u, v);
    gooapi::math::Tvec3f vaddu = gooapi::math::add(v, u);
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_NEAR(uaddv.v[i], vaddu.v[i], 0.01f);
}

TEST(StructTvec3fCase, shouldProveAssociativeOfAddition) { // łączność dodawania
    // Arrange
    gooapi::math::Tvec3f u{2.5f, 5.6f, 4.5f};
    gooapi::math::Tvec3f v{6.3f, 2.7f, 1.9f};
    gooapi::math::Tvec3f w{7.1f, 6.8f, 9.2f};
    // Act
    gooapi::math::Tvec3f uaddvw = gooapi::math::add(u, gooapi::math::add(v, w));
    gooapi::math::Tvec3f uvaddw = gooapi::math::add(gooapi::math::add(u, v), w);
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_NEAR(uaddvw.v[i], uvaddw.v[i], 0.01f);
}