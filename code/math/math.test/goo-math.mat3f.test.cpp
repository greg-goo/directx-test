#include <gtest/gtest.h>
#include <math/matrix/mat2f.hpp>
#include <math/matrix/mat3f.hpp>
#include <math/vector/vec3f.hpp>

TEST(StructTmat3fCase, shouldMatrixHave36Bytes) {
    ASSERT_EQ(sizeof(gooapi::math::Tmat3f), 3 * 3 * sizeof(float));
}

TEST(StructTmat3fCase, shouldReduceMat3ToMat2) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.6f, 1.8f,
        2.1f, 5.9f, 8.6f,
        7.8f, 9.1f, 3.1f
    };

    // Act
    gooapi::math::Tmat2f out = gooapi::math::reduce(3, 2, A);
    gooapi::math::Tmat2f tmp {
        4.7f, 1.8f,
        2.1f, 8.6f
    };

    // Assert
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], tmp.mat[i][j]);
}

TEST(StructTmat3fCase, shouldMatrixEqual) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    gooapi::math::Tmat3f B {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    // Act
    bool isEqual = gooapi::math::isEqual(A, B);
    // Assert
    ASSERT_TRUE(isEqual);
}

TEST(StructTmat3fCase, shouldMatrixAddMatrix) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    gooapi::math::Tmat3f B {
        9.4f, 1.8f, 3.1f,
        1.0f, 6.3f, 9.5f,
        4.8f, 5.1f, 7.5f
    };
    // Act
    gooapi::math::Tmat3f out = gooapi::math::add(A, B);
    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] + B.mat[i][j]);
}

TEST(StructTmat3fCase, shouldMatrixMulScalar) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    float s = 7.2f;
    // Act
    gooapi::math::Tmat3f out = gooapi::math::mul(A, s);
    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] * s);
}

TEST(StructTmat3fCase, shouldMatrixSubMatrix) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    gooapi::math::Tmat3f B {
        9.4f, 1.8f, 3.1f,
        1.0f, 6.3f, 9.5f,
        4.8f, 5.1f, 7.5f
    };
    // Act
    gooapi::math::Tmat3f out = gooapi::math::sub(A, B);
    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] - B.mat[i][j]);
}

TEST(StructTmat3fCase, shouldMatrixMulMatrix) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    gooapi::math::Tmat3f B {
        9.4f, 1.8f, 3.1f,
        1.0f, 6.3f, 9.5f,
        4.8f, 5.1f, 7.5f
    };
    // Act
    gooapi::math::Tmat3f out = gooapi::math::mul(A, B);
    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][0] * B.mat[0][j] +
                                           A.mat[i][1] * B.mat[1][j] +
                                           A.mat[i][2] * B.mat[2][j]);
}

TEST(StructTmat3fCase, shouldVectorMulMatrix) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    gooapi::math::Tvec3f v {
        7.6f, 1.8f, 5.4f
    };
    // Act
    gooapi::math::Tvec3f out = gooapi::math::mul(v, A);
    // Assert
    for (int i = 0; i < 3; i++)
        EXPECT_FLOAT_EQ(out.v[i], v.v[0] * A.mat[0][i] +
                                  v.v[1] * A.mat[1][i] +
                                  v.v[2] * A.mat[2][i]);
}

TEST(StructTmat3fCase, shouldTranspseMatrix) {
    // Arrange
    gooapi::math::Tmat3f A {
        4.7f, 2.5f, 8.4f,
        7.1f, 5.5f, 3.2f,
        8.7f, 2.6f, 1.4f
    };
    // Act
    gooapi::math::Tmat3f out = gooapi::math::transpose(A);
    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[j][i]);
}

TEST(StructTmat3fCase, shouldComputeMatrixDeterminant) {
    // Arrange
    gooapi::math::Tmat3f A {
         2.0f, -5.0f, 3.0f,
         1.0f,  3.0f, 4.0f,
        -2.0f,  3.0f, 7.0f
    };
    float tmp = ((A.e11 * A.e22 * A.e33) +
                 (A.e12 * A.e23 * A.e31) +
                 (A.e13 * A.e21 * A.e32)) -
                ((A.e13 * A.e22 * A.e31) +
                 (A.e11 * A.e23 * A.e32) +
                 (A.e12 * A.e21 * A.e33));

    // Act
    float det = gooapi::math::det(A);
    // Assert
    ASSERT_FLOAT_EQ(det, tmp);
}

TEST(StructTmat3fCase, shouldComputeMatrixInverse) {
    // Arrange
    gooapi::math::Tmat3f A {
         2.0f, -5.0f, 3.0f,
         1.0f,  3.0f, 4.0f,
        -2.0f,  3.0f, 7.0f
    };
    
    gooapi::math::Tmat3f I {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    // Act
    gooapi::math::Tmat3f invA = gooapi::math::inverse(A);
    gooapi::math::Tmat3f tmp = gooapi::math::mul(A, invA);
    // Assert
    bool isEqual = gooapi::math::isEqual(tmp, I);
    ASSERT_TRUE(isEqual);
}
