#include <gtest/gtest.h>
#include <math/vector/vec2f.hpp>

TEST(StructTvec2fCase, shouldVectorHaveEightBytes) {
    ASSERT_EQ(sizeof(gooapi::math::Tvec2f), 2 * sizeof(float));
}

TEST(StructTvec2fCase, shouldVectorsEqual) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{2.5f, 5.6f};
    // Act
    bool isEual = gooapi::math::isEqual(u, v);
    // Assert
    ASSERT_TRUE(isEual);
}

TEST(StructTvec2fCase, shouldVectorAddVector) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f,};
    gooapi::math::Tvec2f v{6.3f, 2.7f,};
    // Act
    gooapi::math::Tvec2f uaddv = gooapi::math::add(u, v);
    // Assert
    for (int i = 0; i < 2; i++)
        ASSERT_FLOAT_EQ(uaddv.v[i], u.v[i] + v.v[i]);
}

TEST(StructTvec2fCase, shouldVectorMulScalar) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    float s = 6.2f;
    // Act
    gooapi::math::Tvec2f umuls = gooapi::math::mul(u, s);
    // Assert
    for (int i = 0; i < 2; i++)
        ASSERT_FLOAT_EQ(umuls.v[i], u.v[i] * s);
}

TEST(StructTvec2fCase, shouldVectorSubVector) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{6.3f, 2.7f};
    // Act
    gooapi::math::Tvec2f usubs = gooapi::math::sub(u, v);
    gooapi::math::Tvec2f tmp = gooapi::math::add(u, gooapi::math::mul(v, -1));
    // Assert
    for (int i = 0; i < 2; i++)
        ASSERT_FLOAT_EQ(usubs.v[i], tmp.v[i]);
}

TEST(StructTvec2fCase, shouldVectorIsZeroVector) {
    // Arrange
    gooapi::math::Tvec2f u{0.0f, 0.0f};
    // Act
    bool isZero = gooapi::math::isZero(u);
    // Assert
    ASSERT_TRUE(isZero);
}

TEST(StructTvec2fCase, shouldComputeVectorMagnitude) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    // Act
    float mag = gooapi::math::mag(u);
    // Assert
    ASSERT_NEAR(mag, std::sqrt(u.x * u.x + u.y * u.y), 0.01f);
}

TEST(StructTvec2fCase, shouldComputeVectorMagnitudeSqr) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    // Act
    float mag = gooapi::math::magsqr(u);
    // Assert
    ASSERT_NEAR(mag, u.x * u.x + u.y * u.y, 0.01f);
}

TEST(StructTvec2fCase, shouldNormalizeVector) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    // Act
    gooapi::math::Tvec2f n = gooapi::math::normalize(u);
    float mag = gooapi::math::mag(n);
    // Assert
    ASSERT_NEAR(mag, 1.0f, 0.01f);
}

TEST(StructTvec2fCase, shouldComputeDotProduct) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{6.3f, 2.7f};
    // Act
    float d = gooapi::math::dot(u, v);

    // Assert
    ASSERT_NEAR(d, u.x * v.x + u.y * v.y, 0.01f);
}

TEST(StructTvec2fCase, shouldNormalizedDotProductOfTwoVectorsEqualsCos) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{6.3f, 2.7f};
    // Act
    gooapi::math::Tvec2f un = gooapi::math::normalize(u);
    gooapi::math::Tvec2f vn = gooapi::math::normalize(v);
    float magu = gooapi::math::mag(un);
    float magv = gooapi::math::mag(vn);
    float d = gooapi::math::dot(un, vn);
    // Assert
    ASSERT_NEAR(d, std::cos(d/ (magu * magv)), 0.1f); // słaba dokładność
}

TEST(StructTvec2fCase, shouldVectorsIsOrthogonal) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{5.6f, -2.5f};
    // Act
    bool isOrtho = gooapi::math::isOrtho(u, v);
    // Assert
    ASSERT_TRUE(isOrtho);
}

TEST(StructTvec2fCase, shouldVectorsIsAcuteAngle) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{6.3f, 2.7f};
    // Act
    bool isAcute = gooapi::math::isAcute(u, v);
    // Assert
    ASSERT_TRUE(isAcute);
}

TEST(StructTvec2fCase, shouldVectorsIsObtuseAngle) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{6.3f, 2.7f};
    // Act
    bool isObtuse = gooapi::math::isObtuse(u, v);
    // Assert
    ASSERT_FALSE(isObtuse);
}

TEST(StructTvec2fCase, shouldComputeProjAndPrep) {
    // Arrange
    gooapi::math::Tvec2f u{2.5f, 5.6f};
    gooapi::math::Tvec2f v{6.3f, 2.7f};
    // Act
    gooapi::math::Tvec2f proj = gooapi::math::proj(u, v);
    gooapi::math::Tvec2f prep = gooapi::math::prep(u, v);
    gooapi::math::Tvec2f sum = gooapi::math::add(proj, prep);
    // Assert
    for (int i = 0; i < 2; i++)
        ASSERT_NEAR(u.v[i], sum.v[i], 0.01f);
}