//
// Created by jakub on 02.04.2021.
//

#ifndef PROJEKT1_ITERATOR_HPP
#define PROJEKT1_ITERATOR_HPP

#include "Node.hpp"

class Iterator{
public:
    Node& operator*();
    bool operator==(const Iterator& positionOfElement) const;
    bool operator!=(const Iterator& positionOfElement)const;
    Iterator& operator++();
    Iterator& operator--();
    Iterator(Node* createFromNode);

private:
    Node* pointerToTheNode;

};
#endif //PROJEKT1_ITERATOR_HPP
