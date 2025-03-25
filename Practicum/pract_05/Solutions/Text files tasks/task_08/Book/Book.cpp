#include "Book.h"

bool Book::isValidString(const char* str) const {
    if (!str || strlen(str) > BookConstants::STR_MAX_SIZE) {
        return false;
    }
    return true;
}

Book::Book(const char* title, const char* author, int year, double price) {
    setTitle(title);
    setAuthor(author);
    setYear(year);
    setPrice(price);
}
    
void Book::setTitle(const char* title) {
    if (!isValidString(title)) {
        return;
    }
    strcpy(this->title, title);
}
void Book::setAuthor(const char* author) {
    if (!isValidString(author)) {
        return;
    }
    strcpy(this->author, author);
}
void Book::setYear(int year) {
    this->year = year;
}
void Book::setPrice(double price) {
    if (price < 1 || price > 100) {
        return;
    }
    this->price = price;
}

const char* Book::getTitle() const {
    return title;
}
const char* Book::getAuthor() const {
    return author;
}
int Book::getYear() const {
    return year;
}
double Book::getPrice() const {
    return price;
}

void Book::readBook(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File could not open" << std::endl;
        return;
    }
    ifs.getline(title, BookConstants::STR_MAX_SIZE, ',');
    ifs.ignore();
    ifs.getline(author, BookConstants::STR_MAX_SIZE, ',');
    ifs.ignore();
    ifs >> year;
    ifs.ignore();
    ifs >> price;
}
void Book::saveBook(std::ofstream& ofs) const {
    if (!ofs.is_open()) {
        std::cout << "File could not open" << std::endl;
        return;
    }
    ofs << title << "," << author << ",";
    ofs << year << "," << price << std::endl;
}

void Book::printBook() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << std::endl; 
}