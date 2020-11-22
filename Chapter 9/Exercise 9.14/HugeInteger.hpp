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
	
	//INPUT-OUTPUT METHODS
	void inputHugeInteger();
	void printHugeInteger() const;
	void printHugeIntegerWithFormat() const;
	
	//GETTERS
	int getSize() const;
	
	//PREDICATE OPERATORS
	bool isEqualTo(const HugeInteger& other) const;
	bool isNotEqualTo(const HugeInteger& other) const;
	bool isGreaterThan(const HugeInteger& other) const;
	bool isLessThan(const HugeInteger& other) const;
	bool isGreaterThanOrEqual(const HugeInteger& other) const;
	bool isLessThanOrEqual(const HugeInteger& other) const;
	bool isGreaterThanAbsolute(const HugeInteger& other) const;

	//ARITHMETIC OPERATORS
	HugeInteger operator+(HugeInteger& other);
	HugeInteger operator-(HugeInteger& other);

private:
	int hugeInteger[MAX_SIZE_OF_HUGE_INTEGER + 1]; 
	int reverseHugeInteger[MAX_SIZE_OF_HUGE_INTEGER + 1]; 
	int hugeIntegerSize; 
	bool isPositive; 
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
	void printReverseHugeInt(); //todo: delete
};