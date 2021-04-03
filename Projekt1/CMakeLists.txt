cmake_minimum_required(VERSION 3.17)
#ustawienie nazwy projektu
project(Projekt1)

#specyfikacja wersji C++
set(CMAKE_CXX_STANDARD 20)

# pliki źródłowe
set(Sources
        src/main.cpp
        src/MyDoublyLinkedList.cpp
        src/Node.cpp
        src/MyPriorityQueue.cpp
        src/Iterator.cpp
        src/DisplayFunction.cpp
        )

#pliki nagłówkowe
set(Headers
        inc/MyDoublyLinkedList.hpp
        inc/Node.hpp
        inc/MyPriorityQueue.hpp
        inc/Iterator.hpp
        inc/DisplayFunction.hpp
        )

# dodanie pliku wykonwyalnego składającego się z nagłówków i plików zródłowych
add_executable(Projekt1 ${Sources} ${Headers})
