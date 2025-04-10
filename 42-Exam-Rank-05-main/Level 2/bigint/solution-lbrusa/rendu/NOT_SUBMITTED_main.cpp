#include "bigint.hpp"
#include <iostream>

int main(){
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b++ << std::endl;
	std::cout << "c = " << ++c << std::endl;
	std::cout << "d = " << d++ << std::endl;
	std::cout << "e = " << ++e << std::endl;

    std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	c++;c++;c++;c++;c++;c++;c++;c++;c++;c++;c++;c++;c++;c++;
	std::cout << "a+b " << a + b << std::endl;
    std::cout << "c+=a " << (c += a) << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "++b " << ++b << std::endl;
    std::cout << "b++ " << b++ << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "(b << 10) + 42 " << (b << 10) + 42 << std::endl;
    std::cout << "d<<=4 " << (d <<= 4) << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "d>>=(const bigint)2 " << (d >>= (const bigint)2) << std::endl;
	std::cout << "d<<=(const bigint)2 " << (d <<= (const bigint)2) << std::endl;
	// with bigint 0
	std::cout << "d>>=(const bigint)0 " << (d >>= (const bigint)0) << std::endl;
	std::cout << "d<<=(const bigint)0 " << (d <<= (const bigint)0) << std::endl;
	// with bigint -1 -- dont!!
	//std::cout << "d>>=(const bigint)-1 " << (d >>= (const bigint)-1) << std::endl;

	std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "d < a " << (d < a) << std::endl;
    std::cout << "d > a " << (d > a) << std::endl;
    std::cout << "d == a " << (d == a) << std::endl;
	// d = a;
	std::cout << "d == a " << (d == a) << std::endl;
    std::cout << "d != a " << (d != a) << std::endl;
    std::cout << "d <= a " << (d <= a) << std::endl;
    std::cout << "d >= a " << (d >= a) << std::endl;
	bigint f(0);
	bigint g(0);
	std::cout << "f == g " << (f == g) << std::endl;
	f++;g++;
	std::cout << "f == g " << (f == g) << std::endl;
	return 0;
}
