// Library System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"cls_Media.h"
#include "cls_Book.h"
#include "clsAddNewBook.h"
#include "cls_DesplayALLBook.h"
using namespace std;
void ShowMainMenu();
void ShowAddNewBookScreen()
{
	clsAddNewBook addNewBook;
	addNewBook.AddNewBook();
}
void ShowAllBooksScreen()
{
	cls_DesplayALLBook desplayALLBook;
	desplayALLBook.DisplayAllBook();
}
enum enMainMenuOptions
{
	addBook = 1,
	displayAllBooks = 2,
	Exit = 3
};
int ReadMainMenuOption()
{
	int option = 0;
	cout << "Enter a number between 1 and 3 : ";
	cin >> option;
	return option;
}
void GoBackToMainMenu()
{
	cout << "\n press any key to go back to main minue ";
	system("pause>0");
	ShowMainMenu();
}
void mainMenuOption(enMainMenuOptions option)
{
		switch (option)
	{
	case addBook:
		ShowAddNewBookScreen();
		GoBackToMainMenu();
		break;
	case displayAllBooks:
        ShowAllBooksScreen();
		GoBackToMainMenu();
		break;
	case Exit:
		cout << "You choose to exit" << endl;
		
		break;
	default:
		cout << "Invalid option" << endl;
		GoBackToMainMenu();
		break;
		}
}
void ShowMainMenu()
{
	

	    system("cls");
		
			cout << "Library System" << endl;
			cout << "[1] Add Book" << endl;
			cout << "[2] desplay All Book" << endl;
			cout << "[3] Exit" << endl;
		
       

	
	mainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}
int main()
{
      ShowMainMenu();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
