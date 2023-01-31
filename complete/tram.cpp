#include "tram.h"

Tram::Tram()
	:Vehicle()
{

}

Tram::~Tram()
{

}

void Tram::set_electricity_consumption(float n)
{
	this->electricity_consumption = n;
}

float Tram::get_electricity_consumption()
{
	return this->electricity_consumption;
}

void Tram::set_year_of_manufacture(int n)
{
	this->year_of_manufacture = n;
}

int Tram::get_year_of_manufacture()
{
	return this->year_of_manufacture;
}

istream& operator >>(istream& in, Tram& ob)
{
	in >> dynamic_cast<Vehicle&>(ob);
	if (&in == &cin)
	{
		cout << "\nEnter the electricity consumption in one hour: ";
		in >> ob.electricity_consumption;
		cout << "\nEnter the year of manufacture: ";
		in >> ob.year_of_manufacture;
		return in;
	}
	else
	{
		in >> ob.electricity_consumption;
		in >> ob.year_of_manufacture;
		return in;
	}
}

ostream& operator <<(ostream& out, const Tram& ob)
{
	out << dynamic_cast<const Vehicle&>(ob);
	if (&out == &cout)
	{
		out << "\nThe electricity consumption in one hour: " << ob.electricity_consumption << endl;
		out << "\nThe year of manufacture: " << ob.year_of_manufacture << endl;
		return out;
	}
	else
	{
		out << " " << ob.electricity_consumption << " " << ob.year_of_manufacture;
		return out;
	}
}
