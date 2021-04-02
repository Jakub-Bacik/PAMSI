//
// Created by jakub on 02.04.2021.
//

#ifndef PROJEKT1_DOUBLYLINKEDLIST_HPP
#define PROJEKT1_DOUBLYLINKEDLIST_HPP

#include "Node.hpp"
#include <iostream>

/*Klasa DoublyLinkedList służy do zaimplementowania listy dwókierunkowej,
 * składa się z atrybutów takich jak początek i koniec listy, posiada
 * kilka metod między innymi wstaiwających i usuwających elementy z
 * konca lub początku.*/

class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int size()const;
    bool Empty()const;
    Node& Front() const;
    Node& Back() const;
    void AddFront(const int numberOfPacket, const std::string dataOfPacket);
    void AddBack(const int numberOfPacket, const std::string dataOfPacket);
    void RemoveFront();
    void RemoveBack();
    void InsertNewNode(Node* nodeAfterInsert, const int numberOfPacket, const std::string dataOfPacket);
    void Earase(Node* elementToRemove);


private:
    Node* HeaderOfList;
    Node* TrailerOfList;
    int NumberOfElementsInList;
};
#endif //PROJEKT1_DOUBLYLINKEDLIST_HPP
