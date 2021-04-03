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
    srand(time(NULL)); //ustawienie czasu potrzebnego do funkcji random
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
    return *TrailerOfList;
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
    Earase(HeaderOfList->GetPointerToNextElementOfList());
}


//Metoda usuwająca elemnt z konca listy
void MyDoublyLinkedList::RemoveBack() {
    Earase(TrailerOfList->GetPointerToPreviousElementOfList());
}


//Metoda odpowiedająca za wstawianie nowego elementu do listy
void MyDoublyLinkedList::InsertNewNode(Node* nodeAfterInsert, const int numberOfPacket, const std::string dataOfPacket) {

    Node *newElementToInsert = new Node;
    newElementToInsert->SetPacketInList(numberOfPacket, dataOfPacket);

    newElementToInsert->SetPointerToNextElementOfList(nodeAfterInsert);
    newElementToInsert->SetPointerToPreviousElementOfList(nodeAfterInsert->GetPointerToPreviousElementOfList());
    nodeAfterInsert->GetPointerToPreviousElementOfList()->SetPointerToNextElementOfList(newElementToInsert);
    nodeAfterInsert->SetPointerToPreviousElementOfList(newElementToInsert);
    NumberOfElementsInList++;

    AddedOrDeletedElementToDoubledLinkedList(Size(),Operation::Add);
}


//Metoda odpowiadajaca za usuwanie wybranego elementu
void MyDoublyLinkedList::Earase(Node *elementToRemove) {
    if(!Empty()) {
        Node* elementBeforeElementToRemove = elementToRemove->GetPointerToPreviousElementOfList();
        Node* elementAfterElementToRemove = elementToRemove ->GetPointerToNextElementOfList();

        elementBeforeElementToRemove->SetPointerToNextElementOfList(elementAfterElementToRemove);
        elementAfterElementToRemove ->SetPointerToPreviousElementOfList(elementBeforeElementToRemove);
        delete elementToRemove;
        NumberOfElementsInList--;

        AddedOrDeletedElementToDoubledLinkedList(Size(),Operation::Delete);
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
    AddedOrDeletedElementToDoubledLinkedList(Size(),Operation::Add);
}


//Przeciązenie operatora << służąca do wyświetlania elementów w liście
std::ostream& operator << (std::ostream &Stream, MyDoublyLinkedList& myDoublyLinkedList){

    while(!myDoublyLinkedList.Empty()){
        Stream << myDoublyLinkedList.Front().GetPacketInList().DataOfPacket << std::endl;
        myDoublyLinkedList.RemoveFront();
    }
    return Stream;
}

//Przeciązenie operatora >> służaca do wstawianie elemntu do listy
std::istream& operator >> (std::istream &streamFromFile, MyDoublyLinkedList& myDoublyLinkedList){
    std::string temporaryStringToDivide;
    int numberOfPacket = 0;

    while (!streamFromFile.eof()) {
        getline(streamFromFile, temporaryStringToDivide, '\n');
        if(RandomAddToFromOrBackToDoublyLinkedList()) {
            myDoublyLinkedList.AddBack(numberOfPacket, temporaryStringToDivide);
        }
        else{
            myDoublyLinkedList.AddFront(numberOfPacket, temporaryStringToDivide);
        }
        ++numberOfPacket;
    }
}


/* Funkcja odpowiadająca za losowe dodawanie elementów do listy, wykorzystuje funkcje rand
 * która zwraca liczbe, obliczane jest modulo 100 co daje liczby z zakresu 0 do 100,
 * następnie zwracamy prawde jeśli liczba jest parzysta, fałsz jeśli nieparzysta*/
bool RandomAddToFromOrBackToDoublyLinkedList(){
    int randomNumber =(rand()%100);
    return randomNumber%2 == 0;

}


