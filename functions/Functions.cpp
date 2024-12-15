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

void addBook(Library &library)
{
    std::string title;
    std::string author;

    std::cout << "Please enter the book's title" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Please enter the book's author" << std::endl;
    std::getline(std::cin, author);

    Book newBook(title, author);

    library.addToLibrary(newBook);
    // library.displayBooks();

    displayMenu();
}

void borrowBook(Library &library)
{
    std::string bookToBorrow;
    std::cout << "Please enter the book you want to borrow" << std::endl;

    std::cin.ignore();
    std::getline(std::cin, bookToBorrow);

    bool bookExists = checkBookExists(library, bookToBorrow);
    if (bookExists)
    {
        library.lendBook(bookToBorrow);
        displayMenu();
    }
    else
    {
        std::cout << "Book not found" << std::endl;
        displayMenu();
    }
}

bool checkBookExists(Library &library, std::string bookToCheck)
{
    std::vector<Book> libraryToCheck = library.getLibrary();

    bool bookExists = false;
    for (Book book : libraryToCheck)
    {
        if (book.getTitle() == bookToCheck)
        {
            bookExists = true;
        }
    }
    return bookExists;
}

void returnBook(Library &library)
{
    std::string bookToReturn;
    std::cout << "Please enter the book you wish to return" << std::endl;

    std::cin.ignore();
    std::getline(std::cin, bookToReturn);

    bool bookExists = checkBookExists(library, bookToReturn);
    if (bookExists)
    {
        library.returnBook(bookToReturn);
        displayMenu();
    }
    else
    {
        std::cout << "Book not found" << std::endl;
        displayMenu();
    }
}

void displayBooks(Library library)
{
    library.displayBooks();
    displayMenu();
}