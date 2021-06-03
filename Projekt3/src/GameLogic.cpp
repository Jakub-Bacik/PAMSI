#include "../inc/GameLogic.hpp"

int GameLogic::MaxValue(int depth, int alfa, int beta) {


    if(depth == 7)
        return 0;

    int score=0;
    if(RowCrossed(Sign::X) == 10 || ColumnCrossed(Sign::X) == 10|| DiagonalCrossed(Sign::X) == 10)
        return -10;

    if(RowCrossed(Sign::O) == 10 || ColumnCrossed(Sign::O) == 10|| DiagonalCrossed(Sign::O) == 10)
        return 10;

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

    if(RowCrossed(Sign::X) == 10 || ColumnCrossed(Sign::X) == 10|| DiagonalCrossed(Sign::X) == 10)
        return -10;

    else if(RowCrossed(Sign::O) == 10 || ColumnCrossed(Sign::O) == 10|| DiagonalCrossed(Sign::O) == 10)
        return 10;

    else if(MatrixIsFull())
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

int GameLogic::IsWinnerAndHowIsTheWinner() {
    if(RowCrossed(Sign::O) == 10 || ColumnCrossed(Sign::O) == 10|| DiagonalCrossed(Sign::O) == 10)
        return 0;
    if(RowCrossed(Sign::X) == 10 || ColumnCrossed(Sign::X) == 10|| DiagonalCrossed(Sign::X) == 10)
        return 1;

    return -1;

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

void FunctionToShow(GameLogic& gameLogic) {
    int firstNumber;
    int secondNumber;
    int whoseTurn = 0;

    while (!gameLogic.MatrixIsFull() && gameLogic.IsWinnerAndHowIsTheWinner() == -1) {

        (whoseTurn) ? std::cout << "Gracz pierwszy " << std::endl <<" ---- X ----" << std::endl : std::cout << "Gracz drugi " << std::endl <<"---- O ----" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "Podaj polozenie poziome:";
        std::cin >> firstNumber;

        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> firstNumber;
        }
        std::cout << "Podaj polozenie pionowe:";
        std::cin >> secondNumber;
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> secondNumber;
        }

        Position position = gameLogic.MakeBestMove();


        switch (whoseTurn) {
            case 0:
                if (gameLogic.SetSign(Player::X, firstNumber, secondNumber)){
                    whoseTurn = 1;
                    std::cout << "------------------" << std::endl;
                    std::cout << gameLogic;
                    std::cout << std::endl;
                }
                break;

            case 1:
                if(gameLogic.SetSign(Player::O, position.row, position.column)) {
                    whoseTurn = 0;
                    std::cout << "------------------" << std::endl;
                    std::cout << gameLogic;
                    std::cout << std::endl;
                }
                break;
        }
        if(gameLogic.IsWinnerAndHowIsTheWinner()!= -1){
            std::cout << "Zwyciezyl gracz ";
            if(gameLogic.IsWinnerAndHowIsTheWinner() == 0){
                std::cout << "pierwszy --- O ---" << std::endl;
            }
            if(gameLogic.IsWinnerAndHowIsTheWinner() == 1){
                std::cout << "drugi --- X ---" << std::endl;
            }
        }

    }
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