#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <string>
#include <cmath>

using namespace std;
// Задан следующий класс точки на плоскости:

class Point
{
protected: // наследник получит
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) // инициализирует члены класса x и y значениями переданными в параметрах конструктора
    {
    }
    Point operator+(const Point &a) const // не изменяет членов данных объектов
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point &a) const
    {
        return Point(x - a.x, y - a.y);
    }
    double dist() const
    {
        return sqrt(x * x + y * y);
    }
};
// Логически точка представлена радиус-вектором, поэтому точки можно складывать и вычитать - соответственные операторы для них уже определены. Также у точки есть метод dist() - получить модуль её радиус-вектора.
// Напишите класс треугольника со следующим прототипом :

class Triangle
{
private: // только внутри класса
    Point a;
    Point b;
    Point c;

public:
    Triangle(const Point &a, const Point &b, const Point &c) : a(a), b(b), c(c)
    {
    }
    double distance(const Point &p1, const Point &p2) const
    {
        return (p1 - p2).dist();
    }
    double perimeter() const
    {
        return distance(a, b) + distance(b, c) + distance(c, a);
    }
};
// Для базового тестирования можете использовать следующий пример:
int main()
{
    Point a(0, 0), b(0, 5), c(5, 0);
    Triangle t(a, b, c);
    cout << t.perimeter() << endl;
    return 0;
}