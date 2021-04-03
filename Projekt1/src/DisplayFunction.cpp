#include "../inc/DisplayFunction.hpp"
#include <random>

void AddedOrDeletedElementToDoubledLinkedList(int sizeOfDoubledLinkedList, Operation operation){
    switch (operation) {
        case Operation::Add:
            std:: cout << "-----------------------------------------------------"<< std::endl
                       << "Zostal dodany element do listy dwukierunkowej." << std::endl
                       << "Aktualny rozmiar listy dwukierunkowej wynosi:    " << sizeOfDoubledLinkedList << std::endl;
            break;
        case Operation::Delete:
            std:: cout << "-----------------------------------------------------"<< std::endl
                       << "Zostal usuniety element z listy dwukierunkowej." << std::endl
                       << "Aktualny rozmiar listy dwukierunkowej wynosi:    " << sizeOfDoubledLinkedList << std::endl;

            break;
    }
}

void AddedOrDeletedElementFromPriorityQueue(int sizeOfDoubledLinkedList, Operation operation) {
    switch (operation) {
        case Operation::Add:
            std::cout << "-----------------------------------------------------"
                      << std::endl
                      << "Zostal dodany element do kolejki prioryterowej." << std::endl
                      << "Aktualny rozmiar kolejki prioryterowej wynosi:    " << sizeOfDoubledLinkedList << std::endl;
            break;
        case Operation::Delete:
            std::cout << "-----------------------------------------------------"
                      << std::endl
                      << "Zostal usuniety element z kolejki prioryterowej." << std::endl
                      << "Aktualny rozmiar kolejki prioryterowej wynosi:    " << sizeOfDoubledLinkedList << std::endl;

            break;
    }
}

void ActionInDriver(Action action){
    switch (action) {
        case Action::AddData:
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
                      << "%     DODANIE DANYCH Z ZEWNETRZNEGO STRUMIENIA      %" << std::endl
                      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;

            break;
        case Action::TransferTo:
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
                      << "%            TEORETYCZNY TRANSFER DANYCH            %" << std::endl
                      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
            break;
        case Action::Sort:
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
                      << "% SORTOWANIE Z ZASOTOSWANIEM KOLEJKI PRIORYTETOWEJ  %" << std::endl
                      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
            break;
        case Action::Messeage:
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
                      << "%              OTRZYMANA WIADOMOSC                  %" << std::endl
                      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
                      << std::endl <<std::endl;
            break;
        case Action::End:
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
                      << "%                      KONIEC                       %" << std::endl
                      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
            break;

    }
}