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

    /*
     * 2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
     * • Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает
     * их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
     * • Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
     * Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
     */

    Date* compare(const std::shared_ptr<Date>& date1, const std::shared_ptr<Date>& date2) {
        int yearDiff = date1->getYear() - date2->getYear();
        int monthDiff = date1->getMonth() - date2->getMonth();
        int dayDiff = date1->getDay() - date2->getDay();

        if (yearDiff != 0) {
            return yearDiff > 0 ? date1.get() : date2.get();
        }

        if (monthDiff != 0)
            return monthDiff > 0 ? date1.get() : date2.get();

        return dayDiff > 0 ? date1.get() : date2.get();
    }

    void swapDates(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2) {
        std::shared_ptr<Date> tmp = std::make_shared<Date>(date1->getDay(), date1->getMonth(), date1->getYear());
        date1.swap(date2);
        date2.swap(tmp);
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

    void dateTest2() {
        std::shared_ptr<Date> date1 = std::make_shared<Date>(15, 04, 2022);
        std::shared_ptr<Date> date2 = std::make_shared<Date>(11, 03, 2021);

        Date* laterDate = compare(date1, date2);
        std::cout << "Later date: " << *laterDate << std::endl;

        std::cout << "Before swap -> Date1: " << *date1 << ", Date2: " << *date2 << std::endl;
        swapDates(date1, date2);
        std::cout << "After swap -> Date1: " << *date1 << ", Date2: " << *date2 << std::endl;
    }

    void run() {
        std::cout << "====================== LESSON 7 ======================" << std::endl;
        std::cout << "Task 1:" << std::endl;
        dateTest1();

        std::cout << std::endl;

        std::cout << "Task 2:" << std::endl;
        dateTest2();
    }
}