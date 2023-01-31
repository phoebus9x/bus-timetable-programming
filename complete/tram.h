#pragma once
#include "vehicle.h"
#include "a.h"
class Tram :public Vehicle
{
private:
	float electricity_consumption;		//Электроэнергия потребление
	int year_of_manufacture;			//Год выпуска
public:
	Tram();			// конструктор
	~Tram();		// деструктор
	void set_electricity_consumption(float);
	float get_electricity_consumption();
	void set_year_of_manufacture(int);
	int get_year_of_manufacture();
	//bool operator ==(const Tram);
	friend istream& operator >>(istream& in, Tram& ob);				// перегрузка оператор чтения данных
	friend ostream& operator <<(ostream& out, const Tram& ob);		// перегрузка оператор записи данных
};