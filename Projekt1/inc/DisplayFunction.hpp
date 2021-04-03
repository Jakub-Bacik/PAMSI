#ifndef PROJEKT1_DISPLAYFUNCTION_HPP
#define PROJEKT1_DISPLAYFUNCTION_HPP

#include <iostream>

enum class Operation{Add, Delete};
enum class Action{AddData, TransferTo, Sort, Messeage, End};


//Funkcja odpowiadająca za wyświetlenie komunikatu po dodaniu lub usunięciu elementu z listy
void AddedOrDeletedElementToDoubledLinkedList(int sizeOfDoubledLinkedList, Operation operation);

//Funkcja odpowiadająca za wyświetlenie komunikatu po dodaniu lub usunięciu elementu z kolejki
void AddedOrDeletedElementFromPriorityQueue(int sizeOfDoubledLinkedList, Operation operation);

//Funkcja odpowiadjąca za wyświetlania akcji w głównej funkcji
void ActionInDriver(Action action);

#endif //PROJEKT1_DISPLAYFUNCTION_HPP
