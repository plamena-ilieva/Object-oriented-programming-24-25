#include "Book/Book.h"

namespace BooksListConstants {
    const int MAX_BOOKS = 100;
    const int MIN_COUNT = 0;
}

class BooksList {
public:

    BooksList() = default;
    BooksList(const Book* books, int currentCount);

    void readBooksFromFile(const char* fileName);
    void addBook(const Book& book);
    void saveBooksToFile(const char* fileName) const;
    void printBooks() const;

private:
    Book books[BooksListConstants::MAX_BOOKS];
    int currentCount = BooksListConstants::MIN_COUNT;
};