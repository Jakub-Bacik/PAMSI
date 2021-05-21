#include "gtest/gtest.h"

//Plik main() dla testów, uruchamia wszystkie testy.

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
     RUN_ALL_TESTS();
     return 0;
}
