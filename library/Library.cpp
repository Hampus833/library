#include "Library.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void Library::displayBooks()
{
    for (Book book : library)
    {
        book.displayBook();
    }
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
    for (Book book : library)
    {
        if (!book.isBorrowed() && book.getTitle() == title)
        {
            book.borrowBook(&book);
        }
    }
}

void Library::returnBook(std::string title)
{
    for (Book book : library)
    {
        if (book.isBorrowed() && book.getTitle() == title)
        {
            book.returnBook(&book);
        }
    }
}

void writeBooks(std::string filename)
{
}