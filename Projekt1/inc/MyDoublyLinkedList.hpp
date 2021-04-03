//
// Created by jakub on 02.04.2021.
//

#ifndef PROJEKT1_MYDOUBLYLINKEDLIST_HPP
#define PROJEKT1_MYDOUBLYLINKEDLIST_HPP

#include "Node.hpp"
#include "Iterator.hpp"
#include "MyDoublyLinkedList.hpp"
#include <iostream>
#include <time.h>
#include "DisplayFunction.hpp"


/*  DoublyLinkedList służy do zaimplementowania listy dwókierunkowej,
 * składa się z atrybutów takich jak początek i koniec listy, posiada
 * kilka metod między innymi wstawiających i usuwających elementy z
 * konca lub początku.*/

class MyDoublyLinkedList{
public:
    MyDoublyLinkedList();
    int Size()const;
    bool Empty()const;
    Node& Front() const;
    Node& Back() const;
    void AddFront(const int numberOfPacket, const std::string dataOfPacket);
    void AddBack(const int numberOfPacket, const std::string dataOfPacket);
    void RemoveFront();
    void RemoveBack();
    void InsertNewNode(Node* nodeAfterInsert, const int numberOfPacket, const std::string dataOfPacket);
    void Insert(Node* nodeAfterInsert, Node* nodeToInsert);
    void Earase(Node* elementToRemove);

private:
    Node* HeaderOfList;
    Node* TrailerOfList;
    int NumberOfElementsInList=0;
};

std::ostream& operator << (std::ostream &Stream, MyDoublyLinkedList& myDoublyLinkedList);
std::istream& operator >> (std::istream &Stream, MyDoublyLinkedList& myDoublyLinkedList);
bool RandomAddToFromOrBackToDoublyLinkedList();

#endif //PROJEKT1_MYDOUBLYLINKEDLIST_HPP
