#include "./book/Book.h"
#include "./libraryClass/Library.h"
#include "./functions/Functions.h"
#include <iostream>

int main()
{
    // Book book1("Harry Potter and the Goblet of fire", "J.K Rowling");
    // Library library;
    // library.loadBooks("./database/database.txt");
    // library.displayBooks();

    displayMenu();

    int userInput;

    while (true)
    {
        if (std::cin >> userInput)
        {
            switch (userInput)
            {
            case 1:
                addBook();
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                std::cout << "exiting" << std::endl;
            default:
                break;
            }
        }
        else
        {
            std::cout << "Please only enter 1 - 5" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            displayMenu();
        }
    }

    return 0;
}