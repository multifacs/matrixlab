#include <../gtest/gtest.h>
#include "MyMatrix.h"

TEST(Matrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(Matrix<int> m(5));
}

TEST(Matrix, cant_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(Matrix<int> m(-5));
}

TEST(Matrix, retrieve_value_from_filled_matrix)
{
	Matrix<int> m(5, 1);
	EXPECT_EQ(m[2][2], 1);
}

TEST(Matrix, can_create_copied_matrix)
{
	Matrix<int> m(5);

	ASSERT_NO_THROW(Matrix<int> m1(m));
}

TEST(Matrix, copied_matrix_is_equal_to_source_one)
{
	Matrix<int> m(5);
	Matrix<int>m1(m);
	EXPECT_EQ(m, m1);
}

TEST(Matrix, can_get_size)
{
	Matrix<int>Res(10);
	EXPECT_EQ(Res.get_rows(), 10);
}

TEST(Matrix, can_set_and_get_element)
{
	Matrix<int>Res(10);
	Res[1][1] = 2;
	EXPECT_EQ(Res[1][1], 2);
}

TEST(Matrix, throws_when_set_element_with_negative_index)
{
	Matrix<int>res(1);
	ASSERT_ANY_THROW(res[-1][-2]);
}

TEST(Matrix, throws_when_set_element_with_too_large_index)
{
	Matrix<int>res(10);
	ASSERT_ANY_THROW(res[10 + 3]);
}

TEST(Matrix, can_assign_matrix_to_itself)
{
	Matrix<int>res(10);
	ASSERT_NO_THROW(res = res);
}

TEST(Matrix, can_assign_matrices_of_equal_size)
{
	Matrix<int>res(10);
	for (int i = 0; i < res.get_rows(); i++)
	{
		for (int j = i; j < res[i].Length() + i; j++)
		{
			res[i][j] = j;
		}
	}
	Matrix<int>B(10);
	B = res;
	EXPECT_EQ(B, res);
}

TEST(Matrix, assign_operator_change_matrix_size)
{
	Matrix<int>A(10);
	Matrix<int>B(1);
	B = A;
	EXPECT_EQ(B.get_rows(), 10);
}

TEST(Matrix, can_assign_matrices_of_different_size)
{
	Matrix<int>A(10);
	Matrix<int>B(1);
	B = A;
	EXPECT_EQ(A, B);
}

TEST(Matrix, compare_equal_matrices_return_true)
{
	Matrix<int>A(10);
	Matrix<int>B(1);
	B = A;
	EXPECT_EQ(B, A);
}

TEST(Matrix, compare_matrix_with_itself_return_true)
{
	Matrix<int>A(10);
	EXPECT_EQ(A, A);
}

TEST(Matrix, matrices_with_different_size_are_not_equal)
{
	Matrix<int>A(10);
	Matrix<int>B(1);
	EXPECT_NE(A, B);
}

TEST(Matrix, can_add_matrices_with_equal_size)
{
	Matrix<int>A(10);
	Matrix<int>B(10);
	ASSERT_NO_THROW(A + B);
}

TEST(Matrix, cant_add_matrices_with_not_equal_size)
{
	Matrix<int>A(10);
	Matrix<int>B(11);
	ASSERT_ANY_THROW(A + B);
}

TEST(Matrix, can_subtract_matrices_with_equal_size)
{
	Matrix<int>A(10);
	Matrix<int>B(10);
	ASSERT_NO_THROW(A - B);
}

TEST(Matrix, cant_subtract_matrixes_with_not_equal_size)
{
	Matrix<int>A(10);
	Matrix<int>B(20);
	ASSERT_ANY_THROW(A - B);
}
