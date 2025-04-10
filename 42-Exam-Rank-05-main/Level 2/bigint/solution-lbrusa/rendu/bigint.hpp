#pragma once


#include <iostream>

#include <vector>
#include <algorithm> // for reverse vector

class bigint {
public:

	bigint() : bigint(0) {} // like int() creates a 0 int
	bigint(size_t n) {
		while (n > 0) {
			digits.push_back(n % 10);
			n /= 10;
		}
		std::reverse(digits.begin(), digits.end()); //reverse is defined in algorithm header
	}
	bigint(const bigint& other) : digits(other.digits) {} // vector has a deep copy constructor
	bigint& operator=(const bigint& other) {
		if (this != &other) {
			digits = other.digits; // vector deep copy 
		}
		return *this;
	}

    // Addition - should be taking a const big int and marked as const
    bigint operator+(const bigint& other) const {
        bigint result;
        int carry = 0;
        int i = digits.size() - 1, j = other.digits.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += digits[i--];
            }
            if (j >= 0) {
                sum += other.digits[j--];
            }
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        // Reverse the digits to get the correct order
        std::reverse(result.digits.begin(), result.digits.end());
        return result;
    }

	// same as above but with normal numbers
	bigint operator+(const size_t& n) const {
		return *this + bigint(n);
	}

	// dummy implementation for the compiler but not req by the subject
	bigint operator-(const size_t& n) const {
		(void)n;
		return bigint(0);
	}

	bigint& operator+=(const bigint& other) {
		return *this = *this + other;
	}

	// pre increment ========================================
	bigint& operator++() {
		*this = *this + bigint(1);
		return *this;
	}

	// post increment ========================================
	bigint operator++(int) {
		bigint temp(*this);
		++(*this);
		return temp;
	}

	// shifting ========================================
	bigint operator<<(size_t n) const {
		bigint result;
		result.digits = digits;
		while (n-- > 0) {
			result.digits.push_back(0);
		}
		return result;
	}

	bigint operator>>(size_t n) const {
		bigint result;
		result.digits = digits;
		if (n >= result.digits.size()) {
			result.digits.clear();
		}
		else {
			result.digits.erase(result.digits.begin() + result.digits.size() - n, result.digits.end());
		}
		return result;
	}	

	// if needed implement both of the above with bigint as param
	
	bigint operator<<(const bigint& other) const {
		bigint temp(0);
		while (temp < other) {
			*this << 1;
			temp++;
		}
		return *this;
	}

	bigint operator>>(const bigint& other)const {
		bigint temp(0);
		while (temp < other) {
			*this >> 1;
			temp++;
		}
		return *this;
	}	

	bigint& operator<<=(size_t n) {
		return *this = *this << n;
	}

	bigint& operator>>=(size_t n) {
		return *this = *this >> n;
	}

	bigint& operator>>=(const bigint& other) {
		bigint temp(0);
		while (temp < other) {
			*this >>= 1;
			temp++;
		}
		return *this;
	}

	bigint& operator<<=(const bigint& other) {
		bigint temp(0);
		while (temp < other) {
			*this <<= 1;
			temp++;
		}
		return *this;
	}

	// comparison ========================================
	bool operator==(const bigint& other) const {
		return digits == other.digits;
	}

	bool operator!=(const bigint& other) const {
		return !(*this == other);
	}

	bool operator<(const bigint& other) const {
		if (digits.size() != other.digits.size()) {
			return digits.size() < other.digits.size();
		} else { // if im here is because they have the same num of digits
			for (size_t i = 0; i < digits.size(); i++) {
				if (digits[i] != other.digits[i]) {
					return digits[i] < other.digits[i];
				}
			}
			return false;
		}
	}

	bool operator>(const bigint& other) const {
		return !(*this < other || *this == other);
	}

	bool operator<=(const bigint& other) const {
		return *this < other || *this == other;
	}

	bool operator>=(const bigint& other) const {
		return *this > other || *this == other;
	}

	// apparently friends functions need to be defined outside the class?
	friend std::ostream &operator<<(std::ostream &os, const bigint &bi);

private:
    std::vector<int> digits;
};

// as a friend function, it can access the private members of the class like digits
std::ostream &operator<<(std::ostream &os, const bigint &bi) {
	for (int digit : bi.digits) {
		os << digit;
	}
	return os;
}
