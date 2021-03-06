// 04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include "book.h"
#include "author.h"
#undef max
using namespace std;

vector<Book> bookList;
vector<Author> authorList;

//Author findAuthor(std::string _code)
//{
//	for (unsigned int i = 0; i < authorList.size(); i++)
//	{
//		if (authorList[i].GetCode() == _code)
//			return authorList[i];
//	}
//}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Book *book;
	Author *author;
	string bookName;
	string authorCode;
	string authorName;
	int bookCount;
	bool flag1 = false;
	bool flag2 = false;
	unsigned int menu = NULL;

	do
	{
		try {
			bookName = "";
			authorCode = "";
			authorName = "";
			bookCount = 0;
			flag1 = false;
			flag2 = false;
			cout << "1) Поступление новой книги\n2) Выдача книги читателю наруки\n3) Возврат книги в библиотеку\n4) Вывод всех книг\n5) Вывод всех авторов\n6) По автору найти все произвдения, числящиеся в библиотеке\n0) Выход\n";
			cin >> menu;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::string err = "Неверное значение\n";
				throw err;
			}
			switch (menu)
			{
			case 1:
				cout << "Введите название книги, имя автора, код автора и кол-во книг\n";
				cin >> bookName >> authorName >> authorCode >> bookCount;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::string err = "Неверное значение\n";
					throw err;
				}
				if (bookList.size() == 0)
				{
					book = new Book(bookName, authorCode, bookCount);
					bookList.push_back(*book);
					delete book;
					author = new Author(authorName, authorCode);
					authorList.push_back(*author);
					delete author;
				}
				else
				{
					for (unsigned int i = 0; i < bookList.size(); i++)
					{
						if (bookName == bookList[i].GetName() && authorCode == bookList[i].GetCode())
						{
							bookList[i].incCount(bookCount);
							flag1 = true;
							flag2 = true;
						}
						if (bookList[i].GetCode() == authorCode)
							flag2 = true;
					}
					if (!flag1)
					{
						book = new Book(bookName, authorCode, bookCount);
						bookList.push_back(*book);
						delete book;
					}
					if (!flag2)
					{
						author = new Author(authorName, authorCode);
						authorList.push_back(*author);
						delete author;
					}
				}
				break;
			case 2:
				if (bookList.size() == 0)
				{
					std::string err = "Книг нет\n";
					throw err;
				}
				cout << "Введите название книги, код автора и кол-во книг для выдачи\n";
				cin >> bookName >> authorCode >> bookCount;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::string err = "Неверное значение\n";
					throw err;
				}
				for (unsigned int i = 0; i < bookList.size(); i++)
				{

					if (bookName == bookList[i].GetName() && authorCode == bookList[i].GetCode())
					{

						if (bookList[i].Count() >= bookCount)
						{
							bookList[i].decCount(bookCount);
							flag1 = true;
						}
						else if (bookList[i].Count() < bookCount)
						{
							std::string err = "В библиотеке меньше книг, чем запрошено\n";
							throw err;
						}
					}
				}
				if (!flag1)
				{
					std::string err = "Такой книги не найдено\n";
					throw err;
				}
				break;
			case 3:
				if (bookList.size() == 0)
				{
					std::string err = "В библиотеке нет зарегистрированных книг\n";
					throw err;
				}
				cout << "Введите название книги, код автора и кол-во книг для возврата\n";
				cin >> bookName >> authorCode >> bookCount;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::string err = "Неверное значение\n";
					throw err;
				}
				for (unsigned int i = 0; i < bookList.size(); i++)
				{
					if (bookName == bookList[i].GetName() && authorCode == bookList[i].GetCode())
					{
						bookList[i].incCount(bookCount);
						flag1 = true;
					}
				}
				if (!flag1)
				{
					std::string err = "Такой книги не зарегистрировано\n";
					throw err;
				}
				break;
			case 4:
				if (bookList.size() == 0)
				{
					std::string err = "В библиотеке нет зарегистрированных книг\n";
					throw err;
				}
				else {
					for (unsigned int i = 0; i < bookList.size(); i++)
					{
						for (unsigned int j = 0; j < authorList.size(); j++)
						{
							if (bookList[i].GetCode() == authorList[j].GetCode())
							{
								authorName = authorList[j].GetName();
								break;
							}
						}
						cout << "Название: " << bookList[i].GetName() << " Автор: " << authorName << " Кол-во: " << bookList[i].Count() << "\n";
					}
				}
				break;
			case 5:
				if (bookList.size() == 0)
				{
					std::string err = "В библиотеке нет зарегистрированных книг\n";
					throw err;
				}
				else {
					for (unsigned int i = 0; i < authorList.size(); i++)
						cout << "Автор: " << authorList[i].GetName() << "\n";
				}
				break;
			case 6:
				cout << "Введите фамилию автора\n";
				cin >> authorName;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::string err = "Неверное значение\n";
					throw err;
				}
				for (unsigned int i = 0; i < authorList.size(); i++)
				{
					if (authorList[i].GetName() == authorName)
					{
						authorCode = authorList[i].GetCode();
						flag1 = true;
					}
				}
				if (!flag1)
				{
					std::string err = "Автор не найден\n";
					throw err;
				}
				else
				{
					if (bookList.size() == 0)
					{
						std::string err = "В библиотеке нет книг\n";
						throw err;
					}
					else
					{
						for (unsigned int i = 0; i < bookList.size(); i++)
						{
							if (bookList[i].GetCode() == authorCode && bookList[i].Count() != 0)
							{
								cout << "Название: " << bookList[i].GetName() << " Кол-во: " << bookList[i].Count() << "\n";
							}
						}
					}
				}
				break;
			case 0:
				break;
			default:
				std::string err = "Неверное значение\n";
				throw err;
				break;
			}
		}
		catch (std::string err)
		{
			cout << err;
		}
	} while (menu != 0);
	cout << "КОНЕЦ";
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
