#include "bigint.hpp"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const bigint& bi) { // this is why digits needs to be public
	for (size_t i = 0; i < bi.digits.size(); ++i)
		os << bi.digits[i];
	return os;
}
