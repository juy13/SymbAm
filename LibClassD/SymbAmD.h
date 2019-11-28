#pragma once
#include <iostream>
#include <string>

#define M 100

class SymbAmD
{
private:
	char *array = NULL;
	int power = 0;
	int real_sz = 0;

	bool find_as(char a) const;
	void clean_str();
	void resize();

public:
	SymbAmD();
	SymbAmD(int p);
	SymbAmD(char s);
	SymbAmD(char *came, int len);
	SymbAmD(const char *came);
	SymbAmD(const SymbAmD &A);

	int get_pow() const;
	const char* get_arr() const;
	int find(char a) const;

	friend std::ostream& operator<< (std::ostream &out, const SymbAmD &point);
	friend std::istream& operator>> (std::istream &in, SymbAmD &point);
	friend SymbAmD operator+(const SymbAmD &d1, const SymbAmD &d2);
	friend SymbAmD operator+(const char &s, const SymbAmD &d2);
	friend SymbAmD operator-(const SymbAmD &d1, const SymbAmD &d2);
	friend SymbAmD operator-(const char &s, const SymbAmD &d2);
	friend SymbAmD operator*(const SymbAmD &d1, const SymbAmD &d2);
	friend SymbAmD operator*(const char &s, const SymbAmD &d2);
	SymbAmD& operator+=(const char& right);
	SymbAmD& operator=(const SymbAmD &d1);
	~SymbAmD();
};