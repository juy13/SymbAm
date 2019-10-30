#include "SymbAm.h"


bool SymbAm::find_as(char a)
{
	for (int i = 0; i < this->power; i++)
	{
		if (this->array[i] == a)
			return true;
	}
	return false;
}

void SymbAm::clean_str()
{
	memset(this->array, 0x00, sizeof(this->array) * sizeof(char));
}

SymbAm::SymbAm()
{

}

SymbAm::SymbAm(int p)
{
	if (p > M)
	{
		throw std::exception("Too big power");
	}
	else
	{
		this->power = p;
		for (int i = 0; i < p; i++)
		{
			this->array[i] = 0x32 + i;
		}
	}
		
}

SymbAm::SymbAm(char * came, int len)
{
	if (len >= M)
	{
		throw std::exception("Too big string");
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (find_as(came[i]))
			{
				throw std::exception("There is some repeated symbols");
			}
				
			else
			{
				this->power++;
				this->array[i] = came[i];
			}
				
		}
	}
}



SymbAm::~SymbAm()
{

}


std::ostream & operator<<(std::ostream & out, const SymbAm & point)
{
	for (int i = 0; i < point.power; i++)
	{
		out << point.array[i];
	}
	out << std::endl;
	return out;
}

std::istream & operator>>(std::istream & in, SymbAm & point)
{
	std::string inp;

	in >> inp;

	if (inp.length() >= M)
	{
		throw std::exception("Too big string");
	}

	for (int i = 0; i < inp.length(); i++)
	{
		if (point.find_as(inp[i]))
		{
			throw std::exception("There is some repeated symbols");
		}
		else
		{
			point.power++;
			point.array[i] = inp[i];
		}
	}

	return in;
}

SymbAm operator+(const SymbAm & d1, const SymbAm & d2)
{

	return SymbAm();
}

SymbAm operator-(const SymbAm & d1, const SymbAm & d2)
{

	return SymbAm();
}

SymbAm operator*(const SymbAm & d1, const SymbAm & d2)
{

	return SymbAm();
}

SymbAm & operator+=(SymbAm & left, const char & right)
{

	// TODO: вставьте здесь оператор return
}
