#include <vector>
#include <unordered_map>
#include <iostream>
#include "ArrayInt.cpp"

namespace lesson4 {

    /*
     * 2. Дан вектор чисел, требуется выяснить, сколько среди них различных.
     * Постараться использовать максимально быстрый алгоритм.
     */
    void printVector(std::vector<int> &v) {
        for (int i : v)
            std::cout << i << ' ';
        std::cout << std::endl;
    }

    void findFreqNumbers(std::vector<int> &v) {
        std::cout << "Input vector: ";
        printVector(v);

        std::unordered_map<int, int> m;

        for (int i : v) {
            if (m.find(i) == m.end()) {
                //первый раз встречам число
                std::pair<int, int> new_pair(i, 1);
                m.insert(new_pair);
                continue;
            }

            m[i]++;
        }

        std::cout << "Result:" << std::endl;
        for (std::pair<int, int> p: m) {
            std::cout << p.first << ": " << p.second << std::endl;
        }
    }

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

    void findFreqNumbersTest() {
        std::vector<int> array { 0, 1, 2, 3, 2, 3, 0, -4, 5, 200, 1, 23, 1, 1, 0, -4, 55 };
        findFreqNumbers(array);
    }

    void run() {
        std::cout << "====================== LESSON 4 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        arrayIntTest();

        std::cout << "Task 2:" << std::endl;
        findFreqNumbersTest();
    }
}