#include "Book.h"
#include <iostream>
#include <string>

Book::Book(std::string t, std::string a)
{
    title = t;
    author = a;
    borrowed = false;
}

Book::~Book()
{
    // std::cout << "Book has been destroyed" << std::endl;
}

void Book::setTitle(std::string t)
{
    title = t;
}

void Book::setAuthor(std::string a)
{
    author = a;
}

std::string Book::getTitle()
{
    return title;
}

std::string Book::getAuthor()
{
    return author;
}

void Book::borrowBook(Book *book)
{
    if (!book->borrowed)
    {
        borrowed = true;
        std::cout << title << " has been borrowed" << std::endl;
    }
    else
    {
        std::cout << title << " is already borrowed" << std::endl;
    }
}

void Book::returnBook(Book *book)
{
    if (book->borrowed)
    {
        borrowed = false;
        std::cout << title << " has been returned" << std::endl;
    }
    else
    {
        std::cout << title << " isn't borrowed" << std::endl;
    }
}

bool Book::isBorrowed()
{
    return borrowed;
}

void Book::displayBook()
{
    std::cout << title << std::endl;
    std::cout << author << std::endl;
    // std::cout << borrowed << std::endl;
}