/*
	File: HugeInteger.cpp
	Version: 1.0
	Writer: Kaan Ozdogan
	Mail: necdetkaanozdogan@gmail.com

	Description: C++ How to Program 9th Edition by Deitel Chapter 9 Exercise 9.14
				 This program contains add and subtract operations. Multiply, divide, and modulus will come
				 Negative values can be useable
*/
#include<stdexcept>
#include<iomanip>
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

void HugeInteger::inputHugeInteger()
{
	std::cout << "Please input your huge integer: ";
	std::cin >> hugeIntegerStr;

	if (hugeIntegerStr[0] == '-') {
		hugeIntegerStr.erase(0, 1);
		isPositive = false;
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

void HugeInteger::printHugeInteger() const
{
	if (!isPositive) {
		std::cout << "-";
	}

	for (int i = 0; i < hugeIntegerSize; i++) {
		std::cout << hugeInteger[i];
	}
}

void HugeInteger::printHugeIntegerWithFormat() const
{
	std::cout << "\nSize:" << hugeIntegerSize << "\n";

	std::cout << "Is positive: " << isPositive << "\n\n";

	if (!isPositive) {
		std::cout << "-";
	}

	for (int i = 0; i < hugeIntegerSize; i++) {
		std::cout << hugeInteger[i];
	}

	std::cout << "\n\n";

	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER; i++) {
		std::cout << i + 1 << ": " << std::setw(2) << hugeInteger[i] << "\n";
	}
}

int HugeInteger::getSize() const
{
	return hugeIntegerSize;
}

bool HugeInteger::isEqualTo(const HugeInteger& other) const
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

bool HugeInteger::isNotEqualTo(const HugeInteger& other) const
{
	return !(this->isEqualTo(other));
}

bool HugeInteger::isGreaterThan(const HugeInteger& other) const
{
	if (this->isPositive && !other.isPositive) {
		return true;
	}
	else if (!this->isPositive && other.isPositive) {
		return false;
	}

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

bool HugeInteger::isLessThan(const HugeInteger& other) const
{
	return !(this->isGreaterThan(other));
}

bool HugeInteger::isGreaterThanOrEqual(const HugeInteger& other) const
{
	if (this->isEqualTo(other) || this->isGreaterThan(other)) {
		return true;
	}

	return false;
}

bool HugeInteger::isLessThanOrEqual(const HugeInteger& other) const
{
	if (this->isEqualTo(other) || this->isLessThan(other)) {
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
	HugeInteger* newHugeInteger = new HugeInteger();

	if (!this->isPositive && !other.isPositive) {
		newHugeInteger->isPositive = false;
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
					if (newHugeInteger->reverseHugeInteger[i + 1] == -1) {
						newHugeInteger->reverseHugeInteger[i + 1] += onHand + 1; //reason of +1 is neutralize the -1
					}
				}
				else {
					this->reverseHugeInteger[i + 1] += onHand;
				}
			}

			newHugeInteger->reverseHugeInteger[i] = sum;
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
					if (newHugeInteger->reverseHugeInteger[i + 1] == -1) {
						newHugeInteger->reverseHugeInteger[i + 1] += onHand + 1; //reason of +1 is neutralize the -1
					}
				}
				else {
					other.reverseHugeInteger[i + 1] += onHand;
				}
			}

			newHugeInteger->reverseHugeInteger[i] = sum;
		}
	}

	//restore reverse huge integers
	this->setReverseHugeInteger();
	other.setReverseHugeInteger();

	newHugeInteger->setSizeFromReverse();

	if (newHugeInteger->hugeIntegerSize > MAX_SIZE_OF_HUGE_INTEGER) {
		std::invalid_argument* err = new std::invalid_argument("a huge integer cannot exceed 40 digits");

		std::cout << err->what() << std::endl;

		throw* err;
	}

	newHugeInteger->setHugeIntegerFromReverse();

	return *newHugeInteger;
}

HugeInteger HugeInteger::subtractOperation(HugeInteger& other)
{
	HugeInteger* newHugeInteger = new HugeInteger();

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
			newHugeInteger->reverseHugeInteger[i] = result;
		}
	}
	else if (this->isEqualTo(other)) {
		newHugeInteger->reverseHugeInteger[0] = 0;
		itNeedRepairment = false;
	}
	else {
		newHugeInteger->isPositive = false;

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
			newHugeInteger->reverseHugeInteger[i] = result;
		}
	}

	//restore reverse huge integers
	this->setReverseHugeInteger();
	other.setReverseHugeInteger();

	if (itNeedRepairment) { newHugeInteger->repairReverseIfZerosInTheBeginning(); }
	newHugeInteger->setSizeFromReverse();
	newHugeInteger->setHugeIntegerFromReverse();

	return *newHugeInteger;
}

void HugeInteger::printReverseHugeInt()
{
	for (int i = 0; i < MAX_SIZE_OF_HUGE_INTEGER + 1; i++) {
		std::cout << reverseHugeInteger[i];
	}

	std::cout << "\n";
}
