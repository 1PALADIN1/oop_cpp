#include <iostream>

namespace lesson2
{
    // ================ Тестирование ================
    /*
     * 1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.
     * Определить методы переназначения имени, изменения возраста и веса.
     * Создать производный класс Student (студент), имеющий поле года обучения.
     * Определить методы переназначения и увеличения этого значения.
     * Создать счетчик количества созданных студентов.
     * В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
     */

    enum Sex { F, M };
    int studentsCounter = 0;

    class Person {
    protected:
        std::string name;
        int age;
        float weight;
        Sex sex;

    public:
        Person(std::string name, int age, float weight, Sex sex)
        : name(name), age(age), weight(weight), sex(sex) { }

        void setName(std::string name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setWeight(float weight) {
            this->weight = weight;
        }
    };

    class Student : public Person {
    private:
        int studyYear;
        int studentNumber;

    public:
        Student(std::string name, int age, float weight, Sex sex, int studyYear)
        : Person(name, age, weight, sex) {
            this->studyYear = studyYear;
            this->studentNumber = ++studentsCounter;
        }

        void setStudyYear(int studyYear) {
            this->studyYear = studyYear;
        }

        void incStudyYear() {
            studyYear++;
        }

        void printInfo() {
            char sexChar = sex == Sex::M ? 'M' : 'F';
            std::cout << "#" << studentNumber << " Student " << name << ". Age: " << age << ", sex: " << sexChar
            << ", weight: " << weight << ", study year: " << studyYear << std::endl;
        }
    };

    /*
     * 2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
     * У Fruit есть две переменные-члена: name (имя) и color (цвет).
     * Добавить новый класс GrannySmith, который наследует класс Apple.
     * Код, приведенный выше, должен давать следующий результат:
     * My apple is red.
     * My banana is yellow.
     * My Granny Smith apple is green.
     */

    class Fruit {
    private:
        std::string name;
        std::string color;

    public:
        Fruit(std::string name, std::string color)
        : name(name), color(color) {
        }

        std::string getColor() {
            return color;
        }

        std::string getName() {
            return name;
        }
    };

    class Apple : public Fruit {
    public:
        Apple(std::string name, std::string color) : Fruit(name + " apple", color) {
        }

        Apple(std::string color) : Fruit("apple", color) {
        }
    };

    class Banana : public Fruit {
    public:
        Banana() : Fruit("banana", "yellow") {
        }
    };

    class GrannySmith : public Apple {
    public:
        GrannySmith() : Apple("Granny Smith", "green") {
        }
    };

    /*
     * 3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++,
     * используя объектно-ориентированное программирование. Сколько будет классов в программе?
     * Какие классы будут базовыми, а какие производными? Продумать реализацию игры с
     * помощью
     */

    /* РЕШЕНИЕ ЗАДАНИЯ 3 */
    /* 1. Должен быть основной класс описывающий состояние игры (GameState). В нём будет содержаться информация начата ли/закончина игра,
     * какой номер текущего хода, сколько активных игроков, максимальное безпроигрышное количество очков (21) и т.п.
     * 2. Выделил бы раунд в отдельный объект (Round). Он содержит информацию о текущем раунде, например, какой игрок сейчас ходит,
     * какие у игроков карты в текущем раунде.
     * 3. Класс игрок (Player). В нём содержится денежный баланс игрока, имя.
     * 4. Базовый класс карта (Card). Реализует общее поведение для всех карт.
     * 5. Класс для карт от 2 до 10. Наследник Card.
     * 6. Класс для туза. Наследник Card.
     * 7. Класс для короля, дамы и валета.
     * 8. Класс для колоды карт.
     * 9. Класс дилера.
     */

    // ================ Тестирование ================

    void studentTest() {
        Student firstStudent("Mick Gordon", 22, 79.0, Sex::M, 1);
        firstStudent.printInfo();

        firstStudent.setAge(23);
        firstStudent.setWeight(82.5);
        firstStudent.incStudyYear();

        firstStudent.printInfo();

        Student secondStudent("Natalie Portman", 26, 62.0, Sex::F, 2);
        secondStudent.printInfo();

        secondStudent.setStudyYear(4);
        secondStudent.setWeight(57.2);

        secondStudent.printInfo();

        Student thirdStudent("Dwayne Johnson", 49, 118.0, Sex::M, 5);
        thirdStudent.printInfo();

        thirdStudent.setName("Dwayne Douglas Johnson");

        thirdStudent.printInfo();

        std::cout << "Total students: " << studentsCounter << std::endl;
    }

    void fruitTest() {
        Apple a("red");
        Banana b;
        GrannySmith c;

        std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    }

    void run() {
        std::cout << "====================== LESSON 2 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        studentTest();

        std::cout << "Task 2:" << std::endl;
        fruitTest();
    }
}