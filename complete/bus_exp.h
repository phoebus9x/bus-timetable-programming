#pragma once
#include "bus.h"
#include "a.h"

class Bus_exp :public Bus		// класс автобус экспресс
{
private:
	string* working_day;		// рабочий день недели
	int number_of_working_day;	// количество - рабочий день недели
public:
	Bus_exp();		// конструктор
	~Bus_exp();		// деструктор
	void set_number_of_working_day(int);
	int get_number_of_working_day();
	void set_working_day();	
	string get_working_day(int);
	//bool operator ==(const Bus_exp);
	friend istream& operator >>(istream& in, Bus_exp& ob);		// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Bus_exp& ob);	// перегрузка оператор записи данных
};
