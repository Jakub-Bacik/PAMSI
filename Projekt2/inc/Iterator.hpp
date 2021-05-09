#ifndef PROJEKT1_ITERATOR_HPP
#define PROJEKT1_ITERATOR_HPP

#include "Node.hpp"

/*Klasa Iterator implementująca iterator, którego można używać podobnie do wskaznika,
 * posiada przeciązenie operatora wyłuskania, równości, nierównosci, preinkrementacji i
 * predekrementacji. Atrybut to wskażnik do przekazanego węzła*/

class Iterator{
public:
    Node& operator*()const;
    bool operator==(const Iterator& positionOfElement) const;
    bool operator!=(const Iterator& positionOfElement)const;
    Iterator& operator++();
    Iterator& operator--();
    Iterator(Node* createFromNode);
    Iterator();

private:
    Node* pointerToTheNode;

};
#endif //PROJEKT1_ITERATOR_HPP
