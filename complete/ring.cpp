#include "ring.h"
#include <sstream>

template <class T>
Ring<T>::~Ring()
{
	for (size_t i = 0; i < length;)
	{
		this->pop();
	}
}

template <class T>
bool Ring<T>::empty()
{
	if (this->head == this->tail && head == NULL)
		return false;
	else return true;
}

template <class T>
void Ring<T>::insert_begin(T value)
{
	item<T>* t = new item<T>;
	t->data = value;
	t->next = NULL;
	t->prev = NULL;
	length++;
	if (!this->empty())
	{
		this->head = this->tail = t;
		head->next = tail->next = NULL;
		head->prev = tail->prev = NULL;
	}
	else
	{
		t->next = head;
		head->prev = t;
		head = t;
		head->prev = tail;
		tail->next = head;
	}
	cout << "Element inserted" << endl;
}

template <class T>
void Ring<T>::insert_end(T value)
{
	item<T>* t = new item<T>;
	t->data = value;
	t->next = NULL;
	t->prev = NULL;
	length++;
	if (!this->empty())
	{
		head = tail = t;
		head->next = tail->next = NULL;
		head->prev = tail->prev = NULL;
	}
	else
	{
		tail->next = t;
		t->prev = tail;
		tail = t;
		head->prev = tail;
		tail->next = head;
	}
	cout << "Element inserted" << endl;
}

template <class T>
void Ring<T>::insert_pos(T value, int pos)
{
	item<T>* t = new item<T>;
	t->data = value;
	t->next = NULL;
	t->prev = NULL;
	length++;
	if (!this->empty())
	{
		if (pos == 1)
		{
			head = tail = t;
			head->next = tail->next = NULL;
			head->prev = tail->prev = NULL;
			cout << "Element inserted" << endl;
		}
		else
		{
			cout << "Position out of range!!!" << endl;
			length--;
			return;
		}
	}
	else
	{
		if (length < pos)
		{
			cout << "Position out of range!!!" << endl;
			length--;
			return;
		}
		else if (length == pos)
		{
			tail->next = t;
			t->prev = tail;
			tail = t;
			head->prev = tail;
			tail->next = head;
			cout << "Element inserted" << endl;
		}
		else
		{
			if (pos == 1)
			{
				t->next = head;
				head->prev = t;
				head = t;
				head->prev = tail;
				tail->next = head;
				cout << "Element inserted" << endl;
			}
			else
			{
				item<T>* h = head;
				item<T>* ptr = new item<T>;
				for (size_t i = 1; i <= length; i++)
				{
					ptr = h;
					h = h->next;
					if (i == pos - 1)
					{
						ptr->next = t;
						t->prev = ptr;
						t->next = h;
						h->prev = t;
						cout << "Element inserted" << endl;
						break;
					}
				}
			}
		}
	}
}

template <class T>
void Ring<T>::display()
{
	item<T>* t = new item<T>;
	if (!this->empty())
	{
		cout << "The List is empty, nothing to display" << endl;
		return;
	}
	t = head;
	for (size_t i = 0; i < length; i++)
	{
		cout << t->data << endl;
		t = t->next;
		cout << "====================================================================" << endl << endl;
	}
	cout << endl;

}

template <class T>
void Ring<T>::pop()
{
	item<T>* t = head;

	if (!this->empty())
	{
		cout << "List is empty, nothing to delete" << endl;
		return;
	}
	else if (this->length == 1)
	{
		this->length--;
		this->head = this->tail = NULL;
	}
	else
	{
		tail->next = t->next;
		t->next->prev = tail;
		head = t->next;
		length--;
	}
	delete t;
}

template <class T>
int Ring<T>::getLength()
{
	return length;
}

template <class T>
void Ring<T>::update(T value, int pos)
{
	if (!this->empty())
	{
		cout << "The List is empty, nothing to update" << endl;
		return;
	}
	item<T>* t = new item<T>;
	if (length < pos)
	{
		cout << "Position out of range" << endl;
		return;
	}
	t = head;
	if (pos == 1)
	{
		t->data = value;
		cout << "Node updated" << endl;
		return;
	}
	for (size_t i = 0; i < pos - 1; i++)
	{
		t = t->next;
	}
	t->data = value;
	cout << "Node updated" << endl;
}

template <class T>
void Ring<T>::delete_pos(int pos)
{
	item<T>* t;
	item<T>* ptr = new item<T>;
	if (!this->empty())
	{
		cout << "List is empty, nothing to delete" << endl;
		return;
	}
	if (length < pos)
	{
		cout << "Position out of range" << endl;
		return;
	}
	t = head;
	if (pos == 1)
	{
		if (this->length == 1)
		{
			this->length--;
			this->head = this->tail = NULL;
		}
		else
		{
			length--;
			tail->next = t->next;
			t->next->prev = tail;
			head = t->next;
		}
		delete t;
		cout << "Element deleted" << endl;
		return;
	}
	for (size_t i = 0; i < pos - 1; i++)
	{
		t = t->next;
		ptr = t->prev;
	}
	ptr->next = t->next;
	t->next->prev = ptr;
	if (pos == length)
	{
		tail = ptr;
	}
	length--;
	delete t;
	cout << "Element Deleted" << endl;
}

template<class T>
void Ring<T>::search_stop(string stop)
{
	if (!this->empty())
	{
		cout << "The List is empty, nothing to search" << endl;
		return;
	}
	item<T>* t = head;
	cout << "======================================" << endl;
	cout << "|       STOP          |     TIME     |" << endl;
	cout << "======================================" << endl;
	for (size_t i = 0; i < this->getLength(); i++)
	{
		for (size_t j = 0; j < t->data.get_number_of_stop(); j++)
		{
			if (t->data.get_stops(j) == stop)
			{
				cout << "|" << setw(20) << t->data.get_ID_number() << " |" << setw(11) << t->data.get_time(j) << "   |" << endl;
				cout << "+---------------------+--------------+" << endl;
			}
		}
		t = t->next;
	}
}

template<class T>
void Ring<T>::search_ID(char* a)
{
	bool check = false;
	if (!this->empty())
	{
		cout << "The List is empty, nothing to search" << endl;
		return;
	}
	item<T>* t = head;
	for (size_t i = 0; i < this->getLength(); i++)
	{
		if (strcmp(t->data.get_ID_number(), a) == 0)
		{
			check = true;
			cout << t->data;
			cout << "\n=================================================" << endl;
			cout << endl;
		}
		t = t->next;
	}
	if (check == false)
	{
		cout << "\tNO RESULT" << endl;
	}
}

template<class T>
void Ring<T>::sort_ID()
{
	if (!this->empty())
	{
		cout << "The List is empty, nothing to search" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->getLength() - 1; i ++)
		{
			item<T>* a = head;
			item<T>* b = a->next;
			for (int j = i + 1; j < this->getLength(); j++)
			{
				if (a->data > b->data)
				{
					swap(a->data, b->data);
				}
				a = a->next;
				b = a->next;
			}
		}
	}
}

template <class T>
void Ring<T>::read_file(string FILE_OF_DATA)
{
	T b;
	string temp;
	ifstream fin(FILE_OF_DATA, ios::in);
	if (!fin.is_open()) cout << "The specified file does not exist!" << endl;
	else
	{
		while (!fin.eof())
		{
			getline(fin, temp);
			if (temp.size() > 1)
			{
				stringstream ss;
				ss << temp;
				ss >> b;
				this->insert_begin(b);
			}
		}
	}
	fin.close();
}

template <class T>
void Ring<T>::write_file(string FILE_OF_DATA)
{
	item<T>* t = new item<T>;
	if (!this->empty())
	{
		cout << "The List is empty, nothing to write" << endl;
		return;
	}
	t = head;
	ofstream fout(FILE_OF_DATA, ios::out);
	for (int i = 0; i < this->length; i++)
	{

		fout << t->data << endl;
		t = t->next;
	}
	fout.close();
}