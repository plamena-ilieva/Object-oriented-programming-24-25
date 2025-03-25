#include "BooksList.h"

BooksList::BooksList(const Book* books, int currentCount) {
    if (currentCount >= 0 &&  currentCount < BooksListConstants::MIN_COUNT) {
        this->currentCount = currentCount;
    }
    else {
        this->currentCount = 0;
    }

    for (int i = 0; i < currentCount; i++) {
        this->books[i] = books[i];
    }
}

void BooksList::readBooksFromFile(const char* fileName) {
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cout << "File could not open" << std::endl;
        return;
    }
    ifs >> currentCount;
    ifs.ignore();
    for (int i = 0; i < currentCount; i++) {
        books[i].readBook(ifs);
    }
    ifs.close();
}
void BooksList::addBook(const Book& book) {
    if (currentCount < BooksListConstants::MIN_COUNT) {
        books[currentCount++] = book;
    }
}
void BooksList::saveBooksToFile(const char* fileName) const {
    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        std::cout << "File could not open" << std::endl;
        return;
    }
    ofs << currentCount << std::endl;
    for (int i = 0; i < currentCount; i++) {
        books[i].saveBook(ofs);
    }
    ofs.close();
}
void BooksList::printBooks() const {
    for (int i = 0; i < currentCount; i++) {
        books[i].printBook();
    }
}