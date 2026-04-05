#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "cls_Book.h"
using namespace std;
class cls_DesplayALLBook:public cls_Book
{
private:
	cls_Book _convertLineToRecord(string Line, string Separator = "#//#")
	{
		cls_Book Book;
		vector <string> vBookData;
		vBookData = _split(Line, Separator);
		if (vBookData.size() == 3)
		{
			Book.title = vBookData[0];
			Book.author = vBookData[1];
			Book.pages = stoi(vBookData[2]);
		}
		return Book;
	}

	vector <string> _split(string str, string separator = "#//#")
	{
		vector <string> vBooks;
		int pos = 0;
		string sWord = "";
		while ((pos = str.find(separator)) != string::npos)
		{
			sWord = str.substr(0, pos);
			vBooks.push_back(sWord);
			str.erase(0, pos + separator.length());
		}
		if (str.length() > 0)
		{
			vBooks.push_back(str);
		}
		return vBooks;
	}
	
	vector <cls_Book> _loadBooksFromFile()
	{
		vector <cls_Book> vBooks;
		ifstream File;
		File.open(FileName, ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				cls_Book Book = _convertLineToRecord(Line);
				vBooks.push_back(Book);
			}
			File.close();
		}
		else
		{
			cout << "Error : Can't open file " << endl;
		}
		return vBooks;
	}
public:
	void DisplayAllBook()
	{
		vector <cls_Book> vBooks = _loadBooksFromFile();
		cout << "All Books in Library : ("<<vBooks.size()<<")" << endl;
		cout << "---------------------" << endl;

		for (cls_Book Book : vBooks)
		{
			cout<<"| " <<setw(20)<<left<< Book.title << endl;
			cout<<"| " <<setw(20)<<left<< Book.author << endl;
			cout<<"| " <<setw(20)<<left<< Book.pages << endl;
			cout << "---------------------" << endl;
		}
	}
};

