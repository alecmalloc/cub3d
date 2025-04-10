#include "bigint.hpp"

std::ostream& operator<<( std::ostream& os, const bigint bi ){
	for( size_t i = 0; i < bi.numbers.size(); i++ )
		os << bi.numbers[i];
	return( os );
}
