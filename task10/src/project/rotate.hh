#ifndef ROTATE_HH
#define ROTATE_HH

#include <vector>

namespace my{
	void rotate(std::vector<double>& vect, int k) {
		if (k == 1 || k == -3)
		{
			double a = vect[1];
			vect[1] = vect[0];
			vect[0] = -a;
		}
		else
		if (k == 2 || k == -2)
		{
			vect[0] = -vect[0];
			vect[1] = -vect[1];
		}
		else
		if (k == 3 || k == -1)
		{
			double a = vect[0];
			vect[0] = vect[1];
			vect[1] = -a;
		}
		else
		if (k == 4 || k == 0 || k == -4)
		{
			vect[0] = vect[0];
			vect[1] = vect[1];
		};

	}
}
#endif
