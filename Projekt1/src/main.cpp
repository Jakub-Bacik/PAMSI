//
// Created by jakub on 24.03.2021.
//

#include <iostream>
#include "../inc/DoublyLinkedList.hpp"
#include "../inc/Node.hpp"
#include "../inc/PriorityQueue.hpp"
#include "../inc/Iterator.hpp"

int main(){
    DoublyLinkedList doublyLinkedList;
    doublyLinkedList.AddFront(6, "HEJ");
    doublyLinkedList.AddFront(6,"dcfhgjbk");
    doublyLinkedList.AddFront(6,"111111");
    doublyLinkedList.AddFront(6,"22222");
    doublyLinkedList.AddFront(6,"4444");
    doublyLinkedList.AddFront(6,"dc666bk");
    doublyLinkedList.AddFront(6,"d888gjbk");
    doublyLinkedList.AddBack(6,"dc00-0bk");


    Iterator iterator(&doublyLinkedList.Front());
    Iterator end(&doublyLinkedList.Back());
    for (auto it = iterator; it != end; ++it) {
            std::cout << *it;
    }

}

