#include <fstream>
#include <chrono>
#include "../inc/MyDoublyLinkedList.hpp"
#include "../inc/SortingAlgorithms.hpp"
#include "../inc/DisplayFunction.hpp"


int main(){
    //Klasa odpowiedzialna za mierzenie czasu wykonania programu
    std::chrono::time_point<std::chrono::system_clock> begin = std::chrono::system_clock::now();
    auto duration = begin.time_since_epoch(); //zwraca aktualny okres czasu "time span"
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count(); // Pobranie aktualnego okresu
                                                                                           // czasu w sekundach i rzutowanie
                                                                                           // na milisekundy

    MyDoublyLinkedList myDoublyLinkedList;
    std::ifstream streamFromFileWithData("../data/projekt2_dane.csv");

    Read(streamFromFileWithData, myDoublyLinkedList, 1000000);
    MergeSort(myDoublyLinkedList);
    MessageActionInDriver(myDoublyLinkedList, Action::VerificationOfSorted);
    MessageActionInDriver(myDoublyLinkedList, Action::MedianOfSorted);
    MessageActionInDriver(myDoublyLinkedList, Action::MeanAverageOfSorted);
    myDoublyLinkedList.Clear();

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    auto duration2 = end.time_since_epoch();
    auto millis2 = std::chrono::duration_cast<std::chrono::milliseconds>(duration2).count();
    OperationShowTime(millis2-millis); //różnica między pierwszym i drugim popmiarem - czas trwania program

    return 0;

}

