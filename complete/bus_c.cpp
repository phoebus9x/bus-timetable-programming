#include "bus_c.h"

Bus_school::Bus_school()
	:Bus()
{

}

Bus_school::~Bus_school()
{

}

void Bus_school::set_age_of_use(int n)
{
	this->age_of_use = n;
}

int Bus_school::get_age_of_use()
{
	return this->age_of_use;
}

istream& operator >>(istream& in, Bus_school& ob)
{
	in >> dynamic_cast<Bus&>(ob);
	if (&in == &cin)
	{
		cout << "\nEnter the age of use: ";
		in >> ob.age_of_use;
		return in;
	}
	else
	{
		in >> ob.age_of_use;
		return in;
	}
}

ostream& operator <<(ostream& out, const Bus_school& ob)
{
	out << dynamic_cast<const Bus&>(ob);
	if (&out == &cout)
	{
		out << "\nAge of use: " << ob.age_of_use << endl;
		return out;
	}
	else
	{
		out << " " << ob.age_of_use;
		return out;
	}
}
