#include <../gtest/gtest.h>
#include "MyVector.h"

TEST(Vector, can_create_vector_with_default_constructor)
{
	ASSERT_NO_THROW(Vector<int> v1);
}

TEST(Vector, can_create_vector_with_size_one)
{
	Vector<double> v1(5.1);
	EXPECT_EQ(1, v1.Length());
	EXPECT_EQ(5.1, v1[0]);

}

TEST(Vector, can_create_vector_with_one_value)
{
	Vector<int> v1(5, 10);

	EXPECT_EQ(5, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(10, v1[i]);
}