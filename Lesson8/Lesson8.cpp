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

    /*
     * 3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод,
     * означающий задание переместиться на соседнюю позицию. Эти методы должны запускать классы-исключения OffTheField,
     * если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится
     * в нужном диапазоне). Объект исключения должен содержать всю необходимую информацию — текущую позицию и
     * направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от
     * его методов, а также выводящую подробную информацию о всех возникающих ошибках.
     */

    const int GRID_SIZE = 10;

    class OffTheField : public std::logic_error {
    public:
        OffTheField(const int startX, const int startY, const int targetX, const int targetY)
        : std::logic_error("Can't move from (" + std::to_string(startX) + ", " + std::to_string(startY) + ") to ("
        + std::to_string(targetX) + ", " + std::to_string(targetY) + "). Point is out of field!") {
        }
    };

    class IllegalCommand : public std::logic_error {
    public:
        IllegalCommand(const int dirX, const int dirY)
        : std::logic_error("Input direction is not correct (" + std::to_string(dirX) + ", "
        + std::to_string(dirY) + ")!") {
        }
    };

    class Robot {
    private:
        int posX;
        int posY;

    public:
        Robot() {
            posX = 0;
            posY = 0;
        }

        void move(const int dirX, const int dirY) {
            if (dirX == 0 && dirY == 0) {
                throw IllegalCommand(dirX, dirY);
            }

            if (!(abs(dirX) <= 1 && abs(dirY) <= 1)) {
                throw IllegalCommand(dirX, dirY);
            }

            int targetX = posX + dirX;
            int targetY = posY + dirY;
            if (targetX >= GRID_SIZE || targetX < 0 || targetY >= GRID_SIZE || targetY < 0) {
                throw OffTheField(posX, posY, targetX, targetY);
            }

            posX += dirX;
            posY += dirY;
            std::cout << "Robot moved to new position (" << posX << ", " << posY << ")" << std::endl;
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

    void robotTest(Robot& robot, const int dirX, const int dirY) {
        try {
            robot.move(dirX, dirY);
        } catch (const IllegalCommand& e) {
            std::cout << ">>> " << e.what() << std::endl;
        } catch (const OffTheField& e) {
            std::cout << ">>> " << e.what() << std::endl;
        }
    }

    void robotTest() {
        Robot robot;

        //not correct command test
        robotTest(robot, 0, 0);
        robotTest(robot, 0, 2);
        robotTest(robot, 2, 2);
        robotTest(robot, -20, -2);

        //out of field test
        robotTest(robot, 0, -1);
        robotTest(robot, -1, 0);
        robotTest(robot, -1, -1);

        //correct input
        for (int i = 0; i < GRID_SIZE - 1; ++i) {
            robotTest(robot, 0, 1);
        }

        //out of field test
        robotTest(robot, 0, 1);

        //correct input
        for (int i = 0; i < GRID_SIZE - 1; ++i) {
            robotTest(robot, 1, 0);
        }

        //out of field test
        robotTest(robot, 1, 0);
        robotTest(robot, 1, 1);
    }

    void run() {
        std::cout << "====================== LESSON 8 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        divTest();

        std::cout << std::endl;

        std::cout << "Task 2:" << std::endl;
        barTest();

        std::cout << std::endl;

        std::cout << "Task 3:" << std::endl;
        robotTest();
    }
}