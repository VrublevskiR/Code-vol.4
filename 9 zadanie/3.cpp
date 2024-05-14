#include <iostream>
#include <vector>

class VectorN
{
private:
    unsigned int size;
    std::vector<int> values;

public:
    VectorN(unsigned int n) : size(n), values(std::vector<int>(n, 0)) {}

    ~VectorN() {}

    unsigned getSize() const
    {
        return size;
    }

    int getValue(unsigned int i) const
    {
        return values[i];
    }

    void setValue(unsigned int i, int value)
    {
        values[i] = value;
    }

    bool operator==(const VectorN &other) const
    {
        if (size != other.size)
        {
            return false;
        }

        for (unsigned int i = 0; i < size; ++i)
        {
            if (values[i] != other.values[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const VectorN &other) const
    {
        return !(*this == other);
    }

    VectorN operator+(const VectorN &other)
    {
        VectorN result(size);
        for (unsigned int i = 0; i < size; ++i)
        {
            result.values[i] = values[i] + other.values[i];
        }
        return result;
    }

    VectorN operator*(int scalar)
    {
        VectorN result(size);
        for (unsigned int i = 0; i < size; ++i)
        {
            result.values[i] = values[i] * scalar;
        }
        return result;
    }
};

int main()
{
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;

    VectorN c = a + b;
    VectorN d = c * 5;

    for (unsigned int i = 0; i < a.getSize(); ++i)
    {
        std::cout << d.getValue(i) << std::endl;
    }

    return 0;
}
