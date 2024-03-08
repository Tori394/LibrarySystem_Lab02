#include "Member.h"
#include "Book.h"
#include <iostream>
using namespace std;

Member::Member(string name)
{
	m_name = name;
	m_booksBorrowed = 0;
}

Member::~Member()
{
	//Nothing
}

void Member::borrowBook()
{
	m_booksBorrowed += 1;
}

void Member::returnBook()
{
	m_booksBorrowed -= 1;
}

void Member::countBooks()
{
	cout << m_name << " " << m_booksBorrowed<<endl;
}

bool Member::operator==(const Member& other) const
{
	return (m_name == other.m_name);
}