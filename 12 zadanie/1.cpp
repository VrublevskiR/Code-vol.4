#include <iostream>
#include <string>
#include <unordered_map>

class Animal
{
public:
    virtual std::string getType() const = 0;
    virtual ~Animal() {}
};

class Monkey : public Animal
{
public:
    std::string getType() const override { return "monkey"; }
};

class Lion : public Animal
{
public:
    std::string getType() const override { return "lion"; }
};

class ZooKeeper
{
private:
    std::unordered_map<std::string, int> animalCounts;

public:
    ZooKeeper() = default;

    void handleAnimal(const Animal &a)
    {
        animalCounts[a.getType()]++;
    }

    int getAnimalCount(const std::string &type) const
    {
        if (animalCounts.count(type) > 0)
        {
            return animalCounts.at(type);
        }
        return 0;
    }
};

int main()
{
    ZooKeeper z;
    Animal *a = new Monkey();
    z.handleAnimal(*a);
    delete a;

    a = new Monkey();
    z.handleAnimal(*a);
    delete a;

    a = new Lion();
    z.handleAnimal(*a);
    delete a;

    std::cout << z.getAnimalCount("monkey") << std::endl; // Должно напечатать 2
    std::cout << z.getAnimalCount("lion") << std::endl;   // Должно напечатать 1
    std::cout << z.getAnimalCount("cat") << std::endl;    // Должно напечатать 0

    return 0;
}
