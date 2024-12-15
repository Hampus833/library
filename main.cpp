#include "./book/Book.h"
#include "./libraryClass/Library.h"
#include "./functions/Functions.h"
#include <iostream>

int main()
{
    std::string filename = "./database/database.txt";

    Library library;
    library.loadBooks(filename);
    Library *libraryptr = &library;

    displayMenu();

    std::vector<std::string> books;
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
                std::cout << "Do you wish to borrow multiple books y/n?" << std::endl;
                char choice;

                std::cin >> choice;

                while (true)
                {
                    if (choice == 'y')
                    {
                        std::string bookTitle;

                        std::cout << "Enter the book you want to borrow" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, bookTitle);
                        books.emplace_back(bookTitle);

                        std::cout << "Do you want to borrow another book? y/n" << std::endl;
                        std::cin >> choice;
                    }
                    else if (choice == 'n')
                    {
                        break;
                    }
                    else if (choice != 'n' || choice != 'y')
                    {
                        std::cout << "Please only enter y or n" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cin >> choice;
                    }
                }

                if (!books.empty())
                {
                    borrowBook(*libraryptr, books);
                    books.clear();
                }
                else
                {
                    std::cin.ignore();
                    borrowBook(*libraryptr);
                }
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