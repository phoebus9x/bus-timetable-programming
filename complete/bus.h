#pragma once
#include "vehicle.h"
#include "a.h"
class Bus : public Vehicle		// класс автобуса
{
private:
	char nomer[10];				// номер автобуса

public:
	Bus();						// конструктор
	~Bus();								// деструктор
	void set_nomer(const char*);		// set номер автобуса
	char* get_nomer();						
	friend istream& operator >>(istream& in, Bus& ob);			// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Bus& ob);	// перегрузка оператор записи данных
	//bool operator ==(const Bus);
};