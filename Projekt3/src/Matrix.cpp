#include "../inc/Matrix.hpp"
//Metoda odpowiedzialna za tworzenie pustej macierzy
void Matrix::FillTheMatrix(){
    for (int i = 0; i < FieldSize*FieldSize; i++) {
        matrix.push_back(' ');
    }
}

//Metoda odpowiedzialna za czyszczenie macierzy
void  Matrix::ClearTheMatrix(){
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i] = ' ';
    }
}

//Metoda odpowiedzialna za pobieranie całej macierzy
std::vector<char> Matrix::GetMatrix()const {
    return matrix;
}

//Metoda odpowiedzialna za długość wektora
int Matrix::GetSizeOfMatrix()const {
    return matrix.size();
}

//Metoda odpowiedzialna za rozmiar macierzy
int Matrix::GetFieldSize() const {
    return FieldSize;
}

//Metoda pobierająca znak z odpowiedniego miejsca
char Matrix::GetCharFromMatrix(int horizontal, int vertical)const{
    return matrix[horizontal + (vertical * FieldSize)];
}

//Metoda wstawiająca znak X w odpowiednim miejscu
void Matrix::SetXOnPosition(int horizontal, int vertical){
    matrix[horizontal + (vertical * FieldSize)] = 'X';
}

//Metoda wstawiająca znak O w odpowiednim miejscu
void Matrix::SetOOnPosition(int horizontal, int vertical){
    matrix[horizontal + (vertical * FieldSize)] = 'O';
}

//Metoda wstawiająca pusty znak w odpowiednim miejscu
void Matrix::SetNOnPosition(int horizontal, int vertical){
    matrix[horizontal + (vertical * FieldSize)] = ' ';
}

/*
 * Przeciązenie operatora << służące do wydrukowania macierzy na strumień zewnętrzny
 * w odpowiednim i czytelnym formacie dla użytkownika. Pierwszy warunek odpowiedzialny
 * jest za wydrukowanie pionowej kreski która odziela pola, natomiast drugi warunek
 * warunek odpowiada za wydrukowanie poziomej kreski.
 * */
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

/* Metoda sprawdzająca czy w rzędzie jest odpowiednia liczba jednakowych znaków uprawniająca do zwycięstwa.
 * Liczona jest liczba wystąpień wybranego znaku aż do napotkaniu innego znaku, jeśli liczba zgada się
 * z założoną liczbą znaków w rzedzie umożliwiającą wygraną to funkcja zwraca 10 w przeciwnnym wypadku funkcja zwraca
 * zero.
 */
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

/* Metoda sprawdzająca czy w kolumnie jest odpowiednia liczba jednakowych znaków uprawniająca do zwycięstwa
 * Liczona jest liczba wystąpień wybranego znaku aż do napotkaniu innego znaku, jeśli liczba zgada się
 * z założoną liczbą znaków w rzedzie umożliwiającą wygraną to funkcja zwraca 10 w przeciwnnym wypadku funkcja zwraca
 * zero.
 */
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

/* Metoda sprawdzająca czy diagonalnie jest odpowiednia liczba jednakowych znaków uprawniająca do zwycięstwa
 * Liczona jest liczba wystąpień wybranego znaku aż do napotkaniu innego znaku, jeśli liczba zgada się
 * z założoną liczbą znaków w rzedzie umożliwiającą wygraną to funkcja zwraca 10 w przeciwnnym wypadku funkcja zwraca
 * zero. Funkcja składa się z czterech pętli, dwie pierwsze odpowiedzialne są za sprawdzenie macierzy diagonalnie z
 * góry do dołu. Natomiast dwie pozostałe odpowiedznialne są za sprawdzenie macierzy z dołu do góry.  Dwie pierwsze
 * pętle podzielone są na pierwszą która sprawdza diagonalnie potem przesuwa się do góry, druga sprawdza poniżej
 * diagonalnej i przesuwa się do dołu. Pozostałe dwie wykonują bardzo podobną funkcje tylko dla diagonalnej rosnącej.
 *
 */
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

//Metoda sprawdzajaca czy miejsce w macierzy jest puste
bool Matrix::PlaceIsEmpty(int horizontal, int vertical){
    return (GetCharFromMatrix(horizontal,vertical) != 'X' && GetCharFromMatrix(horizontal,vertical) != 'O') ||GetCharFromMatrix(horizontal,vertical) == ' ';
}

//Metoda sprawdzająca czy macierz jest pełna
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