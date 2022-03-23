#include <iostream>
#include <cmath>

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


    // ================ Тестирование ================

    void powerTest() {
        Power power;
        power.calculate();
        power.set(2, 6);
        power.calculate();
        power.set(11, 4);
        power.calculate();
    }

    void run() {
        std::cout << "====================== LESSON 1 ======================" << std::endl;
        std::cout << "Task1:" << std::endl;

        powerTest();
    }
}