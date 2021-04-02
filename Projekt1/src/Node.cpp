//
// Created by jakub on 02.04.2021.
//

#include "../inc/Node.hpp"

/*Implementacja konstruktora domyślnego*/
Node::Node(): NextElementOfList{nullptr}, PreviousElementOfList{nullptr}{
    PacketInList.DataOfPacket = "";
    PacketInList.NumberOfPacket= 0;
}

/*Implementacja konstruktora dodatkowego*/
Node::Node(int numberOfPacket, std::string dataOfPacket,Node* nextElementOfList,Node* previousElementOfList):
            NextElementOfList{nextElementOfList},PreviousElementOfList{previousElementOfList} {
    PacketInList.DataOfPacket = dataOfPacket;
    PacketInList.NumberOfPacket = numberOfPacket;
}

/*Metoda zwracająca pakiet*/
Packet Node::GetPacketInList() const{
    return PacketInList;
}

/*Metoda zwracajaca wskaźnik na następny element*/
Node *Node::GetPointerToNextElementOfList() const {
    return NextElementOfList;
}

/*Metoda zwracająca wskaźnik na poprzedni element*/
Node *Node::GetPointerToPreviousElementOfList() const{
    return PreviousElementOfList;
}


/*Metoda ustawiająca numer pakietu*/
void Node::SetPacketlInList(int numberOfPacket, std::string dataOfPacket){
    PacketInList.DataOfPacket = dataOfPacket;
    PacketInList.NumberOfPacket = numberOfPacket;
}


/*Metoda ustawiająca wskaźnik na następny element*/
void Node::SetPointerToNextElementOfList(Node* pointerToNextElement) {
    NextElementOfList = pointerToNextElement;
}

/*Metoda ustawiająca wskaźnik na poprzedni element*/
void Node::SetPointerToPreviousElementOfList(Node* pointerToPreviousElement) {
    PreviousElementOfList=pointerToPreviousElement;
}

bool Node::operator<(Node &ElementToCompare) {
    return GetPacketInList().NumberOfPacket < ElementToCompare.GetPacketInList().NumberOfPacket;
}

std::ostream& operator << (std::ostream &Strm, Node nodeToShow){
    Strm << nodeToShow.GetPacketInList().NumberOfPacket << "|" << nodeToShow.GetPacketInList().DataOfPacket << std::endl;
    return Strm;
}