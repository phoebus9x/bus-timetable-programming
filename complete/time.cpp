#include "time.h"

Time::Time()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
Time::Time(int h, int m, int s)
	:hour(h), minute(m), second(s)
{

}
Time::~Time()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

void Time::setTime(int h, int m, int s)
{
	bool flag_exit_1 = false;
	do
	{
		if (h >= 0 && h <= 23)
		{
			this->hour = h;
			flag_exit_1 = true;
		}
		else
		{
			cout << "\tInvalid hours. Please re-enter (0->23): "; cin >> h;
		}
	} while (flag_exit_1 != true);
	bool flag_exit_2 = false;
	do
	{
		if (m >= 0 && m <= 59)
		{
			this->minute = m;
			flag_exit_2 = true;
		}
		else
		{
			cout << "\tInvalid minutes. Please re-enter (0->59): "; cin >> m;
		}
	} while (flag_exit_2 != true);
	bool flag_exit_3 = false;
	do
	{
		if (s >= 0 && s <= 59)
		{
			this->second = s;
			flag_exit_3 = true;
		}
		else
		{
			cout << "\tInvalid seconds. Please re-enter (0->59):  "; cin >> s;
		}
	} while (flag_exit_3 != true);
}

void Time::setHour(int h)
{
	bool flag_exit = false;
	do
	{
		if (h >= 0 && h <= 23)
		{
			this->hour = h;
			flag_exit = true;
		}
		else
		{
			cout << "\tInvalid hours. Please re-enter (0->23): "; cin >> h;
		}
	} while (flag_exit != true);
}

int Time::getHour()
{
	return this->hour;
}

void Time::setMinute(int m)
{
	bool flag_exit = false;
	do
	{
		if (m >= 0 && m <= 59)
		{
			this->minute = m;
			flag_exit = true;
		}
		else
		{
			cout << "\tInvalid minutes. Please re-enter (0->59): "; cin >> m;
		}
	} while (flag_exit != true);
}

int Time::getMinute()
{
	return this->minute;
}

void Time::setSecond(int s)
{
	bool flag_exit = false;
	do
	{
		if (s >= 0 && s <= 59)
		{
			this->second = s;
			flag_exit = true;
		}
		else
		{
			cout << "\tInvalid seconds. Please re-enter (0->59): "; cin >> s;
		}
	} while (flag_exit != true);
}

int Time::getSecond()
{
	return this->second;
}

void Time::display()
{
	string hour = to_string(this->hour);
	string minute = to_string(this->minute);
	string second = to_string(this->second);
	if (hour.length() == 1)
		hour = "0" + hour;
	if (minute.length() == 1)
		minute = "0" + minute;
	if (second.length() == 1)
		second = "0" + second;
	cout << hour + ":" << minute + ":" + second << endl;
}

string Time::getTime()
{
	string hour = to_string(this->hour);
	string minute = to_string(this->minute);
	string second = to_string(this->second);
	if (hour.length() == 1)
		hour = "0" + hour;
	if (minute.length() == 1)
		minute = "0" + minute;
	if (second.length() == 1)
		second = "0" + second;
	return hour + ":" + minute + ":" + second;
}

istream& operator >>(istream& in, Time& ob)
{
	if (&in == &cin)
	{
		cout << "Enter the number of hours (0-23): ";
		in >> ob.hour;
		cout << "Enter the number of minutes (0-59): ";
		in >> ob.minute;
		cout << "Enter the number of seconds (0-59): ";
		in >> ob.second;
		return in;
	}
	else
	{
		in >> ob.hour;
		in >> ob.minute;
		in >> ob.second;
		return in;
	}
}

ostream& operator <<(ostream& out, const Time& ob)
{
	if (&out == &cout)
	{
		string hour = to_string(ob.hour);
		string minute = to_string(ob.minute);
		string second = to_string(ob.second);
		if (hour.length() == 1)
			hour = "0" + hour;
		if (minute.length() == 1)
			minute = "0" + minute;
		if (second.length() == 1)
			second = "0" + second;
		out << hour + ":" + minute + ":" + second;
		return out;
	}
	else
	{
		out << ob.hour << " " << ob.minute << " " << ob.second;
		return out;
	}
}