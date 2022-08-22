#include <gtest/gtest.h>
#include <vector/vec-comp.hpp>
#include <cmath>

TEST(VectorAsmAlgorithms, shouldCalculateMagnitude) {
    // Arrange
    xmmword xw{2.0f, 5.0f, 6.2f, 8.7f};
    // Act
    float mag = gooapi::math::vec4f_mag_asm_impl(xw);
    // Assert
    ASSERT_FLOAT_EQ(mag, std::sqrt(
        xw.mF32[0] * xw.mF32[0] +
        xw.mF32[1] * xw.mF32[1] +
        xw.mF32[2] * xw.mF32[2] +
        xw.mF32[3] * xw.mF32[3] ));
}

TEST(VectorAsmAlgorithms, shouldCalculateDotProduct) {
    // Arrange
    xmmword xwA{2.0f, 5.0f, 8.9f, 4.5f};
    xmmword xwB{7.0f, 4.0f, 6.3f, 2.1f};
    // Act
    float mag = gooapi::math::vec4f_dot_product_asm_impl(xwA, xwB);
    // Assert
    ASSERT_FLOAT_EQ(mag,
        xwA.mF32[0] * xwB.mF32[0] +
        xwA.mF32[1] * xwB.mF32[1] +
        xwA.mF32[2] * xwB.mF32[2] +
        xwA.mF32[3] * xwB.mF32[3] );
}

TEST(VectorAsmAlgorithms, shouldCalculateCrossProduct) {
    // Arrange
    xmmword xwA{2.0f, 5.0f, 8.9f};
    xmmword xwB{7.0f, 4.0f, 6.3f};
    xmmword xwOut{};
    xmmword xwTmp{};
    // Act
    gooapi::math::vec4f_cross_product_asm_impl(xwA, xwB, xwOut);
    xwTmp.mF32[0] = xwA.mF32[1] * xwB.mF32[2] - xwA.mF32[2] * xwB.mF32[1];
    xwTmp.mF32[1] = xwA.mF32[2] * xwB.mF32[0] - xwA.mF32[0] * xwB.mF32[2];
    xwTmp.mF32[2] = xwA.mF32[0] * xwB.mF32[1] - xwA.mF32[1] * xwB.mF32[0];
    // Assert
    for (int i = 0; i < 3; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwTmp.mF32[i]);
}

TEST(VectorAsmAlgorithms, shouldReturnNormalizedVector) {
    // Arrange
    xmmword xwIn{2.0f, 5.0f, 2.1f, 3.4f};
    xmmword xwOut{};
    // Act
    gooapi::math::vec4f_normalize_asm_impl(xwIn, xwOut);
    float mag = gooapi::math::vec4f_mag_asm_impl(xwOut);
    // Assert
    ASSERT_FLOAT_EQ(mag, 1.0f);
}

TEST(VectorAsmAlgorithms, shouldCalculateScalarAddition) {
    // Arrange
    xmmword xwIn{2.0f, 5.0f, 3.2f, 1.7f};
    xmmword xwOut{};
    float a = 6.7;
    // Act
    gooapi::math::vec4f_scalar_add_asm_impl(a, xwIn, xwOut);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwIn.mF32[i] + a);
}

TEST(VectorAsmAlgorithms, shouldCalculateVectorAddintion) {
    // Arrange
    xmmword xwA{2.0f, 5.0f, 3.1f, 6.2f};
    xmmword xwB{7.2f, 8.3f, 1.4f, 5.5f};
    xmmword xwOut{};
    // Act
    gooapi::math::vec4f_vector_add_asm_impl(xwA, xwB, xwOut);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwA.mF32[i] + xwB.mF32[i]);
}

TEST(VectorAsmAlgorithms, shouldCalculateScalarSubstraction) {
    // Arrange
    xmmword xwIn{2.0f, 5.0f, 6.5f, 3.7f};
    xmmword xwOut{};
    float a = 6.7;
    // Act
    gooapi::math::vec4f_scalar_sub_asm_impl(a, xwIn, xwOut);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwIn.mF32[i] - a);
}

TEST(VectorAsmAlgorithms, shouldCalculateVectorSubstraction) {
    // Arrange
    xmmword xwA{2.0f, 5.0f, 4.6f, 1.5f};
    xmmword xwB{7.2f, 8.3f, 7.4f, 2.2f};
    xmmword xwOut{};
    // Act
    gooapi::math::vec4f_vector_sub_asm_impl(xwA, xwB, xwOut);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwA.mF32[i] - xwB.mF32[i]);
}

TEST(VectorAsmAlgorithms, shouldCalculateScalarMultiplication) {
    // Arrange
    xmmword xwIn{2.0f, 5.0f, 9.2f, 5.2f};
    xmmword xwOut{};
    float a = 6.7;
    // Act
    gooapi::math::vec4f_scalar_mul_asm_impl(a, xwIn, xwOut);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwIn.mF32[i] * a);
}

TEST(VectorAsmAlgorithms, shouldCalculateVectorMultiplication) {
    // Arrange
    xmmword xwA{2.0f, 5.0f, 4.5f, 2.1f};
    xmmword xwB{7.2f, 8.3f, 8.8f, 3.1f};
    xmmword xwOut{};
    // Act
    gooapi::math::vec4f_vector_mul_asm_impl(xwA, xwB, xwOut);
    // Assert
    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(xwOut.mF32[i], xwA.mF32[i] * xwB.mF32[i]);
}
