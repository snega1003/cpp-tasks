#ifndef OSTREAM_GUARD
#define OSTREAM_GUARD
#include <ostream>

class my_guard {
	std::ostream * stream;
	std::ios_base::fmtflags flag;
	std::ios::char_type fill;
public:
	my_guard(std::ostream & s) {
		stream = &s;
		flag = s.flags();
		fill = s.fill();
	}

	~my_guard() {
		(*stream).flags(flag);
		(*stream).fill(fill);

	}
};

#endif
