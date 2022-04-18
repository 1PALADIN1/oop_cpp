#include <iostream>

namespace lesson8 {

    /*
     * 1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров
     * и запускать исключение DivisionByZero, если второй параметр равен 0. В функции main выводить результат
     * вызова функции div в консоль, а также ловить исключения.
     */

    class DivisionByZero : public std::logic_error {
    public:
        DivisionByZero() : std::logic_error("Division by 0 is not allowed!") { }

        const char* what() const noexcept override {
            return std::logic_error::what();
        }
    };

    template<class T>
    T div(T a, T b) {
        if (b == 0) {
            throw DivisionByZero();
        }

        return a / b;
    }

    /*
     * 2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу,
     * инициализирующий x значением параметра. Написать класс Bar, хранящий вещественное число y
     * (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
     * Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a.
     * В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
     * Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0.
     * В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
     */

    class Ex : public std::logic_error {
    private:
        float x;

    public:
        Ex(const float x) : std::logic_error("Error!") {
            this->x = x;
        }

        float getX() const {
            return x;
        }

        const char* what() const noexcept override {
            return std::logic_error::what();
        }
    };

    class Bar {
    private:
        float y;

    public:
        Bar() {
            y = 0.0f;
        }

        void set(float a) {
            if (y + a > 100) {
                throw Ex(a*y);
            }

            y = a;
        }
    };

    // ================ Тестирование ================

    void divTest() {
        try {
            std::cout << "Catch int:" << std::endl;
            div(1, 0);
        } catch (const DivisionByZero& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << "Catch float:" << std::endl;
            div(1.0f, 0.0f);
        } catch (const DivisionByZero& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << "Catch double:" << std::endl;
            div(1.0, 0.0);
        } catch (const DivisionByZero& e) {
            std::cout << e.what() << std::endl;
        }
    }

    void barTest() {
        Bar b;

        int n = -1;
        while (n != 0) {
            std::cout << "Please, enter n:" << std::endl;
            std::cin >> n;

            try {
                if (n != 0)
                    b.set(float(n));
            } catch (const Ex& e) {
                std::cout << e.what() << " Error number = " << e.getX() << std::endl;
            }
        }
    }

    void run() {
        std::cout << "====================== LESSON 8 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        divTest();

        std::cout << std::endl;

        std::cout << "Task 2:" << std::endl;
        barTest();
    }
}