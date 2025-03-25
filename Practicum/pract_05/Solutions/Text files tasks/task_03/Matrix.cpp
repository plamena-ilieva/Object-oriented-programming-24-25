#include "Matrix.h"

void Matrix::loadMatrix(const char* fileName) {
    std::ifstream file(fileName);
        if (!file.is_open()) {
            return;
        }
    
        rows = MatrixUtils::getCharCountFromFile(file, '|') + 1;
        colls = MatrixUtils::getCharCountFromFile(file, ',') / rows + 1;
    
        file.seekg(0, std::ios::beg);
        char buff[MatrixConstants::MAX_INT_LEN];
    
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < colls - 1; j++) {
                file.getline(buff, MatrixConstants::MAX_INT_LEN, ',');
                matrix[i][j] = MatrixUtils::convertStrToUnsigned(buff);
            }
            file.getline(buff, MatrixConstants::MAX_INT_LEN, '|');
            matrix[i][colls - 1] = MatrixUtils::convertStrToUnsigned(buff);
        }
    
        for (int j = 0; j < colls - 1; j++) {
            file.getline(buff, MatrixConstants::MAX_INT_LEN, ',');
            matrix[rows - 1][j] = MatrixUtils::convertStrToUnsigned(buff);
        }
        file.getline(buff, MatrixConstants::MAX_INT_LEN);
        matrix[rows - 1][colls - 1] = MatrixUtils::convertStrToUnsigned(buff);
    
        file.close();
}

Matrix Matrix::matrixMultiplication(const Matrix& matrix1, const Matrix& matrix2) const {
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

Matrix Matrix::matrixMultiplicationFromFile(const char* file1, const char* file2) const {
    Matrix matrix1;
    Matrix matrix2;

    matrix1.loadMatrix(file1);
    matrix2.loadMatrix(file2);
    
    Matrix result = matrixMultiplication(matrix1, matrix2);
    return result;
}

Matrix Matrix::matrixMultiplicationFromFile(const char* file1, const char* file2, const char* fileToSave) const {
    Matrix res = matrixMultiplicationFromFile(file1, file2);

    std::ofstream saveFile(fileToSave, std::ios::trunc);
    if (!saveFile.is_open()) {
        return res;
    }
    for (int i = 0; i < res.rows-1; i++) {
        for (int j = 0; j < res.colls-1; j++) {
            
            saveFile << std::to_string(res.matrix[i][j])<<',';
        }
        saveFile << std::to_string(res.matrix[i][res.colls-1]) << '|';
    }
    for (int j = 0; j < res.colls - 1; j++) {
        saveFile << std::to_string(res.matrix[res.rows - 1][j]) << ',';
    }

    saveFile << std::to_string(res.matrix[res.rows - 1][res.colls - 1]) << std::endl;

    saveFile.close();
    return res;
}