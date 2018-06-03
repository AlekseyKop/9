#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

class Session {
public:
	// номер курса
	int course;
	// Фамилия студента
	string LastName;
	// название дисциплины
	string Discipline;
	// код группы
	int group;
	// номер зачётки
	int zachetka;
	// оценка по дисциплине
	int markofdiscipline;

	// конструктор по умолчанию
	Session()
	{
		int course = 0;
		string LastName = "";
		string Discipline = "";
		int group = 0;
		int zachetka = 0;
		int markofdiscipline = 0;
	}


	// изменение структуры "сессия"
	Session ChangeSession(Session &result)
	{
		if (InputNumber(0, 1, "Вы хотите изменить Курс " + to_string(result.course) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.course = InputNumber(1, 6, "Введите новый курс (1 - 6): ");
		if (InputNumber(0, 1, "Вы хотите изменить Фамилию Студента " + result.LastName + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.LastName = InputInformation("Введите новую Фамилию Студента: ");
		if (InputNumber(0, 1, "Вы хотите изменить название Дисциплины " + result.Discipline + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.Discipline = InputInformation("Введите новую Дисциплину: ");
		if (InputNumber(0, 1, "Вы хотите изменить Код Группы " + to_string(result.group) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.group = InputNumber(0, 99, "Введите новый код группы (0 - 99): ");
		if (InputNumber(0, 1, "Вы хотите изменить номер зачётной книжки " + to_string(result.zachetka) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.zachetka = InputNumber(0, 999999, "Введите новый номер зачётной книжки (000000 - 999999): ");
		if (InputNumber(0, 1, "Вы хотите изменить дисциплину " + to_string(result.markofdiscipline) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.markofdiscipline = InputNumber(2, 5, "Введите оценку по дисциплину (2 - 5): ");

		return result;
	}

	// перегруженный оператор равенства для структуры "сессия"
	Session& operator = (Session c)
	{
		course = c.course;
		LastName = c.LastName;
		Discipline = c.Discipline;
		group = c.group;
		zachetka = c.zachetka;
		markofdiscipline= c.markofdiscipline;

		return (*this);
	}
};

// функция ввода структуры "cессия" с консоли
Session InputScreenSession()
{
	Session c;
	c.course = InputNumber(1,6,"Введите курс: ");
	c.LastName = InputInformation("Введите Фамилию Студента: ");
	c.Discipline = InputInformation("Введите Дисциплину: ");
	c.group = InputNumber(0, 99, "Введите группу (0 - 100): ");
	c.zachetka = InputNumber(0, 999999, "Введите номер зачётки (0 - 999999): ");
	c.markofdiscipline = InputNumber(2, 5, "Введите оценку (2 - 5): ");
	return c;
}

// функция вывода структуры "cессия" на консоль
void OutputScreenSession(Session c)
{
	cout << "Курс: " << c.course << endl;
	cout << "Фамилия Студента: " << c.LastName << endl;
	cout << "Дисциплина: " << c.Discipline << endl;
	cout << "Код группы: " << c.group << endl;
	cout << "Номер зачётной книжки:" << c.zachetka << endl;
	cout << "Оценка по дисциплине:" << c.markofdiscipline << endl;
}
bool IsEqual(Session c1, Session c2)
{
	return ((c1.zachetka == c2.zachetka) && (c1.Discipline == c2.Discipline) && (c1.LastName == c2.LastName));
}
// функция вывода структуры "cессия" на консоль
int OutputAverage(Session c)
{
	return c.markofdiscipline;
}


//перевод структуры "сессия" в строку
string ToString(Session c, int i)
{
	string result = "Запись № " + to_string(i) + "\n" + "Курс: " + to_string(c.course) + "\n" + "Фамилия Студента: " + c.LastName + "\n" + "Дисциплина: " + c.Discipline + "\n" + "Код группы: " + to_string(c.group) + "\n" + "Номер зачётной книжки: " 
		+ to_string(c.zachetka) + "\n" + "Оценка по дисциплине: " + to_string(c.markofdiscipline) + "\n";
	return result;
}

////считывание структуры "сессия" из строки
Session ReadFromString(ifstream& input)
{
	Session result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Курс: ";
			result.course = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Фамилия студента: ";
			result.LastName = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Дисциплина: ";
			result.Discipline = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Код группы: ";
			result.group = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Номер зачётной книжки: ";
			result.zachetka = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Оценка по дисциплине: ";
			result.markofdiscipline = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}


// поиск равного элемента по выбранному критерию
// type_search - тип поиска
//1 - по курсу
//2 - по фамилии
//3 - по дисциплине
//4 - по коду группы
//5 - по номеру зачётки
//6 - по оценке
bool SearchElement(Session m, Session n, int type_search)
{
	switch (type_search)
	{
	case 1:
		return (m.course == n.course);
	case 2:
		return (m.group == n.group);
	case 3:
		return (m.Discipline == n.Discipline);
	case 4:
		return (m.zachetka == n.zachetka);
	case 5:
		return (m.markofdiscipline == n.markofdiscipline);
	case 6:
		return (m.LastName == n.LastName);
	default:
		return false;
	}
}

// ввод критерия поиска в зависимости от выбранного типа 
// type_search - тип поиска
//1 - по курсу
//2 - по фамилии
//3 - по дисциплине
//4 - по коду группы
//5 - по номеру зачётки
//6 - по оценке
Session InputChangeTypeSearch(int type_search)
{
	Session result;
	switch (type_search)
	{

	case 1:
		result.course = InputNumber(1, 6, "Введите курс: ");
		return result;
	case 2:
		result.group = InputNumber(0, 99, "Введите код группы: ");
		return result;
	case 3:
		result.Discipline = InputInformation("Введите Дисциплину: ");
		return result;
	case 4:
		result.zachetka = InputNumber(0, 999999, "Введите номер зачётки: ");
		return result;
	case 5:
		result.markofdiscipline = InputNumber(2, 5, "Введите оценку: ");
		return result;
	case 6:
		result.LastName = InputInformation("Введите Фамилию: ");
		return result;
	default:
		return result;
	}
}

// сравнения структур в зависимости от выбранного поля для сортировки
// type_search - тип поиска
//1 - по курсу
//2 - по фамилии
//3 - по дисциплине
//4 - по коду группы
//5 - по номеру зачётки
//6 - по оценке
int Sorte(Session n, Session m, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (n.course > m.course) return 1;
		else if (n.course < m.course) return -1;
		else return 0;
	case 2:
		if (n.group > m.group) return 1;
		else if (n.group < m.group) return -1;
		else return 0;
	case 3:
		if (n.Discipline > m.Discipline) return 1;
		else if (n.Discipline < m.Discipline) return -1;
		else return 0;
	case 4:
		if (n.zachetka > m.zachetka) return 1;
		else if (n.zachetka < m.zachetka) return -1;
		else return 0;
	case 5:
		if (n.markofdiscipline > m.markofdiscipline) return 1;
		else if (n.markofdiscipline < m.markofdiscipline) return -1;
		else return 0;
	case 6:
		if (n.LastName > m.LastName) return 1;
		else if (n.LastName < m.LastName) return -1;
		else return 0;

	default:
		return -2;
	}
}



