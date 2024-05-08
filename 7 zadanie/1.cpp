#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/*Напишите класс `CalendarData`, в котором определены:
- конструктор с параметрами (день, месяц, год), каждое из которых
представляет из себя `int`;
- деструктор, который автоматически при уничтожении экземпляра объекта
выводит на поток `std::cout` полученные в констукторе "день.мексяц.год" (через
точку без пробелов).
Других методов, кроме конструктора и деструктора, описывать не требуется.
Формат входных данных
Считывать с клавиатуры ничего не требуется. Дата попадает в объект класса
через конструктор с параметрами.
Формат выходных данных
Три числа через точку на поток `std::cout`.
Примеры*/

class CalendarData
{
private:
    int day;
    int month;
    int year;

public:
    CalendarData(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    ~CalendarData()
    {
        cout << day << "." << month << "." << year << std::endl;
    }
};

/*-> CalendarData data(5, 8, 2005);
--
<- 5.8.2005
-> CalendarData data(15, 12, 2012);
--
<- 15.12.2012
-> CalendarData data(3, 3, 333);
--
<- 3.3.333 */