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

    void run() {
        std::cout << "====================== LESSON 8 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        divTest();
    }
}