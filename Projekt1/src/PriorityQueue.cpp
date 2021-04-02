//
// Created by jakub on 02.04.2021.
//
#include "../inc/PriorityQueue.hpp"

int ListPriorityQueue::Size() const {
    List.size();
}

bool ListPriorityQueue::empty() const {
    return List.Empty();
}

void ListPriorityQueue::Insert(const Node &elementToInsert) {

}

Node &ListPriorityQueue::Min() const {
    return List.Front();
}

void ListPriorityQueue::RemoveMin() {
    List.RemoveFront();
}

