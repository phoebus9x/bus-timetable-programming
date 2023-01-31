#pragma once
#include "bus.h"
#include "a.h"
class Bus_school :public Bus	// класс автобус для школьника
{
private:
	int age_of_use;			// возраст использования
public:
	Bus_school();			// конструктор
	~Bus_school();			// деструктор
	void set_age_of_use(int);
	int get_age_of_use();
	friend istream& operator >>(istream& in, Bus_school& ob);					// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Bus_school& ob);			// перегрузка оператор записи данных
	//bool operator ==(const Bus_school);
};
