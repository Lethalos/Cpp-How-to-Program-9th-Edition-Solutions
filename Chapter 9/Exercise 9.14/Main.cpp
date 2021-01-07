/*
	File: Main.cpp
	Version: 2.0
	Writer: Kaan Ozdogan
	Mail: necdetkaanozdogan@gmail.com

	Description: C++ How to Program 9th Edition by Deitel Chapter 9 Exercise 9.14
				 This program contains addition substraction, multiplication, divison, and modulus operations
				 Negative values can be useable
*/

#include"HugeInteger.hpp"

int main()
{
	//positive-positive
	HugeInteger hugeInt1 = "123";
	HugeInteger hugeInt2 = "123456";
	HugeInteger hugeInt3;

	HugeInteger hugeIntZero = "0";

	std::cout << "== Predicate Operations ==" << std::endl;
	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << " hugeIntZero: " << hugeIntZero << std::endl;
	std::cout << "is hugeIntZero zero: " << ((hugeIntZero.isZero()) ? "True" : "False") << std::endl;
	std::cout << "is hugeInt1 zero: " << ((hugeInt1.isZero()) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 == hugeInt2: " << ((hugeInt1 == hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 != hugeInt2: " << ((hugeInt1 != hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 > hugeInt2: " << ((hugeInt1 > hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 < hugeInt2: " << ((hugeInt1 < hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 >= hugeInt2: " << ((hugeInt1 >= hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 <= hugeInt2: " << ((hugeInt1 <= hugeInt2) ? "True" : "False") << "\n\n";

	std::cout << "== Addition and Substraction ==" << std::endl;
	hugeInt3 = hugeInt1 + hugeInt2;
	std::cout << hugeInt1 << " + " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt1 - hugeInt2;
	std::cout << hugeInt1 << " - " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt2 - hugeInt1;
	std::cout << hugeInt2 << " - " << hugeInt1 << " = " << hugeInt3 << "\n\n";

	//pozitive-negative
	hugeInt1 = "123456";
	hugeInt2 = "-987";
	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 + hugeInt2;
	std::cout << hugeInt1 << " + " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt1 - hugeInt2;
	std::cout << hugeInt1 << " - " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt2 - hugeInt1;
	std::cout << hugeInt2 << " - " << hugeInt1 << " = " << hugeInt3 << "\n\n";

	//negative-positive
	hugeInt1 = "-123456";
	hugeInt2 = "987";
	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 + hugeInt2;
	std::cout << hugeInt1 << " + " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt1 - hugeInt2;
	std::cout << hugeInt1 << " - " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt2 - hugeInt1;
	std::cout << hugeInt2 << " - " << hugeInt1 << " = " << hugeInt3 << "\n\n";

	//negative-negative
	hugeInt1 = "-123456";
	hugeInt2 = "-987";
	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 + hugeInt2;
	std::cout << hugeInt1 << " + " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt1 - hugeInt2;
	std::cout << hugeInt1 << " - " << hugeInt2 << " = " << hugeInt3 << std::endl;
	hugeInt3 = hugeInt2 - hugeInt1;
	std::cout << hugeInt2 << " - " << hugeInt1 << " = " << hugeInt3 << "\n\n";

	//equal
	hugeInt1 = "123123";
	hugeInt2 = "123123";
	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	std::cout << "hugeInt1 == hugeInt2: " << ((hugeInt1 == hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 != hugeInt2: " << ((hugeInt1 != hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 > hugeInt2: " << ((hugeInt1 > hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 < hugeInt2: " << ((hugeInt1 < hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 >= hugeInt2: " << ((hugeInt1 >= hugeInt2) ? "True" : "False") << std::endl;
	std::cout << "hugeInt1 <= hugeInt2: " << ((hugeInt1 <= hugeInt2) ? "True" : "False") << "\n\n";

	//exceed 40 digit
	/*hugeInt1 = "9999999999999999999999999999999999999999";
	hugeInt2 = "1";
	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 + hugeInt2;
	std::cout << hugeInt1 << " + " << hugeInt2 << " = " << hugeInt3 << std::endl;

	std::cout << "Please input your huge integer: ";
	std::cin >> hugeInt1;
	std::cout << "Huge integer: " << hugeInt1 << std::endl;
	std::cout << "Size: " << hugeInt1.getSize() << std::endl;
	*/

	//Multiplication
	std::cout << "== Multiplication ==\n";
	
	//positive-positive
	hugeInt1 = "12";
	hugeInt2 = "6";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 * hugeInt2;
	std::cout << hugeInt1 << " * " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//positive-negative
	hugeInt1 = "12";
	hugeInt2 = "-6";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 * hugeInt2;
	std::cout << hugeInt1 << " * " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//negative-negative
	hugeInt1 = "-12";
	hugeInt2 = "-6";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 * hugeInt2;
	std::cout << hugeInt1 << " * " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//Division
	std::cout << "\n== Division ==\n";

	//positive-positive
	hugeInt1 = "64";
	hugeInt2 = "8";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 / hugeInt2;
	std::cout << hugeInt1 << " / " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//positive-negative
	hugeInt1 = "64";
	hugeInt2 = "-8";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 / hugeInt2;
	std::cout << hugeInt1 << " / " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//negative-negative
	hugeInt1 = "-64";
	hugeInt2 = "-8";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 / hugeInt2;
	std::cout << hugeInt1 << " / " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//Mod
	std::cout << "\n== Mod Operation ==\n";

	//positive-positive
	hugeInt1 = "13";
	hugeInt2 = "5";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 % hugeInt2;
	std::cout << hugeInt1 << " % " << hugeInt2 << " = " << hugeInt3 << std::endl;

	//negative-positive
	hugeInt1 = "-13";
	hugeInt2 = "5";

	std::cout << "hugeInt1: " << hugeInt1 << " hugeInt2: " << hugeInt2 << std::endl;
	hugeInt3 = hugeInt1 % hugeInt2;
	std::cout << hugeInt1 << " % " << hugeInt2 << " = " << hugeInt3 << std::endl;
}
