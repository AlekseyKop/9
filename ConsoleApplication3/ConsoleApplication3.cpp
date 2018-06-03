//#9 Запись в журнале экзаменационной сессии содержит следующую информацию: курс, код группы, Фамилия студента, номер зачётки, дисциплина, 
//оценка по дисциплине. Вычисляются средние баллы по дисциплине, по группе, по курсу. Поиск по группе, курсу, номеру зачётки, фамилии, оценкам.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "HelpUtils.h"
#include "Operation.h"
#include "Session.h"
using namespace std;




int Menu()
{
	cout << " ------------Cправочник деканата--------------  " << endl;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить " << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл " << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "8 - Вычислить средний балл" << endl;
	cout << "9 - Вывести подможество на экран" << endl;
	cout << "10 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

bool ChangeInputData()
{
	Task<Session> task;
	bool change = true;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenSession);
		break;

	case 2:
		change = task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		Session elem;
		vector<Session> subset;
		Session search_elem;
		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				task.Add(InputScreenSession());
				/*if (task.NoMoreTime(task.vect, IsEqual)==false) 
				{
					
					 numb = InputNumber(0, 1, "Найдено совпадение! Переписать запись/удалить старую запись(1/0)? ")
					(if numb !=0)
					{
						task.vect[numbst - 1] = task.vect[task.size()];
						task.Remove(task.size());
					}
					else
					{
						task.Remove(numbst);
					}
						
				}*/
				break;

			case 2:
				task.OutputScreen(task.vect, OutputScreenSession);
				task.Remove(InputNumber(0, task.size(), "Введите номер удаляемого эл-та (0 - если передумали удалять): "));
				break;

			case 3:
				task.OutputScreen(task.vect, OutputScreenSession);
				numb = InputNumber(0, task.size(), "Введите номер изменяеиого эл-та (0 - если передумали изменять): ");
				if (numb != 0)
					task.vect[numb - 1] = elem.ChangeSession(task.vect[numb - 1]);
				break;

			case 4:
				task.OutputScreen(task.vect, OutputScreenSession);
				break;

			case 5:
				task.OutputFile(task.vect, ToString);
				break;

			case 6:
				numb = InputNumber(1, 5, "Выберите тип поиска:\n 1 - по курсу\n 2 - по коду группы\n 3 - по дисциплине 4 - по номеру зачётки \n 5 - по оценке \n 6 - по фамилии\nВаш выбор: ");
				subset = task.LinearySearch(search_elem, SearchElement, numb);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenSession);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 7:
				numb = InputNumber(1, 5, "Выберите тип поиска:\n 1 - по курсу\n 2 - по коду группы\n 3 - по дисциплине 4 - по номеру зачётки \n 5 - по оценке \n 6 - по фамилии\nВаш выбор: ");
				search_elem = InputChangeTypeSearch(numb);
				subset = task.BinarySearch(numb, search_elem, Sorte, SearchElement);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenSession);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 8:
				numb = InputNumber(1, 3, "Выберите по чему вычислять средний балл:\n 1 - по курсу\n 2 - по коду группы\n 3 - по дисциплине \nВаш выбор: ");
				search_elem = InputChangeTypeSearch(numb);
				subset = task.BinarySearch(numb, search_elem, Sorte, SearchElement);
				if (subset.size() != 0)
					task.OutputAverage(subset, OutputAverage);
				else
					cout << "Элементы не найдены" << endl;
				break;
			case 9:
				task.OutputScreen(subset, OutputScreenSession);
				break;

			case 10:
				task.OutputFile(subset, ToString);
				break;

			default:
				cout << "Выход " << endl; exit(0);
				break;

			}
		}
	}
	else
		cout << "До новых встреч!!!\n";
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
}
