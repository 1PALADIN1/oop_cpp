#include <iostream>

namespace lesson5 {
    /*
     * 1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
     * Следующий код:

    int main()
    {
        Pair1<int> p1(6, 9);
        cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair1<double> p2(3.4, 7.8);
        cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

        return 0;
    }

    … должен производить результат:
     Pair: 6 9
     Pair: 3.4 7.8
     */

    template <class T>
    class Pair1 {
    private:
        T m_first;
        T m_second;

    public:
        Pair1(T first, T second)
        : m_first(first), m_second(second) {
        }

        T first() const {
            return m_first;
        }

        T second() const {
            return m_second;
        }
    };


    // ================ Тестирование ================

    void pairTest() {
        Pair1<int> p1(6, 9);
        std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair1<double> p2(3.4, 7.8);
        std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }

    void run() {
        std::cout << "====================== LESSON 5 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        pairTest();
    }
}