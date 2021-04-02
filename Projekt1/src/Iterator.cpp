//
// Created by jakub on 02.04.2021.
//

#include "../inc/Iterator.hpp"

Node &Iterator::operator*() {
    return *pointerToTheNode;
}

bool Iterator::operator==(const Iterator &positionOfElement) const {
    return pointerToTheNode == positionOfElement.pointerToTheNode;
}

bool Iterator::operator!=(const Iterator &positionOfElement) const {
    return pointerToTheNode != positionOfElement.pointerToTheNode;
}

Iterator &Iterator::operator++() {
    pointerToTheNode = pointerToTheNode->GetPointerToNextElementOfList();
    return *this;
}

Iterator &Iterator::operator--() {
    pointerToTheNode = pointerToTheNode->GetPointerToPreviousElementOfList();
    return *this;
}

Iterator::Iterator(Node *createFromNode) {
    pointerToTheNode = createFromNode;
}


