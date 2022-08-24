#include <gtest/gtest.h>
#include <math/matrix/mat2f.hpp>
#include <math/vector/vec2f.hpp>

TEST(StructTmat2fCase, shouldMatrixHave16Bytes) {
    ASSERT_EQ(sizeof(gooapi::math::Tmat2f), 2 * 2 * sizeof(float));
}

TEST(StructTmat2fCase, shouldMatrixEqual) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    gooapi::math::Tmat2f B {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    // Act
    bool isEqual = gooapi::math::isEqual(A, B);
    // Assert
    ASSERT_TRUE(isEqual);
}

TEST(StructTmat2fCase, shouldMatrixAddMatrix) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    gooapi::math::Tmat2f B {
        9.4f, 1.8f,
        1.0f, 6.3f
    };
    // Act
    gooapi::math::Tmat2f out = gooapi::math::add(A, B);
    // Assert
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] + B.mat[i][j]);
}

TEST(StructTmat2fCase, shouldMatrixMulScalar) {
    // Arrange
     gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    float s = 7.2f;
    // Act
    gooapi::math::Tmat2f out = gooapi::math::mul(A, s);
    // Assert
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] * s);
}

TEST(StructTmat2fCase, shouldMatrixSubMatrix) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    gooapi::math::Tmat2f B {
        9.4f, 1.8f,
        1.0f, 6.3f
    };
    // Act
    gooapi::math::Tmat2f out = gooapi::math::sub(A, B);
    // Assert
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] - B.mat[i][j]);
}

TEST(StructTmat2fCase, shouldMatrixMulMatrix) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    gooapi::math::Tmat2f B {
        9.4f, 1.8f,
        1.0f, 6.3f
    };
    // Act
    gooapi::math::Tmat2f out = gooapi::math::mul(A, B);
    // Assert
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][0] * B.mat[0][j] +
                                           A.mat[i][1] * B.mat[1][j]);
}

TEST(StructTmat2fCase, shouldVectorMulMatrix) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    gooapi::math::Tvec2f v {
        7.6f, 1.8f
    };
    // Act
    gooapi::math::Tvec2f out = gooapi::math::mul(v, A);
    // Assert
    for (int i = 0; i < 2; i++)
        EXPECT_FLOAT_EQ(out.v[i], v.v[0] * A.mat[0][i] +
                                  v.v[1] * A.mat[1][i]);
}

TEST(StructTmat2fCase, shouldTranspseMatrix) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    // Act
    gooapi::math::Tmat2f out = gooapi::math::transpose(A);
    // Assert
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[j][i]);
}

TEST(StructTmat2fCase, shouldComputeMatrixDeterminant) {
    // Arrange
    gooapi::math::Tmat2f A {
        4.7f, 2.5f,
        7.1f, 5.5f
    };
    float tmp = (A.e11 * A.e22 - A.e12 * A.e21);
    // Act
    float det = gooapi::math::det(A);
    // Assert
    ASSERT_FLOAT_EQ(det, tmp);
}

TEST(StructTmat2fCase, shouldComputeMatrixInverse) {
    // Arrange
    gooapi::math::Tmat2f A {
        3.0f, 0.0f,
       -1.0f, 2.0f
    };
    gooapi::math::Tmat2f I {
        1.0f, 0.0f,
        0.0f, 1.0f
    };
    // Act
    gooapi::math::Tmat2f invA = gooapi::math::inverse(A);
    gooapi::math::Tmat2f tmp = gooapi::math::mul(A, invA);
    // Assert
    bool isEqual = gooapi::math::isEqual(tmp, I);
    ASSERT_TRUE(isEqual);
}