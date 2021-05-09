#include "../inc/SortingAlgorithms.hpp"

/*
 * Algorytm sortowania szybkiego (QuickSort), polega na technice "Dziel i zwyciężaj".
 * Sortowanie listy dwukierunkowej realizowane jest przy pomocy rekuranecji. Z listy wybierany jest
 * specyficzny element nazywany pivotem najczęsciej jest to ostatni element z nieposortowanej listy.
 * Następnie lista wejściowa jeśli zawiera co najmniej dwa elementy, dzielona jest na
 * trzy listy zawierające odpowiednio: większe, równe oraz mniejsze niż pivot. Następnie
 * rekurencyjnie wywołana jest funkcja QuickSort dla elementów mniejszych i większych
 * niż pivot. Po tym składana jest lista wyjściowa z wcześniej podzielonych list w odpowiedniej
 * kolejnosći, lista zawierająca elementy mniejsze, równe, większe.
 * */
void QuickSort(MyDoublyLinkedList &myDoublyLinkedList){
    if(myDoublyLinkedList.Size() <= 1){
        return;
    }
    Node pivot = myDoublyLinkedList.Back();
    MyDoublyLinkedList myDoublyLinkedListLessThanPivot;
    MyDoublyLinkedList myDoublyLinkedListEqualToPivot;
    MyDoublyLinkedList myDoublyLinkedListGreaterThanPivot;

    while(!myDoublyLinkedList.Empty()) {
        if (myDoublyLinkedList.Back() < pivot) {
            myDoublyLinkedListLessThanPivot.AddBack(myDoublyLinkedList.Back());
            myDoublyLinkedList.RemoveBack();
        } else if (myDoublyLinkedList.Back() == pivot) {
            myDoublyLinkedListEqualToPivot.AddBack(myDoublyLinkedList.Back());
            myDoublyLinkedList.RemoveBack();
        } else {
            myDoublyLinkedListGreaterThanPivot.AddBack(myDoublyLinkedList.Back());
            myDoublyLinkedList.RemoveBack();
        }
    }
    QuickSort(myDoublyLinkedListLessThanPivot);
    QuickSort(myDoublyLinkedListGreaterThanPivot);

    while(!myDoublyLinkedListLessThanPivot.Empty()){
        myDoublyLinkedList.AddBack(myDoublyLinkedListLessThanPivot.Front());
        myDoublyLinkedListLessThanPivot.RemoveFront();
    }

    while(!myDoublyLinkedListEqualToPivot.Empty()){
        myDoublyLinkedList.AddBack(myDoublyLinkedListEqualToPivot.Front());
        myDoublyLinkedListEqualToPivot.RemoveFront();
    }

    while(!myDoublyLinkedListGreaterThanPivot.Empty()){
        myDoublyLinkedList.AddBack(myDoublyLinkedListGreaterThanPivot.Front());
        myDoublyLinkedListGreaterThanPivot.RemoveFront();
    }


}

/* Algorytm sortowania kubełkowego(Bucket Sort) polega na użyciu tablicy list dwukierunkowej,
 * której kolejne indeksy pełną funkcje kubełków. Dla każdego elementu z listy wejściowej pobierany
 * jest numer rankingu, następnie jest on usuwany z listy wejściowej  oraz dodany do tablicy list
 * dwukierunkowej w odpowiednim miejscu, numerze indeksu tablicy zgodnym z numerem rankingu.
 * Następnie zaczynając od indeksu początkowego zwracany jest element po elemencie z listy
 * dwukierunkowej będącą pod odpowiednim indeksem w tablicy, następnie indeks jest zwiększany i następuje
 * to samo.
 * */

void BucketSort(MyDoublyLinkedList &myDoublyLinkedList, int numberOfKey){
    MyDoublyLinkedList arrayOfMyDoubleLinkedList[numberOfKey+1];
    int numberOfElementsInMyDoubleLinkedList = myDoublyLinkedList.Size();
    for(int i=0; i < numberOfElementsInMyDoubleLinkedList; i++){
        Node temporaryNodeForElementFromBackOfMDLL = myDoublyLinkedList.Back();
        myDoublyLinkedList.RemoveBack();
        int numberOfRating = temporaryNodeForElementFromBackOfMDLL.GetMovieAndRatingInList().Rating;
        arrayOfMyDoubleLinkedList[numberOfRating].AddBack(temporaryNodeForElementFromBackOfMDLL);
    }

    for(int i=0; i < numberOfKey+1; i++){
        while(!arrayOfMyDoubleLinkedList[i].Empty()){
            Node temporaryNodeForElementFromFrontOfArray = arrayOfMyDoubleLinkedList[i].Front();
            arrayOfMyDoubleLinkedList[i].RemoveFront();
            myDoublyLinkedList.AddBack(temporaryNodeForElementFromFrontOfArray);
        }
    }


}


/* Algorytm sortowania szybkiego (QuickSort), polega na technice "Dziel i zwyciężaj".
 * Sortowanie listy dwukierunkowej realizowane jest przy pomocy rekuranecji. Jeśli
 * lista wejściowa jest większa niż dwa elementy to lista wejściowa dzielona jest
 * na dwie listy dwukierunkowe. Po czym następuje reukrencyjne wywołanie funkcji MergeSort
 * aż do uzyskania, listy składającej się z dwóch elementów. Następnie listy przekazane są
 * do funkcji Merge która łaczy listy w liste wyjściową.
 * */
void MergeSort(MyDoublyLinkedList &myDoublyLinkedList){
    int sizeOfMyDoublyLinkedList = myDoublyLinkedList.Size();

    if(sizeOfMyDoublyLinkedList <= 1)
        return;

    MyDoublyLinkedList myDoublyLinkedListFirstPart;
    MyDoublyLinkedList myDoublyLinkedListSecondPart;

    for(int i=0; i < sizeOfMyDoublyLinkedList/2; i++){
        myDoublyLinkedListFirstPart.AddBack(myDoublyLinkedList.Front());
        myDoublyLinkedList.RemoveFront();
    }

    for(int i=sizeOfMyDoublyLinkedList/2; i < sizeOfMyDoublyLinkedList; i++){
        myDoublyLinkedListSecondPart.AddBack(myDoublyLinkedList.Front());
        myDoublyLinkedList.RemoveFront();
    }

    MergeSort(myDoublyLinkedListFirstPart);
    MergeSort(myDoublyLinkedListSecondPart);
    Merge(myDoublyLinkedListFirstPart, myDoublyLinkedListSecondPart, myDoublyLinkedList);

}

/*Funkcja odpowiedzialna za połaczenie list dwukierunkowych. Polega na porównaniu klucza oraz dodaniu do
 * wyjściowej listy swukierunkowej w odpowiedni sposób.*/

void Merge(MyDoublyLinkedList &myDoublyLinkedListFirstPart, MyDoublyLinkedList &myDoublyLinkedListSecondPart,
           MyDoublyLinkedList &myDoublyLinkedList){

    while(!myDoublyLinkedListFirstPart.Empty() && !myDoublyLinkedListSecondPart.Empty()){
        if(myDoublyLinkedListFirstPart.Front() < myDoublyLinkedListSecondPart.Front()){
            myDoublyLinkedList.AddBack(myDoublyLinkedListFirstPart.Front());
            myDoublyLinkedListFirstPart.RemoveFront();
        }else{
            myDoublyLinkedList.AddBack(myDoublyLinkedListSecondPart.Front());
            myDoublyLinkedListSecondPart.RemoveFront();
        }
    }
    while(!myDoublyLinkedListFirstPart.Empty()){
        myDoublyLinkedList.AddBack(myDoublyLinkedListFirstPart.Front());
        myDoublyLinkedListFirstPart.RemoveFront();
    }

    while(!myDoublyLinkedListSecondPart.Empty()){
        myDoublyLinkedList.AddBack(myDoublyLinkedListSecondPart.Front());
        myDoublyLinkedListSecondPart.RemoveFront();
    }
}

//Funkcja odpowiedzialna za weryfikacje poprawności przeprowadzonego sortowania
bool VerificationOfSortedMyDoublyLinkedList(MyDoublyLinkedList& myDoublyLinkedList, int amountNodeToShow){
    Iterator myIteratorAfterMDLL(&myDoublyLinkedList.Front());

    int firstRatingOfSortedMDLL = myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating;

    for(int i = 0; i< myDoublyLinkedList.Size(); i++){
        if(firstRatingOfSortedMDLL > (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating){
            return false;
        }

        if(firstRatingOfSortedMDLL < (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating){
            firstRatingOfSortedMDLL = (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating;
        }


        if(myDoublyLinkedList.Size() < amountNodeToShow){
            std::cout << (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating << std::endl;
        }
        ++myIteratorAfterMDLL;
    }

    return true;

}

//Funkcja odpowiedzialna za obliczenie mediany rankigu posortowanej listy dwukierunkowej
double MedianOfSortedMyDoublyLinkedList(MyDoublyLinkedList& myDoublyLinkedList){
    double Median=0;
    double temporaryFirstNumber=0;
    double temporarySecondNumber=0;

    Iterator myIteratorAfterMDLL(&myDoublyLinkedList.Front());
    if(myDoublyLinkedList.Size() % 2 ==0){
        for(int i = 0; i<= myDoublyLinkedList.Size()/2; i++){
            if(i==myDoublyLinkedList.Size()/2-1) {
                temporaryFirstNumber = (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating;
            }
            if(i==myDoublyLinkedList.Size()/2) {
                temporarySecondNumber = (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating;
            }
            ++myIteratorAfterMDLL;
        }
        Median = (temporaryFirstNumber + temporarySecondNumber)/2;
    }else{
        for(int i = 0; i<= myDoublyLinkedList.Size()/2; i++){
            Median = (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating;
            ++myIteratorAfterMDLL;
        }
    }

    return Median;
}

//Funkcja odpowiedzialna za obliczenie wartości średniej rankingu posortowanej listy dwukierunkowej
double MeanAverageOfSortedDoublyLinkedList(MyDoublyLinkedList& myDoublyLinkedList){
    double MeanAverage=0;
    double SumOfRating=0;

    Iterator myIteratorAfterMDLL(&myDoublyLinkedList.Front());

    for(int i = 0; i< myDoublyLinkedList.Size(); i++){
        SumOfRating += (*myIteratorAfterMDLL).GetMovieAndRatingInList().Rating;
        ++myIteratorAfterMDLL;
    }
    MeanAverage = SumOfRating/myDoublyLinkedList.Size();

    return MeanAverage;

}
