﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

struct Tel
{
	int tfnum;
	int roomnum;
	int k;
	string sl1;
	string sl2;
	string sl3;
	string sl4;
};
int TfnumSearch(Tel* p, char* fname, int tfnum1);
int RoomnumSearch(Tel* p, char* fname, int roomnum1);
int SlSearch(Tel* p, char* fname, string sl);
void Create(char* fname, Tel* p)
{
	ofstream fout(fname);
	char ch;
	int i = 0;
	do
	{
		cin.get();
		cin.sync();
		cout << "Введіть телефонний номер: "; cin >> p[i].tfnum;
		fout << p[i].tfnum << endl;
		cout << "Введіть номер кімнати: "; cin >> p[i].roomnum;
		fout << p[i].roomnum << endl;
		cout << "Введіть кількість службовців: "; cin >> p[i].k;
		fout << p[i].k << endl;
		switch (p[i].k)
		{
		case 1:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : "; getline(cin, p[i].sl1);
			fout << p[i].sl1 << endl;
			break;
		case 2:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : "; getline(cin, p[i].sl1);
			fout << p[i].sl1 << endl;
			cout << " Прізвище службовця 2 : "; getline(cin, p[i].sl2);
			fout << p[i].sl2 << endl;
			break;
		case 3:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : "; getline(cin, p[i].sl1);
			fout << p[i].sl1 << endl;
			cout << " Прізвище службовця 2 : "; getline(cin, p[i].sl2);
			fout << p[i].sl2 << endl;
			cout << " Прізвище службовця 3 : "; getline(cin, p[i].sl3);
			fout << p[i].sl3 << endl;
			break;
		case 4:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : "; getline(cin, p[i].sl1);
			fout << p[i].sl1 << endl;
			cout << " Прізвище службовця 2 : "; getline(cin, p[i].sl2);
			fout << p[i].sl2 << endl;
			cout << " Прізвище службовця 3 : "; getline(cin, p[i].sl3);
			fout << p[i].sl3 << endl;
			cout << " Прізвище службовця 4 : "; getline(cin, p[i].sl4);
			fout << p[i].sl4 << endl;
			break;
		}
		i++;

		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void Print(Tel* p, char* fname);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, tfnum, found, roomnum;
	string prizv;
	Tel* p = new Tel[1000000];

	char fname[100];
	cout << "Введіть ім`я файлу: "; cin >> fname;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - пошук за номером телефону" << endl;
		cout << " [4] - пошук телефону за номером приміщення" << endl;
		cout << " [5] - пошук номеру телефону і номеру кімнати за прізвищем службовця" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(fname, p);
			break;

		case 2:
			Print(p, fname);
			break;
		case 3:
			cout << "Введіть номер телефону:"; cin >> tfnum;
			if ((found = TfnumSearch(p, fname, tfnum)) != -1)
			{
				cout << "Номер кімнати:  " << p[found].roomnum << endl;
				cout << "Прізвища службовців:";
				cout << endl;
				cout << p[found].sl1 << ' ' << p[found].sl2 << ' ' << p[found].sl3 << ' ' << p[found].sl4;
			}
			else
				cout << "Шуканих даних не знайдено" << endl;
			cout << endl;
			break;
		case 4:
			cout << "Введіть номер кімнати: "; cin >> roomnum;
			if ((found = RoomnumSearch(p, fname, roomnum)) != -1)
			{
				cout << "Номер телефону:  " << p[found].tfnum << endl;
			}
			else
				cout << "Шуканих даних не знайдено" << endl;
			break;
		case 5:
			cout << " Прізвище: ";
			cin.get();
			cin.sync();
			getline(cin, prizv);
			cout << endl;

			if ((found = SlSearch(p, fname, prizv)) != -1)
			{
				cout << "Номер телефону:  " << p[found].tfnum << endl;
				cout << "Номер кімнати:  " << p[found].roomnum << endl;
			}
			else
				cout << "Шуканого службовця не знайдено" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void Print(Tel* p, char* fname)
{
	int i = 0;
	ifstream fin(fname);
	while (!fin.eof())
	{
		fin >> p[i].tfnum >> p[i].roomnum >> p[i].k;
		switch (p[i].k)
		{
		case 1:

			fin >> p[i].sl1;
			break;
		case 2:

			fin >> p[i].sl1;
			fin >> p[i].sl2;
			break;
		case 3:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			break;
		case 4:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			fin >> p[i].sl4;
			break;
		}
		i++;

	}

	cout << "========================================================================================"
		<< endl;
	cout << "| Номер телефону | Номер кімнати | Кількість службовців |     Прізвища службовців      | "
		<< endl;
	cout << "-----------------------------------------------------------------------------------------"
		<< endl;
	for (int j = 0; j < i - 1; j++)
	{
		cout << "|" << "      " << p[j].tfnum << "        ";
		cout << "|  " << "      " << p[j].roomnum << "      | " << "        " << p[j].k << "            "
			<< "| " << p[j].sl1 << ' ' << p[j].sl2 << ' ' << p[j].sl3 << ' ' << p[j].sl4 << " | ";
		cout << endl;
	}
	cout << "========================================================================================" << endl;
}
int TfnumSearch(Tel* p, char* fname, int tfnum1)
{
	int i = 0;
	ifstream fin(fname);
	while (!fin.eof())
	{
		fin >> p[i].tfnum >> p[i].roomnum >> p[i].k;
		switch (p[i].k)
		{
		case 1:

			fin >> p[i].sl1;
			break;
		case 2:

			fin >> p[i].sl1;
			fin >> p[i].sl2;
			break;
		case 3:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			break;
		case 4:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			fin >> p[i].sl4;
			break;
		}
		i++;

	}

	for (int j = 0; j < i - 1; j++)
	{
		if (p[j].tfnum == tfnum1)
			return j;
	}
	return -1;
}
int RoomnumSearch(Tel* p, char* fname, int roomnum1)
{
	int i = 0;
	ifstream fin(fname);
	while (!fin.eof())
	{
		fin >> p[i].tfnum >> p[i].roomnum >> p[i].k;
		switch (p[i].k)
		{
		case 1:

			fin >> p[i].sl1;
			break;
		case 2:

			fin >> p[i].sl1;
			fin >> p[i].sl2;
			break;
		case 3:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			break;
		case 4:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			fin >> p[i].sl4;
			break;
		}
		i++;

	}
	for (int j = 0; j < i - 1; j++)
	{
		if (p[j].roomnum == roomnum1)
			return j;
	}
	return -1;
}
int SlSearch(Tel* p, char* fname, string sl)
{
	int i = 0;
	ifstream fin(fname);
	while (!fin.eof())
	{
		fin >> p[i].tfnum >> p[i].roomnum >> p[i].k;
		switch (p[i].k)
		{
		case 1:

			fin >> p[i].sl1;
			break;
		case 2:

			fin >> p[i].sl1;
			fin >> p[i].sl2;
			break;
		case 3:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			break;
		case 4:
			fin >> p[i].sl1;
			fin >> p[i].sl2;
			fin >> p[i].sl3;
			fin >> p[i].sl4;
			break;
		}
		i++;
	}
	for (int j = 0; j < i - 1; j++)
	{
		if (p[j].sl1 == sl || p[j].sl2 == sl || p[j].sl3 == sl || p[j].sl4 == sl)
			return j;
	}
	return -1;
}