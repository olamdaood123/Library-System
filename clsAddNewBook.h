#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "cls_Book.h"
using namespace std;

class clsAddNewBook :public cls_Book
{
	public:
		void ReadBookInfo()
		{
			system("cls");
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter Book Title : ";
			getline(cin, title);
			cout << "Enter Book Author : ";
			getline(cin, author) ;
			cout << "Enter Book Pages : ";
			cin >> pages;
	    }
		string ConvertBookInfoToLine(string Separator="#//#")
		{
			string Line = "";
			Line += title + Separator;
			Line += author + Separator;
			Line += to_string(pages);
			return Line;
		}
		void SaveBookToFile()
		{
			ofstream File;
			File.open(FileName, ios::app);
			if (File.is_open())
			{
				File << ConvertBookInfoToLine() << endl;
				File.close();
				cout << "Book Added Successfully " << endl;
			}
			else
			{
				cout << "Error : Can't open file " << endl;
			}
		}
	     void AddNewBook()
	    {
			 ReadBookInfo();
			 ConvertBookInfoToLine();
			 SaveBookToFile();

	    }
};

