// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	//русификация ввода/вывода
	  // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleCP(1251);
	// установка кодовой страницы win-cp 1251 в поток вывода
	SetConsoleOutputCP(1251);

	char fileName[20] = { 0 };
	int fileName_size = sizeof(fileName) / sizeof(char);
	char str[40] = { 0 };
	int str_size = sizeof(str) / sizeof(char);
	int i = 0;
	bool end = false;

	//Описание
	puts("Программа создает файл, записывает в него строки и выводит на экран строки с\n выбранным символом на конце\n");

	//Ввод имени файла
	puts("Введите имя файла");
	fgets(fileName, fileName_size, stdin);
	i = 0;
	while (!end && i < fileName_size)
		if (fileName[i] == '\n')
		{
			fileName[i] = NULL;
			end = true;
		}
		else i++;

	//Создание файла
	FILE* file = fopen(fileName, "wt");
	if (file == NULL) puts("Ошибка");
	else puts("Файл открыт");

	//Запись строк
	puts("Введите строки для записи в файл. Для завершения ввода нажмите enter.");
	while (str[0] != '\n')
	{
		fgets(str, str_size, stdin);
		fputs(str, file);
	}
	fclose(file);

	//Ввод имени файла
	end = false;
	puts("Введите имя файла");
	fgets(fileName, fileName_size, stdin);
	i = 0;
	while (!end && i < fileName_size)
		if (fileName[i] == '\n')
		{
			fileName[i] = NULL;
			end = true;
		}
		else i++;

	//Вывод строк, заканчивающихся на выбранный символ
	puts("Введите символ");
	char letter = getchar();
	char tmp;
	file = fopen(fileName, "rt");
	if (file == NULL) puts("Ошибка");
	else puts("Файл открыт");
	puts("Строки, оканчивающиеся на заданный символ");
	while (tmp = fgets(str, str_size, file) != NULL)
	{
		i = 0;
		end = false;
		while (!end)
		{
			if (str[i] != '\n') i++;
			else 
			{
				if (i != 0 && str[i - 1] == letter)
				{
					puts(str);
				}
				end = true;
			}
		}
	}
	puts("КОНЕЦ");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу раfgets(fileName, fileName_size, stdin);боты 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
