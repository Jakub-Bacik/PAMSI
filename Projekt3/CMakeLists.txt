cmake_minimum_required(VERSION 3.17)
#ustawienie nazwy projektu
project(Projekt2)

#specyfikacja wersji C++
set(CMAKE_CXX_STANDARD 20)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
enable_testing()

# pliki źródłowe
set(Sources
        src/GameLogic.cpp
        src/Matrix.cpp
        )

#pliki nagłówkowe
set(Headers
        inc/GameLogic.hpp
        inc/Matrix.hpp
        )

set(TestSources
        test/MainTest.cpp
        test/Test.cpp)

add_subdirectory(lib/googletest-master)

# dodanie pliku wykonwyalnego składającego się z nagłówków i plików zródłowych
add_executable(Projekt1_run ${Sources} ${Headers} src/main.cpp)

#konfiguracja dla testów
add_executable(unit-test ${TestSources} ${Sources} ${Headers})
target_link_libraries(unit-test gtest gtest_main)



