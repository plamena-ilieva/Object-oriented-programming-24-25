#include <iostream>
#include <fstream>

namespace BookConstants {
    const int STR_MAX_SIZE = 65;
    const int YEAR_INIT_VAL = 0;
    const double PRICE_INIT_VAL = 0.0;
}

class Book {
    char title[BookConstants::STR_MAX_SIZE] = "";
    char author[BookConstants::STR_MAX_SIZE] = "";
    int year = BookConstants::YEAR_INIT_VAL;
    double price = BookConstants::PRICE_INIT_VAL;

    bool isValidString(const char* str) const;

public:
    Book() = default;
    Book(const char* title, const char* author, int year, double price);
    
    void setTitle(const char* title);
    void setAuthor(const char* author);
    void setYear(int year);
    void setPrice(double price);

    const char* getTitle() const;
    const char* getAuthor() const;
    int getYear() const;
    double getPrice() const;

    void readBook(std::ifstream& ifs);
    void saveBook(std::ofstream& ofs) const;

    void printBook() const;
};