#include <iostream>
#include <string>

namespace lesson6 {

    /*
     * 1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если
     * пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке
     * и предложить ввести число еще раз. Пример неправильных введенных строк:
        rbtrb
        nj34njkn
        1n
     */

    bool tryReadNumber() {
        std::cout << "Number: " << std::endl;
        std::string number_str;
        std::cin >> number_str;

        for (char c : number_str) {
            if (!isdigit(c))
                return false;
        }

        return true;
    }

    /*
     * 2. Создать собственный манипулятор endll для стандартного потока вывода,
     * который выводит два перевода строки и сбрасывает буфер.
     */

    std::ostream& endll(std::ostream& os) {
        return os << "\n" << "\n" << std::flush;
    }

    // ================ Тестирование ================

    void readIntTest() {
        while (!tryReadNumber()) {
            std::cerr << "Input number is not correct! Try again." << std::endl;
        }
    }

    void endllTest() {
        std::cout << "Hello world!" << endll << "One more text..." << std::endl;
    }


    void run() {
        std::cout << "====================== LESSON 6 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        readIntTest();

        std::cout << std::endl;

        std::cout << "Task 2:" << std::endl;
        endllTest();
    }
}