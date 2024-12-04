#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "Book.h"

class Library
{
private:
    std::vector<Book> library{};

public:
    void displayBooks();
    void loadBooks(std::string filename);
    void lendBook(std::string title);
    void returnBook(std::string title);
    void writeBooks(std::string filename);
};

#endif