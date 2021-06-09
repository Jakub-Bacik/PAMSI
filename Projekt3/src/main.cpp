#include "../inc/GameLogic.hpp"

/* Stworzenie obiektu klasy GameLogic o wymiarach 3 na 3 oraz wywołanie funkcji
 * obsługujacej interakcje z użytkownikiem wybór przeciwnika jako AI. */
int main(){
    GameLogic gameLogic(3,3);
    FunctionToShow(gameLogic, Opponent::AI);

   return 0;
}