#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
	string nameBook;
	string nameAuthor;
	int numberBook;

public:
	Book() {}
	Book(string nameBook, string nameAuthor, int numberBook) : nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}
	void getInformation()
	{
		system("cls");
		cout << "_____________Nhap du lieu sach_____________" << endl;
		int n;
		cin.ignore();
		cout << "nhap ten sach: ";
		getline(cin, this->nameBook);
		cout << "nhap ten tac gia: ";
		getline(cin, this->nameAuthor);
		do
		{
			cout << "nhap so luong: ";
			cin >> n;
		} while (n <= 0);
		this->numberBook = n;
	}
	string getNameBook()
	{
		return nameBook;
	}
	string getNameAuthor()
	{
		return nameAuthor;
	}
	int getNumberBook()
	{
		return numberBook;
	}
	void display()
	{
		cout << "_____________SACH_____________" << endl;
		cout << "Name Book: " << this->nameBook << endl;
		cout << "Name Author: " << this->nameAuthor << endl;
		cout << "Number Book: " << this->numberBook << endl;
	}
};
