#include "./book/Book.h"
#include "./libraryClass/Library.h"
#include "./functions/Functions.h"
#include <iostream>

int main()
{

    std::string filename = "./database/database.txt";
    // TODO
    // fixa så att man inte kan lägga till en bok som redan finns i biblioteket
    // Fixa function overloading biten
    // Lista ut vad som ska vara med i destructor (tilde) funktionerna i mina klasser
    Library library;
    library.loadBooks(filename);
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
                std::cout << "Thank you for visiting the library, goodbye!" << std::endl;
                library.writeBooks(filename);
                return 0;
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