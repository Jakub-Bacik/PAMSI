#ifndef PROJEKT1_NODE_HPP
#define PROJEKT1_NODE_HPP

#include <iostream>

/*Struktur Packet która implementuje pakiet składający się z numeru pakietu i treści pakieru */

struct Packet{
    int NumberOfPacket;
    std::string DataOfPacket;
};

/*Klasa Node implementuje węzeł listy dwukierukowej. Zawiera metody do ustawiania i pobierania
 * danych z klasy, dwa konstruktory oraz zawiera przeciążenie operatora <.
 * atrybuty to wskaźnik do poprzedniego elementu listy i następnego elementu listy oraz
 * sam pakiet który składa się numeru pakietu i treści pakietu.
 *
 * */

class Node{
private:
    Packet PacketInList;
    Node*  NextElementOfList;
    Node*  PreviousElementOfList;
public:
    Node();
    Node(int numberOfPacket, std::string dataOfPacket, Node* nextElementOfList, Node* previousElementOfList);
    Packet GetPacketInList() const;
    Node*  GetPointerToNextElementOfList() const;
    Node*  GetPointerToPreviousElementOfList() const;
    void   SetPacketInList(int numberOfPacket, std::string dataOfPacket);
    void   SetPointerToNextElementOfList(Node* nextElementOfList);
    void   SetPointerToPreviousElementOfList(Node* previousElementOfList);
    bool operator<(Node& ElementToCompare);
};

std::ostream& operator << (std::ostream &Stream, Node nodeToShow);

#endif //PROJEKT1_NODE_HPP
