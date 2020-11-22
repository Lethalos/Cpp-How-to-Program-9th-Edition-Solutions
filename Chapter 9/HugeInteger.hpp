/*
	File: HugeInteger.hpp
	Version: 1.0
	Writer: Kaan Ozdogan
	Mail: necdetkaanozdogan@gmail.com

	Description: C++ How to Program 9th Edition by Deitel Chapter 9 Exercise 9.14
				 This program contains add and subtract operations. Multiply, divide, and modulus will come
				 Negative values can be useable
*/
#pragma once
#include<iostream>
#include<string>

#define MAX_SIZE_OF_HUGE_INTEGER 40

class HugeInteger
{
public:
	HugeInteger();
	HugeInteger(const char* hugeIntegerStr);
	
	bool isPositive;

	//SETTERS
	void setHugeInteger(std::string& hugeIntegerStr);

	//GETTERS
	int getSize() const;
	
	//PREDICATE OPERATIONS
	bool isZero() const;
	bool operator==(const HugeInteger& other) const;
	bool operator!=(const HugeInteger& other) const;
	bool operator>(const HugeInteger& other) const;
	bool operator<(const HugeInteger& other) const;
	bool operator>=(const HugeInteger& other) const;
	bool operator<=(const HugeInteger& other) const;
	bool isGreaterThanAbsolute(const HugeInteger& other) const;

	//ARITHMETIC OPERATIONS
	HugeInteger operator+(HugeInteger& other);
	HugeInteger operator-(HugeInteger& other);
	
	//INPUT-OUTPUT OPERATIONS
	//void inputHugeInteger();
	friend std::istream& operator>>(std::istream& stream, HugeInteger& other);
	friend std::ostream& operator<<(std::ostream& stream, const HugeInteger& other);

private:
	int hugeInteger[MAX_SIZE_OF_HUGE_INTEGER + 1]; 
	int reverseHugeInteger[MAX_SIZE_OF_HUGE_INTEGER + 1]; 
	int hugeIntegerSize; 
	std::string hugeIntegerStr;
	
	//UTILITY METHODS
	void repairInputIfZerosInTheBeginning();
	void setHugeIntegerFromString(const std::string& hugeIntegerStr, const int& hugeIntegerSize);
	void setReverseHugeInteger();
	void setHugeIntegerFromReverse();
	void setSizeFromReverse();
	void tuneSmallForOperations(HugeInteger& smallHugeInteger);
	void repairReverseIfZerosInTheBeginning();
	HugeInteger addOperation(HugeInteger& other, bool isOtherChanged);
	HugeInteger subtractOperation(HugeInteger& other);
};