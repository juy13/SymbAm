#include "SymbAm.h"


bool SymbAm::find_as(char a) const
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
	memset(this->array, 0x00, M * sizeof(char));
}

SymbAm::SymbAm(int p)
{
	memset(this->array, 0x00, M * sizeof(char));
	if (p >= M)
	{
		throw std::exception("Too big power");
	}
	else
	{
		this->power = p;
		for (int i = 0; i < p; i++)
		{
			this->array[i] = 0x20 + i;
		}
	}
		
}

SymbAm::SymbAm(char * came, int len)
{
	memset(this->array, 0x00, M * sizeof(char));
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

SymbAm::SymbAm(const char * came)
{
	memset(this->array, 0x00, M * sizeof(char));
	if (strlen(came) >= M)
	{
		throw std::exception("Too big string");
	}
	else
	{
		for (int i = 0; i < strlen(came); i++)
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

SymbAm::SymbAm(const SymbAm & A)
{
	memset(this->array, 0x00, M * sizeof(char));
	memcpy(this->array, A.get_arr(), M * sizeof(char));
	this->power = A.get_pow();
}

int SymbAm::get_pow() const
{
	return this->power;
}

const char * SymbAm::get_arr() const
{
	return this->array;
}

int SymbAm::find(char a) const
{
	for (int i = 0; i < this->power; i++)
	{
		if (this->array[i] == a)
			return i;
	}
	return -1;
}

SymbAm::~SymbAm()
{

}


std::ostream & operator<<(std::ostream & out, const SymbAm & point)
{
	for (int i = 0; i < point.get_pow(); i++)
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
	SymbAm ncl(d1);
	int am = d1.get_pow() + d2.get_pow();

	for (int i = d1.get_pow(), j = 0; j < d2.power; i++, j++)
	{
		if (!d1.find_as(d2.array[j]))
		{
			ncl.array[i] = d2.array[j];
			ncl.power++;
			if(ncl.power >= M)
				throw std::exception("Out of range");
		}
		else
		{
			i--;
			continue;
		}
			
	}
	return ncl;
}

SymbAm operator-(const SymbAm & d1, const SymbAm & d2)
{
	SymbAm ncl;
	int am = d1.get_pow() + d2.get_pow();

	for (int i = 0, j = 0; i < d1.get_pow(); i++)
	{
		/*if (d2.power <= i)
		{
			for (int k = i; k < d1.get_pow(); k++)
			{
				ncl.array[j] = d1.array[k];
				ncl.power++;
				j++;
			}
			break;
		}*/
			
		if (d2.find_as(d1.array[i]))
			continue;
		else
		{
			ncl.array[j] = d1.array[i];
			ncl.power++;
			j++;
		}
	}

	return ncl;
}

SymbAm operator*(const SymbAm & d1, const SymbAm & d2)
{
	SymbAm ncl;
	int am = d1.get_pow() + d2.get_pow();

	for (int i = 0, j = 0; i < d1.get_pow(); i++)
	{
		if (d2.power <= i)
		{
			break;
		}
			
		if (!d1.find_as(d2.array[i]))
			continue;
		else
		{
			ncl.array[j] = d1.array[i];
			ncl.power++;
			j++;
		}
	}
	return ncl;
}

SymbAm & SymbAm::operator+=(const char & right)
{
	if (this->power >= M)
	{
		throw std::exception("Out of range");
	}
	else
	{
		this->array[this->power] = right;
		this->power++;
	}
	return *this;
}
