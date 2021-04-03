#ifndef PROJEKT1_MYPRIORITYQUEUE_HPP
#define PROJEKT1_MYPRIORITYQUEUE_HPP

#include "MyDoublyLinkedList.hpp"
#include "Iterator.hpp"
#include "DisplayFunction.hpp"

/* Klasa MyPriorityQueue implementuje kolejke priorytetowa opartą na liście dwukierunkowej,
 * zawiery metody sprawdzające liczbe elementów w kolejce, wstawiająca elementy kolejki oraz
 * usuwające elementy z kolejki*/

class MyPriorityQueue{
public:
    int Size() const;
    bool Empty() const;
    Iterator Insert(const int numberOfPacket, const std::string dataOfPacket);
    Node& Min() const;
    void RemoveMin();
    void Remove(const Iterator& elementToRemove);
    bool IsLess(const Iterator& firstIteratorToCompare, const Iterator& secondIteratorToCompare);


private:
    MyDoublyLinkedList ListToImplementPriorityQueue;
};

std::ostream& operator << (std::ostream &Stream, MyPriorityQueue& ListPriorityQueue);
MyDoublyLinkedList PriorityQueueSort(MyDoublyLinkedList &doublyLinkedList, MyPriorityQueue &priorityQueue);

#endif //PROJEKT1_MYPRIORITYQUEUE_HPP
