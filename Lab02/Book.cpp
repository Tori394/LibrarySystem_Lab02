#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string title, string author, string isbn) : m_title(title), m_author(author), m_isbn(isbn)
{
	m_ava = true;
}

Book::~Book()
{ 
	//Nothing
}

void Book::getInfo()
{
	cout << "\nTytul: " << m_title << "|  Autor: " << m_author << "|  ISBN: " << m_isbn << "|  Dostepna?    ";
	if (m_ava == true)
		cout << "tak" << endl;
	else
		cout << "nie" << endl;
}

bool Book::operator==(const Book& other) const 
{
	return (m_title == other.m_title && m_author == other.m_author && m_isbn == other.m_isbn);
}

bool Book::doesAvalable()
{
	return m_ava;
}

string Book::getISBN()
{
	return m_isbn;
}

void Book::setAvalable(bool a)
{
	m_ava = a;
}
