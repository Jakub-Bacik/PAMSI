#include "gtest/gtest.h"
#include "../inc/GameLogic.hpp"
#include "../inc/Matrix.hpp"

/*Testy klasy GameLogic*/

/*Test sprawdzający poprawność dodania nowego znaku lub usunięcia w odpowiednim miejscu macierzy*/
TEST(GL, setSign){
    GameLogic gameLogic(3,3);
    gameLogic.SetSign(Player::X,0,0);
    gameLogic.SetSign(Player::O, 1, 1);
    EXPECT_EQ(gameLogic.GetCharFromMatrix(0,0), 'X');
    EXPECT_EQ(gameLogic.GetCharFromMatrix(1,1), 'O');

    gameLogic.SetSign(Player::N,1,1);
    EXPECT_EQ(gameLogic.GetCharFromMatrix(1,1), ' ');

}

/*Test sprawdzajacy funkcje odpowiedzialna za kontrolowanie czy któryś z graczy zwyciężył */
TEST(GL, isWinnerAndHowIsTheWinner){
    GameLogic gameLogic(3,3);
    gameLogic.SetSign(Player::X,0,0);
    gameLogic.SetSign(Player::X,1,1);
    gameLogic.SetSign(Player::X,2,2);

    EXPECT_EQ(gameLogic.IsWinnerAndHowIsTheWinner(), 10);
    gameLogic.ClearTheMatrix();

    gameLogic.SetSign(Player::O,0,2);
    gameLogic.SetSign(Player::O,1,1);
    gameLogic.SetSign(Player::O,2,0);
    EXPECT_EQ(gameLogic.IsWinnerAndHowIsTheWinner(), -10);
    gameLogic.ClearTheMatrix();

    gameLogic.SetSign(Player::X,0,0);
    gameLogic.SetSign(Player::X,0,1);
    gameLogic.SetSign(Player::X,0,2);

    EXPECT_EQ(gameLogic.IsWinnerAndHowIsTheWinner(), 10);
    gameLogic.ClearTheMatrix();

    gameLogic.SetSign(Player::O,0,0);
    gameLogic.SetSign(Player::O,1,0);
    gameLogic.SetSign(Player::O,2,0);
    EXPECT_EQ(gameLogic.IsWinnerAndHowIsTheWinner(), -10);


}

/*Sprawdzenie algorytmu polegające na zablokowaniu zwycięstwa gracza*/
TEST(GL, makeBestMove){
    GameLogic gameLogic(3,3);
    gameLogic.SetSign(Player::X,1,1);
    gameLogic.SetSign(Player::O, 0,0);
    gameLogic.SetSign(Player::X,0,2);

    Position positionToCheck = MakeBestMove(gameLogic);

    EXPECT_EQ(positionToCheck.column, 0);
    EXPECT_EQ(positionToCheck.row, 2);

}

/*Test klady Matrix*/
/*Test sprawdzający podstawowe operacje na macierzy takie jak
 * dodanie znaku w odpowiednim miejscu, pobranie znaku z
 * odpowiedniego miejsca, sprawdzenie wymiarów macierzy,
 * spradzenie obecnosci znaku w  wybranym miejscu i sprawdzenie
 * czy macierz jest pusta*/
TEST(Matrix, baseOperationOfMatrix){
    Matrix matrix(3,3);
    matrix.FillTheMatrix();
    EXPECT_EQ(matrix.GetSizeOfMatrix(), 9);
    EXPECT_EQ(matrix.GetFieldSize(), 3);

    matrix.SetXOnPosition(1,1);
    EXPECT_EQ(matrix.GetCharFromMatrix(1,1), 'X');

    matrix.SetOOnPosition(2,2);
    EXPECT_EQ(matrix.GetCharFromMatrix(2,2), 'O');

    matrix.ClearTheMatrix();
    EXPECT_EQ(matrix.GetCharFromMatrix(1,1), ' ');

    EXPECT_FALSE(matrix.MatrixIsFull());
    EXPECT_TRUE(matrix.PlaceIsEmpty(2,2));

}

/*Test polegający na sprawdzeniu poprawności funkcji odpowiedzialnej za
 * kontrolowanie wystąpienia odpowiedniej ilości takich samych znaków w rzędzie*/
TEST(Matrix, rowCrossed){
    Matrix matrix(3,3);
    matrix.FillTheMatrix();
    matrix.SetXOnPosition(0,1);
    matrix.SetXOnPosition(1,1);
    matrix.SetXOnPosition(2,1);

    EXPECT_EQ(matrix.RowCrossed(Sign::X), 10);

    matrix.ClearTheMatrix();

    EXPECT_EQ(matrix.RowCrossed(Sign::X),0);

}

/*Test polegający na sprawdzeniu poprawności funkcji odpowiedzialnej za
 * kontrolowanie wystąpienia odpowiedniej ilości takich samych znaków w kolumnie*/
TEST(Matrix, columnCrossed){
    Matrix matrix(3,3);
    matrix.FillTheMatrix();
    matrix.SetXOnPosition(1,0);
    matrix.SetXOnPosition(1,1);
    matrix.SetXOnPosition(1,2);

    EXPECT_EQ(matrix.ColumnCrossed(Sign::X), 10);

    matrix.ClearTheMatrix();

    EXPECT_EQ(matrix.ColumnCrossed(Sign::X), 0);

}

/*Test polegający na sprawdzeniu poprawności funkcji odpowiedzialnej za
 * kontrolowanie wystąpienia odpowiedniej ilości takich samych znaków diagonalnie*/
TEST(Matrix, dialogCrossed){
    Matrix matrix(3,3);
    matrix.FillTheMatrix();
    matrix.SetXOnPosition(0,0);
    matrix.SetXOnPosition(1,1);
    matrix.SetXOnPosition(2,2);

    EXPECT_EQ(matrix.DiagonalCrossed(Sign::X), 10);

    matrix.ClearTheMatrix();

    EXPECT_EQ(matrix.DiagonalCrossed(Sign::X), 0);

    matrix.SetXOnPosition(0,2);
    matrix.SetXOnPosition(1,1);
    matrix.SetXOnPosition(2,0);

    EXPECT_EQ(matrix.DiagonalCrossed(Sign::X), 10);

    matrix.ClearTheMatrix();

    EXPECT_EQ(matrix.DiagonalCrossed(Sign::X), 0);

}

