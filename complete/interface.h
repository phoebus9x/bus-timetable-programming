#pragma once
#include "a.h"
#include "vehicle.h"
#include "bus.h"
#include "tram.h"
#include "trolleybus.h"
#include "bus_c.h"
#include "bus_exp.h"
#include "ring.h"
template <class T>
class Interface		// класс интерфейса
{
	T ob; 
public:
	Interface()		// конструктор
	{

	}
	~Interface()	// деструктор
	{

	}
	void menu_admin();
	void menu_user();
	void fun_admin(string);		// функция для администраторы
	void fun_user(string);		// функция для пользователя
};

template class Interface<Vehicle>;
template class Interface<Tram>;
template class Interface<Bus>;
template class Interface<Trolleybus>;
template class Interface<Bus_exp>;
template class Interface<Bus_school>;