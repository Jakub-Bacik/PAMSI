#include "../inc/Matrix.hpp"
void Matrix::FillTheMatrix(){
    for (int i = 0; i < FieldSize*FieldSize; i++) {
        matrix.push_back(' ');
    }
}

void  Matrix::ClearTheMatrix(){
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i] = ' ';
    }
}

std::vector<char> Matrix::GetMatrix()const {
    return matrix;
}

int Matrix::GetSizeOfMatrix()const {
    return matrix.size();
}

int Matrix::GetFieldSize() const {
    return FieldSize;
}

char Matrix::GetCharFromMatrix(int horizontal, int vertical)const{
    return matrix[horizontal + (vertical * FieldSize)];
}

void Matrix::SetXOnPosition(int horizontal, int vertical){
    matrix[horizontal + (vertical * FieldSize)] = 'X';
}

void Matrix::SetOOnPosition(int horizontal, int vertical){
    matrix[horizontal + (vertical * FieldSize)] = 'O';
}

void Matrix::SetNOnPosition(int horizontal, int vertical){
    matrix[horizontal + (vertical * FieldSize)] = ' ';
}

std::ostream& operator << (std::ostream& outputStream, const Matrix& matrix){
    outputStream <<std::endl;

    for (int i = 0; i < matrix.GetSizeOfMatrix(); i++) {
        outputStream << "  "<< matrix.GetMatrix()[i];

        if((i+1)%matrix.GetFieldSize() != 0){
            outputStream << "  |";
        }

        if((i+1) % matrix.GetFieldSize() == 0 && (i+matrix.GetFieldSize()) <= matrix.GetSizeOfMatrix()){
            outputStream << std::endl;

            for (int j = 0; j < matrix.GetFieldSize(); ++j) {
                outputStream << "------";
            }

            outputStream << std::endl;
        }
    }

    outputStream << std::endl;
}

int Matrix::RowCrossed(Sign sign) {
    char stringToFind;
    if(sign == Sign::X)
        stringToFind = 'X';
    if(sign == Sign::O)
        stringToFind = 'O';

    int numberInRow = 0;

    for (int i = 0; i < FieldSize*FieldSize && numberInRow < CharacterInARow; i++) {
        if(i%FieldSize == 0){
            numberInRow=0;
        }
        if(matrix[i] == stringToFind){
            numberInRow++;
        }else{
            numberInRow = 0;
        }
    }

    if(numberInRow == CharacterInARow)
        return 10;
    else
        return 0;
}

int Matrix::ColumnCrossed(Sign sign){
    char stringToFind;
    if(sign == Sign::X)
        stringToFind = 'X';
    if(sign == Sign::O)
        stringToFind = 'O';

    int numberInColumn = 0;

    for (int i = 0; i < FieldSize && numberInColumn <CharacterInARow; i++) {
        numberInColumn = 0;
        for(int j = 0; j < FieldSize && numberInColumn <CharacterInARow; j++)
        if(matrix[i+(j*FieldSize)] == stringToFind){
            numberInColumn++;
        }else{
            numberInColumn = 0;
        }
    }

    if(numberInColumn == CharacterInARow)
        return 10;
    else
        return 0;
}

int Matrix::DiagonalCrossed(Sign sign){
    char stringToFind;
    if(sign == Sign::X)
        stringToFind = 'X';
    if(sign == Sign::O)
        stringToFind = 'O';

    int diagonalCrossedDecreasing = 0;
    int temporary3 = FieldSize;
    for(int i=0; i < FieldSize && diagonalCrossedDecreasing <CharacterInARow; i++){
        diagonalCrossedDecreasing = 0;
        for(int j=0; j<=temporary3-1 ;j++){
            int tmp =i+(j*(FieldSize+1));
            if(matrix[tmp] == stringToFind){
                diagonalCrossedDecreasing++;
            }else{
                diagonalCrossedDecreasing = 0;
            }
        }
        temporary3--;
    }

    int diagonalCrossedDecreasing1 = 0;
    int temporary4=FieldSize-1;
    for(int i=FieldSize; i < FieldSize*FieldSize && diagonalCrossedDecreasing <CharacterInARow; i=i+FieldSize){
        diagonalCrossedDecreasing = 0;
        for(int j=0; j<=temporary4-1 ;j++){
            int tmp =i+(j*(FieldSize+1));
            if(matrix[tmp] == stringToFind){
                diagonalCrossedDecreasing++;
            }else{
                diagonalCrossedDecreasing = 0;
            }
        }
        temporary4--;
    }

    int diagonalCrossedGrowing = 0;
    int temporary = 0;
    for(int i=0; i < FieldSize && diagonalCrossedGrowing <CharacterInARow; i++){
        diagonalCrossedGrowing = 0;
        for(int j=0; j<=temporary ;j++){
            int tmp = i+(j*(FieldSize-1));
            if(matrix[tmp] == stringToFind){
                diagonalCrossedGrowing++;
            }else{
                diagonalCrossedGrowing = 0;
            }

        }
            temporary++;
    }

    int diagonalCrossedGrowing1 = 0;
    int temporary1 = FieldSize-1;
    for(int i=((2*FieldSize)-1); i < FieldSize*FieldSize && diagonalCrossedGrowing1 <CharacterInARow; i=i+FieldSize){
        diagonalCrossedGrowing1 = 0;
        for(int j=0; j<=temporary1-1 ;j++){
            int tmp = i+(j*(FieldSize-1));
            if(matrix[tmp] == stringToFind){
                diagonalCrossedGrowing1++;
            }else{
                diagonalCrossedGrowing1 = 0;
            }

        }
        temporary1--;
    }

    if(diagonalCrossedDecreasing == CharacterInARow || diagonalCrossedGrowing == CharacterInARow || diagonalCrossedDecreasing1 == CharacterInARow || diagonalCrossedGrowing1 == CharacterInARow)
        return 10;
    else
        return 0;
}

bool Matrix::PlaceIsEmpty(int horizontal, int vertical){
    return GetCharFromMatrix(horizontal,vertical) != 'X' && GetCharFromMatrix(horizontal,vertical) != 'O';
}

bool Matrix::MatrixIsFull(){
    char cross = 'X';
    char circle = 'O';
    int numberToReturn = 0;

    for(int i=0; i < FieldSize*FieldSize; i++){
        if(matrix[i] == cross || matrix[i] == circle){
            numberToReturn++;
        }
    }

    return numberToReturn == FieldSize*FieldSize;
}