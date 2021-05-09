#ifndef PROJEKT2_SORTINGALGORITHMS_HPP
#define PROJEKT2_SORTINGALGORITHMS_HPP

#include "MyDoublyLinkedList.hpp"

void QuickSort(MyDoublyLinkedList &myDoublyLinkedList);
void BucketSort(MyDoublyLinkedList &myDoublyLinkedList, int numberOfKey = 10);
void MergeSort(MyDoublyLinkedList &myDoublyLinkedList);
void Merge(MyDoublyLinkedList &myDoublyLinkedListFirstPart, MyDoublyLinkedList &myDoublyLinkedListFirstSecond,
           MyDoublyLinkedList &myDoublyLinkedList);

bool VerificationOfSortedMyDoublyLinkedList(MyDoublyLinkedList& myDoublyLinkedList, int amountNodeToShow=10);
double MedianOfSortedMyDoublyLinkedList(MyDoublyLinkedList& myDoublyLinkedList);
double MeanAverageOfSortedDoublyLinkedList(MyDoublyLinkedList& myDoublyLinkedList);

#endif //PROJEKT2_SORTINGALGORITHMS_HPP
