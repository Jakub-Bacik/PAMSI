cmake_minimum_required(VERSION 3.17)
#ustawienie nazwy projektu
project(Projekt1)

#specyfikacja wersji c++
set(CMAKE_CXX_STANDARD 20)

# pliki źródłowe
set(Sources
        src/main.cpp
        src/DoublyLinkedList.cpp
        src/Node.cpp
        src/PriorityQueue.cpp
        src/Iterator.cpp
        )
#pliki nagłówkowe
set(Headers
        inc/DoublyLinkedList.hpp
        inc/Node.hpp
        inc/PriorityQueue.hpp
        inc/Iterator.hpp)

# dodanie pliku wykonwyalnego składającego się z nagłówków i plików zródłowych
add_executable(Projekt1 ${Sources} ${Headers})
