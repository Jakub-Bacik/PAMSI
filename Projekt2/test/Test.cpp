#include "gtest/gtest.h"
#include "../inc/MyDoublyLinkedList.hpp"
#include "../inc/Node.hpp"
#include "../inc/Iterator.hpp"
#include "../inc/SortingAlgorithms.hpp"

/*Testy klasy MyDoublyLinkedList*/

/*Test polega na dodawaniu elementów na końcu listy, sprawdzaniu pierwszego
 * elementu, usuwaniu elementów z początku listy.*/
TEST(MyDLL, addAndRemoveElementsFromBack) {
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(1,"Adam");
    myDoublyLinkedList.AddBack(2, "Marian");
    myDoublyLinkedList.AddBack(3,"Adrian");
    EXPECT_EQ(myDoublyLinkedList.Size(), 3);
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating,1);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Size(), 2);
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating,2);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Size(), 1);
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating,3);
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
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating,3);
    myDoublyLinkedList.RemoveBack();
    EXPECT_EQ(myDoublyLinkedList.Size(), 2);
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating,3);
    myDoublyLinkedList.RemoveBack();
    EXPECT_EQ(myDoublyLinkedList.Size(), 1);
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating,3);
    myDoublyLinkedList.RemoveBack();
    EXPECT_TRUE(myDoublyLinkedList.Empty());

}

/*Test sprawdzeniający poprawność filtracji danych wejściowych, poprzez podzielenie
 * string'a na tytuł filmu i numer rankingu*/
TEST(MyDLL, inputDataFiltering){
    std::string temporaryStringToOTheEntireLine = "20, Game Of Throne, 8.0";
    std::string temporaryStringToFilmRating;
    std::string temporaryStringToMovieTitle;
    InputDataFiltering(temporaryStringToOTheEntireLine, temporaryStringToMovieTitle, temporaryStringToFilmRating);

    EXPECT_EQ(temporaryStringToFilmRating, " 8.0");
    EXPECT_EQ(temporaryStringToMovieTitle, " Game Of Throne");

}

/* Test sprawdzajacy poprawność obliczania mediany numeru rankingu w posortowanej liście dwukierunkowej */
TEST(MyDLL, medianOfSortedMyDLL){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddFront(1,"Adam");
    myDoublyLinkedList.AddFront(2, "Marian");
    myDoublyLinkedList.AddFront(6,"Adrian");

    EXPECT_EQ(MedianOfSortedMyDoublyLinkedList(myDoublyLinkedList), 2);
}
/* Test sprawdzajacy poprawność obliczania średniej numeru rankingu w posorowanej liście dwukierunkowej */
TEST(MyDLL, meanAverageOfSortedMyDLL){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddFront(1,"Adam");
    myDoublyLinkedList.AddFront(2, "Marian");
    myDoublyLinkedList.AddFront(6,"Adrian");

    EXPECT_EQ(MeanAverageOfSortedDoublyLinkedList(myDoublyLinkedList), 3);
}


/* Test polegający na sprawdzeniu poprawności sortowania listy dwukierunkowej */
TEST(MyDLL, verificationOfSortedMyDLL){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(1,"Adam");
    myDoublyLinkedList.AddBack(2, "Marian");
    myDoublyLinkedList.AddBack(6,"Adrian");

    EXPECT_TRUE(VerificationOfSortedMyDoublyLinkedList(myDoublyLinkedList));
    myDoublyLinkedList.AddFront(3,"Adrian");
    EXPECT_FALSE(VerificationOfSortedMyDoublyLinkedList(myDoublyLinkedList));
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


/*Testy klasy Node*/

/*Testuje przeciązenie operatora < wykorzystanego do komparatora*/
TEST(Node, comparator){
    Node firstNode;
    Node secondNode;
    firstNode.SetMovieAndRatingInList(3, "Adam");
    secondNode.SetMovieAndRatingInList(5, "Marian");
    EXPECT_GT(secondNode.GetMovieAndRatingInList().Rating, firstNode.GetMovieAndRatingInList().Rating);
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

/*Tests sprwadzający działanie metod iteratora*/
TEST(Iterator, createAndWork){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(3, "Adam");
    myDoublyLinkedList.AddBack(2, "Adrian");
    myDoublyLinkedList.AddBack(5, "Marian");

    Iterator firstIterator(&(myDoublyLinkedList.Front()));
    Iterator secondIterator = firstIterator;
    ++firstIterator;
    EXPECT_EQ((*firstIterator).GetMovieAndRatingInList().Rating, 2);
    EXPECT_TRUE(secondIterator!=firstIterator);
    EXPECT_FALSE(secondIterator == firstIterator);
    --firstIterator;
    EXPECT_TRUE(secondIterator==firstIterator);
    EXPECT_FALSE(secondIterator != firstIterator);

}

/*Test algorytmu QuickSort (Sortowanie szybkie), sprawdzenie poprawności sortoania elementów w liście
 * dwukierunkowej*/
TEST(QuickSort, checkingTheCorrectnessOfSorting){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(3, "Adam");
    myDoublyLinkedList.AddBack(2, "Adrian");
    myDoublyLinkedList.AddBack(5, "Marian");

    QuickSort(myDoublyLinkedList);

    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 2);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 3);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 5);
    myDoublyLinkedList.RemoveFront();
}


/*Test algorytmu BucketSort (Sortowanie kubełkowe), sprawdzenie poprawności sortoania elementów w liście
 * dwukierunkowej */
TEST(BucketSort, checkingTheCorrectnessOfSorting){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(3, "Adam");
    myDoublyLinkedList.AddBack(2, "Adrian");
    myDoublyLinkedList.AddBack(5, "Marian");

    BucketSort(myDoublyLinkedList);

    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 2);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 3);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 5);
    myDoublyLinkedList.RemoveFront();
}

/*Test algorytmu MergeSort (Sortowanie przez scalanie), sprawdzenie poprawności sortoania elementów w liście
 * dwukierunkowej */
TEST(MergeSort, checkingTheCorrectnessOfSorting){
    MyDoublyLinkedList myDoublyLinkedList;
    myDoublyLinkedList.AddBack(3, "Adam");
    myDoublyLinkedList.AddBack(2, "Adrian");
    myDoublyLinkedList.AddBack(5, "Marian");

    MergeSort(myDoublyLinkedList);

    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 2);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 3);
    myDoublyLinkedList.RemoveFront();
    EXPECT_EQ(myDoublyLinkedList.Front().GetMovieAndRatingInList().Rating, 5);
    myDoublyLinkedList.RemoveFront();
}