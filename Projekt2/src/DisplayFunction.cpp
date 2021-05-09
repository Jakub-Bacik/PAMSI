#include "../inc/DisplayFunction.hpp"

/*Funkcja odpowiadjąca za wyświetlanie mediany rankingu posortowanej listy, średnią arytmetyczną rankingu,
 * oraz weryfikacje posortowania.*/
void MessageActionInDriver(MyDoublyLinkedList& myDoublyLinkedList, Action action){
    switch (action) {
        case Action::VerificationOfSorted:
            if(VerificationOfSortedMyDoublyLinkedList(myDoublyLinkedList)){
                std::cout << "---------------------------------------------------" << std::endl
                          << "|     Lista zostala posortowana poprawnie          |" << std::endl
                          << "---------------------------------------------------" << std::endl;
            }else{
                std::cout << "---------------------------------------------------" << std::endl
                          << "|    Lista zostala posortowana niepoprawnie        |" << std::endl
                          << "---------------------------------------------------" << std::endl;
            }
            break;

        case Action::MedianOfSorted:
            std::cout << "---------------------------------------------------" << std::endl;
            std::cout << "|";
            std::cout.width(40);
            std::cout << std::internal<< "Mediana rankigu posortowanej listy: ";
            std::cout.width(10);
            std::cout << std::left<< MedianOfSortedMyDoublyLinkedList(myDoublyLinkedList) ;
            std::cout << "|" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
            break;

        case Action::MeanAverageOfSorted:
            std::cout << "---------------------------------------------------" << std::endl;
            std::cout << "|";
            std::cout.width(40);
            std::cout << std::internal<< "Srednia rankingu posortowanej listy: ";
            std::cout.width(10);
            std::cout << std::left<< MeanAverageOfSortedDoublyLinkedList(myDoublyLinkedList) ;
            std::cout << "|" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
            break;
    }
}

//Funkcja odpowiedzialna za formatowanie sposobu wyświetlenia czasu
void OperationShowTime(long long int time){
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "|";
    std::cout.width(30);
    std::cout << std::internal<< "Czas programu wynosi: ";
    std::cout.width(15);
    std::cout << std::left<< time;
    std::cout.width(5);
    std::cout << std::left<< "ms";
    std::cout << "|" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}