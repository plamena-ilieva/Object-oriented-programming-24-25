#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

namespace MatrixConstants {
    const int MAX_SIZE = 100;
    const int MAX_INT_LEN = 20;
}

namespace MatrixUtils {
    unsigned charToDigit(char ch) {
        return ch - '0';
    }
    
    unsigned convertStrToUnsigned(const char* str) {
        unsigned res = 0;
        while (*str) {
            res = ((res * 10) + charToDigit(*str));
            str++;
        }
        return res;
    }
    
    size_t getFileLength(std::ifstream& ifs) {
        size_t currPos = ifs.tellg(), res = 0;
        ifs.seekg(0, std::ios::end);
        res = ifs.tellg();
        ifs.seekg(currPos, std::ios::beg);
        return res;
    }
    
    unsigned getCharCountFromFile(std::ifstream& ifs, char ch) {
        size_t currentPosition = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
    
        if (!ifs.is_open())
            return 0;
    
        unsigned int count = 0;
    
        while (true) {
            char current = ifs.get();
            if (ifs.eof()) {
                break;
            }
            if (current == ch) {
                count++;
            }
        }
    
        ifs.clear();
        ifs.seekg(currentPosition);
        return count;
    }
}

struct Matrix {
	unsigned matrix[MatrixConstants::MAX_SIZE][MatrixConstants::MAX_SIZE];
	unsigned rows;
	unsigned colls;

    void loadMatrix(const char* fileName);
    
    Matrix matrixMultiplication(const Matrix& matrix1, const Matrix& matrix2) const {
        Matrix result;
        result.rows = matrix1.rows;
        result.colls = matrix2.colls;
    
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.colls; j++) {
                result.matrix[i][j] = 0;
    
                for (int k = 0; k < matrix2.rows; k++) {
                    result.matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
                }
            }
        }
    
        return result;
    }
    
    Matrix matrixMultiplicationFromFile(const char* file1, const char* file2) const {
        Matrix matrix1;
        Matrix matrix2;

        matrix1.loadMatrix(file1);
        matrix2.loadMatrix(file2);
    
        Matrix result = matrixMultiplication(matrix1, matrix2);
        return result;
    }
    
    Matrix matrixMultiplicationFromFile(const char* file1, const char* file2, const char* fileToSave) const;
};