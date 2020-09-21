//
// Created by NSC on 11/7/18.
//
#include <string.h>
#include <cstring>
#include "BigInt.h"

unsigned long InfInt::length() const {
	if (value == "0")
		return 0;
	return value.length();
}

InfInt::InfInt() {
	value = "0";
}

InfInt::InfInt(const std::string &s) {
	unsigned long start = s.find_first_not_of("0-");

	if (!std::strcmp(&s[start], "")) {
		std::strcpy(&value[0], "0");
	}

	if (s[0] == '-') {
		sign = 1;
	}
	value = &s[start];
}

InfInt::InfInt(long int a) {
	sign = 0;
	if (a < 0) {
		sign = 1;
		a *= -1;
	}

	value = std::to_string(a);
}

InfInt InfInt::operator=(long int a) {
	return *new InfInt(a);
}

std::string InfInt::getValue() const {
	return value;
}

bool InfInt::getSign() const {
	return sign;
}

void InfInt::setSign(const bool s) {
	sign = s;
}

InfInt::operator int() const {
	int final = 0;
	int pow = 1;
	for (long i = length() - 1; i >= 0; i--) {
		final += pow * (value[i] - '0');
		pow *= 10;
	}
	if (sign)
		final *= -1;
	return final;
}

std::string InfInt::getBinary() const {
	//if the number is 0
	if (!length())
		return "0";
	InfInt temp = *new InfInt(value);
	//sign at the start and then from lsb to msb
	std::string result = "";
	result = result + (char)((int)sign + '0');
	std::string current;

	while (temp > 0) {
		current = (temp % 2).getValue();
		if (current.length() == 0)
			result = result + "0";
		else
			result = result + current;
		temp = temp / 2;
	}

	return result;
}

void InfInt::initFromBinary(const std::string b) {
	sign = b[0] - '0';
	InfInt temp = 0;
	InfInt shift = 1;
	for (long i = 1; i < b.length(); i++) {
		temp += *new InfInt((int)(b[i] - '0')) * shift;
		shift = shift * 2;
	}

	value = temp.value;
}

std::ostream& operator<<(std::ostream& os, const InfInt& a) {
	if (a.length() == 0 || a.getValue()[0] == '0') {
		std::string zero = "0";
		return os << zero;
	}
	if (a.getSign())
		return os << "-" + a.getValue();
	else
		return os << a.getValue();
}

std::string InfInt::align(const unsigned long l) const {
	std::string newStr = value;
	for (unsigned long i = 0; i < l; i++) {
		newStr = "0" + newStr;
	}
	return newStr;
}

InfInt InfInt::alignLeft(const unsigned long l) const {
	std::string newStr = value;
	for (unsigned long i = 0; i < l; i++) {
		newStr = newStr + "0";
	}
	return newStr;
}

void InfInt::operator++() {
	*this += 1;
}

void InfInt::operator--() {
	*this = *this - 1;
}

//adding the values of the input w/o their sign
std::string InfInt::add(const InfInt & a) const {
	unsigned long numOfZeros = value.length() - a.length();
	std::string aligned = a.align(numOfZeros);
	//now this and a are in the same length

	std::string result;
	int x = 0;
	bool carry = 0;

	for (long i = value.length() - 1; i >= 0; i--) {
		//according to the ascii table '0' = 0 + 48 so subtracting 48 is a more sufficient way to convert
		x = value[i] + aligned[i] - 96 + carry;
		carry = x / 10;
		result = (char)(x % 10 + 48) + result;
	}

	//in case of "overflow"
	if (carry)
		result = "1" + result;

	return result;
}

InfInt InfInt::operator+(const InfInt & a) const {
	//a + (-b) = a - b
	if (!getSign() && a.getSign()) {
		InfInt * temp = new InfInt(a.value);
		return *this - *temp;
	}

	//(-a) + b = b - a
	if (getSign() && !a.getSign()) {
		//temp is positive. temp = -a
		InfInt * temp = new InfInt(value);
		return a - *temp;
	}

	//a + b = b + a
	if (value.length() < a.length())
		return a.operator+(*this);

	std::string result = this->add(a);

	//(-a) + (-b) = -(a + b)
	if (getSign() && a.getSign())
		return *new InfInt('-' + result);

	return *new InfInt(result);
}

//when this function is called, we can be sure that a > b
std::string InfInt::subtract(const InfInt& a) const {

	if (a.length() > length())
		return a.subtract(*this);
	long numOfZeros = this->length() - a.length();
	std::string aligned = a.align(numOfZeros);
	//now this and a are in the same length

	std::string result = "";
	int x = 0;
	bool carry = 0;

	for (long i = value.length() - 1; i >= 0; i--) {
		x = value[i] - aligned[i] - carry;
		carry = false;
		if (x < 0) {
			x += 10;
			carry = true;
		}
		result = (char)(x + 48) + result;
	}

	return result;
}

InfInt InfInt::operator-(const InfInt &a) const {
	if (length() == 0)
		return a * *new InfInt(-1);
	if (a.length() == 0)
		return *this * *new InfInt(-1);
	//both positive
	if (!getSign() && !a.getSign()) {
		if (*this > a)
			return *new InfInt(this->subtract(a));

		// a - b = -(b - a)
		InfInt * result = new InfInt(a.subtract(*this));
		result->setSign(true);
		return *result;
	}

	//a - (-b) = a + b
	if (!getSign() && a.getSign())
		return *new InfInt(this->add(a));

	//(-a) - b = - (a + b)
	if (getSign() && !a.getSign()) {
		InfInt result = this->add(a);
		result.setSign(true);
		return result;
	}

	//(-a) - (-b) = b - a
	InfInt temp1 = *new InfInt(value);
	InfInt temp2 = *new InfInt(a.value);
	return temp2 - temp1;
	//    if (a > *this)
	//        return *new InfInt(a.subtract(*this));
	//
	//    InfInt * result = new InfInt(this->subtract(a));
	//    result->setSign(true);
	//    return *result;
}

void InfInt::operator+=(const InfInt& a) {
	InfInt temp = *this + a;
	value = temp.value;
	sign = temp.sign;
}

void InfInt::operator-=(const InfInt& a) {
	InfInt temp = *this - a;
	value = temp.value;
	sign = temp.sign;
}

InfInt InfInt::operator*(const InfInt& a) const {

	InfInt final = 0;
	std::string result;
	InfInt* temp;


	int carry;
	int current;

	//fast mult algorithm. the same we were taught in elementary.
	for (long i = length() - 1; i >= 0; i--) {
		carry = 0;
		result = "";
		for (long j = a.length() - 1; j >= 0; j--) {
			current = (value[i] - '0') * (a.value[j] - '0') + carry;
			result = (char)(current % 10 + '0') + result;
			carry = current / 10;
		}

		if (carry > 0)
			result = (char)(carry + '0') + result;

		temp = new InfInt(result);
		final += *new InfInt(temp->alignLeft(length() - i - 1));
	}

	final.setSign(sign ^ a.sign);
	return final;
}

//long division implementation
InfInt InfInt::operator/(const InfInt& a) const {
	if (a.length() == 0 || a.getValue()[0] == '0') {
		throw "Devision By Zero";
	}

	//divider = |a|
	InfInt divider = *new InfInt(a.getValue());
	if (divider > *new InfInt(value))
		return *new InfInt();

	std::string result;
	int idx = 0;

	//temp is the part of the divided that's being currently focused
	InfInt temp = value[idx] - '0';
	while (temp < divider.value)
		temp = temp * 10 + (value[++idx] - '0');

	while (idx < length()) {

		if (temp == 0) {
			result = result + "0";
			idx++;
		}
		else {
			// Find prefix of number that's larger
			// than a.value.


			InfInt multNum = 1;
			InfInt leftover = temp - divider;
			while (leftover >= divider) {
				leftover -= divider;
				multNum += 1;
			}

			leftover = temp - (multNum * divider);
			result = result + multNum.getValue();

			temp = leftover * 10 + (value[++idx] - '0');
			temp.setSign(false);
		}
	}
	// If a.value is greater than value
	if (result.length() == 0)
		return *new InfInt();

	InfInt final = *new InfInt(result);
	final.setSign(this->sign ^ a.getSign());
	return final;
}

InfInt InfInt::operator%(const InfInt& a) const {
	if (a.length() == 0 || a.getValue()[0] == '0') {
		throw "Modulo By Zero";
	}

	if (a > *this)
		return *new InfInt(*this);
	//divider = |a|
	InfInt divider = *new InfInt(a.getValue());

	if (divider > *new InfInt(value))
		return (*this + a) % a;
	std::string result;
	int idx = 0;
	InfInt leftover;

	InfInt temp = value[idx] - '0';
	while (temp < divider.value)
		temp = temp * 10 + (value[++idx] - '0');

	while (idx < length()) {
		// Find prefix of number that's larger
		// than a.value.


		InfInt multNum = 0;
		leftover = temp;
		while (leftover >= divider) {
			leftover -= divider;
			multNum += 1;
		}

		leftover = temp - (multNum * divider);
		leftover.setSign(false);

		temp = leftover * 10 + (value[++idx] - '0');
	}
	// If a.value is greater than value

	return leftover;
}

bool InfInt::operator<(const InfInt& a) const {
	if (getSign() && !a.getSign())
		return true;
	if (!getSign() && a.getSign())
		return false;

	unsigned long l1 = length(), l2 = a.length();

	//both positive
	if (!getSign() && !a.getSign()) {
		if (l1 > l2)
			return false;

		if (l1 < l2)
			return true;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return false;

			if (value[i] < a.value[i])
				return true;
		}
	}

	else {
		if (l1 > l2)
			return true;

		if (l1 < l2)
			return false;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return true;

			if (value[i] < a.value[i])
				return false;
		}
	}

	//equal
	return false;
}

bool InfInt::operator<=(const InfInt& a) const {
	if (getSign() && !a.getSign())
		return true;
	if (!getSign() && a.getSign())
		return false;

	unsigned long l1 = length(), l2 = a.length();

	//both positive
	if (!getSign() && !a.getSign()) {
		if (l1 > l2)
			return false;

		if (l1 < l2)
			return true;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return false;

			if (value[i] < a.value[i])
				return true;
		}
	}

	else {
		if (l1 > l2)
			return true;

		if (l1 < l2)
			return false;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return true;

			if (value[i] < a.value[i])
				return false;
		}
	}

	//equal
	return true;
}

bool InfInt::operator>(const InfInt& a) const {
	if (getSign() && !a.getSign())
		return false;
	if (!getSign() && a.getSign())
		return true;

	unsigned long l1 = length(), l2 = a.length();

	//both negative
	if (getSign() && a.getSign()) {
		if (l1 > l2)
			return false;

		if (l1 < l2)
			return true;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return false;

			if (value[i] < a.value[i])
				return true;
		}
	}

	else {
		if (l1 > l2)
			return true;

		if (l1 < l2)
			return false;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return true;

			if (value[i] < a.value[i])
				return false;
		}
	}

	//equal
	return false;
}

bool InfInt::operator>=(const InfInt& a) const {
	if (getSign() && !a.getSign())
		return false;
	if (!getSign() && a.getSign())
		return true;

	unsigned long l1 = length(), l2 = a.length();

	//both negative
	if (getSign() && a.getSign()) {
		if (l1 > l2)
			return false;

		if (l1 < l2)
			return true;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return false;

			if (value[i] < a.value[i])
				return true;
		}
	}

	else {
		if (l1 > l2)
			return true;

		if (l1 < l2)
			return false;

		for (long i = 0; i < l1; i++) {
			if (value[i] > a.value[i])
				return true;

			if (value[i] < a.value[i])
				return false;
		}
	}

	//equal
	return true;
}

bool InfInt::operator==(const InfInt& a) const {

	if (length() == 0 && a.length() == 0)
		return true;

	//if the signs are not the same
	if (getSign() ^ a.getSign())
		return false;

	if (length() != a.length())
		return false;

	for (long i = 0; i < length(); i++) {
		if (value[i] != a.value[i])
			return false;
	}

	return true;
}

void InfInt::operator<<=(const InfInt& a) {

	InfInt result = *this << a;

	value = result.getValue();
	sign = result.getSign();
}

void InfInt::operator>>=(const InfInt& a) {

	InfInt result = *this >> a;

	value = result.getValue();
	sign = result.getSign();
}

void InfInt::operator&=(const InfInt& a) {
	InfInt temp = *this & a;
	value = temp.getValue();
	sign = temp.getSign();
}

InfInt InfInt::operator^(const InfInt& a) const {
	std::string b1 = this->getBinary();
	std::string b2 = a.getBinary();

	long l1 = b1.length();
	long l2 = b2.length();

	//adding zeros from right doesn't change the value of the number
	int numOfZeros;

	if (l1 > l2) {
		numOfZeros = l1 - l2;
		for (int i = 0; i < numOfZeros; i++)
			b2 = b2 + "0";
	}
	else if (l2 > l1) {
		numOfZeros = l2 - l1;
		for (int i = 0; i < numOfZeros; i++)
			b1 = b1 + "0";
	}

	std::string result = "";

	for (int i = 0; i < l1 + 1; i++) {
		if (b1[i] == '1' ^ b2[i] == '1')
			result = result + "1";
		else
			result = result + "0";
	}

	InfInt final = *new InfInt();
	final.initFromBinary(result);
	return final;
}

InfInt InfInt::operator|(const InfInt& a) const {
	std::string b1 = this->getBinary();
	std::string b2 = a.getBinary();

	long l1 = b1.length();
	long l2 = b2.length();

	//adding zeros from right doesn't change the value of the number
	int numOfZeros;

	if (l1 > l2) {
		numOfZeros = l1 - l2;
		for (int i = 0; i < numOfZeros; i++)
			b2 = b2 + "0";
	}
	else if (l2 > l1) {
		numOfZeros = l2 - l1;
		for (int i = 0; i < numOfZeros; i++)
			b1 = b1 + "0";
	}

	std::string result = "";

	for (int i = 0; i < l1; i++) {
		if (b1[i] == '1' || b2[i] == '1')
			result = result + "1";
		else
			result = result + "0";
	}

	InfInt final = *new InfInt();
	final.initFromBinary(result);
	return final;
}

InfInt InfInt::operator&(const InfInt& a) const {
	std::string b1 = this->getBinary();
	std::string b2 = a.getBinary();

	long l1 = b1.length();
	long l2 = b2.length();

	//adding zeros from right doesn't change the value of the number
	int numOfZeros;

	if (l1 > l2) {
		numOfZeros = l1 - l2;
		for (int i = 0; i < numOfZeros; i++)
			b2 = b2 + "0";
	}
	else if (l2 > l1) {
		numOfZeros = l2 - l1;
		for (int i = 0; i < numOfZeros; i++)
			b1 = b1 + "0";
	}

	std::string result = "";

	for (int i = 0; i < l1; i++) {
		if (b1[i] == '1' && b2[i] == '1')
			result = result + "1";
		else
			result = result + "0";
	}

	InfInt final = *new InfInt();
	final.initFromBinary(result);
	return final;
}

InfInt InfInt::operator<<(const InfInt& a) const {
	std::string b = this->getBinary();
	std::string result = "";
	result = result + b[0];

	//adding 0's multiplies by 2
	for (InfInt i = 0; i < a; i += 1) {
		result = result + "0";
	}

	//adding the original bits after adding zeros
	for (long j = 1; j < b.length(); j++) {
		result = result + b[j];
	}

	InfInt final = *new InfInt();
	final.initFromBinary(result);
	return final;
}

InfInt InfInt::operator>>(const InfInt& a) const {
	std::string b = this->getBinary();

	b.erase(1, (int)a);

	InfInt final = *new InfInt();
	final.initFromBinary(b);
	return final;
}