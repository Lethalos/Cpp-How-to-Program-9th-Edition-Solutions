/*
	File: HugeInteger.cpp
	Version: 2.0
	Writer: Kaan Ozdogan
	Mail: necdetkaanozdogan@gmail.com

	Description: C++ How to Program 9th Edition by Deitel Chapter 9 Exercise 9.14
				 This program contains addition substraction, multiplication, divison, and modulus operations
				 Negative values can be useable
*/
#include<stdexcept>
#include"HugeInteger.hpp"

HugeInteger::HugeInteger()
{
	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER + 1; i++) {
		hugeInteger[i] = -1;
		reverseHugeInteger[i] = -1;
	}

	hugeIntegerSize = 0;
	isPositive = true;
}

HugeInteger::HugeInteger(const char* hugeIntegerStr)
{
	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER + 1; i++) {
		hugeInteger[i] = -1;
		reverseHugeInteger[i] = -1;
	}

	std::string str(hugeIntegerStr);
	this->hugeIntegerStr = str;

	setHugeInteger(this->hugeIntegerStr);
}

void HugeInteger::setHugeInteger(std::string& hugeIntegerStr)
{
	if (hugeIntegerStr[0] == '-') {
		hugeIntegerStr.erase(0, 1);
		isPositive = false;
	}
	else {
		isPositive = true;
	}

	if (hugeIntegerStr[0] == '0') {
		if (hugeIntegerStr.size() == 1) { //control if input is zero
			isPositive = true; //Warning: zero is not positive, but I use it as like a positive number because it is has got no minus sign
		}
		else {
			repairInputIfZerosInTheBeginning();
		}
	}

	while (hugeIntegerStr.size() <= 0 || hugeIntegerStr.size() > MAX_SIZE_OF_HUGE_INTEGER) {
		isPositive = true;

		if (hugeIntegerStr.size() <= 0) {
			std::cout << "Your input cannot be empty. Please try again: ";
		}
		else {
			std::cout << "Your input cannot exceed 40 digits. Please try again: ";
		}

		std::cin >> hugeIntegerStr;

		if (hugeIntegerStr[0] == '-') {
			hugeIntegerStr.erase(0, 1);
			isPositive = false;
		}
	}

	hugeIntegerSize = hugeIntegerStr.size();
	setHugeIntegerFromString(hugeIntegerStr, hugeIntegerSize);
	setReverseHugeInteger();
}

void HugeInteger::repairInputIfZerosInTheBeginning() //if user's input is like: 0003242 convert to: 3242
{
	for (int i = 0; i < hugeIntegerStr.size(); i++) {
		if (hugeIntegerStr[i] == '0') {
			hugeIntegerStr.erase(i, 1);
			i--;
		}
	}
}

void HugeInteger::setHugeIntegerFromString(const std::string& hugeIntegerStr, const int& hugeIntegerSize)
{
	for (int i = 0; i < hugeIntegerSize; i++) {
		hugeInteger[i] = (int)hugeIntegerStr[i] - 48;
	}
}

int HugeInteger::getSize() const
{
	return hugeIntegerSize;
}

std::istream& operator>>(std::istream& stream, HugeInteger& other)
{
	stream >> other.hugeIntegerStr;
	other.setHugeInteger(other.hugeIntegerStr);

	return stream;
}

std::ostream& operator<<(std::ostream& stream, const HugeInteger& other)
{
	if (!other.isPositive) {
		stream << "-";
	}

	for (int i = 0; i < other.hugeIntegerSize; i++) {
		stream << other.hugeInteger[i];
	}

	return stream;
}

bool HugeInteger::isZero() const
{
	if (hugeInteger[0] == 0 && hugeIntegerSize == 1) {
		return true;
	}

	return false;
}

bool HugeInteger::operator==(const HugeInteger& other) const
{
	if (this->isPositive != other.isPositive) {
		return false;
	}

	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER; i++) {
		if (this->hugeInteger[i] != other.hugeInteger[i]) {
			return false;
		}
	}

	return true;
}

bool HugeInteger::operator!=(const HugeInteger& other) const
{
	return !(*this == other);
}

bool HugeInteger::operator>(const HugeInteger& other) const
{
	if (this->isPositive && !other.isPositive) {
		return true;
	}
	else if (!this->isPositive && other.isPositive) {
		return false;
	}

	bool reverseResult = false;
	if (!this->isPositive && !other.isPositive) {
		reverseResult = true;
	}

	if (this->hugeIntegerSize > other.hugeIntegerSize) {
		return reverseResult ? false : true;
	}
	else if (this->hugeIntegerSize == other.hugeIntegerSize) {
		for (int i = 0; i < hugeIntegerSize; i++) {
			if (this->hugeInteger[i] > other.hugeInteger[i]) {
				return reverseResult ? false : true;
			}
			else if (this->hugeInteger[i] == other.hugeInteger[i]) {
				continue;
			}
			else {
				return reverseResult ? true : false;
			}
		}
	}

	return reverseResult ? true : false;
}

bool HugeInteger::operator<(const HugeInteger& other) const
{
	return !(*this >= other);
}

bool HugeInteger::operator>=(const HugeInteger& other) const
{
	if (*this == other || *this > other) {
		return true;
	}

	return false;
}

bool HugeInteger::operator<=(const HugeInteger& other) const
{
	if (*this == other || *this < other) {
		return true;
	}

	return false;
}

//checks if the absolute values of huge integers are larger
bool HugeInteger::isGreaterThanAbsolute(const HugeInteger& other) const
{
	if (this->hugeIntegerSize > other.hugeIntegerSize) {
		return true;
	}
	else if (this->hugeIntegerSize == other.hugeIntegerSize) {
		for (int i = 0; i < hugeIntegerSize; i++) {
			if (this->hugeInteger[i] > other.hugeInteger[i]) {
				return true;
			}
			else if (this->hugeInteger[i] == other.hugeInteger[i]) {
				continue;
			}
			else {
				return false;
			}
		}
	}

	return false;
}

bool HugeInteger::isEqualAbsolute(const HugeInteger& other) const
{
	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER; i++) {
		if (this->hugeInteger[i] != other.hugeInteger[i]) {
			return false;
		}
	}

	return true;
}

void HugeInteger::setReverseHugeInteger()
{
	for (int i = 0; i < hugeIntegerSize; i++) {
		reverseHugeInteger[i] = hugeInteger[(hugeIntegerSize - 1) - i];
	}
}

void HugeInteger::setHugeIntegerFromReverse()
{
	for (int i = 0; i < hugeIntegerSize; i++) {
		hugeInteger[i] = reverseHugeInteger[(hugeIntegerSize - 1) - i];
	}
}

void HugeInteger::setSizeFromReverse()
{
	int sizeCounter = 0;

	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER + 1; i++) {
		if (reverseHugeInteger[i] != -1) {
			sizeCounter++;
		}
	}

	hugeIntegerSize = sizeCounter;
}

//tunes small reverse huge integer according to big reverse huge integer
// 1234      1234
// 12-1-1 -> 1200
// ____+     ____+ 
void HugeInteger::tuneSmallForOperations(HugeInteger& smallHugeInteger)
{
	for (int i = smallHugeInteger.hugeIntegerSize; i < this->hugeIntegerSize; i++) {
		smallHugeInteger.reverseHugeInteger[i] = 0;
	}
}

//if reverse huge integer is like: 1023000-1-1-1... convert to: 1023-1-1-1-1-1-1...
void HugeInteger::repairReverseIfZerosInTheBeginning()
{
	int sizeOfReverse = 0;

	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER; i++) {
		if (reverseHugeInteger[i] != -1) {
			sizeOfReverse++;
		}
	}

	for (int i = sizeOfReverse - 1; i >= 0; i--) {
		if (reverseHugeInteger[i] == 0) {
			reverseHugeInteger[i] = -1;
		}
		else {
			break;
		}
	}
}

//ARITHMETIC OPERATIONS
HugeInteger HugeInteger::operator++()
{
	if (isPositive) {
		return incrementOperation();
	}
	else {
		return decrementOperation();
	}
}

HugeInteger HugeInteger::operator--()
{
	if (isPositive) {
		return decrementOperation();
	}
	else {
		return incrementOperation();
	}
}

HugeInteger HugeInteger::incrementOperation()
{
	reverseHugeInteger[0]++;

	for (int i = 0; reverseHugeInteger[i] > 9; i++) {
		if (i == hugeIntegerSize - 1) {
			hugeIntegerSize++;
			reverseHugeInteger[i + 1] = 0;
		}

		reverseHugeInteger[i] = 0;
		reverseHugeInteger[i + 1]++;
	}

	if (hugeIntegerSize > MAX_SIZE_OF_HUGE_INTEGER) {
		std::invalid_argument err("a huge integer cannot exceed 40 digits");
		std::cout << err.what() << std::endl;
		throw err;
	}

	setHugeIntegerFromReverse();

	return *this;
}

HugeInteger HugeInteger::decrementOperation()
{
	int i = 0;
	reverseHugeInteger[i]--;

	if (reverseHugeInteger[i] < 0 && hugeIntegerSize == 1) {
		reverseHugeInteger[i] = 1;
		isPositive = false;
	}
	else if (reverseHugeInteger[i] == 0 && hugeIntegerSize == 1 && !isPositive) {
		isPositive = !isPositive;
	}
	else if (reverseHugeInteger[i] < 0 && hugeIntegerSize > 1) {
		reverseHugeInteger[i] = 9;

		while (reverseHugeInteger[i + 1] == 0) {
			reverseHugeInteger[i + 1] = 9;
			i++;
		}

		reverseHugeInteger[i + 1]--;

		if (reverseHugeInteger[hugeIntegerSize - 1] == 0) {
			reverseHugeInteger[hugeIntegerSize - 1] = -1;
			hugeInteger[hugeIntegerSize - 1] = -1;
			hugeIntegerSize--;
		}
	}

	setHugeIntegerFromReverse();

	return *this;
}

HugeInteger HugeInteger::operator+(HugeInteger& other)
{
	if (this->isPositive && other.isPositive) { //positive-positive e.g, (+10) + (+5) 
		return this->addOperation(other, false);
	}
	else if (this->isPositive && !other.isPositive) { //positive-negative e.g, (+10) + (-5)
		return this->subtractOperation(other);
	}
	else if (!this->isPositive && other.isPositive) { //negative-positive e.g, (-10) + (+5)
		return other.subtractOperation(*this);
	}
	else { //negative-negative e.g, (-10) + (-5)
		return this->addOperation(other, false);
	}
}

HugeInteger HugeInteger::operator-(HugeInteger& other)
{
	if (this->isPositive && other.isPositive) { //positive-positive e.g, (+10) - (+5) 
		return this->subtractOperation(other);
	}
	else if (this->isPositive && !other.isPositive) { //positive-negative e.g, (+10) - (-5) 
		return this->addOperation(other, false);
	}
	else if (!this->isPositive && other.isPositive) { //positive-negative e.g, (-10) - (+5)
		other.isPositive = false; //other should be negative because it has a minus sign in front of
		return this->addOperation(other, true);
	}
	else { //negative-negative e.g, (-10) - (-5)
		return other.subtractOperation(*this);
	}
}

HugeInteger HugeInteger::addOperation(HugeInteger& other, bool isOtherChanged)
{
	HugeInteger newHugeInteger;

	if (!this->isPositive && !other.isPositive) {
		newHugeInteger.isPositive = false;
	}

	if (isOtherChanged) { //change other's sign because it is not original 
		other.isPositive = !other.isPositive;
	}

	if (this->hugeIntegerSize > other.hugeIntegerSize) {
		this->tuneSmallForOperations(other);

		for (int i = 0; i < this->hugeIntegerSize; i++) {
			int sum = this->reverseHugeInteger[i] + other.reverseHugeInteger[i];

			if (sum >= 10) {
				int onHand = sum / 10;
				sum %= 10;

				if (i == this->hugeIntegerSize - 1) {
					if (newHugeInteger.reverseHugeInteger[i + 1] == -1) {
						newHugeInteger.reverseHugeInteger[i + 1] += onHand + 1; //reason of +1 is neutralize the -1
					}
				}
				else {
					this->reverseHugeInteger[i + 1] += onHand;
				}
			}

			newHugeInteger.reverseHugeInteger[i] = sum;
		}
	}
	else {
		other.tuneSmallForOperations(*this);

		for (int i = 0; i < other.hugeIntegerSize; i++) {
			int sum = this->reverseHugeInteger[i] + other.reverseHugeInteger[i];

			if (sum >= 10) {
				int onHand = sum / 10;
				sum %= 10;

				if (i == other.hugeIntegerSize - 1) {
					if (newHugeInteger.reverseHugeInteger[i + 1] == -1) {
						newHugeInteger.reverseHugeInteger[i + 1] += onHand + 1; //reason of +1 is neutralize the -1
					}
				}
				else {
					other.reverseHugeInteger[i + 1] += onHand;
				}
			}

			newHugeInteger.reverseHugeInteger[i] = sum;
		}
	}

	//restore reverse huge integers
	this->setReverseHugeInteger();
	other.setReverseHugeInteger();

	newHugeInteger.setSizeFromReverse();

	if (newHugeInteger.hugeIntegerSize > MAX_SIZE_OF_HUGE_INTEGER) {
		std::invalid_argument err("a huge integer cannot exceed 40 digits");
		std::cout << err.what() << std::endl;

		throw err;
	}

	newHugeInteger.setHugeIntegerFromReverse();

	return newHugeInteger;
}

HugeInteger HugeInteger::subtractOperation(HugeInteger& other)
{
	HugeInteger newHugeInteger;

	bool itNeedRepairment = true;

	if (this->isGreaterThanAbsolute(other)) {
		this->tuneSmallForOperations(other);

		for (int i = 0; i < this->hugeIntegerSize; i++) {
			if (this->reverseHugeInteger[i] < other.reverseHugeInteger[i]) {
				int counter = 1;

				while (reverseHugeInteger[i + counter] == 0) {
					reverseHugeInteger[i + counter] += 9;
					counter++;
				}

				reverseHugeInteger[i + counter]--;
				reverseHugeInteger[i] += 10;
			}

			int result = this->reverseHugeInteger[i] - other.reverseHugeInteger[i];
			newHugeInteger.reverseHugeInteger[i] = result;
		}
	}
	else if (this->isEqualAbsolute(other)) {
		newHugeInteger.reverseHugeInteger[0] = 0;
		itNeedRepairment = false;
	}
	else {
		newHugeInteger.isPositive = false;

		other.tuneSmallForOperations(*this);

		for (int i = 0; i < other.hugeIntegerSize; i++) {
			if (other.reverseHugeInteger[i] < this->reverseHugeInteger[i]) {
				int counter = 1;

				while (other.reverseHugeInteger[i + counter] == 0) {
					other.reverseHugeInteger[i + counter] += 9;
					counter++;
				}

				other.reverseHugeInteger[i + counter]--;
				other.reverseHugeInteger[i] += 10;
			}

			int result = other.reverseHugeInteger[i] - this->reverseHugeInteger[i];
			newHugeInteger.reverseHugeInteger[i] = result;
		}
	}

	//restore reverse huge integers
	this->setReverseHugeInteger();
	other.setReverseHugeInteger();

	if (itNeedRepairment) { newHugeInteger.repairReverseIfZerosInTheBeginning(); }
	newHugeInteger.setSizeFromReverse();
	newHugeInteger.setHugeIntegerFromReverse();

	return newHugeInteger;
}

HugeInteger HugeInteger::operator*(HugeInteger& other)
{
	HugeInteger newHugeInteger;
	HugeInteger temp = other;

	if (this->isZero() || other.isZero()) {
		newHugeInteger.hugeInteger[0] = 0;
		newHugeInteger.hugeIntegerSize = 1;
		newHugeInteger.isPositive = true;

		return newHugeInteger;
	}

	if (temp.isPositive) {
		for (; !temp.isZero(); --temp) {
			newHugeInteger = newHugeInteger + *this;
		}
	}
	else {
		for (; !temp.isZero(); ++temp) {
			newHugeInteger = newHugeInteger + *this;
		}
	}

	if (!this->isPositive && !other.isPositive) {
		newHugeInteger.isPositive = true;
	}

	if ((this->isPositive && !other.isPositive) || (!this->isPositive && other.isPositive)) {
		newHugeInteger.isPositive = false;
	}

	return newHugeInteger;
}

HugeInteger HugeInteger::operator/(HugeInteger& other)
{
	HugeInteger newHugeInteger = "0";
	HugeInteger tempBig;
	HugeInteger tempSmall;

	if (other.isZero()) {
		std::logic_error err("The divisor cannot be zero");
		std::cout << err.what() << std::endl;
		throw err;
	}

	if (this->isGreaterThanAbsolute(other)) {
		tempBig = *this;
		tempSmall = other;

		tempBig.isPositive = true;
		tempSmall.isPositive = true;

		while (tempBig.isGreaterThanAbsolute(tempSmall) || tempBig.isEqualAbsolute(tempSmall)) {
			tempBig = tempBig - tempSmall;
			++newHugeInteger;
		}
	}
	else if (this->isEqualAbsolute(other)) {
		return ++newHugeInteger;
	}
	else {
		newHugeInteger.hugeInteger[0] = 0;
		newHugeInteger.hugeIntegerSize = 1;
		newHugeInteger.isPositive = true;

		return newHugeInteger;
	}

	if ((this->isPositive && !other.isPositive) || (!this->isPositive && other.isPositive)) {
		newHugeInteger.isPositive = false;
	}

	return newHugeInteger;
}

HugeInteger HugeInteger::operator%(HugeInteger& other)
{
	if (!other.isPositive) {
		std::logic_error err("Modulus should be positive");
		std::cout << err.what() << std::endl;

		throw err;
	}

	HugeInteger temp = *this;

	if (this->isGreaterThanAbsolute(other) || this->isEqualAbsolute(other)) {
		if (this->isPositive) {
			while (temp > other || temp == other) {
				temp = temp - other;
			}

			return temp;
		}
		else {
			while (!temp.isPositive) {
				temp = temp + other;
			}

			return temp;
		}
	}
	else {
		if (!this->isPositive) {
			temp = temp + other;
			return temp;
		}

		return temp;
	}
}


