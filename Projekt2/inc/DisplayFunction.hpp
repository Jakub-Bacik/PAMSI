#ifndef PROJEKT1_DISPLAYFUNCTION_HPP
#define PROJEKT1_DISPLAYFUNCTION_HPP

#include <iostream>
#include "MyDoublyLinkedList.hpp"
#include "../inc/SortingAlgorithms.hpp"

enum class Action{VerificationOfSorted, MedianOfSorted, MeanAverageOfSorted};

void MessageActionInDriver(MyDoublyLinkedList& myDoublyLinkedList, Action action);
void OperationShowTime(long long int time);

#endif //PROJEKT1_DISPLAYFUNCTION_HPP
