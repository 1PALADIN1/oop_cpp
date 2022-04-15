#include <iostream>
#include <memory>

namespace lesson7 {

    /*
     * 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
     * Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date.
     * Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа
     * к полям класса Date, а также выведите на экран данные всего объекта с помощью перегруженного
     * оператора вывода. Затем переместите ресурс, которым владеет указатель today в указатель date.
     * Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
     */

    class Date {
        friend std::ostream& operator<<(std::ostream& os, const Date& date);

    private:
        int day;
        int month;
        int year;

    public:
        Date(int day, int month, int year)
        : day(day), month(month), year(year) {
        }

        int getDay() const {
            return day;
        }

        int getMonth() const {
            return month;
        }

        int getYear() const {
            return year;
        }
    };

    std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.day << "." << date.month << "." << date.year;
        return os;
    }


    // ================ Тестирование ================

    void dateTest1() {
        std::shared_ptr<Date> today = std::make_shared<Date>(15, 04, 2022);
        std::shared_ptr<Date> date;
        std::cout << "D: " << today->getDay() << ", M: " << today->getMonth() << ", Y: " << today->getYear() << std::endl;
        std::cout << *today << std::endl;
        date.swap(today);

        std::cout << "Today is null? " << (today == nullptr)
        << ". Date is null? " << (date == nullptr) << std::endl;
    }

    void run() {
        std::cout << "====================== LESSON 7 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        dateTest1();
    }
}