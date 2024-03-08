#pragma once
#include <string>
using namespace std;

class Member
{
public:
	Member(string name);
	~Member();
	void borrowBook();
	void returnBook();
	void countBooks();

	bool operator==(const Member& other) const;

private:
	string m_name;
	unsigned int m_booksBorrowed;
};