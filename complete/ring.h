#pragma once
#include "a.h"
#include "bus.h"
#include "tram.h"
#include "trolleybus.h"
#include "vehicle.h"
#include "bus_c.h"
#include "bus_exp.h"
using namespace std;

template <class T>
struct item				// структура представляющая единичный элемент списка
{
	T data;				// переменная необходимая для хранения данных в элементе списка
	item<T>* next;		// указатель на следующий элемент списка
	item<T>* prev;		// указатель на предыдущий элемент списка
};

template <class T>
class Ring				// шаблон класса списков
{
private:				// данные доступные для класса
	item<T>* head;		// указатель первый добавленный элемент
	item<T>* tail;		// указатель последний добавленный элемент
	int length;			// количество элементов в списке
public:
	Ring()				// конструктор
	{
		head = NULL;
		tail = NULL;
		length = 0;
	}
	~Ring();			// деструктор
	bool empty();		// проверка состояния списка
	void insert_begin(T value);				// добавляем новый элемент в список
	void insert_end(T value);				// добавляем новый элемент в список
	void insert_pos(T value, int pos);		// добавляем новый элемент в список
	void pop();								// извлекаем первый элемент
	void delete_pos(int pos);				// извлекаем элемент
	void update(T value, int pos);			// изменение данных элемент
	void display();							// вывод на экране
	int getLength();						// получить длину
	void search_stop(string stop);			// поиск по остановке
	void sort_ID();							// сортировка списка 
	void search_ID(char*);					// поиск по ID номер транспорта
	void read_file(string FILE_OF_DATA);	// Чтение из файла
	void write_file(string FILE_OF_DATA);	// Запись в файл
};

template class Ring<Vehicle>;
template class Ring<Bus>;
template class Ring<Tram>;
template class Ring<Trolleybus>;
template class Ring<Bus_exp>;
template class Ring<Bus_school>;
