#include <iostream>
#include <ostream>
#include <istream>

template <typename T>
class Vector2D
{
public:
    // Конструкторы
    Vector2D() : x(T()), y(T()) {}
    Vector2D(T x, T y) : x(x), y(y) {}

    // Деструктор
    ~Vector2D() {}

    // Получение координат
    T getX() const { return x; }
    T getY() const { return y; }

    // Задание координат
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    // Перегруженные операторы
    bool operator==(const Vector2D &v2) const
    {
        return x == v2.x && y == v2.y;
    }

    bool operator!=(const Vector2D &v2) const
    {
        return !(*this == v2);
    }

    Vector2D operator+(const Vector2D &v2) const
    {
        return Vector2D(x + v2.x, y + v2.y);
    }

    Vector2D operator-(const Vector2D &v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }

    Vector2D operator*(const T a) const
    {
        return Vector2D(x * a, y * a);
    }

    friend Vector2D operator*(T a, const Vector2D &v)
    {
        return Vector2D(a * v.x, a * v.y);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2D &v)
    {
        return os << "(" << v.x << "; " << v.y << ")";
    }

    friend std::istream &operator>>(std::istream &is, Vector2D &v)
    {
        return is >> v.x >> v.y;
    }

private:
    T x;
    T y;
};

int main()
{
    Vector2D<int> v1;
    std::cin >> v1;
    std::cout << "Read vector: " << v1 << std::endl;
    std::cout << "Vector multiplied by 42: " << v1 * 42 << std::endl;

    Vector2D<double> v2;
    std::cin >> v2;
    std::cout << "Read vector: " << v2 << std::endl;
    std::cout << "Vector multiplied by 42: " << 42.0 * v2 << std::endl;

    return 0;
}
