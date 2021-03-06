// 03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

#define bool int

int main()
{
	//русификация ввода/вывода
	  // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleCP(1251);
	// установка кодовой страницы win-cp 1251 в поток вывода
	SetConsoleOutputCP(1251);

	struct link {
		unsigned long name_idx; //индекс записи в файле FIO.DAT;
		unsigned long sport_idx; //индекс записи в файле SPORT.DAT
	};

	//Описание
	puts("Программа позволяет редактировать базу данных и выполнять по ней поиск");

	char str1[40] = { NULL };
	char str2[40] = { NULL };
	int str1_len = sizeof(str1) / sizeof(char);
	int str2_len = sizeof(str2) / sizeof(char);
	bool flag = false;
	bool END = false;
	unsigned int menu = NULL;
	link links;
	FILE* file1;
	FILE* file2;
	FILE* file3;
	do 
	{
		puts("Выберите действие:\n1 - добавить спортсмена и его дисциплину\n2 - добавить новый вид спорта\n3 - найти вид спорта спортсмена\n0 - выход");
		scanf_s("%u", &menu);
		switch (menu) {
		case 1:
			flag = false;
			END = false;
			file1 = fopen("LINK.IDX", "ab");
			file2 = fopen("FIO.DAT", "a+b");
			puts("Введите фамилию спортсмена");
			memset(str1, NULL, str1_len * sizeof(char));
			scanf("%s", str1);
			while (!END && !flag) 
			{
				links.name_idx = ftell(file2);
				memset(str2, NULL, str2_len * sizeof(char));
				if (fgets(str2, 40, file2) == NULL)
					END = true;
				else 
					if (strstr(str2, str1) != NULL)
						flag = true;
			}
			if (!flag)
			{
				//fseek(file2, 0, SEEK_END);	//можно убрать
				fprintf(file2, "%s\r\n", str1);
				//fwrite(str1, (i + 1) * sizeof(char), 1, file2);
			}
			fclose(file2);

			flag = false;
			END = false;
			file2 = fopen("SPORT.DAT", "rb");
			puts("Введите название спорта");
			memset(str1, NULL, str1_len * sizeof(char));
			scanf("%s", str1);
			while (!END && !flag) {
				memset(str2, NULL, str2_len * sizeof(char));
				links.sport_idx = ftell(file2);
				if (fgets(str2, 40, file2) == NULL)
					END = true;
				else if (strstr(str2, str1) != NULL)
					flag = true;
			}
			if (!flag)
				puts("Такого вида спорта не сущестует");
			else
			{
				fprintf(file1, "%u", links.name_idx);
				fprintf(file1, " ");
				fprintf(file1, "%u", links.sport_idx);
				fprintf(file1, "\r\n");
			}
			fclose(file1);
			fclose(file2);
			break;
		case 2:
			flag = false;
			END = false;
			file1 = fopen("SPORT.DAT", "r+b");
			if (file1 == NULL)
				puts("Ошибка чтения файла");
			else {
				puts("Введите название спорта");
				memset(str1, NULL, str1_len * sizeof(char));
				scanf("%s", str1);
				while (!END && !flag) {
					memset(str2, NULL, str2_len * sizeof(char));
					if (fgets(str2, 40, file1) == NULL)
						END = true;
					else {
						if (strstr(str2, str1) != NULL)
						{
							flag = true;
							puts("Такой вид спорта уже есть");
						}
					}
				}
				if (!flag) {
					fseek(file1, 0, SEEK_END);
					fprintf(file1, "%s\r\n", str1);
					//fwrite(str1, (i + 1) * sizeof(char), 1, file1);
				}
				fclose(file1);
			}
			break;
		case 3:
			flag = false;
			END = false;
			file1 = fopen("LINK.IDX", "rb");
			file2 = fopen("FIO.DAT", "rb");
			file3 = fopen("SPORT.DAT", "rb");
			memset(str1, NULL, str1_len * sizeof(char));
			puts("Введите фамилию");
			memset(str1, NULL, str1_len * sizeof(char));
			scanf("%s", str1);
			puts("Результат:");
			while (!END)
			{
				memset(str2, NULL, str2_len * sizeof(char));
				if (fgets(str2, 40, file1) == NULL)
					END = true;
				else {
					//запоминаем индекс фамилии и спорта
					links.name_idx = atoi(str2);
					int j = 0;
					while (isdigit(str2[j]))
					{
						str2[j] = ' ';
						j++;
					}
					links.sport_idx = atoi(str2);
					
					fseek(file2, links.name_idx, SEEK_SET);
					memset(str2, NULL, str2_len * sizeof(char));
					fgets(str2, 40, file2);
					if (strstr(str2, str1) != NULL)
					{
						flag = true;
						memset(str2, NULL, str2_len * sizeof(char));
						fseek(file3, links.sport_idx, SEEK_SET);
						fgets(str2, 40, file3);
						puts(str2);
					}
				}
			}
			if (!flag)
				puts("Такого спортсмена не найдено");
			fclose(file1);
			fclose(file2);
			fclose(file3);
			break;
		case 0:
			break;
		default: puts("Неверное значение");
		}
	} while (menu != 0);
    puts("КОНЕЦ"); 
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
