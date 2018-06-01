//#9 ������ � ������� ��������������� ������ �������� ��������� ����������: ����, ��� ������, ������� ��������, ����� �������, ����������, 
//������ �� ����������. ����������� ������� ����� �� ����������, �� ������, �� �����. ����� �� ������, �����, ������ �������, �������, �������.
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
	cout << " ------------C��������� ��������--------------  " << endl;
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - �������� " << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ����� �� �����" << endl;
	cout << "5 - ��������� � ���� " << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� �����" << endl;
	cout << "8 - ��������� ������� ����" << endl;
	cout << "9 - ������� ����������� �� �����" << endl;
	cout << "10 - ��������� ������������ � ����" << endl;
	cout << "0 - �����" << endl;
	int n = InputNumber(0, 9, "��� �����: ");
	cout << "\n";
	return n;
}

bool ChangeInputData()
{
	Task<Session> task;
	bool change = true;
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - ���������� ���������� � �������" << endl;
	cout << "2 - ���������� ���������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	int changemenu = InputNumber(0, 2, "��� �����: ");
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
					
					 numb = InputNumber(0, 1, "������� ����������! ���������� ������/������� ������ ������(1/0)? ")
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
				task.Remove(InputNumber(0, task.size(), "������� ����� ���������� ��-�� (0 - ���� ���������� �������): "));
				break;

			case 3:
				task.OutputScreen(task.vect, OutputScreenSession);
				numb = InputNumber(0, task.size(), "������� ����� ����������� ��-�� (0 - ���� ���������� ��������): ");
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
				numb = InputNumber(1, 5, "�������� ��� ������:\n 1 - �� �����\n 2 - �� ���� ������\n 3 - �� ���������� 4 - �� ������ ������� \n 5 - �� ������ \n 6 - �� �������\n��� �����: ");
				subset = task.LinearySearch(search_elem, SearchElement, numb);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenSession);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 7:
				numb = InputNumber(1, 5, "�������� ��� ������:\n 1 - �� �����\n 2 - �� ���� ������\n 3 - �� ���������� 4 - �� ������ ������� \n 5 - �� ������ \n 6 - �� �������\n��� �����: ");
				search_elem = InputChangeTypeSearch(numb);
				subset = task.BinarySearch(numb, search_elem, Sorte, SearchElement);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenSession);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 8:
				numb = InputNumber(1, 3, "�������� �� ���� ��������� ������� ����:\n 1 - �� �����\n 2 - �� ���� ������\n 3 - �� ���������� \n��� �����: ");
				search_elem = InputChangeTypeSearch(numb);
				subset = task.BinarySearch(numb, search_elem, Sorte, SearchElement);
				if (subset.size() != 0)
					task.OutputAverage(subset, OutputAverage);
				else
					cout << "�������� �� �������" << endl;
				break;
			case 9:
				task.OutputScreen(subset, OutputScreenSession);
				break;

			case 10:
				task.OutputFile(subset, ToString);
				break;

			default:
				cout << "����� " << endl; exit(0);
				break;

			}
		}
	}
	else
		cout << "�� ����� ������!!!\n";
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
}
