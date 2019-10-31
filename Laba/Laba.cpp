// Laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SymbAm.h"




int main()
{
	SymbAm A;
	int i = 0;
	std::cout << "Inputing elements in class A" << std::endl;
	try
	{
		for (i = 0; i < 200; i++)
		{
			A += char(i + 0x25);
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "  in i = " << i << std::endl;
	}
	std::cout << "sizeof class A: " << A.get_pow() << std::endl;
	std::cout << "Printing class A: " << A << std::endl;

	std::cout << "Creating class B by power" << std::endl;
	SymbAm B(40);
	std::cout << "sizeof class B: " << B.get_pow() << std::endl;
	std::cout << "Printing class B: " << B << std::endl;

	std::cout << "Creating class C by concatination of A and B" << std::endl;
	SymbAm C;
	try
	{
		C = A + B;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << "sizeof class C: " << C.get_pow() << std::endl;
	std::cout << "Printing class C: " << C << std::endl;

	std::cout << "Creating class D by string" << std::endl;
	SymbAm D("1234567890-=qwefjsk");	
	std::cout << "sizeof class D: " << D.get_pow() << std::endl;
	std::cout << "Printing class D: " << D << std::endl;

	std::cout << "class C is concatination of A and B" << std::endl;
	try
	{
		C = D + B;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "sizeof class C: " << C.get_pow() << std::endl;
	std::cout << "Printing class C: " << C << std::endl;

	std::cout << "Creating class F by intersection of C and D" << std::endl;
	SymbAm F;
	try
	{
		F = C * D;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "sizeof class F: " << F.get_pow() << std::endl;
	std::cout << "Printing class F: " << F << std::endl;

	std::cout << "Creating class E by subtraction from A D" << std::endl;
	SymbAm E;
	try
	{
		E = A - D;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "sizeof class E: " << E.get_pow() << std::endl;
	std::cout << "Printing class E: " << E << std::endl;
	
	std::cout << "Input any symbol to find in class E: ";
	char a;
	std::cin >> a;
	int rc = E.find(a);
	if(rc != -1)
		std::cout << "Symbol was found" << std::endl;
	else
		std::cout << "Symbol wasn't found" << std::endl;

	std::cout << "Creating class E by inputing from stream" << std::endl;
	SymbAm H;
	try
	{
		std::cin >> H;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "sizeof class H: " << H.get_pow() << std::endl;
	std::cout << "Printing class H: " << H << std::endl;

}

