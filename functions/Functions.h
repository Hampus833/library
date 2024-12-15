#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../libraryClass/Library.h"

void displayMenu();

void addBook(Library &library);

void borrowBook(Library &library);

void returnBook(Library &library);

void displayBooks(Library library);

bool checkBookExists(Library &library, std::string bookToCheck);

#endif