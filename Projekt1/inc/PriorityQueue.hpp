//
// Created by jakub on 02.04.2021.
//
#ifndef PROJEKT1_PRIORITYQUEUE_HPP
#define PROJEKT1_PRIORITYQUEUE_HPP

#include "DoublyLinkedList.hpp"


class ListPriorityQueue{
public:
    int Size() const;
    bool empty() const;
    void Insert(const Node& elementToInsert);
    Node& Min() const;
    void RemoveMin();

private:
    DoublyLinkedList List;
};


#endif //PROJEKT1_PRIORITYQUEUE_HPP
