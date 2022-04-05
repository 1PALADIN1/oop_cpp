#include <iostream>
#include "ArrayInt.cpp"

namespace lesson4 {

    // ================ Тестирование ================

    void arrayIntTest() {
        ArrayInt arrayInt;
        arrayInt.push_back(100);
        arrayInt.push_back(0);
        arrayInt.push_back(1);
        arrayInt.push_back(200);
        arrayInt.push_back(-11);
        arrayInt.push_back(-154);
        arrayInt.push_back(99);
        arrayInt.push_back(-400);
        std::cout << arrayInt.toString() << std::endl;

        std::cout << "Pop back test:" << std::endl;
        arrayInt.pop_back();
        arrayInt.pop_back();
        std::cout << arrayInt.toString() << std::endl;

        std::cout << "Pop front test:" << std::endl;
        arrayInt.pop_front();
        arrayInt.pop_front();
        std::cout << arrayInt.toString() << std::endl;

        std::cout << "Sort test:" << std::endl;
        arrayInt.push_back(12);
        arrayInt.push_back(-77);
        arrayInt.push_back(404);
        arrayInt.push_back(12);

        std::cout << "Before sort: " << arrayInt.toString() << std::endl;
        arrayInt.sort();
        std::cout << "After sort: " << arrayInt.toString() << std::endl;
    }

    void run() {
        std::cout << "====================== LESSON 4 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        arrayIntTest();
    }
}