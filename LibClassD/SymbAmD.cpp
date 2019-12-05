#include "SymbAmD.h"



bool SymbAmD::find_as(char a) const
{
	for (int i = 0; i < this->power; i++)
	{
		if (this->array[i] == a)
			return true;
	}
	return false;
}

void SymbAmD::clean_str()
{
	this->power = 0;
	this->real_sz = 0;
	delete this->array;
}

void SymbAmD::resize()
{
	char *new_array = new char[this->real_sz + 100];
	for (int i = 0; i < this->power; i++)
	{
		new_array[i] = this->array[i];
	}
	this->real_sz = this->real_sz + 100;
	delete this->array;
	this->array = new_array;
}

SymbAmD::SymbAmD()
{

}

SymbAmD::~SymbAmD()
{
	this->clean_str();
}

SymbAmD::SymbAmD(int p)
{
	if (this->array == NULL)
	{
		this->array = new char[p + 100];
		this->real_sz = 100 + p;
	}
	this->power = p;
	for (int i = 0; i < p; i++)
	{
		this->array[i] = 0x20 + i;
	}
}

SymbAmD::SymbAmD(char s)
{
	if (this->array == NULL)
	{
		this->array = new char[100];
		this->real_sz = 100;
	}
	this->power = 1;
	this->array[0] = s;
}

SymbAmD::SymbAmD(char * came, int len)
{
	if (this->array == NULL)
	{
		this->array = new char[len + 100];
		this->real_sz = 100 + len;
	}
	for (int i = 0; i < len; i++)
	{
		if (find_as(came[i]))
		{
			throw std::exception("There are some repeated symbols");
			this->clean_str();
		}

		else
		{
			this->power++;
			this->array[i] = came[i];
		}

	}
}

SymbAmD::SymbAmD(const char * came)
{
	if (this->array == NULL)
	{
		this->array = new char[strlen(came) + 100];
		this->real_sz = 100 + strlen(came);
	}
	for (int i = 0; i < strlen(came); i++)
	{
		if (find_as(came[i]))
		{
			throw std::exception("There are some repeated symbols");
			this->clean_str();
		}
		else
		{
			this->power++;
			this->array[i] = came[i];
		}

	}
}

SymbAmD::SymbAmD(const SymbAmD & A)
{
	if (this->array == NULL)
	{
		this->array = new char[A.get_pow() + 100];
		this->real_sz = 100 + A.get_pow();
	}
	memcpy(this->array, A.get_arr(), A.get_pow() * sizeof(char));
	this->power = A.get_pow();
}

int SymbAmD::get_pow() const
{
	return this->power;
}

const char * SymbAmD::get_arr() const
{
	return this->array;
}

int SymbAmD::find(char a) const
{
	for (int i = 0; i < this->power; i++)
	{
		if (this->array[i] == a)
			return i;
	}
	return -1;
}


SymbAmD & SymbAmD::operator+=(const char & right)
{
	if (this->real_sz <= this->get_pow() + 1)
		this->resize();
	this->array[this->power] = right;
	this->power++;
	return *this;
}

SymbAmD & SymbAmD::operator=(const SymbAmD & d1)
{
	if (this == &d1) 
	{
		return *this;
	}
	if (this->array == NULL)
	{
		this->array = new char[d1.get_pow() + 100];
		this->real_sz = 100 + d1.get_pow();
	}
	this->power = d1.get_pow();
	memcpy(this->array, d1.get_arr(), sizeof(char) * this->power);
	return *this;
}


std::ostream & operator<<(std::ostream & out, const SymbAmD & point)
{
	for (int i = 0; i < point.get_pow(); i++)
	{
		out << point.array[i];
	}
	out << std::endl;
	return out;
}

std::istream & operator>>(std::istream & in, SymbAmD & point)
{
	std::string inp;

	in >> inp;

	if (point.array == NULL)
	{
		point.array = new char[100 + inp.length()];
		point.real_sz = 100 + inp.length();
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

SymbAmD operator+(const SymbAmD & d1, const SymbAmD & d2)
{
	SymbAmD ncl(d1);
	int am = d1.get_pow() + d2.get_pow();

	for (int i = d1.get_pow(), j = 0; j < d2.power; i++, j++)
	{
		if (ncl.real_sz <= ncl.get_pow() + 1)
			ncl.resize();
		if (!d1.find_as(d2.array[j]))
		{
			if (ncl.real_sz <= ncl.get_pow() + 1)
				ncl.resize();
			ncl.array[i] = d2.array[j];
			ncl.power++;
			if (ncl.power >= ncl.real_sz)
				ncl.resize();
		}
		else
		{
			i--;
			continue;
		}

	}
	return ncl;
}

SymbAmD operator+(const char & s, const SymbAmD & d2)
{
	SymbAmD S(s);
	SymbAmD nw = S + d2;
	return nw;
}

SymbAmD operator-(const SymbAmD & d1, const SymbAmD & d2)
{
	SymbAmD ncl;
	int am = d1.get_pow() + d2.get_pow();

	for (int i = 0, j = 0; i < d1.get_pow(); i++)
	{
		if (ncl.real_sz <= ncl.get_pow() + 1)
			ncl.resize();
		if (d2.power <= i)
		{
			for (int k = i; k < d1.get_pow(); k++)
			{
				if (ncl.real_sz <= ncl.get_pow() + 1)
					ncl.resize();
				ncl.array[j] = d1.array[k];
				ncl.power++;
				j++;
			}
			break;
		}

		if (d1.find_as(d2.array[i]))
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

SymbAmD operator-(const char & s, const SymbAmD & d2)
{
	SymbAmD S(s);
	SymbAmD nw = S - d2;
	return nw;
}

SymbAmD operator*(const SymbAmD & d1, const SymbAmD & d2)
{
	SymbAmD ncl;
	int am = d1.get_pow() + d2.get_pow();

	for (int i = 0, j = 0; i < d1.get_pow(); i++)
	{
		if (ncl.real_sz <= ncl.get_pow() + 1)
			ncl.resize();
		if (d2.power <= i)
		{
			for (int k = 0; k < d2.power; k++)
			{
				if (ncl.real_sz <= ncl.get_pow() + 1)
					ncl.resize();
				if (d2.find_as(d1.array[i]))
					continue;
				else
				{
					
					ncl.array[j] = d2.array[k];
					ncl.power++;
					j++;
				}
			}
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

SymbAmD operator*(const char & s, const SymbAmD & d2)
{
	SymbAmD S(s);
	SymbAmD nw = S * d2;
	return nw;
}
