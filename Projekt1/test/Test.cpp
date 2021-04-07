#include "gtest/gtest.h"
#include "../inc/MyDoublyLinkedList.hpp"
#include "../inc/MyPriorityQueue.hpp"
#include "../inc/Node.hpp"
#include "../inc/Iterator.hpp"

/*Testy klasy MyDoublyLinkedList*/

/*Test polega na dodawaniu elementów na końcu listy, sprawdzaniu pierwszego
 * elementu, usuwaniu elementów z początku listy.*/
TEST(MyDLL, addAndRemoveElementsFromBack) {
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(1,"Adam");
    myDoublyLinkedList.AddBack(2, "Marian");
    myDoublyLinkedList.AddBack(3,"Adrian");
    EXPECT_EQ(myDoublyLinkedList.Size(), 3);
    EXPECT_EQ(myDoublyLinkedList.Front().GetPacketInList().NumberOfPacket,1);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Size(), 2);
    EXPECT_EQ(myDoublyLinkedList.Front().GetPacketInList().NumberOfPacket,2);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Size(), 1);
    EXPECT_EQ(myDoublyLinkedList.Front().GetPacketInList().NumberOfPacket,3);
    myDoublyLinkedList.RemoveFront();
    EXPECT_TRUE(myDoublyLinkedList.Empty());

}

/*Test polega na dodawaniu elementów na początku listy, sprawdzaniu pierwszego
 * elementu, usuwaniu elementu z końca listy*/
TEST(MyDLL, addAndRemoveElementsFromFront){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddFront(1,"Adam");
    myDoublyLinkedList.AddFront(2, "Marian");
    myDoublyLinkedList.AddFront(3,"Adrian");
    EXPECT_EQ(myDoublyLinkedList.Size(), 3);
    EXPECT_EQ(myDoublyLinkedList.Front().GetPacketInList().NumberOfPacket,3);
    myDoublyLinkedList.RemoveBack();
    EXPECT_EQ(myDoublyLinkedList.Size(), 2);
    EXPECT_EQ(myDoublyLinkedList.Front().GetPacketInList().NumberOfPacket,3);
    myDoublyLinkedList.RemoveBack();
    EXPECT_EQ(myDoublyLinkedList.Size(), 1);
    EXPECT_EQ(myDoublyLinkedList.Front().GetPacketInList().NumberOfPacket,3);
    myDoublyLinkedList.RemoveBack();
    EXPECT_TRUE(myDoublyLinkedList.Empty());

}

/*Test sprawdzający czy przeciążenie operatora << usunie wszystkie elementy z listy*/
TEST(MyDLL, removeElementsFromStream){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddFront(1,"Adam");
    myDoublyLinkedList.AddFront(2, "Marian");
    myDoublyLinkedList.AddFront(3,"Adrian");
    std::cout << myDoublyLinkedList;
    EXPECT_TRUE(myDoublyLinkedList.Empty());
}

/*Testy klasy MyPriorityQueue*/

/*Test polegający na dodawaniu i odejmowaniu elementów ze struktury kolejki priorytetowej
 * i sprawdzaniu rozmiaru kolejki po usunięciu elementów*/
TEST(MyPQ, addAndRemoveElemntFrom){
    MyPriorityQueue myPriorityQueue;
    myPriorityQueue.Insert(3, "Adam");
    myPriorityQueue.Insert(2, "Adrian");
    myPriorityQueue.Insert(5, "Marian");
    EXPECT_EQ(myPriorityQueue.Min().GetPacketInList().NumberOfPacket, 2);
    EXPECT_EQ(myPriorityQueue.Size(), 3);
    myPriorityQueue.RemoveMin();
    EXPECT_EQ(myPriorityQueue.Min().GetPacketInList().NumberOfPacket, 3);
    EXPECT_EQ(myPriorityQueue.Size(), 2);
    myPriorityQueue.RemoveMin();
    EXPECT_EQ(myPriorityQueue.Min().GetPacketInList().NumberOfPacket, 5);
    EXPECT_EQ(myPriorityQueue.Size(), 1);
    myPriorityQueue.RemoveMin();
    EXPECT_TRUE(myPriorityQueue.Empty());
}

/*Testy klasy Node*/

/*Testuje przeciązenie operatora < wykorzystanego do komparatora*/
TEST(Node, comparator){
    Node firstNode;
    Node secondNode;
    firstNode.SetPacketInList(3, "Adam");
    secondNode.SetPacketInList(5, "Marian");
    EXPECT_GT(secondNode.GetPacketInList().NumberOfPacket,firstNode.GetPacketInList().NumberOfPacket);
}

/*Testuje tworzenie powiązań między elementami Klasy Node*/
TEST(Node, creatorStruct){
    Node firstNode;
    Node secondNode;
    firstNode.SetPointerToNextElementOfList(&secondNode);
    secondNode.SetPointerToPreviousElementOfList(&firstNode);
    EXPECT_EQ(firstNode.GetPointerToNextElementOfList(),&secondNode);
}

/*Testy klasy Iterator*/

/*Testuje działanie metod iteratora*/
TEST(Iterator, createAndWork){
    MyPriorityQueue myPriorityQueue;
    myPriorityQueue.Insert(3, "Adam");
    myPriorityQueue.Insert(2, "Adrian");
    myPriorityQueue.Insert(5, "Marian");
    Iterator firstIterator(&(myPriorityQueue.Min()));
    Iterator secondIterator = firstIterator;
    ++firstIterator;
    EXPECT_EQ((*firstIterator).GetPacketInList().NumberOfPacket, 3);
    EXPECT_TRUE(secondIterator!=firstIterator);
    EXPECT_FALSE(secondIterator == firstIterator);
    --firstIterator;
    EXPECT_TRUE(secondIterator==firstIterator);
    EXPECT_FALSE(secondIterator != firstIterator);

}