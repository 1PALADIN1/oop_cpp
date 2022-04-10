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

    /*
     * 2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
     * Следующий код:

        int main()
        {
            Pair<int, double> p1(6, 7.8);
            cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

            const Pair<double, int> p2(3.4, 5);
            cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

            return 0;
        }

        … должен производить следующий результат:
        Pair: 6 7.8
        Pair: 3.4 5

        Подсказка: чтобы определить шаблон с использованием двух разных типов, просто разделите параметры типа шаблона запятой.
     */

    template <class T, class V>
    class Pair {
    private:
        T m_first;
        V m_second;

    public:
        Pair(T first, V second)
        : m_first(first), m_second(second) {
        }

        T first() const {
            return m_first;
        }

        V second() const {
            return m_second;
        }
    };

    /*
     * 3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
     * Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string,
     * а второй — любого типа данных.
     * Следующий код:

        int main()
        {
            StringValuePair<int> svp("Amazing", 7);
            std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
            return 0;
        }

        … должен производить следующий результат:
        Pair: Amazing 7

        Подсказка: при вызове конструктора класса **Pair* из конструктора класса StringValuePair не забудьте указать,
        что параметры относятся к классу Pair. *
     */

    template<class V>
    class StringValuePair : public Pair<std::string, V> {
    public:
        StringValuePair(std::string first, V second)
        : Pair<std::string, V>(first, second) {
        }
    };


    // ================ Тестирование ================

    void pair1Test() {
        Pair1<int> p1(6, 9);
        std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair1<double> p2(3.4, 7.8);
        std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }

    void pairTest() {
        Pair<int, double> p1(6, 7.8);
        std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair<double, int> p2(3.4, 5);
        std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }

    void stringPairTest() {
        StringValuePair<int> svp("Amazing", 7);
        std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    }

    void run() {
        std::cout << "====================== LESSON 5 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        pair1Test();

        std::cout << std::endl;

        std::cout << "Task 2:" << std::endl;
        pairTest();

        std::cout << std::endl;

        std::cout << "Task 3:" << std::endl;
        stringPairTest();
    }
}