#include "../inc/Node.hpp"

//Implementacja konstruktora domyślnego
Node::Node(): NextElementOfList{nullptr}, PreviousElementOfList{nullptr}{
    MovieAndRatingInList.MovieTittle = "";
    MovieAndRatingInList.Rating = 0;
}

//Implementacja konstruktora dodatkowego
Node::Node(int rating, std::string movieTittle,Node* nextElementOfList,Node* previousElementOfList):
            NextElementOfList{nextElementOfList},PreviousElementOfList{previousElementOfList} {
    MovieAndRatingInList.MovieTittle = movieTittle;
    MovieAndRatingInList.Rating = rating;
}


//Metoda zwracająca tytul filmu i ranking znajdujuący sie w klasie Node
MovieAndRating Node::GetMovieAndRatingInList() const{
    return MovieAndRatingInList;
}


//Metoda zwracajaca wskaźnik na następny element
Node* Node::GetPointerToNextElementOfList() const {
    return NextElementOfList;
}


//Metoda zwracająca wskaźnik na poprzedni element
Node *Node::GetPointerToPreviousElementOfList() const{
    return PreviousElementOfList;
}


//Metoda ustawiająca numer rankingu
void Node::SetMovieAndRatingInList(int rating, std::string movieTittle){
    MovieAndRatingInList.MovieTittle = movieTittle;
    MovieAndRatingInList.Rating = rating;
}


//Metoda ustawiająca wskaźnik węzła na następny element
void Node::SetPointerToNextElementOfList(Node* pointerToNextElement) {
    NextElementOfList = pointerToNextElement;
}


//Metoda ustawiająca wskaźnik węzła na poprzedni element
void Node::SetPointerToPreviousElementOfList(Node* pointerToPreviousElement) {
    PreviousElementOfList=pointerToPreviousElement;
}

//Przeciązenie operatora < dla klasy Node
bool Node::operator<(Node &elementToCompare) {
    return GetMovieAndRatingInList().Rating < elementToCompare.GetMovieAndRatingInList().Rating;
}
//Przeciązenie operatora == dla klasy Node
bool Node::operator==(Node &elementToCompare) {
    return GetMovieAndRatingInList().Rating == elementToCompare.GetMovieAndRatingInList().Rating;
}

//Przeciązenie operatora << dla klasy Node do wypisywania struktury MovieAndRating
std::ostream& operator << (std::ostream &Stream, Node nodeToShow){
    Stream << nodeToShow.GetMovieAndRatingInList().Rating << "|" << nodeToShow.GetMovieAndRatingInList().MovieTittle << std::endl;
    return Stream;
}

