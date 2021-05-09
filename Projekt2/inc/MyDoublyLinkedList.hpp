//
// Created by jakub on 02.04.2021.
//

#ifndef PROJEKT1_MYDOUBLYLINKEDLIST_HPP
#define PROJEKT1_MYDOUBLYLINKEDLIST_HPP

#include "Node.hpp"
#include "Iterator.hpp"
#include "MyDoublyLinkedList.hpp"
#include <iostream>
#include <string>
#include <time.h>


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
    void AddFront(const int rating, const std::string movieTittle);
    void AddBack(const int rating, const std::string movieTittle);
    void AddFront(const Node nodeOfData);
    void AddBack(const Node nodeOfData);
    void RemoveFront();
    void RemoveBack();
    void InsertNewNode(Node* nodeAfterInsert, const int rating, const std::string movieTittle);
    void Insert(Node* nodeAfterInsert, Node* nodeToInsert);
    void Erase(Node* elementToRemove);
    void Clear();

private:
    Node* HeaderOfList;
    Node* TrailerOfList;
    int NumberOfElementsInList=0;
};

std::ostream& operator << (std::ostream &Stream, MyDoublyLinkedList& myDoublyLinkedList);

void Read(std::istream &streamFromFile, MyDoublyLinkedList& myDoublyLinkedList, int rating);
void InputDataFiltering(std::string &temporaryStringToOTheEntireLine, std::string &temporaryStringToMovieTitle, std::string &temporaryStringToFilmRating);
void StringCleaner(std::string &temporaryStringToOTheEntireLine, std::string &temporaryStringToMovieTitle, std::string &temporaryStringToFilmRating);


#endif //PROJEKT1_MYDOUBLYLINKEDLIST_HPP
