#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    bool borrowed;

public:
    Book(std::string t, std::string a);

    ~Book();

    void setTitle(std::string t);

    void setAuthor(std::string a);

    std::string getTitle();

    std::string getAuthor();

    void borrowBook(Book *book);

    void returnBook(Book *book);

    bool isBorrowed();

    void displayBook();
};

#endif