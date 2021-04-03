#include "../inc/MyPriorityQueue.hpp"

//Metoda zwracająca aktualną liczbe elementów w kolejce
int MyPriorityQueue::Size() const {
    return ListToImplementPriorityQueue.Size();
}


//Metoda implementująca sprawdzenie czy kolejka jest pusta
bool MyPriorityQueue::Empty() const {
    return ListToImplementPriorityQueue.Empty();
}

//Metoda implementująca wstawiania elementu
Iterator MyPriorityQueue::Insert(const int numberOfPacket, const std::string dataOfPacket) {
    Node* elementToInsert = new Node(numberOfPacket,dataOfPacket, nullptr, nullptr);
    Iterator beginOfPriorityQueue(&ListToImplementPriorityQueue.Front());
    Iterator endOfPriorityQueue(&ListToImplementPriorityQueue.Back());

    while(beginOfPriorityQueue != endOfPriorityQueue && !IsLess(elementToInsert, beginOfPriorityQueue)){
        ++beginOfPriorityQueue;
    }
    ListToImplementPriorityQueue.Insert(&(*beginOfPriorityQueue), &(*elementToInsert));

    Iterator iteratorOfPositionInsertElement;
    iteratorOfPositionInsertElement = --beginOfPriorityQueue;

    AddedOrDeletedElementFromPriorityQueue(Size(),Operation::Add);

    return iteratorOfPositionInsertElement;

}


//Metoda zwracająca element o najmniejszej wartości klucza
Node &MyPriorityQueue::Min() const {
    return ListToImplementPriorityQueue.Front();
}


//Metoda usuwająca element o najmniejszej wartości klucza
void MyPriorityQueue::RemoveMin() {
    if (!Empty()){
        ListToImplementPriorityQueue.RemoveFront();
        AddedOrDeletedElementFromPriorityQueue(Size(),Operation::Delete);
    }
    else{
        std::cerr << "Pusta Kolejka Priorytetowa" <<std::endl;
    }

}


//Metoda usuwająca wybrany element z kolejki
void MyPriorityQueue::Remove( const Iterator &elementToRemove) {
    if(!Empty()) {
        ListToImplementPriorityQueue.Earase(&(*elementToRemove));
        AddedOrDeletedElementFromPriorityQueue(Size(),Operation::Delete);
    }
}


//Metoda sprawdzająca który element jest mniejszy
bool MyPriorityQueue::IsLess(const Iterator &firstIteratorToCompare, const Iterator &secondIteratorToCompare) {
    return (&(*firstIteratorToCompare))->GetPacketInList().NumberOfPacket < (&(*secondIteratorToCompare))->GetPacketInList().NumberOfPacket;
}


//Metoda sortująca elementy za pomocą kolejki priorytetowej
MyDoublyLinkedList PriorityQueueSort(MyDoublyLinkedList &myDoublyLinkedList, MyPriorityQueue &myPriorityQueue){

    while (!myDoublyLinkedList.Empty()){
        Node temporaryNode = myDoublyLinkedList.Front();
        myPriorityQueue.Insert(temporaryNode.GetPacketInList().NumberOfPacket, temporaryNode.GetPacketInList().DataOfPacket);
        myDoublyLinkedList.RemoveFront();
    }
    while (!myPriorityQueue.Empty()){
        Node temporaryNode = myPriorityQueue.Min();
        myDoublyLinkedList.AddBack(temporaryNode.GetPacketInList().NumberOfPacket, temporaryNode.GetPacketInList().DataOfPacket);
        myPriorityQueue.RemoveMin();
    }
    return myDoublyLinkedList;
}


//Przeciazenie operatora << umożliwiające wyświetlenie elementów znajdujących sie na liście oraz usuwanie ich niej
std::ostream& operator << (std::ostream &Stream, MyPriorityQueue& myPriorityQueue){
    while (!myPriorityQueue.Empty()){
        Stream << myPriorityQueue.Min();
        myPriorityQueue.RemoveMin();
    }

    return Stream;
}

