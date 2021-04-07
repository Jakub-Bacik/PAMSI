#include <fstream>
#include <iostream>
#include "../inc/MyDoublyLinkedList.hpp"
#include "../inc/MyPriorityQueue.hpp"
#include <chrono>

int main(){
    //Klasa odpowiedzialna za mierzenie czasu wykonania programu
    std::chrono::time_point<std::chrono::system_clock> begin = std::chrono::system_clock::now();
    auto duration = begin.time_since_epoch(); //zwraca aktualny okres czasu "time span"
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count(); // Pobranie aktualnego okresu
                                                                                      // czasu w sekundach i rzutowanie
    MyPriorityQueue myPriorityQueue;                                                  //na milisekundy
    MyDoublyLinkedList myDoublyLinkedList;
    std::ifstream streamFromFileWithData("../data/loremIpsumAverage.txt");

    MessageActionInDriver(Action::AddData);
    streamFromFileWithData >> myDoublyLinkedList;


    //Teoretyczne wysłanie danych
    MessageActionInDriver(Action::TransferTo);

    MessageActionInDriver(Action::Sort);
    PriorityQueueSort(myDoublyLinkedList, myPriorityQueue);

    MessageActionInDriver(Action::Messeage);
    std::cout << myDoublyLinkedList;

    MessageActionInDriver(Action::End);


    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    auto duration2 = end.time_since_epoch();
    auto millis2 = std::chrono::duration_cast<std::chrono::milliseconds>(duration2).count();
    std::cout<<millis2-millis << " ms";  //różnica między pierwszym i drugim popmiarem - czas trwania programu

    return 0;

}

