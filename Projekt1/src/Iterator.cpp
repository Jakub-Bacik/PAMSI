#include "../inc/Iterator.hpp"

//Przeciązenie operatora wyłuskania obiektu klasy Iterator
Node &Iterator::operator*()const {
    return *pointerToTheNode;
}

//Przeciazenie operatora porównania dwóch obiektów klasy Iterator
bool Iterator::operator==(const Iterator &positionOfElement) const {
    return pointerToTheNode == positionOfElement.pointerToTheNode;
}


//Przeciazenie operatora nierównośći dwóch obiektów klasy Iterator
bool Iterator::operator!=(const Iterator &positionOfElement) const {
    return pointerToTheNode != positionOfElement.pointerToTheNode;
}


//Przeciązenie operatora preinkrementacji obiektu klasy Iterator
Iterator &Iterator::operator++() {
    pointerToTheNode = pointerToTheNode->GetPointerToNextElementOfList();
    return *this;
}


//Przeciązenie operatora predekrementacji obiektu klasy Iterator
Iterator &Iterator::operator--() {
    pointerToTheNode = pointerToTheNode->GetPointerToPreviousElementOfList();
    return *this;
}


//Implementacja konstruktora dodatkowego
Iterator::Iterator(Node *createFromNode) {
    pointerToTheNode = createFromNode;
}


//Implementacja konstruktora domyślnego
Iterator::Iterator():pointerToTheNode(nullptr){};

