#include "Library.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

std::vector<Book> Library::getLibrary()
{
    return library;
}

void Library::displayBooks()
{
    for (Book &book : library)
    {
        book.displayBook();
    }
}

Library::~Library()
{
}

void Library::loadBooks(std::string filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "File doesn't exist";
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string title, author;

        std::getline(ss, title, ',');
        std::getline(ss, author, ',');

        library.emplace_back(title, author);
    }
}

void Library::lendBook(std::string title)
{
    for (Book &book : library)
    {
        if (!book.isBorrowed() && book.getTitle() == title)
        {
            book.borrowBook(&book);
        }
        else if (book.isBorrowed() && book.getTitle() == title)
        {
            std::cout << title << " is already borrowed" << std::endl;
        }
    }
}

void Library::returnBook(std::string title)
{
    for (Book &book : library)
    {
        if (book.isBorrowed() && book.getTitle() == title)
        {
            book.returnBook(&book);
        }
        else if (!book.isBorrowed() && book.getTitle() == title)
        {
            std::cout << "You can't return a book that you haven't borrowed" << std::endl;
        }
    }
}

void Library::writeBooks(std::string filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "File doesn't exist" << std::endl;
        return;
    }

    for (Book &book : library)
    {
        file << book.getTitle() << "," << book.getAuthor() << ",\n";
    }
}

void Library::addToLibrary(Book newBook)
{
    library.emplace_back(newBook);
}