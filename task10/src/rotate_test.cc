#include <gtest/gtest.h>
#include <project/rotate.hh>

TEST(rotate_vec, correctness)
{
	std::vector<double> vector({ 10, 100 });
	std::vector<double> vector1({ -100, 10 });
	std::vector<double> vector2({ -10, -100 });
	std::vector<double> vector3({ 100, -10 });

	my::rotate(vector, 0);
	EXPECT_EQ(vector, vector);
	
	my::rotate(vector, 1);
  EXPECT_EQ(vector, vector1);

  my::rotate(vector, 2);
  EXPECT_EQ(vector, vector2);

  my::rotate(vector, 3);
  EXPECT_EQ(vector, vector3);

	my::rotate(vector, 4);
	EXPECT_EQ(vector, vector);

  my::rotate(vector, -1);
  EXPECT_EQ(vector, vector3);

  my::rotate(vector, -2);
  EXPECT_EQ(vector, vector2);

  my::rotate(vector, -3);
  EXPECT_EQ(vector, vector1);

	my::rotate(vector, -4);
	EXPECT_EQ(vector, vector);
}
