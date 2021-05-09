#include "../inc/MyDoublyLinkedList.hpp"


//Domyślny konstruktor klasy MyDoublyLinkedList inicjalizuje liste bez elementów
MyDoublyLinkedList::MyDoublyLinkedList() {
    HeaderOfList = new Node;
    TrailerOfList = new Node;
    HeaderOfList->SetPointerToNextElementOfList(TrailerOfList);
    HeaderOfList->SetPointerToPreviousElementOfList(nullptr);
    TrailerOfList->SetPointerToPreviousElementOfList(HeaderOfList);
    TrailerOfList->SetPointerToNextElementOfList(nullptr);
    NumberOfElementsInList=0;
}


//Metoda sprawdza czy lista nie zawiera żadnego elementu
bool MyDoublyLinkedList::Empty() const {
    return HeaderOfList->GetPointerToNextElementOfList() == TrailerOfList;
}


//Metoda zwracająca strukture znajdującą sie na początku listy
Node &MyDoublyLinkedList::Front() const{
    return *HeaderOfList->GetPointerToNextElementOfList();
}


//Metoda zwracająca strukture znajdującą sie na końcu listy
Node &MyDoublyLinkedList::Back() const {
    return *TrailerOfList->GetPointerToPreviousElementOfList();
}


//Metoda dodająca  element na początku listy
void MyDoublyLinkedList::AddFront(const Node nodeOfData) {
    InsertNewNode(HeaderOfList->GetPointerToNextElementOfList(), nodeOfData.GetMovieAndRatingInList().Rating,
                  nodeOfData.GetMovieAndRatingInList().MovieTittle);
}


//Metoda dodająca element na końcu listy
void MyDoublyLinkedList::AddBack(const Node nodeOfData) {
    InsertNewNode(TrailerOfList,nodeOfData.GetMovieAndRatingInList().Rating, nodeOfData.GetMovieAndRatingInList().MovieTittle);
}

//Metoda dodająca  element na początku listy
void MyDoublyLinkedList::AddFront(const int numberOfPacket, const std::string dataOfPacket) {
    InsertNewNode(HeaderOfList->GetPointerToNextElementOfList(),numberOfPacket, dataOfPacket);
}


//Metoda dodająca element na końcu listy
void MyDoublyLinkedList::AddBack(const int numberOfPacket, const std::string dataOfPacket) {
    InsertNewNode(TrailerOfList,numberOfPacket, dataOfPacket);
}

//Metoda usuwająca element z początku listy
void MyDoublyLinkedList::RemoveFront() {
    Erase(HeaderOfList->GetPointerToNextElementOfList());
}


//Metoda usuwająca elemnt z konca listy
void MyDoublyLinkedList::RemoveBack() {
    Erase(TrailerOfList->GetPointerToPreviousElementOfList());
}


//Metoda odpowiedająca za wstawianie nowego elementu do listy
void MyDoublyLinkedList::InsertNewNode(Node* nodeAfterInsert, const int numberOfPacket, const std::string dataOfPacket) {

    Node *newElementToInsert = new Node;
    newElementToInsert->SetMovieAndRatingInList(numberOfPacket, dataOfPacket);

    newElementToInsert->SetPointerToNextElementOfList(nodeAfterInsert);
    newElementToInsert->SetPointerToPreviousElementOfList(nodeAfterInsert->GetPointerToPreviousElementOfList());
    nodeAfterInsert->GetPointerToPreviousElementOfList()->SetPointerToNextElementOfList(newElementToInsert);
    nodeAfterInsert->SetPointerToPreviousElementOfList(newElementToInsert);
    NumberOfElementsInList++;

}


//Metoda odpowiadajaca za usuwanie wybranego elementu
void MyDoublyLinkedList::Erase(Node *elementToRemove) {
    if(!Empty()) {
        Node* elementBeforeElementToRemove = elementToRemove->GetPointerToPreviousElementOfList();
        Node* elementAfterElementToRemove = elementToRemove ->GetPointerToNextElementOfList();

        elementBeforeElementToRemove->SetPointerToNextElementOfList(elementAfterElementToRemove);
        elementAfterElementToRemove ->SetPointerToPreviousElementOfList(elementBeforeElementToRemove);
        delete elementToRemove;
        NumberOfElementsInList--;

    }else{
        std::cerr << "Pusta Lista" <<std::endl;
    }
}


//Metoda zwracająca ilość elementów w liscie
int MyDoublyLinkedList::Size() const {
    return NumberOfElementsInList;
}


//Metoda odpowiadająca za dodawanie wybranego elementu
void MyDoublyLinkedList::Insert(Node *nodeAfterInsert, Node *nodeToInsert) {
    nodeToInsert->SetPointerToNextElementOfList(nodeAfterInsert);
    nodeToInsert->SetPointerToPreviousElementOfList(nodeAfterInsert->GetPointerToPreviousElementOfList());
    nodeAfterInsert->GetPointerToPreviousElementOfList()->SetPointerToNextElementOfList(nodeToInsert);
    nodeAfterInsert->SetPointerToPreviousElementOfList(nodeToInsert);
    NumberOfElementsInList++;
}

//Usuwa wszystkie elementy z listy dwukierunkowej
void MyDoublyLinkedList::Clear() {
    while(!Empty()){
        RemoveFront();
    }
}


//Przeciązenie operatora << służąca do wyświetlania elementów w liście
std::ostream& operator << (std::ostream &Stream, MyDoublyLinkedList& myDoublyLinkedList){

    while(!myDoublyLinkedList.Empty()){
        std::cout.width(4);
        Stream  << std::left << myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating << "|"
                             << myDoublyLinkedList.Front().GetMovieAndRatingInList().MovieTittle<< std::endl;
        myDoublyLinkedList.RemoveFront();
    }
    return Stream;
}

/* Funkcja służąca do pobierania danych z pliku .csv. Funkcja pobiera wyznaczoną liczbę linii lub
 * do momentu końca pliku. Za pomocą funkcji getline pobierana jest cała linia. Następnie string przekazany
 * jest do funkcji InputDataFiltering która odpowiedzialna jest za przefiltrowanie danych. Następnie jeśli
 * przefiltrowane dane spełniają następujące kryteria: pobrana linia nie jest pusta, nie brakuje tytułu, rankingu
 * lub nie jest to pierwszy wiersz tytułowy. Następnie za pomocą funkcji atoi typ string rzutowany jest na typ int.
 * Następnie wywołana jest funkcja StringCleaner czyści używane string'y.
 */
void Read(std::istream &streamFromFile, MyDoublyLinkedList& myDoublyLinkedList, int desiredNumberOfData){
    std::string temporaryStringToOTheEntireLine;
    std::string temporaryStringToMovieTitle;
    int temporaryIntToTypeConversionFromStringToFilmRatingToInt;
    std::string temporaryStringToFilmRating;

    int currentNumberOfData = 0;

    while (!streamFromFile.eof() && currentNumberOfData <= desiredNumberOfData) {
        getline(streamFromFile, temporaryStringToOTheEntireLine, '\n');

        InputDataFiltering(temporaryStringToOTheEntireLine, temporaryStringToMovieTitle, temporaryStringToFilmRating);

        if(currentNumberOfData != 0 && temporaryStringToMovieTitle != "" && temporaryStringToFilmRating != "" && temporaryStringToOTheEntireLine != "") {
            temporaryIntToTypeConversionFromStringToFilmRatingToInt = std::stoi(temporaryStringToFilmRating);
            myDoublyLinkedList.AddBack(temporaryIntToTypeConversionFromStringToFilmRatingToInt, temporaryStringToMovieTitle);
        }

        StringCleaner(temporaryStringToOTheEntireLine, temporaryStringToMovieTitle, temporaryStringToFilmRating);
        currentNumberOfData++;
    }
}

/* Funkcja odpowiedzialna za przefiltrowanie danych wejściowych polegająca na podzieleniu string'a wejsciowego,
 * na dwa string'i odpowiednio tytuł i ranking filmu.
 * */
void InputDataFiltering(std::string &temporaryStringToOTheEntireLine, std::string &temporaryStringToMovieTitle, std::string &temporaryStringToFilmRating){
    char characterToSeparateData = ',';
    int firstComma =0;
    int lastComma=0;

    for(int i=0; i< temporaryStringToOTheEntireLine.size(); i++){
        if(temporaryStringToOTheEntireLine[i] == characterToSeparateData && !firstComma)
            firstComma = i;

        if(temporaryStringToOTheEntireLine[i] == characterToSeparateData)
            lastComma = i;
    }

    for(int j=0; j<temporaryStringToOTheEntireLine.size(); j++) {
        if(j > firstComma && j < lastComma)
            temporaryStringToMovieTitle += temporaryStringToOTheEntireLine[j];

        if(j > lastComma)
            temporaryStringToFilmRating += temporaryStringToOTheEntireLine[j];
    }

}


//Funkcja odpowiedzialana za wyczyszenie zawartości string'ów
void StringCleaner(std::string &temporaryStringToOTheEntireLine, std::string &temporaryStringToMovieTitle, std::string &temporaryStringToFilmRating){
    temporaryStringToFilmRating.clear();
    temporaryStringToMovieTitle.clear();
    temporaryStringToOTheEntireLine.clear();
}






