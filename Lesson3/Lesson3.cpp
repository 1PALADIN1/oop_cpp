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
            std::cout << ">>> Car(" << company << ", " << model << ")" << std::endl;
        }

        const std::string getCompany() {
            return company;
        }

        const std::string getModel() {
            return model;
        }

        virtual const std::string getInfo() {
            return "Company: " + company + ", model: " + model;
        }

        ~Car() {
            std::cout << ">>> ~Car(" << company << ", " << model << ")" << std::endl;
        }
    };

    class PassengerCar : virtual public Car {
    public:
        PassengerCar(std::string company, std::string model)
        : Car(company, model) {
            std::cout << ">>> PassengerCar(" << company << ", " << model << ")" << std::endl;
        }

        const std::string getInfo() override {
            return "[PassengerCar]: " + Car::getInfo();
        }

        ~PassengerCar() {
            std::cout << ">>> ~PassengerCar(" << getCompany() << ", " << getModel() << ")" << std::endl;
        }
    };

    class Bus : virtual public Car {
    public:
        Bus(std::string company, std::string model)
        : Car(company, model) {
            std::cout << ">>> Bus(" << company << ", " << model << ")" << std::endl;
        }

        const std::string getInfo() override {
            return "[Bus]: " + Car::getInfo();
        }

        ~Bus() {
            std::cout << ">>> ~Bus(" << getCompany() << ", " << getModel() << ")" << std::endl;
        }
    };

    class Minivan : public Bus, public PassengerCar {
    public:
        Minivan(std::string company, std::string model)
        : Car(company, model), Bus(company, model), PassengerCar(model, company) {
            std::cout << ">>> Minivan(" << company << ", " << model << ")" << std::endl;
        }

        const std::string getInfo() override {
            return "[Minivan]: " + Car::getInfo();
        }

        ~Minivan() {
            std::cout << ">>> ~Minivan()" << getCompany() << ", " << getModel() << ")" << std::endl;
        }
    };

    /*
     * 3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
     * Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
     * - математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
     * - унарный оператор (-)
     * - логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
     *
     * Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности,
     * попробуйте перегрузить один через другой.
     *
     * Продемонстрировать использование перегруженных операторов.
     */

    class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction() {
            this->numerator = 0;
            this->denominator = 0;
        }

        Fraction(int numerator, int denominator) {
            if (denominator == 0) {
                std::cout << "Error: denominator can't be 0!" << std::endl;
                Fraction();
                return;
            }

            this->numerator = numerator;
            this->denominator = denominator;
        }

        //арифметические операции
        Fraction operator+(const Fraction &other) const {
            if (numerator == 0)
                return Fraction(other.numerator, other.denominator);

            if (other.numerator == 0)
                return Fraction(numerator, denominator);

            if (denominator == other.denominator)
                return Fraction(numerator + other.numerator, denominator);

            int newNumerator = other.numerator * denominator + numerator * other.denominator;
            int newDenominator = denominator * other.denominator;

            return Fraction(newNumerator, newDenominator);
        }
        Fraction operator-() const {
            return Fraction(-numerator, denominator);
        }

        Fraction operator-(const Fraction &other) const {
            if (other.numerator == 0)
                return Fraction(numerator, denominator);

            if (numerator == 0)
                return Fraction(other.numerator, other.denominator);

            if (denominator == other.denominator)
                return Fraction(numerator - other.numerator, denominator);

            int newNumerator = other.numerator * denominator - numerator * other.denominator;
            int newDenominator = denominator * other.denominator;

            return Fraction(newNumerator, newDenominator);
        }

        Fraction operator*(const Fraction &other) const {
            if (other.numerator == 0 || numerator == 0)
                return Fraction();

            return Fraction(numerator * other.numerator, denominator * other.denominator);
        }

        Fraction operator/(const Fraction &other) const {
            Fraction swapFraction = Fraction(other.denominator, other.numerator);
            return *this * swapFraction;
        }

        //логические операции
        bool operator==(const Fraction &other) const {
            if (other.denominator == denominator)
                return other.numerator == numerator;

            int newDenominator = other.denominator * denominator;
            Fraction fraction(numerator * other.denominator, newDenominator);
            Fraction otherFraction(other.numerator * denominator, newDenominator);
            return fraction.numerator == otherFraction.numerator;
        }

        bool operator!=(const Fraction &other) const {
            return !(Fraction(numerator, denominator) == other);
        }

        bool operator>(const Fraction &other) const {
            if (other.denominator == denominator)
                return numerator > other.numerator;

            return numerator * other.denominator > other.numerator * denominator;
        }

        bool operator<(const Fraction &other) const {
            if (*this == other)
                return false;

            return !(*this > other);
        }

        bool operator>=(const Fraction &other) const {
            if (*this > other)
                return true;

            return *this == other;
        }

        bool operator<=(const Fraction &other) const {
            if (*this < other)
                return true;

            return *this == other;
        }

        const std::string toString() {
            if (numerator == 0)
                return "0";

            return std::to_string(numerator) + "/" + std::to_string(denominator);
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

    void fractionTest() {
        Fraction fraction1(2, 3);
        Fraction fraction2(4, 5);
        Fraction fraction3(10, 5);
        Fraction fraction4(8, 10);
        Fraction fraction5(4, 5);
        Fraction zeroFraction;

        // +
        std::cout << "[+]" << std::endl;
        std::cout << fraction1.toString() << " + " << fraction2.toString() << " = "
        << (fraction1 + fraction2).toString() << std::endl;
        std::cout << fraction3.toString() << " + " << fraction2.toString() << " = "
        << (fraction3 + fraction2).toString() << std::endl;

        // -
        std::cout << "[-]" << std::endl;
        std::cout << fraction1.toString() << " - " << fraction2.toString() << " = "
        << (fraction1 - fraction2).toString() << std::endl;
        std::cout << fraction3.toString() << " - " << fraction2.toString() << " = "
        << (fraction3 - fraction2).toString() << std::endl;
        std::cout << fraction2.toString() << " - " << fraction3.toString() << " = "
        << (fraction2 - fraction3).toString() << std::endl;
        //унарный -
        std::cout << "-1 * " << fraction2.toString() << " = "
        << (-fraction2).toString() << std::endl;

        // *
        std::cout << "[*]" << std::endl;
        std::cout << fraction1.toString() << " * " << fraction2.toString() << " = "
        << (fraction1 * fraction2).toString() << std::endl;
        std::cout << fraction1.toString() << " * " << zeroFraction.toString() << " = "
        << (fraction1 * zeroFraction).toString() << std::endl;

        // :
        std::cout << "[:]" << std::endl;
        std::cout << fraction1.toString() << " : " << fraction2.toString() << " = "
        << (fraction1 / fraction2).toString() << std::endl;

        // ==
        std::cout << "[==]" << std::endl;
        std::cout << fraction1.toString() << " == " << fraction2.toString() << " = "
        << (fraction1 == fraction2) << std::endl;
        std::cout << fraction2.toString() << " == " << fraction4.toString() << " = "
        << (fraction2 == fraction4) << std::endl;
        std::cout << fraction2.toString() << " == " << fraction5.toString() << " = "
        << (fraction2 == fraction5) << std::endl;

        // !=
        std::cout << "[!=]" << std::endl;
        std::cout << fraction1.toString() << " != " << fraction2.toString() << " = "
        << (fraction1 != fraction2) << std::endl;
        std::cout << fraction2.toString() << " != " << fraction4.toString() << " = "
        << (fraction2 != fraction4) << std::endl;
        std::cout << fraction2.toString() << " != " << fraction5.toString() << " = "
        << (fraction2 != fraction5) << std::endl;

        // <
        std::cout << "[<]" << std::endl;
        std::cout << fraction1.toString() << " < " << fraction2.toString() << " = "
        << (fraction1 < fraction2) << std::endl;
        std::cout << fraction2.toString() << " < " << fraction4.toString() << " = "
        << (fraction2 < fraction4) << std::endl;

        // >
        std::cout << "[>]" << std::endl;
        std::cout << fraction1.toString() << " > " << fraction2.toString() << " = "
        << (fraction1 > fraction2) << std::endl;
        std::cout << fraction2.toString() << " > " << fraction4.toString() << " = "
        << (fraction2 > fraction4) << std::endl;

        // <=
        std::cout << "[<=]" << std::endl;
        std::cout << fraction1.toString() << " <= " << fraction2.toString() << " = "
        << (fraction1 <= fraction2) << std::endl;
        std::cout << fraction2.toString() << " <= " << fraction4.toString() << " = "
        << (fraction2 <= fraction4) << std::endl;

        // >=
        std::cout << "[>=]" << std::endl;
        std::cout << fraction1.toString() << " >= " << fraction2.toString() << " = "
        << (fraction1 >= fraction2) << std::endl;
        std::cout << fraction2.toString() << " >= " << fraction4.toString() << " = "
        << (fraction2 >= fraction4) << std::endl;
    }

    void run() {
        std::cout << "====================== LESSON 3 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        figureTest();

        std::cout << "Task 2:" << std::endl;
        carTest();

        std::cout << "Task 3:" << std::endl;
        fractionTest();
    }
}