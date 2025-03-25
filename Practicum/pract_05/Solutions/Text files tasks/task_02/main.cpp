#include <iostream>
#include <fstream>

const char FILE_NAME[] = "result.txt";

void input(int& a, int& b, int& c) {
    std::cin >> a >> b >> c;
}

int getSum(int a, int b, int c) {
    return a + b + c;
}

int getMult(int a, int b, int c) {
    return a * b * c;
}

void writeToFile(int sum, int mult, std::ofstream& ofs) {
    if (!ofs.is_open()) {
        std::cout << "File could not open!" << std::endl;
        return;
    }
    ofs << sum << mult;
}

int readFromFileAndGetResult(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File could not open!" << std::endl;
        return -1;
    }
    int sum, mult;
    ifs >> sum >> mult;
    return sum - mult;
}

int main() {
    int a, b, c;
    input(a, b, c);
    std::ofstream ofs(FILE_NAME);
    int sum = getSum(a, b, c);
    int mult = getMult(a, b, c);

    writeToFile(sum, mult, ofs);

    std::ifstream ifs(FILE_NAME);
    std::cout << readFromFileAndGetResult(ifs);

    ofs.close();
    ifs.close();
}
