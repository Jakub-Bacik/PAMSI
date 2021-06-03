#ifndef PROJEKT2_MATRIX_HPP
#define PROJEKT2_MATRIX_HPP
#include <vector>
#include <ostream>
#include <iostream>

enum class Sign{X, O};

class Matrix{
    int CharacterInARow;
    int FieldSize;
    std::vector<char> matrix;

    public:
    Matrix(int characterInARow, int fieldSize):CharacterInARow(characterInARow), FieldSize(fieldSize){};
    void FillTheMatrix();
    void ClearTheMatrix();
    std::vector<char> GetMatrix() const;
    int GetSizeOfMatrix() const;
    int GetFieldSize() const;
    char GetCharFromMatrix(int horizontal, int vertical) const;
    void SetXOnPosition(int horizontal, int vertical);
    void SetOOnPosition(int horizontal, int vertical);
    void SetNOnPosition(int horizontal, int vertical);
    int RowCrossed(Sign sign);
    int ColumnCrossed(Sign sign);
    int DiagonalCrossed(Sign sign);
    bool PlaceIsEmpty(int horizontal, int vertical);
    bool MatrixIsFull();

};

std::ostream& operator << (std::ostream& outputStream, const Matrix& matrix);



#endif //PROJEKT2_MATRIX_HPP
