#include <iostream>
#include <cmath>
#include <cstdint>

namespace lesson1
{
    /*
     * 1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две
     * переменные-члена для хранения этих вещественных чисел. Еще создать два метода: один с именем set,
     * который позволит присваивать значения объявленным в классе переменным, второй — calculate,
     * который будет выводить результат возведения первого числа в степень второго числа.
     * Задать значения этих двух чисел по умолчанию.
     */

    class Power {
    private:
        float number;
        float power;

    public:
        Power() {
            number = 0.0;
            power = 0.0;
        }

        void set(float number, float power) {
            this->number = number;
            this->power = power;
        }

        void calculate() {
            float result = pow(number, power);
            std::cout << number << "^" << power << " = " << result << std::endl;
        }
    };

    /*
     * 2. Написать класс с именем RGBA, который содержит 4 переменные-члена
     * типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
     * Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
     * Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения
     * для m_red, m_blue, m_green и m_alpha.
     * Написать функцию print(), которая будет выводить значения переменных-членов.
     */

    class RGBA {
    private:
        std::uint8_t m_red;
        std::uint8_t m_green;
        std::uint8_t m_blue;
        std::uint8_t m_alpha;

    public:
        RGBA() {
            m_red = 0;
            m_green = 0;
            m_blue = 0;
            m_alpha = 255;
        }

        RGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
        : m_red(r), m_green(g), m_blue(b), m_alpha(a) {
        }

        void print() {
            std::cout << "R:" << (int)m_red << ", G:" << (int)m_green
            << ", B:" << (int)m_blue << ", A:" << (int)m_alpha << std::endl;
        }
    };

    // ================ Тестирование ================

    void powerTest() {
        Power pwr;
        pwr.calculate();
        pwr.set(2, 6);
        pwr.calculate();
        pwr.set(11, 4);
        pwr.calculate();
    }

    void rgbaTest() {
        RGBA rgba;
        rgba.print();

        RGBA rgba1(23, 123, 2, 180);
        rgba1.print();
    }

    void run() {
        std::cout << "====================== LESSON 1 ======================" << std::endl;
        std::cout << "Task1:" << std::endl;
        powerTest();

        std::cout << "Task2:" << std::endl;
        rgbaTest();
    }
}