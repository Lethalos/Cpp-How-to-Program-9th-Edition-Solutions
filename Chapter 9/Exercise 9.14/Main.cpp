/*
	File: Main.cpp
	Version: 1.0
	Writer: Kaan Ozdogan
	Mail: necdetkaanozdogan@gmail.com

	Description: C++ How to Program 9th Edition by Deitel Chapter 9 Exercise 9.14
				 This program contains add and subtract operations. Multiply, divide, and modulus will come
				 Negative values can be useable
*/
#include"HugeInteger.hpp"
#include<exception>

int main()
{
	HugeInteger* num1 = new HugeInteger();
	HugeInteger* num2 = new HugeInteger();

	num1->inputHugeInteger();
	num2->inputHugeInteger();

	HugeInteger num3 = *num1 + *num2;

	num3.printHugeIntegerWithFormat();

	std::cout << "\n\n";

	num3.printHugeInteger();
}