#ifndef PROJEKT2_GAMELOGIC_HPP
#define PROJEKT2_GAMELOGIC_HPP
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "Matrix.hpp"

//Rodzaj stawianego znaku X, O lub nic.
enum class Player{X, O, N};
//Przeciwko algorytmowi lub przeciwko drugiemu graczowi.
enum class Opponent{NormalPlayer, AI};

/*Struktura pomocna do zaimplementowania sterowania
 * wstawianiem znaków przez algorytm.
 * */
struct Position{
    int column = -1;
    int row = -1;
};

/* Klasa GameLogic odpowiedzialna za część logiczną gry kółko i krzyżyk, dziedziczy po klasie Matrix.
 * Klasa posiada metody służące do wstawiania znaku w odpowiednim miejscu.
 * */
class GameLogic:public Matrix{

public:
    GameLogic(int characterInARow, int fieldSize): Matrix(characterInARow, fieldSize){FillTheMatrix();};
    int IsWinnerAndHowIsTheWinner();
    bool SetSign(Player player, int horizontal, int vertical);

};

int MaxValue(GameLogic &board,int depth, int alfa, int beta);
int MinValue(GameLogic &board,int depth, int alfa, int beta);
Position MakeBestMove(GameLogic &board);

void FunctionToShow(GameLogic& gameLogic, Opponent opponent);
#endif //PROJEKT2_GAMELOGIC_HPP
