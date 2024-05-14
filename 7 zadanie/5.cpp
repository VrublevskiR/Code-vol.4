#include <iostream>
#include <vector>
#include <algorithm>

class MyClass
{
private:
    struct MyStruct
    {
        int num;
        std::string str;

        MyStruct(int n, const std::string &s) : num(n), str(s) {}
    };

    std::vector<MyStruct> elements;

public:
    void addElement(int num, const std::string &str)
    {
        elements.emplace_back(num, str);
    }

    void printStructures() const
    {
        for (const auto &element : elements)
        {
            std::cout << element.num << " " << element.str << std::endl;
        }
    }

    MyClass &operator+=(const MyClass &other)
    {
        for (const auto &elem : other.elements)
        {
            if (std::find_if(elements.begin(), elements.end(), [&](const MyStruct &e)
                             { return e.num == elem.num && e.str == elem.str; }) == elements.end())
            {
                elements.emplace_back(elem.num, elem.str);
            }
        }
        return *this;
    }
};

int main()
{
    MyClass obj1;
    obj1.addElement(1, "hi");
    obj1.addElement(2, "hello");
    obj1.addElement(2, "hello");

    MyClass obj2;
    obj2.addElement(3, "hey");
    obj2.addElement(4, "pop");
    obj2.addElement(2, "hello");
    obj2.addElement(5, "hello");

    obj1 += obj2;
    obj1.printStructures();

    return 0;
}
