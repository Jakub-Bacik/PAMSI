#ifndef PROJEKT2_GAMELOGIC_HPP
#define PROJEKT2_GAMELOGIC_HPP
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "Matrix.hpp"

enum class Player{X, O, N};
enum class Opponent{NormalPlayer, AI};
struct Position{
    int column = -1;
    int row = -1;
};

class GameLogic:public Matrix{

public:
    GameLogic(int characterInARow, int fieldSize): Matrix(characterInARow, fieldSize){};
    int MaxValue(int depth, int alfa, int beta);
    int MinValue(int depth, int alfa, int beta);
    Position MakeBestMove();
    int IsWinnerAndHowIsTheWinner();
    bool SetSign(Player player, int horizontal, int vertical);

};
void FunctionToShow(GameLogic& gameLogic, Opponent opponent);
#endif //PROJEKT2_GAMELOGIC_HPP
