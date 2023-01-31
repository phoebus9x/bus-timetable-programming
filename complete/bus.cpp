#include "bus.h"
Bus::Bus()
	:Vehicle()
{

}

Bus::~Bus()
{

}

void Bus::set_nomer(const char* nomer)
{
	strcpy_s(this->nomer, strlen(nomer) + 1, nomer);
}

char* Bus::get_nomer()
{
	return this->nomer;
}

istream& operator >>(istream& in, Bus& ob)
{
	in >> dynamic_cast<Vehicle&>(ob);
	if (&in == &cin)
	{
		cout << "\nEnter the number of bus: ";
		in.ignore();
		in.getline(ob.nomer, 5);
		return in;
	}
	else
	{
		in >> ob.nomer;
		return in;
	}
}

ostream& operator <<(ostream& out, const Bus& ob)
{
	out << dynamic_cast<const Vehicle&>(ob);
	if (&out == &cout)
	{
		out << "\nThe number of bus: " << ob.nomer << endl;
		return out;
	}
	else
	{
		out << " " << ob.nomer;
		return out;
	}
}
