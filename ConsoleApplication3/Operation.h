﻿#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Session.h"
#include "HelpUtils.h"
using namespace std;


template <class Type>
class Task {
private:
	// сортировка по заданному критерию
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search  
	void ShellSort(int n, int typ, int(*Compare)(Type, Type, int))
	{
		int i, j, step;
		Type tmp;
		for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = vect[i];
			for (j = i; j >= step; j -= step)
			{
				if ((Compare(tmp, vect[j - step], typ) == -1))
					vect[j] = vect[j - step];
				else
					break;
			}
			vect[j] = tmp;
		}

	}
	// бинарный поиск
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search  
	int Binary_Search_Element(int left, int right, int type_search, Type d, int(*Compare)(Type, Type, int))
	{
		int midd = 0;
		while (1)
		{
			midd = (left + right) / 2;

			if (Compare(d, vect[midd], type_search) == -1)// если искомое больше значения в ячейке
				right = midd - 1;				// смещаем правую границу поиска
			else if (Compare(d, vect[midd], type_search) == 1)  // если искомое меньше значения в ячейке
				left = midd + 1;					// смещаем левую границу поиска
			else                       // иначе (значения равны)
				return midd;           // функция возвращает индекс ячейки

			if (left > right)          // если границы сомкнулись 
				return -1;
		}
	}
public:
	vector<Type> vect;
	Task() {}
	~Task() {}

	// удаление элемента
	void Remove(int numb)
	{
		if (numb != 0)
			vect.erase(vect.begin() + numb - 1);
	}

	// добавление элемента
	void Add(Type &elem)
	{
		vect.push_back(elem);
	}

	//размер вектора
	int size()
	{
		return vect.size();
	}

	// проверка на пустоту
	bool Is_empty()
	{
		return (vect.size() == 0);
	}

	// вывод в файл
	// void(*f) (Type) - указатель на функцию, которая записывает одну структуру в файл  
	void OutputFile(vector<Type> items, string(*f)(Type, int))
	{
		string newfname = InputFileName();
		ofstream fout(newfname);
		if (fout)
		{
			vector<Type>::const_iterator pos;
			int count = 1;
			for (pos = items.begin(); pos != items.end(); ++pos)
			{
				fout << f(*pos, count) << ' ';
				count++;
			}
			cout << endl << "Файл заполнен!" << endl;
			fout.close();
		}
		else
		{
			cout << "Файл не заполнен!" << endl;
		}
	}

	// вывод на экран
	// void(*f) (Type) - указатель на функцию, которая считывает одну структуру на экран  
	void OutputScreen(vector<Type> items, void(*f) (Type))
	{
		vector<Type>::const_iterator pos;
		int count = 1;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			cout << "Запись № " << count << endl;
			f(*pos);
			++count;
		}
		if (items.empty())
			cout << "Вектор пуст!" << endl;	
		cout << "Конец вывода!" << endl;
	} 
	bool NoMoreTime(vector<Type> items, bool(*f) (Type,Type))
	{
		vector<Type>::const_iterator pos;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			if f(elem, *pos)
				return false;
			
		}
		return true;
	}
	// вывод на экран
	// void(*f) (Type) - указатель на функцию, которая считывает одну структуру на экран  
	void OutputAverage(vector<Type> items, int(*f) (Type))
	{
		vector<Type>::const_iterator pos;
		double count = 0;
		double kolvo = 0;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			count = count + f(*pos);
			kolvo++;
		}
		double result = count / kolvo;
		cout << " Cредний балл: " << result << endl;
		cout << "Конец вывода!" << endl;
	}
	// ввод из файла
	// Type(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла 
	bool ReadFromFile(Type(*f)(ifstream&))
	{
		string newfname = InputFileName();
		std::ifstream input;

		input.open(newfname);

		if (!input)
		{
			cout << "Не удалось открыть файл" << endl;
			return false;
		}
		else
		{
			while (!input.eof())
			{
				vect.push_back(f(input));//добавление нового элемента в конец вектора
			}
			vect.erase(vect.begin() + vect.size() - 1);

			input.close();
			return true;
		}
	}

	// ввод с экрана
	//Type(*f)() - указатель на функцию, которая вводит одну структуру с консоли
	void ReadFromScreen(Type(*f)())
	{
		int n;
		Type elem;
		do
		{
			vect.push_back(f());
			n = InputNumber(0, 1, "Вы хотите добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
		} while (n != 0);
	}

	// линейный поиск
	// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
	vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type, int), int type_search)
	{
		vector<Type> NewVect;
		for (auto iter = vect.begin(); iter != vect.end(); iter++)
		{
			if (Equal(search_elem, *iter, type_search))
				NewVect.push_back(*iter);

		}

		return NewVect;
	}

	// бинарный поиск
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search 
	// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
	vector<Type> BinarySearch(int type_search, Type find_element, int(*Compare)(Type, Type, int), bool(*Equal)(Type, Type, int))
	{
		vector<Type> NewVect;
		ShellSort(vect.size(), type_search, Compare);
		int left = 0;
		int right = vect.size();
		int index;
		if ((index = Binary_Search_Element(left, right - 1, type_search, find_element, Compare)) != -1)
		{
			NewVect.push_back(vect[index]);
			int first_index = index;
			while ((++index < right) && Equal(vect[index], find_element, type_search))
				NewVect.push_back(vect[index]);
			while ((--first_index >= 0) && Equal(vect[first_index], find_element, type_search))
				NewVect.push_back(vect[first_index]);
		}
		return NewVect;
	}
};