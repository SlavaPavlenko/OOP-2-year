// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>



int main()
{
	//русификация ввода/вывода
	  // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleCP(1251);
	// установка кодовой страницы win-cp 1251 в поток вывода
	SetConsoleOutputCP(1251);

	bool error;
	int i = 0;
	int letter;
	char str1[41];
	char str2[41];
	char str3[80] = { NULL };
	char str1_copy[41];
	char str2_copy[41];
	int str1_size = sizeof(str1) / sizeof(char);
	int str2_size = sizeof(str2) / sizeof(char);
	int str1_len;
	int str2_len;
	int word_amount_1 = 0;
	int word_amount_2 = 0;

	//Описание
	std::cout << "Программа составляет новую строку из нечетных слов первой строки и четных слов второй строки\n\n";

	//Ввод первой строки
	do {
		i = 0;
		memset(str1, 0, sizeof(str1));
		std::cout << "Введите первую строку\n";
		while (((letter = getchar()) != '\n') && (i < str1_size))
		{
			str1[i] = letter;
			i++;
		}
		if ((int)strlen(str1) <= str1_size && str1[0] != NULL)
		{
			str1_len = strlen(str1);
			error = false;
		}
		else error = true;
	} while (error);

	//Подсчет количества слов в первой строке
	for (i = 0; i < str1_len-1; i++)
	{
		if (str1[i] == ' ' && str1[i+1] != ' ') word_amount_1++;
	}
	if (str1[0] != ' ') word_amount_1++;

	//Ввод второй строки
	do {
		i = 0;
		memset(str2, 0, sizeof(str2));
		std::cout << "Введите вторую строку\n";
		while (((letter = getchar()) != '\n') && (i < str2_size))
		{
			str2[i] = letter;
			i++;
		}
		if ((int)strlen(str2) <= str2_size && str2[0] != NULL)
		{
			str2_len = strlen(str2);
			error = false;
		}
		else error = true;
	} while (error);

	//Подсчет количества слов во второй строке
	for (i = 0; i < str2_len - 1; i++)
	{
		if (str2[i] == ' ' && str2[i + 1] != ' ') word_amount_2++;
	}
	if (str2[0] != ' ') word_amount_2++;

	//Вывод первой строки
	i = 0;
	std::cout << "\nПервая строка: ";
	while (i < str1_len)
	{
		std::cout << str1[i];
		i++;
	}

	//Вывод второй строки
	i = 0;
	std::cout << "\nВторая строка: ";
	while (i < str2_len)
	{
		std::cout << str2[i];
		i++;
	}

	std::cout << "\n";
	//Формирование третьей строки
	strcpy(str1_copy, str1);
	strcpy(str2_copy, str2);
	char * word1 = strtok(str1_copy, " ");
	char * word2 = strtok(str2_copy, " ");
	word2 += strlen(word2) + 1;
	word2 = strtok(NULL, " ");
	while (word1 != NULL && word2 != NULL)
	{
		strcat(str3, word1);
		word1 += strlen(word1) + 1;
		word1 = strtok(word1, " ");
		word1 = strtok(NULL, " ");

		strcat(str3, word2);
		word2 += strlen(word2) + 1;
		word2 = strtok(word2, " ");
		word2 = strtok(NULL, " ");
		if (word_amount_1 > word_amount_2 && word2 == NULL)
		{
			strcpy(str2_copy, str2);
			word2 = strtok(str2_copy, " ");
			word2 += strlen(word2);
			word2 = strtok(NULL, " ");
		}
		else if (word_amount_1 < word_amount_2 && word1 == NULL)
		{
			strcpy(str1_copy, str1);
			word1 = strtok(str1_copy, " ");
		}
		else if (word_amount_1 == word_amount_2 && word2 == NULL) strcat(str3, word1);
	}
	std::cout << "Результат преобразования: " << str3;
	std::cout << "\nКОНЕЦ";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
