#pragma once
#include <iostream>
#include <string>

#define M 100

class SymbAm
{
private:
	char array[M] = { 0 };
	int power = 0;

	bool find_as(char a);
	void clean_str();

public:
	SymbAm();
	SymbAm(int p);
	SymbAm(char *came, int len);

	friend std::ostream& operator<< (std::ostream &out, const SymbAm &point);
	friend std::istream& operator>> (std::istream &in, SymbAm &point);
	friend SymbAm operator+(const SymbAm &d1, const SymbAm &d2);
	friend SymbAm operator-(const SymbAm &d1, const SymbAm &d2);
	friend SymbAm operator*(const SymbAm &d1, const SymbAm &d2);
	friend SymbAm& operator+=(SymbAm& left, const char& right);
	~SymbAm();
};

