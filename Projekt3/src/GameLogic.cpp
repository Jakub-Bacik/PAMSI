#include "../inc/GameLogic.hpp"
 /*
  * Algorytm MinMax, Metoda Max opdowiadjąca za maksymalizacje zwycięstwa AI.
  * Funkcja wywoływana jest rekurencyjnie. Przerwanie wywoływania może
  * nastąpić jeśłi głebokość jest równa 7, tablica jest pełna wtedy
  * zwracana jest wartość 0. Natomiast jeśli AI zwycięży zwracana
  * jest wartość -10, w przeciwnym wypadku 10. Cięcia alfa beta
  * zastosowane są aby nie przeszukiwać całego drzewa, co skutkuje
  * oszczędnością czasu. W dwóch pętlach symulowane są kolejne ruchy gracza.
  * */
int MaxValue(GameLogic &board, int depth, int alfa, int beta) {
    if(depth == 7)
        return 0;

    if(board.IsWinnerAndHowIsTheWinner() != 0)
        return board.IsWinnerAndHowIsTheWinner();

    if(board.MatrixIsFull())
        return 0;

    int valueToReturn = -1000;

    for(int i=0; i<board.GetFieldSize(); i++){
        for (int j = 0; j < board.GetFieldSize(); j++) {
            if (board.PlaceIsEmpty(i,j)){
                board.SetSign(Player::X,i,j);
                int value = MinValue(board, depth+1, alfa, beta);
                board.SetSign(Player::N, i, j);
                if(value > valueToReturn)
                    valueToReturn = value;

                if (value >= beta)
                    return valueToReturn;

                if(value > alfa)
                    alfa = value;
            }
        }
    }

    return valueToReturn;

}

/*
  * Algorytm MinMax, Metoda Min opdowiadjąca za minimalizacje zwycięstwa gracza.
  * Funkcja wywoływana jest rekurencyjnie. Przerwanie wywoływania może
  * nastąpić jeśłi głebokość jest równa 7, tablica jest pełna wtedy
  * zwracana jest wartość 0. Natomiast jeśli AI zwycięży zwracana
  * jest wartość -10, w przeciwnym wypadku 10. Cięcia alfa beta
  * zastosowane są aby nie przeszukiwać całego drzewa, co skutkuje
  * oszczędnością czasu. W dwóch pętlach symulowane są kolejne ruchy AI.
  * */
int MinValue(GameLogic &board, int depth, int alfa, int beta) {
    if (depth == 7)
        return 0;

    if(board.IsWinnerAndHowIsTheWinner() != 0)
        return board.IsWinnerAndHowIsTheWinner();

    if(board.MatrixIsFull())
        return 0;

    int valueToReturn = 1000;

    for(int i=0; i<board.GetFieldSize(); i++){
        for (int j = 0; j < board.GetFieldSize(); j++) {
            if (board.PlaceIsEmpty(i,j)){
                board.SetSign(Player::O,i,j);
                int value = MaxValue(board, depth+1, alfa, beta);
                board.SetSign(Player::N, i, j);

                if(value < valueToReturn)
                    valueToReturn = value;

                if (value <= alfa)
                    return valueToReturn;

                if (value < beta)
                    beta = value;
            }
        }
    }

    return valueToReturn;
}

/* Funkcja odpowiedzialna za znalezienie najlepszego ruchu. Skanowana jest cała plansza wywołując
 * przy każdej pozycji algorytm minmax jeśli miejsce jest puste. Natępnie jeśli wartość zwrócona
 * jest mniejsza niż bestValue następuje przypisanie pozycji optymalnej i zmiana wartości zmiennej
 * bestValue na wartość zwróconą przez algorytm.
 *
 */
Position MakeBestMove(GameLogic &board){
    Position position;
    int bestValue = 1000;

    for(int i=0; i<board.GetFieldSize(); i++){
        for (int j = 0; j < board.GetFieldSize(); j++) {
            if (board.PlaceIsEmpty(i,j)){
                board.SetSign(Player::O,i,j);
                int moveValue = MaxValue(board, 0, -1000, 1000);
                board.SetSign(Player::N, i, j);

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

/* Metoda sprawdzająca czy jest zwycięzca albo występuje remis. Jeśli zwyciężył gracz z kółkiem zwracana jest
 * wartosć -10, jeśli z krzyżykiem zwracana jest wartosć 10, jeśli z kółkiem zwracana jest wartość -1. Natomiast
 * jeśli nie wystąpi żaden z poniższych scenariuszy zwracane jest 0.
 * */
int GameLogic::IsWinnerAndHowIsTheWinner() {
    if(RowCrossed(Sign::O) == 10 || ColumnCrossed(Sign::O) == 10|| DiagonalCrossed(Sign::O) == 10)
        return -10;
    if(RowCrossed(Sign::X) == 10 || ColumnCrossed(Sign::X) == 10|| DiagonalCrossed(Sign::X) == 10)
        return 10;
    if (MatrixIsFull())
        return -1;

    return 0;

}

/* Metoda odpowiedzialna za postawienia odpowiedziego znaku w odpowiednim miejscu.
 * Jeśli gracz wpisze liczbę większą niż rozmiar tablicy to fuknkcja zwraca fałsz.
 * */
bool GameLogic::SetSign(Player player, int horizontal, int vertical){
    if(horizontal > GetFieldSize()-1 || horizontal < 0 || vertical > GetFieldSize()-1 ||vertical < 0) {
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
/*
 * Funkcja odpowiedzialna za interakcje z użytkownikiem. Na początku wyświetlana jest informacja określająca
 * którego z graczy jest kolej. Następnie następuje kontrola strumienia wejściowego sprawdzająca
 * czy dane wpiszane są liczbą. Następnie w switch'u następuje odpowiedni wybór gracza w zależności od
 * zmiennej whoseTurn, dodatkowo w przypadku złego podania wartości ta część się nie wykonana i gracz ponownie
 * musi wpisać pozycje go interesującą. Gdy poprawnie wybraliśmy pozycje oraz miejsce jest puste następuje wstawienie
 * znaku w wybranym miejscu, poczym następuje zmiana wartości zmiennej whoseTurn i wyświetlenie aktualnego stanu planszy.
 * W przypadku drugiego gracza procedura jest podobna do opisanej wyżej. Natomiast jeśli przeciwnikiem jest AI to
 * następuje wywołanie funkcji FindBestMove, która zwraca pozycje wybraną przez algorytm. Gdy tablica zostanie wypełniona
 * do pełna lub któryś z graczy zwycieży gra jest przerywana. Wyświetlany jest komunikat, zwycięstwo któregoś z
 * graczy albo remis.
 * */
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
                if (gameLogic.PlaceIsEmpty(firstNumber-1, secondNumber-1)) {
                    if (gameLogic.SetSign(Player::X, firstNumber - 1, secondNumber - 1) ) {
                        whoseTurn = 1;
                        std::cout << "------------------" << std::endl;
                        std::cout << gameLogic;
                        std::cout << std::endl;
                    }
                }
                break;

            case 1:
                if (opponent == Opponent::NormalPlayer) {
                    if (gameLogic.PlaceIsEmpty(firstNumber-1, secondNumber-1)) {
                        if (gameLogic.SetSign(Player::O, firstNumber - 1, secondNumber - 1)) {
                            whoseTurn = 0;
                            std::cout << "------------------" << std::endl;
                            std::cout << gameLogic;
                            std::cout << std::endl;
                        }
                    }
                }

                if (opponent == Opponent::AI) {
                    Position position = MakeBestMove(gameLogic);
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

