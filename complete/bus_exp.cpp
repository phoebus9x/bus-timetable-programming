#include "bus_exp.h"

Bus_exp::Bus_exp()
	:Bus()
{

}

Bus_exp::~Bus_exp()
{
	/*delete this->working_day;*/
}

void Bus_exp::set_number_of_working_day(int n)
{
	this->number_of_working_day = n;
}

int Bus_exp::get_number_of_working_day()
{
	return this->number_of_working_day;
}

void Bus_exp::set_working_day()
{
	cout << "Enter the number of working day: ";
	cin >> this->number_of_working_day;
	this->working_day = new string[number_of_working_day];
	cin.ignore();
	for (size_t i = 0; i < number_of_working_day; i++)
	{
		cout << "Working day: " << i + 1 << ": ";
		getline(cin, working_day[i]);
	}
}

string Bus_exp::get_working_day(int n)
{
	return working_day[n];
}

istream& operator >>(istream& in, Bus_exp& ob)
{
	in >> dynamic_cast<Bus&>(ob);
	if (&in == &cin)
	{
		cout << "\nEnter the number of working day: ";
		in >> ob.number_of_working_day;
		ob.working_day = new string[ob.number_of_working_day];
		in.ignore();
		for (size_t i = 0; i < ob.number_of_working_day; i++)
		{
			cout << "Working day " << i + 1 << ". ";
			getline(in, ob.working_day[i]);
		}
		return in;
	}
	else
	{
		in >> ob.number_of_working_day;
		ob.working_day = new string[ob.number_of_working_day];
		for (size_t i = 0; i < ob.number_of_working_day; i++)
		{
			in >> ob.working_day[i];
		}
		return in;
	}
}
ostream& operator <<(ostream& out, const Bus_exp& ob)
{
	out << dynamic_cast<const Bus&>(ob);
	if (&out == &cout)
	{
		out << "\n\=========== Working day =========== " << endl;
		for (size_t i = 0; i < ob.number_of_working_day; i++)
		{
			out << i + 1 << ". " << ob.working_day[i] << endl;
		}
		return out;
	}
	else
	{
		out << " " << ob.number_of_working_day;
		for (size_t i = 0; i < ob.number_of_working_day; i++)
		{
			out << " " << ob.working_day[i];
		}
		return out;
	}
}
