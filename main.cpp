#include "Book.h"
#include "Library.h"
// #include "Functions.h"

int main()
{
    Book book1("Harry Potter and the Goblet of fire", "J.K Rowling");
    Library library;
    library.loadBooks("database.txt");
    return 0;
}