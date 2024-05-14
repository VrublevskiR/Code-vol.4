#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm> // для использования std::pair и std::make_pair

class MyClass
{
private:
    std::vector<std::pair<int, std::string>> structures;

public:
    void addElement(int num, const std::string &str)
    {
        std::pair<int, std::string> newStruct = std::make_pair(num, str);
        // Проверка наличия такой же структуры в массиве
        if (std::find(structures.begin(), structures.end(), newStruct) == structures.end())
        {
            structures.push_back(newStruct);
        }
    }

    void printStructures()
    {
        for (const auto &item : structures)
        {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }
};

int main()
{
    MyClass obj1;
    obj1.addElement(1, "hello");
    obj1.addElement(2, "hi");
    obj1.addElement(2, "hi");

    obj1.printStructures();

    return 0;
}
