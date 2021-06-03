#include "../inc/GameLogic.hpp"

int GameLogic::MaxValue(int depth, int alfa, int beta) {
    if(depth == 7)
        return 0;

    if(IsWinnerAndHowIsTheWinner() != 0)
        return IsWinnerAndHowIsTheWinner();

    if(MatrixIsFull())
        return 0;

    int valueToReturn = -1000;

    for(int i=0; i<GetFieldSize(); i++){
        for (int j = 0; j < GetFieldSize(); j++) {
            if (PlaceIsEmpty(i,j)){
                SetSign(Player::X,i,j);
                valueToReturn = std::max(valueToReturn,MinValue(depth+1, alfa, beta));
                SetSign(Player::N, i, j);
                alfa = std::max(alfa, valueToReturn);

                if(beta <= alfa)
                    break;
            }
        }
    }

    return valueToReturn;

}

int GameLogic::MinValue(int depth, int alfa, int beta) {
    if (depth == 7)
        return 0;

    if(IsWinnerAndHowIsTheWinner() != 0)
        return IsWinnerAndHowIsTheWinner();

    if(MatrixIsFull())
        return 0;

    int valueToReturn = 1000;

    for(int i=0; i<GetFieldSize(); i++){
        for (int j = 0; j < GetFieldSize(); j++) {
            if (PlaceIsEmpty(i,j)){
                SetSign(Player::O,i,j);
                valueToReturn = std::min(valueToReturn, MaxValue(depth+1, alfa, beta));
                SetSign(Player::N, i, j);

                beta = std::min(beta,valueToReturn);
                if (beta <= alfa)
                    break;
            }
        }
    }

    return valueToReturn;
}

Position GameLogic::MakeBestMove(){
    Position position;
    int bestValue = 1000;

    for(int i=0; i<GetFieldSize(); i++){
        for (int j = 0; j < GetFieldSize(); j++) {
            if (PlaceIsEmpty(i,j)){
                SetSign(Player::O,i,j);
                int moveValue = MaxValue(0, -1000, 1000);
                SetSign(Player::N, i, j);

                if(moveValue < bestValue){
                    position.column = j;
                    position.row = i;
                    bestValue = moveValue;
                }
            }
        }
    }
    return position;
}

int GameLogic::IsWinnerAndHowIsTheWinner() {
    if(RowCrossed(Sign::O) == 10 || ColumnCrossed(Sign::O) == 10|| DiagonalCrossed(Sign::O) == 10)
        return -10;
    if(RowCrossed(Sign::X) == 10 || ColumnCrossed(Sign::X) == 10|| DiagonalCrossed(Sign::X) == 10)
        return 10;
    if (MatrixIsFull())
        return -1;

    return 0;

}

bool GameLogic::SetSign(Player player, int horizontal, int vertical){
    if(horizontal > GetFieldSize()-1 || horizontal < 0 || vertical > GetFieldSize()-1 ||vertical < 0 ) {
        return false;
    }

    switch (player) {
        case Player::O:
            SetOOnPosition(horizontal,vertical);
            break;

        case Player::X:
            SetXOnPosition(horizontal,vertical);
            break;

        case Player::N:
            SetNOnPosition(horizontal,vertical);
            break;
    }

    return true;
}

void FunctionToShow(GameLogic& gameLogic, Opponent opponent) {
    int firstNumber;
    int secondNumber;
    int whoseTurn = 0;

    while (!gameLogic.MatrixIsFull() && gameLogic.IsWinnerAndHowIsTheWinner()== 0 ) {
        if (opponent != Opponent::AI || whoseTurn == 0) {
            if (whoseTurn == 0) {
                std::cout << "Kolej gracza ---- X ----" << std::endl;
            }
            if (whoseTurn == 1) {
                std::cout << "Kolej gracza ---- O ----" << std::endl;
            }

            std::cout << "Podaj polozenie poziome:";
            std::cin >> firstNumber;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin >> firstNumber;
            }
            std::cout << "Podaj polozenie pionowe:";
            std::cin >> secondNumber;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin >> secondNumber;
            }
        }

        switch (whoseTurn) {
            case 0:
                if (gameLogic.SetSign(Player::X, firstNumber - 1, secondNumber - 1)) {
                    whoseTurn = 1;
                    std::cout << "------------------" << std::endl;
                    std::cout << gameLogic;
                    std::cout << std::endl;
                }
                break;

            case 1:
                if (opponent == Opponent::NormalPlayer) {
                    if (gameLogic.SetSign(Player::O, firstNumber - 1, secondNumber - 1)) {
                        whoseTurn = 0;
                        std::cout << "------------------" << std::endl;
                        std::cout << gameLogic;
                        std::cout << std::endl;
                    }
                }

                if (opponent == Opponent::AI) {
                    Position position = gameLogic.MakeBestMove();
                    if (gameLogic.SetSign(Player::O, position.row, position.column)) {
                        whoseTurn = 0;
                        std::cout << "------------------" << std::endl;
                        std::cout << "Kolej AI" << std::endl;
                        std::cout << gameLogic;
                        std::cout << std::endl;
                    }
                }
                break;
        }
    }
    if(gameLogic.IsWinnerAndHowIsTheWinner() != 0 && gameLogic.IsWinnerAndHowIsTheWinner() != -1){
         std::cout << "Zwyciezyl gracz ";
         if(gameLogic.IsWinnerAndHowIsTheWinner() == 10){
             std::cout << "pierwszy --- X ---" << std::endl;
         }
         if(gameLogic.IsWinnerAndHowIsTheWinner() == -10){
             std::cout << "drugi --- O ---" << std::endl;
         }
    }

    if(gameLogic.IsWinnerAndHowIsTheWinner() == -1){
        std::cout << " REMIS " << std::endl;
    }


}

