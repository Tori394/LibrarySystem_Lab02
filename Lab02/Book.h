#pragma once
#include <string>
using namespace std;

class Book
{
public:
	Book(string title, string author, string isbn);
	~Book();

	void getInfo();
	bool doesAvalable();
	string getISBN();
	void setAvalable(bool a);

	bool operator==(const Book& other) const;

private:
	string m_title;
	string m_author;
	string m_isbn;
	bool m_ava;


};