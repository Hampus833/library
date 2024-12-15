#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../libraryClass/Library.h"

void displayMenu();

void addBook(Library &library);

void borrowBook(Library &library);

void borrowBook(Library &library, std::vector<std::string> titles);

void returnBook(Library &library);

void displayBooks(Library library);

bool checkBookExists(Library &library, std::string bookToCheck);

void availableBooks(Library &library, int action);

void exitLibrary(Library &library);

#endif