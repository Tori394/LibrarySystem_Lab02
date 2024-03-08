#include <iostream>
#include "Book.h"
#include "Member.h"
#include "Library.h"
using namespace std;

int main()
{
	Library biblioteka;
	int a;
	string tytul, autor, isbn;

	vector <Member> czytelnicy;

	//przykladowe
	biblioteka.addBook(Book("Harry Potter", "J.K. Rowling", "1234"));
	biblioteka.addBook(Book("Lord of the Rings", "J.R.R. Tolkien", "0987"));
	biblioteka.addBook(Book("Mam Kota", "Ala", "5678"));
	czytelnicy.push_back(Member("Maja"));
	czytelnicy.push_back(Member("Ola"));


	do
	{
		cout << "\nCo chcesz zrobic?\n1 - dodaj ksiazke\n2 - usun ksiazke\n3 - wyporzycz ksiazke\n4 - zwroc ksiazke\n5 - wyswietl stan biblioteki\n6 - dodaj czytelnika\n7 - sprwdz ilosc wyporzyczonych ksiazek\n0 - zamknij\n\n";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Podaj tytul: ";
			cin >> tytul;
			cout << "Podaj autora: ";
			cin >> autor;
			cout << "Podaj nr isbn: ";
			cin >> isbn;
			biblioteka.addBook(Book(tytul, autor, isbn));
			break;
		}
		case 2:
		{
			cout << "Podaj tytul: ";
			cin >> tytul;
			cout << "Podaj autora: ";
			cin >> autor;
			cout << "Podaj nr isbn: ";
			cin >> isbn;
			biblioteka.removeBook(Book(tytul, autor, isbn));
			break;
		}
		case 3:
		{
			cout << "Podaj nr isbn: ";
			cin >> isbn;
			cout << "Podaj imie czytelnika: ";
			cin >> autor;
			auto czytelnik = find(czytelnicy.begin(), czytelnicy.end(), autor);
			if (czytelnik == czytelnicy.end())
			{
				cout << "Nie ma zarejestrowanego takiego czytelnika"<<endl;
				break;
			}
			Member& o = *czytelnik;
			biblioteka.borrowBook(o, isbn);
			break;
		}
		case 4:
		{
			cout << "Podaj nr isbn: ";
			cin >> isbn;
			cout << "Podaj imie czytelnika: ";
			cin >> autor;
			auto czytelnik = find(czytelnicy.begin(), czytelnicy.end(), autor);
			if (czytelnik == czytelnicy.end())
			{
				cout << "Nie ma zarejestrowanego takiego czytelnika"<<endl;
				break;
			}
			Member& o = *czytelnik;
			biblioteka.returnBook(o, isbn);
			break;
		}
		case 5:
		{
			biblioteka.displayBooks();
			break;
		}
		case 0:
			return 0;
		case 6:
		{
			cout << "Podaj imie: ";
			cin >> autor;
			czytelnicy.push_back(autor);
			break;
		}
		case 7:
		{
			for (int i = 0; i < czytelnicy.size(); i++)
			{
				czytelnicy[i].countBooks();
			}
		}
		}
	} while (a != 0);
}