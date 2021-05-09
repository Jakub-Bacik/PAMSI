#ifndef PROJEKT2_NODE_HPP
#define PROJEKT2_NODE_HPP

#include <iostream>

/*Struktur MovieAndRating która implementuje strukture składającą się z numeru rankingu i tytułu filmu */

struct MovieAndRating{
    int Rating;
    std::string MovieTittle;
};

/*Klasa Node implementuje węzeł listy dwukierukowej. Zawiera metody do ustawiania i pobierania
 * danych z klasy, dwa konstruktory oraz zawiera przeciążenie operatora <.
 * atrybuty to wskaźnik do poprzedniego elementu listy i następnego elementu listy oraz
 * sam struktury MovieAndRating który składa się numeru rankingu i tytułu filmu.
 *
 * */

class Node{
private:
    MovieAndRating MovieAndRatingInList;
    Node*  NextElementOfList;
    Node*  PreviousElementOfList;
public:
    Node();
    Node(int rating, std::string movieTittle, Node* nextElementOfList, Node* previousElementOfList);
    MovieAndRating GetMovieAndRatingInList() const;
    Node*  GetPointerToNextElementOfList() const;
    Node*  GetPointerToPreviousElementOfList() const;
    void   SetMovieAndRatingInList(int rating, std::string movieTittle);
    void   SetPointerToNextElementOfList(Node* nextElementOfList);
    void   SetPointerToPreviousElementOfList(Node* previousElementOfList);
    bool operator< (Node& elementToCompare);
    bool operator==(Node& elementToCompare);
};

std::ostream& operator << (std::ostream &Stream, Node nodeToShow);

#endif //PROJEKT2_NODE_HPP
