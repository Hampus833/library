#include "./book/Book.h"
#include "./libraryClass/Library.h"
#include "./functions/Functions.h"
#include <iostream>

int main()
{
    // TODO stringtolower när man lånar och lämnar tillbaka böcker så man inte måste skriva exakt rätt med stora och små bokstäver.
    // fixa så att exit funktionen faktiskt exitar appen.
    // Fixa så att alla böcker man lägger till skrivs in i databasen
    // Fixa function overloading biten
    Library library;
    library.loadBooks("./database/database.txt");
    Library *libraryptr = &library;

    displayMenu();

    int userInput;

    while (true)
    {
        if (std::cin >> userInput)
        {
            switch (userInput)
            {
            case 1:
                addBook(*libraryptr);
                break;
            case 2:
                borrowBook(*libraryptr);
                break;
            case 3:
                returnBook(*libraryptr);
                break;
            case 4:
                displayBooks(library);
                break;
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