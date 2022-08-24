#include <gtest/gtest.h>
#include <math/matrix/mat3f.hpp>
#include <math/matrix/mat4f.hpp>
#include <math/vector/vec4f.hpp>

TEST(StructTmat4fCase, shouldMatrixHave64Bytes) {
    ASSERT_EQ(sizeof(gooapi::math::Tmat4f), 4 * 4 * sizeof(float));
}

TEST(StructTmat4fCase, shouldReduceMat4ToMat3) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.6f, 1.8f, 3.1f,
        2.1f, 5.9f, 8.6f, 7.3f,
        7.8f, 9.1f, 3.1f, 3.2f,
        1.4f, 0.5f, 4.3f, 7.6f,
    };

    // Act
    gooapi::math::Tmat3f out = gooapi::math::reduce(3, 2, A);
    gooapi::math::Tmat3f tmp {
        4.7f, 1.8f, 3.1f,
        2.1f, 8.6f, 7.3f,
        1.4f, 4.3f, 7.6f,
    };

    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], tmp.mat[i][j]);
}

TEST(StructTmat4fCase, shouldMatrixEqual) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.6f, 1.8f, 3.1f,
        2.1f, 5.9f, 8.6f, 7.3f,
        7.8f, 9.1f, 3.1f, 3.2f,
        1.4f, 0.5f, 4.3f, 7.6f,
    };
    gooapi::math::Tmat4f B {
        4.7f, 2.6f, 1.8f, 3.1f,
        2.1f, 5.9f, 8.6f, 7.3f,
        7.8f, 9.1f, 3.1f, 3.2f,
        1.4f, 0.5f, 4.3f, 7.6f,
    };
    // Act
    bool isEqual = gooapi::math::isEqual(A, B);
    // Assert
    ASSERT_TRUE(isEqual);
}

TEST(StructTmat4fCase, shouldMatrixAddMatrix) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };
    gooapi::math::Tmat4f B {
        9.4f, 1.8f, 3.1f, 0.5f,
        1.0f, 6.3f, 9.5f, 2.1f,
        4.8f, 5.1f, 7.5f, 5.2f,
        9.2f, 1.1f, 5.1f, 2.8f
    };
    // Act
    gooapi::math::Tmat4f out = gooapi::math::add(A, B);
    // Assert
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] + B.mat[i][j]);
}

TEST(StructTmat4fCase, shouldMatrixMulScalar) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };

    float s = 7.2f;
    // Act
    gooapi::math::Tmat4f out = gooapi::math::mul(A, s);
    // Assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] * s);
}

TEST(StructTmat4fCase, shouldMatrixSubMatrix) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };
    gooapi::math::Tmat4f B {
        9.4f, 1.8f, 3.1f, 0.5f,
        1.0f, 6.3f, 9.5f, 2.1f,
        4.8f, 5.1f, 7.5f, 5.2f,
        9.2f, 1.1f, 5.1f, 2.8f
    };
    // Act
    gooapi::math::Tmat4f out = gooapi::math::sub(A, B);
    // Assert
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][j] - B.mat[i][j]);
}

TEST(StructTmat4fCase, shouldMatrixMulMatrix) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };
    gooapi::math::Tmat4f B {
        9.4f, 1.8f, 3.1f, 0.5f,
        1.0f, 6.3f, 9.5f, 2.1f,
        4.8f, 5.1f, 7.5f, 5.2f,
        9.2f, 1.1f, 5.1f, 2.8f
    };
    // Act
    gooapi::math::Tmat4f out = gooapi::math::mul(A, B);
    // Assert
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[i][0] * B.mat[0][j] +
                                           A.mat[i][1] * B.mat[1][j] +
                                           A.mat[i][2] * B.mat[2][j] +
                                           A.mat[i][3] * B.mat[3][j]);
}

TEST(StructTmat4fCase, shouldVectorMulMatrix) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };

    gooapi::math::Tvec4f v {
        7.6f, 1.8f, 5.4f, 9.1f
    };
    // Act
    gooapi::math::Tvec4f out = gooapi::math::mul(v, A);
    // Assert
    for (int i = 0; i < 4; i++)
        EXPECT_FLOAT_EQ(out.v[i], v.v[0] * A.mat[0][i] +
                                  v.v[1] * A.mat[1][i] +
                                  v.v[2] * A.mat[2][i] +
                                  v.v[3] * A.mat[3][i]);
}

TEST(StructTmat4fCase, shouldTranspseMatrix) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };
    // Act
    gooapi::math::Tmat4f out = gooapi::math::transpose(A);
    // Assert
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(out.mat[i][j], A.mat[j][i]);
}

TEST(StructTmat4fCase, shouldComputeMatrixDeterminant) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };

    float det{0.0f};
    float m{1.0f};

    for (int i = 0; i < 4; i++, m *= -1.0f)
        det += m * A.mat[0][i] * gooapi::math::det(gooapi::math::reduce(1, i + 1, A));
    
    // Act
    float out = gooapi::math::det(A);
    // Assert
    ASSERT_NEAR(out, det, 0.01f);
}

TEST(StructTmat4fCase, shouldComputeMatrixInverse) {
    // Arrange
    gooapi::math::Tmat4f A {
        4.7f, 2.5f, 8.4f, 9.0f,
        7.1f, 5.5f, 3.2f, 3.7f,
        8.7f, 2.6f, 1.4f, 2.5f,
        1.7f, 5.8f, 1.3f, 2.2f
    };
    
    gooapi::math::Tmat4f I {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Act
    gooapi::math::Tmat4f invA = gooapi::math::inverse(A);
    gooapi::math::Tmat4f tmp = gooapi::math::mul(A, invA);
    // Assert
    bool isEqual = gooapi::math::isEqual(tmp, I);
    ASSERT_TRUE(isEqual);
}