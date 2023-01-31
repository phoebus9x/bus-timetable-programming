#pragma once
#include "a.h"
#include "time.h"

class Vehicle			// класс транспорта
{
private:
	int number_of_seats;	// количество стула
	char ID_number[5];		// ID транспорта
	Time workStartTime;		// время сначала работать
	Time workEndTime;		// время конец работать
	string* stop;			// остановки
	Time* t;				// время дойти до остановки
	int number_of_stop;		// количество остановки
public:
	Vehicle();		// конструктор
	~Vehicle();		// деструктор
	void set_number_of_seats(int);
	int get_number_of_seats();
	void set_ID_number(const char*);
	char* get_ID_number();
	void setWorkStartTime();
	string getWorkStartTime();
	void setWorkEndTime();
	string getWorkEndTime();
	void set_stops();
	string get_stops(int);
	int get_number_of_stop();
	string get_time(int);
	friend istream& operator >>(istream& in, Vehicle& ob);		// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Vehicle& ob);	// перегрузка оператор записи данных
	bool operator ==(const Vehicle);		// перегрузка оператор ==
	bool operator >(Vehicle);				// перегрузка оператор >
};
