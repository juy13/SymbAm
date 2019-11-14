// Laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SymbAm.h"




int main()
{
	SymbAm S7('2');
	std::cout << S7;
	char z = 'z';
	SymbAm S3, S4;
	S3 = S4 - z;
	std::cout << S3;
	SymbAm S("01234");
	SymbAm S1("ABC");
	SymbAm S2 = S + S1;
	std::cout << S ;
	std::cout << S1;
	std::cout << S2;



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
}

