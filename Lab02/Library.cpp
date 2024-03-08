#include "Library.h"
#include "Member.h"
#include "Book.h"
#include <iostream>
#include <vector>
using namespace std;

Library::Library()
{
	//-
}

Library::~Library()
{
	//Nothing
}

void Library::addBook(Book b)
{
	m_books.push_back(b);
}

void Library::removeBook(Book b)
{
	auto a = find(m_books.begin(), m_books.end(), b);
	if (a != m_books.end())
		m_books.erase(a);
	else
		cout << "Nie ma takiej ksiazki";
}

void Library::borrowBook(Member& a, string isbn)
{
	for (int i = 0; i < m_books.size(); i++)
	{
		if (m_books[i].getISBN() == isbn)
		{
			if (m_books[i].doesAvalable() == true)
			{
				a.borrowBook();
				m_books[i].setAvalable(false);
				return;
			}
			else
			{
				cout << "Ksiazka jest niedostpena" << endl;
				return;
			}
		}
	}
	cout << "Nie ma takiej ksiazki" << endl;
}

void Library::returnBook(Member& a, string isbn)
{
	for (int i = 0; i < m_books.size(); i++)
	{
		if (m_books[i].getISBN() == isbn)
		{
			if (m_books[i].doesAvalable() == false)
			{
				a.returnBook();
				m_books[i].setAvalable(true);
				return;
			}
			else
			{
				cout << "Ksiazka nie byla wypozyczana" << endl;
				return;
			}
		}
	}
	cout << "Nie ma takiej ksiazki" << endl;
}

void Library::displayBooks()
{
	cout << "Biblioteka:" << endl;
	for (int i = 0; i < m_books.size(); i++)
	{
		m_books[i].getInfo();
	}
}