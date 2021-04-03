#include <fstream>
#include <iostream>
#include "../inc/MyDoublyLinkedList.hpp"
#include "../inc/MyPriorityQueue.hpp"

int main(){

    MyPriorityQueue myPriorityQueue;
    MyDoublyLinkedList myDoublyLinkedList;
    std::ifstream streamFromFileWithData("../data/loremIpsumSmall.txt");

    ActionInDriver(Action::AddData);
    streamFromFileWithData >> myDoublyLinkedList;


    //Teoretyczne wysłanie danych
    ActionInDriver(Action::TransferTo);

    ActionInDriver(Action::Sort);
    PriorityQueueSort(myDoublyLinkedList, myPriorityQueue);

    ActionInDriver(Action::Messeage);
    std::cout << myDoublyLinkedList;

    ActionInDriver(Action::End);

}

