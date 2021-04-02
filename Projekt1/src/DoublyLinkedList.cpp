//
// Created by jakub on 02.04.2021.
//
#include "../inc/DoublyLinkedList.hpp"

/*Domyślny konstruktor klasy DoublyLinkedList inicjalizuje liste bez elementów*/
DoublyLinkedList::DoublyLinkedList() {
    HeaderOfList = new Node;
    TrailerOfList = new Node;
    HeaderOfList->SetPointerToNextElementOfList(TrailerOfList);
    TrailerOfList->SetPointerToPreviousElementOfList(HeaderOfList);
    NumberOfElementsInList=0;
}

/*Domyślny destuktor klasy DoublyLinkedList usuwa głowe i ogon listy*/
DoublyLinkedList::~DoublyLinkedList() {
    delete HeaderOfList;
    delete TrailerOfList;
}

/*Metoda sprawdza czy lista nie zawiera żadnego elementu*/
bool DoublyLinkedList::Empty() const {
    return (HeaderOfList->GetPointerToNextElementOfList() == TrailerOfList);
}

/* Zwraca strukture znajdującą sie na początku listy*/
Node &DoublyLinkedList::Front() const{
    return *HeaderOfList->GetPointerToNextElementOfList();
}

/* Zwraca strukture znajdującą sie na końcu listy*/
Node &DoublyLinkedList::Back() const {
    return *TrailerOfList;
}

/*Dodaje element na początku listy*/
void DoublyLinkedList::AddFront(const int numberOfPacket, const std::string dataOfPacket) {
    InsertNewNode(HeaderOfList->GetPointerToNextElementOfList(),numberOfPacket, dataOfPacket);
}

/*Dodaje element na końcu listy*/
void DoublyLinkedList::AddBack(const int numberOfPacket, const std::string dataOfPacket) {
    InsertNewNode(TrailerOfList,numberOfPacket, dataOfPacket);
}

/*Usuwa element z końca listy*/
void DoublyLinkedList::RemoveFront() {
    Earase(HeaderOfList->GetPointerToNextElementOfList());
}

/*Usuwa elemnt z przodu listy*/
void DoublyLinkedList::RemoveBack() {
    Earase(TrailerOfList->GetPointerToPreviousElementOfList());
}

/*Metoda odpowiedająca za wstawianie nowego pakietu do listy*/
void DoublyLinkedList::InsertNewNode(Node* NodeAfterInsert, const int numberOfPacket, const std::string dataOfPacket) {

    Node *newElementToInsert = new Node;
    newElementToInsert->SetPacketlInList(numberOfPacket, dataOfPacket);

    newElementToInsert->SetPointerToNextElementOfList(NodeAfterInsert);
    newElementToInsert->SetPointerToPreviousElementOfList(NodeAfterInsert->GetPointerToPreviousElementOfList());
    NodeAfterInsert->GetPointerToPreviousElementOfList()->SetPointerToNextElementOfList(newElementToInsert);
    NodeAfterInsert->SetPointerToPreviousElementOfList(newElementToInsert);
    ++NumberOfElementsInList;
}

/*Metoda odpowiadajaca za usuwanie wybranego elementu*/
void DoublyLinkedList::Earase(Node *elementToRemove) {
    if(!Empty()) {
        Node* elementBeforeElementToRemove = elementToRemove->GetPointerToPreviousElementOfList();
        Node* elementAfterElementToRemove = elementToRemove ->GetPointerToNextElementOfList();

        elementBeforeElementToRemove->SetPointerToNextElementOfList(elementAfterElementToRemove);
        elementAfterElementToRemove ->SetPointerToPreviousElementOfList(elementBeforeElementToRemove);
        delete elementToRemove;
        --NumberOfElementsInList;
    }else{
        std::cerr << "Pusta Lista" <<std::endl;
    }
}

int DoublyLinkedList::size() const {
    return NumberOfElementsInList;
}



