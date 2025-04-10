#pragma once

#include <cstdint>
#include <deque>
#include <ostream>
#include <string>

struct bigint {
	std::deque<int> digits; // each digit is a int, so substraction carry logic is easier. public because it's useful
	bigint() : digits(1) {} // default ctor: only one digit (namely 0)
	bigint(size_t init) {
		while (init) {
			digits.push_front(static_cast<int>(init % 10));
			init /= 10;
		}
		if (digits.empty()) // when passing 0 explicitly, no digits will have been pushed, hence this
			digits.push_front(0);
	}
	bigint(const bigint& other) : digits(other.digits) {} // trivial
	bigint &operator=(const bigint& other) {
		digits = other.digits;
		return *this;
	}

	bigint operator+(const bigint& other) const {
		return add_or_substract(other, true);
	}

	bigint operator-(const bigint& other) const {
		(void)other;
		return bigint(0);
	}

	bigint operator+=(const bigint& other) {
		*this = add_or_substract(other, true);
		return *this;
	}

	bigint operator++() {
		*this = add_or_substract(bigint(1), true);
		return *this;
	}

	bigint operator++(int) {
		bigint old_val(*this);
		*this = add_or_substract(bigint(1), true);
		return old_val;
	}

	bigint operator<<(int lshift) const {
		bigint copy(*this);
		if (digits.size() == 1 && digits[0] == 0)
			return copy;
		for (int i = 0; i < lshift; ++i)
			copy.digits.push_back(0);
		return copy;
	}

	bigint operator>>(int rshift) const {
		bigint copy(*this);
		for (int i = 0; i < rshift; ++i) {
			if (!copy.digits.empty())
				copy.digits.pop_back();
			else {
				copy.digits.push_front(0); // restore 0
				break;
			}
		}
		return copy;
	}

	bigint operator<<(const bigint& lshift) const {
		bigint copy(*this);
		if (digits.size() == 1 && digits[0] == 0)
			return copy;
		for (bigint i; i < lshift; ++i) {
			copy.digits.push_back(0);
		}
		return copy;
	}

	bigint operator>>(const bigint& rshift) const {
		bigint copy(*this);
		for (bigint i = 0; i < rshift; ++i) {
			if (!copy.digits.empty())
				copy.digits.pop_back();
			else {
				copy.digits.push_front(0); // restore 0
				break;
			}
		}
		return copy;
	}

	bigint operator<<=(int lshift) {
		if (digits.size() == 1 && digits[0] == 0)
			return *this;
		for (int i = 0; i < lshift; ++i)
			digits.push_back(0);
		return *this;
	}

	bigint operator>>=(int rshift) {
		for (int i = 0; i < rshift; ++i) {
			if (!digits.empty())
				digits.pop_back();
			else {
				digits.push_front(0); // restore 0
				break;
			}
		}
		return *this;
	}

	bigint operator<<=(const bigint& lshift) {
		if (digits.size() == 1 && digits[0] == 0)
			return *this;
		for (bigint i; i < lshift; ++i) {
			digits.push_back(0);
		}
		return *this;
	}

	bigint operator>>=(const bigint& rshift) {
		for (bigint i = 0; i < rshift; ++i) {
			if (!digits.empty())
				digits.pop_back();
			else {
				digits.push_front(0); // restore 0
				break;
			}
		}
		return *this;
	}

	bool operator<(const bigint& other) const {
		if (digits.size() < other.digits.size())
			return true;
		else if (digits.size() > other.digits.size())
			return false;
		for (size_t i = 0; i < digits.size(); ++i) {
			if (digits[i] < other.digits[i])
				return true;
			else if (digits[i] > other.digits[i])
				return false;
		}
		return false; // equal
	}

	bool operator<=(const bigint& other) const {
		if (digits.size() < other.digits.size())
			return true;
		else if (digits.size() > other.digits.size())
			return false;
		for (size_t i = 0; i < digits.size(); ++i) {
			if (digits[i] < other.digits[i])
				return true;
			else if (digits[i] > other.digits[i])
				return false;
		}
		return true; // equal
	}

	bool operator>(const bigint& other) const {
		return !(*this < other);
	}

	bool operator>=(const bigint& other) const {
		return !(*this <= other);
	}

	bool operator==(const bigint& other) const {
		return (*this <= other) && (*this >= other);
	}

	bool operator!=(const bigint& other) const {
		return !(*this == other);
	}
private:
	bigint add_or_substract(const bigint& other, bool do_add) const {
		bool other_has_more_digits = digits.size() < other.digits.size();

		const bigint& bigint_with_less_digits(other_has_more_digits ? *this : other);
		bigint        bigint_with_more_digits(other_has_more_digits ? other : *this); // returning this

		size_t offset = bigint_with_more_digits.digits.size() - bigint_with_less_digits.digits.size();

		for (int idx = static_cast<int>(bigint_with_less_digits.digits.size()) - 1; idx >= 0; --idx) { // start from least significant digit on smaller number
			size_t i = static_cast<size_t>(idx);
			int digit = bigint_with_less_digits.digits[i];
			bigint_with_more_digits.digits[i + offset] += digit;							// ADD LOGIC
			// # basic carry
			// b1 = 1234   -> size 4
			// b2 = 123456 -> size 6 -> offset == 2
			// i          starts at 3, which is the last digit (4) in b1
			// i + offset starts at 5, which is the last digit (6) in b2
			// 4+6 == 10, which is bigger than 9
			// turns into 0, 5 gets incremented to 6

			// # complex carry
			// b1 = 1111 -> size 4
			// b2 = 9999 -> size 4 -> offset == 0
			// i          starts at 3, which is the last digit (1) in b1
			// i + offset starts at 3, which is the last digit (9) in b2
			// carrying:
			//  9 9 9 10
			//  9 9 10 0
			//  9 10 0 0
			//  10 0 0 0
			// 1 0 0 0 0
			// now we need to increment offset, because of this change

			// SUBSTRACT LOGIC
			// not handling whoops, should read the subject more clearly

			size_t j = i + offset;
			while (bigint_with_more_digits.digits[j] > 9) { // carry logic
				bigint_with_more_digits.digits[j] -= 10;
				if (j == 0) {
					bigint_with_more_digits.digits.push_front(1); // order of magnitude changed
					++offset;
				} else {
					--j;
					bigint_with_more_digits.digits[j] += 1; // carry
				}
			}

		}

		return bigint_with_more_digits; // should be done I hope
	}
};

std::ostream &operator<<(std::ostream &os, const bigint& bi);
