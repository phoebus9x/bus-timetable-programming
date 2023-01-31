#pragma once
#include "a.h"
class Time	// класс времени
{
protected:
	int hour;		//час
	int minute;		//минут
	int second;		//секунд
public:
	Time();					// конструктор
	~Time();				// деструктор
	Time(int, int, int);
	void setTime(int, int, int);
	string getTime();
	void setHour(int);
	int getHour();
	void setMinute(int);
	int getMinute();
	void setSecond(int);
	int getSecond();
	void display();
	friend istream& operator >>(istream& in, Time& ob);			// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Time& ob);	// перегрузка оператор записи данных

	friend class Vehicle;
};
