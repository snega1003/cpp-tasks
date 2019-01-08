#include "rotate.hh"

void my::rotate(std::vector<double>& vect, int i) {
	if (i % 4 == 1 || i % 4 == -3)
	{
		double a = vect[1];
		vect[1] = -vect[0];
		vect[0] = a;
	}
	else
	if (i % 4 == 2 || i % 4 == -2)
	{
		vect[0] = -vect[0];
		vect[1] = -vect[1];
	}
	else
	if (i % 4 == 3 || i % 4 == -1)
	{
		double a = vect[0];
		vect[0] = -vect[1];
		vect[1] = a;
	}
}
