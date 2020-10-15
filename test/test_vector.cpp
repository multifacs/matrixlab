#include <../gtest/gtest.h>
#include "MyVector.h"

TEST(Vector, can_create_vector_with_default_constructor)
{
	ASSERT_NO_THROW(Vector<int> v1);
}

TEST(Vector, can_create_vector_with_size_one)
{
	Vector<double> v1(1);
	EXPECT_EQ(1, v1.Length());
	EXPECT_EQ(0, v1[0]);

}

TEST(Vector, can_create_vector_with_one_value)
{
	Vector<int> v1(5, 10);

	EXPECT_EQ(5, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(10, v1[i]);
}

TEST(Vector, can_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, can_create_copied_vector)
{
	Vector<int> v(10);

	ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(Vector, copied_vector_is_equal_to_source)
{
	Vector<int>v1(10);
	Vector<int>v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(Vector, can_get_size)
{
	Vector<int> v(4);

	EXPECT_EQ(4, v.Length());
}

TEST(Vector, can_set_and_get_element)
{
	Vector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(Vector, cant_set_negative_index)
{
	Vector<int>P(2);
	ASSERT_ANY_THROW(P[-1]);
}

TEST(Vector, cant_set_bigger_index)
{
	Vector<int>P(10);
	ASSERT_ANY_THROW(P[10]);
}

TEST(Vector, can_assign_vector_to_itself)
{
	Vector<int>P(10);
	ASSERT_NO_THROW(P = P);
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
	Vector<int>A(10);
	Vector<int>B(10);
	ASSERT_NO_THROW(A = B);
	EXPECT_EQ(A, B);
}

TEST(Vector, can_assign_vectors_with_different_size)
{
	Vector<int>A(3);
	Vector<int>B(4);
	A = B;
	EXPECT_EQ(A.Length(), B.Length());
}

TEST(Vector, can_assign_vectors_with_different_sizes)
{
	Vector<int>A(10);
	Vector<int>B(12);
	ASSERT_NO_THROW(A = B);
	EXPECT_EQ(A, B);
}

TEST(Vector, equal_vectors_are_equal)
{

	Vector<int>A(10);
	Vector<int>B(10);
	EXPECT_EQ(A, B);
}

TEST(Vector, vector_is_equal_to_itself)
{
	Vector<int>A(10);
	EXPECT_EQ(A, A);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
	Vector<int>A(10);
	Vector<int>B(12);
	EXPECT_NE(A, B);
}

TEST(Vector, can_add_vectors_with_equal_size)
{
	Vector<int>A(3), B(3), C(3);
	for (int i = 0; i < A.Length(); i++)
	{
		A[i] = i;
		B[i] = 2 * i;
		C[i] = 3 * i;
	}
	A = A + B;
	EXPECT_EQ(A, C);
}

TEST(Vector, can_subtract_vectors_with_equal_size)
{
	Vector<int>A(3), B(3), C(3);
	for (int i = 0; i < A.Length(); i++)
	{
		A[i] = i;
		B[i] = 2 * i;
		C[i] = i;
	}
	B = B - A;
	EXPECT_EQ(A, C);
}

