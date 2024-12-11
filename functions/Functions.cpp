#include "Functions.h"
#include "../book/Book.h"
#include "../libraryClass/Library.h"

#include <iostream>
#include <string>

void displayMenu()
{
    std::cout << "Main menu:" << std::endl;
    std::cout << "1: Add new book" << std::endl;
    std::cout << "2: Lend a book" << std::endl;
    std::cout << "3: Return a book" << std::endl;
    std::cout << "4: View all available books" << std::endl;
    std::cout << "5: Exit" << std::endl;
}

void addBook()
{
    std::string title;
    std::string author;

    std::cout << "Please enter the book's title" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Please enter the book's author" << std::endl;
    std::getline(std::cin, author);

    Book newBook(title, author);

    Library library;
    library.addToLibrary(newBook);
    library.displayBooks();

    displayMenu();
}