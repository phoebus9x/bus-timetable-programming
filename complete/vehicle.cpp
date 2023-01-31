#include "vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::~Vehicle()
{
	/*delete this->stop;
	delete this->t;*/
}

void Vehicle::set_number_of_seats(int n)
{
	this->number_of_seats = n;
}

int Vehicle::get_number_of_seats()
{
	return number_of_seats;
}

void Vehicle::set_ID_number(const char* ID)
{
	strcpy_s(this->ID_number, strlen(ID) + 1, ID);
}

char* Vehicle::get_ID_number()
{
	return ID_number;
}

void Vehicle::setWorkStartTime()
{
	int h, m, s;
	Time t;
	cout << "enter the number of hours: ";
	cin >> h;
	cout << "enter the number of minutes: ";
	cin >> m;
	cout << "enter the number of seconds: ";
	cin >> s;
	t.setTime(h, m, s);
	this->workStartTime.hour = t.hour;
	this->workStartTime.minute = t.minute;
	this->workStartTime.second = t.second;
}

string Vehicle::getWorkStartTime()
{
	return workStartTime.getTime();
}

void Vehicle::setWorkEndTime()
{
	int h, m, s;
	Time t;
	cout << "enter the number of hours: ";
	cin >> h;
	cout << "enter the number of minutes: ";
	cin >> m;
	cout << "enter the number of seconds: ";
	cin >> s;
	t.setTime(h, m, s);
	this->workEndTime.hour = t.hour;
	this->workEndTime.minute = t.minute;
	this->workEndTime.second = t.second;
}

string Vehicle::getWorkEndTime()
{
	return workEndTime.getTime();
}

void Vehicle::set_stops()
{
	cout << "Enter the number of stop: ";
	cin >> this->number_of_stop;
	this->stop = new string[number_of_stop];
	cin.ignore();
	for (size_t i = 0; i < number_of_stop; i++)
	{
		cout << "Stop " << i + 1 << ": ";
		getline(cin, stop[i]);
	}
}

string Vehicle::get_stops(int n)
{
	return stop[n];
}

int Vehicle::get_number_of_stop()
{
	return this->number_of_stop;
}

string Vehicle::get_time(int i)
{
	return t[i].getTime();
}

istream& operator >>(istream& in, Vehicle& ob)
{
	if (&in == &cin)
	{
		int h, m, s;
		in.ignore();
		cout << "Enter the ID_number: ";
		in.getline(ob.ID_number, 5);
		cout << "Enter the number of seats: ";
		in >> ob.number_of_seats;
		cout << "\n\tEnter the Work_start_time" << endl;
		in >> ob.workStartTime;
		cout << "\n\tEnter the Work_end_time" << endl;
		in >> ob.workEndTime;
		cout << "\nEnter the number of stop: ";
		in >> ob.number_of_stop;
		ob.stop = new string[ob.number_of_stop];
		ob.t = new Time[ob.number_of_stop];
		for (size_t i = 0; i < ob.number_of_stop; i++)
		{
			cout << "\nEnter the bus stop " << i + 1 << ". ";
			in.ignore();
			getline(in, ob.stop[i]);
			cout << "\tEnter the time " << endl;
			cout << "enter the number of hours: ";
			cin >> h;
			cout << "enter the number of minutes: ";
			cin >> m;
			cout << "enter the number of seconds: ";
			cin >> s;
			ob.t[i].setTime(h, m, s);
		}
		return in;
	}
	else
	{
		in >> ob.ID_number
			>> ob.number_of_seats
			>> ob.workStartTime
			>> ob.workEndTime
			>> ob.number_of_stop;
		ob.stop = new string[ob.number_of_stop];
		ob.t = new Time[ob.number_of_stop];
		for (size_t i = 0; i < ob.number_of_stop; i++)
		{
			in >> ob.stop[i]
				>> ob.t[i];
		}
		return in;
	}
}

ostream& operator <<(ostream& out, const Vehicle& ob)
{
	if (&out == &cout)
	{
		out << "ID_number: " << ob.ID_number << ". The number of seats: " << ob.number_of_seats << endl;
		out << "\nStart working from " << ob.workStartTime << " to " << ob.workEndTime << "." << endl;
		out << "\n=========== STOPS ===========" << endl;
		for (size_t i = 0; i < ob.number_of_stop; i++)
		{
			out << i + 1 << ". " << ob.stop[i] << " " << ob.t[i].getTime() << endl;
		}
		return out;
	}
	else
	{
		out << ob.ID_number << " " << ob.number_of_seats << " " << ob.workStartTime << " " << ob.workEndTime << " " << ob.number_of_stop;
		for (size_t i = 0; i < ob.number_of_stop; i++)
		{
			out << " " << ob.stop[i] << " " << ob.t[i];
		}
		return out;
	}

}

bool Vehicle::operator ==(const Vehicle obj)
{
	if (strcmp(this->ID_number, obj.ID_number) == 0)
		return true;
	else return false;
}

bool Vehicle::operator >(Vehicle data)
{
	for (int i = 0; this->get_ID_number()[i] != '\0' || data.get_ID_number()[i] != '\0'; i++)
	{
		if ((int(this->get_ID_number()[i]) == 255 || int(data.get_ID_number()[i] == 255)))
		{
			if ((int(255 - this->get_ID_number()[i]) > int(255 - data.get_ID_number()[i])))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (int(this->get_ID_number()[i]) > int(data.get_ID_number()[i]))
		{
			return true;
		}
		else if (int(this->get_ID_number()[i]) < int(data.get_ID_number()[i]))
		{
			return false;
		}
	}
}
