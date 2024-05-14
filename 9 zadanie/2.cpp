#include <iostream>

class Vector2D
{
public:
    // Constructors
    Vector2D() : x(0), y(0) {}
    Vector2D(int x, int y) : x(x), y(y) {}

    // Destructor
    ~Vector2D() {}

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }

    // Setters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // Comparison operators
    bool operator==(const Vector2D &v2) const
    {
        return (x == v2.x) && (y == v2.y);
    }

    bool operator!=(const Vector2D &v2) const
    {
        return !(*this == v2);
    }

    // Vector addition
    Vector2D operator+(const Vector2D &v2) const
    {
        return Vector2D(x + v2.x, y + v2.y);
    }

    // Vector subtraction
    Vector2D operator-(const Vector2D &v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }

    // Scalar multiplication
    Vector2D operator*(const int a) const
    {
        return Vector2D(x * a, y * a);
    }

private:
    int x;
    int y;
};

// Scalar multiplication of a vector
Vector2D operator*(int a, const Vector2D &v)
{
    return Vector2D(v.getX() * a, v.getY() * a);
}

// Output format for Vector2D
std::ostream &operator<<(std::ostream &os, const Vector2D &v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

// Input format for Vector2D
std::istream &operator>>(std::istream &is, Vector2D &v)
{
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main()
{
    Vector2D v1;
    std::cin >> v1;
    std::cout << v1 << std::endl;

    Vector2D v2;
    std::cin >> v2;
    std::cout << v2 << std::endl;

    std::cout << std::boolalpha << (v1 == v2) << std::endl;
    std::cout << std::boolalpha << (v1 != v2) << std::endl;

    Vector2D v3 = v1 - v2;
    std::cout << v3 << std::endl;
    std::cout << v3 * 42 << std::endl;
    std::cout << 42 * v3 << std::endl;

    return 0;
}
