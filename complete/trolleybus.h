#pragma once
#include "vehicle.h"
#include "a.h"
class Trolleybus :public Vehicle
{
private:
	char type[10];			// тип троллейбуса
public:
	Trolleybus();				// конструктор
	~Trolleybus();				// деструктор
	void set_type(const char*);
	char* get_type();
	//bool operator ==(const Trolleybus);
	friend istream& operator >>(istream& in, Trolleybus& ob);					// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Trolleybus& ob);			// перегрузка оператор записи данных
};