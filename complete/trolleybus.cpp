#include "trolleybus.h"

Trolleybus::Trolleybus()
	:Vehicle()
{

}

Trolleybus::~Trolleybus()
{

}

void Trolleybus::set_type(const char* type)
{
	strcpy_s(this->type, strlen(type) + 1, type);
}

char* Trolleybus::get_type()
{
	return this->type;
}

istream& operator >>(istream& in, Trolleybus& ob)
{
	in >> dynamic_cast<Vehicle&>(ob);
	if (&in == &cin)
	{
		cout << "\nEnter trolleybus type: ";
		in.ignore();
		in.getline(ob.type, 10);
		return in;
	}
	else
	{
		in >> ob.type;
		return in;
	}
}

ostream& operator <<(ostream& out, const Trolleybus& ob)
{
	out << dynamic_cast<const Vehicle&>(ob);
	if (&out == &cout)
	{
		out << "\nTrolleybus type: " << ob.type << endl;
		return out;
	}
	else
	{
		out << " " << ob.type;
		return out;
	}
}
