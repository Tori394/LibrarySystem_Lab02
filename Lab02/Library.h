#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "Member.h"
using namespace std;

class Library
{
public:
	Library();
	~Library();

	void addBook(Book b);
	void removeBook(Book b);
	void borrowBook(Member& a, string isbn);
	void returnBook(Member& a, string isbn);
	void displayBooks();


private:
	vector<Book> m_books;
};