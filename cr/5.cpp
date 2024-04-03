#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

class Rational
{
private:
    int numerator;   // Числитель
    int denominator; // Знаменатель

public:
    Rational(int a, int b) : numerator(a), denominator(b) {}

    // Сложение двух дробей
    Rational operator+(const Rational &other)
    {
        return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    // Вычитание двух дробей
    Rational operator-(const Rational &other)
    {
        return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    // Умножение двух дробей
    Rational operator*(const Rational &other)
    {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    // Деление двух дробей
    Rational operator/(const Rational &other)
    {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Умножение дроби на целое число (работает при любом порядке операндов)
    friend Rational operator*(int value, const Rational &rational) // этот оператор дружетсвенная ф-ция для класса Rational, а значит имеет доступ к закрытым данным
    {
        return Rational(value * rational.numerator, rational.denominator);
    }
    friend Rational operator*(const Rational &rational, int value)
    {
        return Rational(value * rational.numerator, rational.denominator);
    }

    /* Оператор вывода дроби в формате a/b

    std::ostream& operator << (std::ostream &os, const Rational &rational)  почему то не работает :(
    {
       return os << rational.numerator << "/" << rational.denominator;
    }
    */

    friend std::ostream &operator<<(std::ostream &out, const Rational &rational);

    std::ostream &operator<<(std::ostream &out, const Rational &rational)
    {
        // Since operator<< is a friend of the Point class, we can access Point's members directly.
        out << rational.numerator << "/" << rational.denominator; // actual output done here

        return out; // return std::ostream so we can chain calls to operator<<
    }
};

int main()
{
    Rational a(1, 2);
    Rational b(1, 3);
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;
    return 0;
}