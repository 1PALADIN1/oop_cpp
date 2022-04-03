#include <iostream>

namespace lesson3 {
    /*
     * 1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм)
     * и Circle (круг). Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат),
     * Rhombus (ромб). Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную
     * функцию area() (площадь). Во всех остальных классах переопределить эту функцию, исходя из
     * геометрических формул нахождения площади.
     */

    class Figure {
    public:
        virtual const float area()=0;
    };

    class Circle : Figure {
    private:
        const float pi = 3.14;
        float r; //радиус

    public:
        Circle(float r) {
            this->r = r;
        }

        const float area() override {
            return pi * r * r;
        }
    };

    class Parallelogram : public Figure {
    private:
        float a; //сторона
        float h; //высота

    public:
        Parallelogram(float a, float h) {
            this->a = a;
            this->h = h;
        }

        const float area() override {
            return a * h;
        }
    };

    class Rectangle : public Parallelogram {
    public:
        //a - длина, b - ширина
        Rectangle(float a, float b) : Parallelogram(a, b) {
        }
    };

    class Square : public Parallelogram {
    public:
        //a - сторона
        Square(float a) : Parallelogram(a, a) {
        }
    };

    class Rhombus : public Parallelogram {
    public:
        //a - сторона, h - высота
        Rhombus(float a, float h) : Parallelogram(a, h) {
        }
    };

    /*
     * 2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
     * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
     * От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов,
     * чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть,
     * в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
     *
     * Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего"
     * базового класса создает самый "дочерний" класс.
     */

    class Car {
    private:
        std::string company;
        std::string model;

    public:
        Car(std::string company, std::string model)
        : company(company), model(model) {
        }

        virtual const std::string getInfo() {
            return "Company: " + company + ", model: " + model;
        }
    };

    class PassengerCar : virtual public Car {
    public:
        PassengerCar(std::string company, std::string model)
        : Car(company, model) {
        }

        const std::string getInfo() override {
            return "[PassengerCar]: " + Car::getInfo();
        }
    };

    class Bus : virtual public Car {
    public:
        Bus(std::string company, std::string model)
        : Car(company, model) {
        }

        const std::string getInfo() override {
            return "[Bus]: " + Car::getInfo();
        }
    };

    class Minivan : public Bus, public PassengerCar {
    public:
        Minivan(std::string company, std::string model)
        : Car(company, model), Bus(company, model), PassengerCar(model, company) {
        }

        const std::string getInfo() override {
            return "[Minivan]: " + Car::getInfo();
        }
    };

    // ================ Тестирование ================

    void figureTest() {
        Circle circle(4.0);
        Parallelogram parallelogram(2.0, 4.25);
        Rectangle rectangle(4.0, 5.0);
        Square square(10.0);
        Rhombus rhombus(20.0, 4.0);

        std::cout << "Circle area = " << circle.area() << std::endl;
        std::cout << "Parallelogram area = " << parallelogram.area() << std::endl;
        std::cout << "Rectangle area = " << rectangle.area() << std::endl;
        std::cout << "Square area = " << square.area() << std::endl;
        std::cout << "Rhombus area = " << rhombus.area() << std::endl;
    }

    void carTest() {
        PassengerCar passengerCar("Tesla", "Model S");
        Bus bus("Volvo", "9900");
        Minivan minivan("KIA", "Carnival");

        std::cout << passengerCar.getInfo() << std::endl;
        std::cout << bus.getInfo() << std::endl;
        std::cout << minivan.getInfo() << std::endl;
    }

    void run() {
        std::cout << "====================== LESSON 3 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        figureTest();

        std::cout << "Task 2:" << std::endl;
        carTest();
    }
}