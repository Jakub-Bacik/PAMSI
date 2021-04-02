//
// Created by jakub on 02.04.2021.
//

#ifndef PROJEKT1_NODE_HPP
#define PROJEKT1_NODE_HPP

#include <iostream>

/*Klasa implementująca elementy takie jak numer pakietu czyli klucz oraz wartość czyli
 * dane pakietu, wskaźnik na poprzedni i następny element listy. W klasie zaimplemenowałem
 * get'tery aby użyć enkapsulacji.*/

struct Packet{
    int NumberOfPacket;
    std::string DataOfPacket;
};

class Node{
private:
    Packet PacketInList;
    Node* NextElementOfList;
    Node* PreviousElementOfList;
public:
    Node();
    Node(int numberOfParcel, std::string dataOfParcel,Node* nextElementOfList,Node* previousElementOfList);
    Packet GetPacketInList() const;
    Node* GetPointerToNextElementOfList() const;
    Node* GetPointerToPreviousElementOfList() const;
    void SetPacketlInList(int numberOfPacket, std::string dataOfPacket);
    void SetPointerToNextElementOfList(Node* nextElementOfList);
    void SetPointerToPreviousElementOfList(Node* previousElementOfList);
    bool operator<(Node& ElementToCompare);
};

std::ostream& operator << (std::ostream &Strm, Node nodeToShow);

#endif //PROJEKT1_NODE_HPP
