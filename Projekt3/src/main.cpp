#include "../inc/GameLogic.hpp"

/* Stworzenie obiektu klasy GameLogic o wymiarach spersonalizowanych przez gracza
 * oraz wywołanie funkcji obsługujacej interakcje z użytkownikiem wybór przeciwnika jako AI. */
int main(){
    GameLogic gameLogic = ChooseTheSizeOfBoardAndCharacterInARow();
    FunctionToShow(gameLogic, Opponent::AI);

   return 0;
}