#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
class Animal
{
protected:
    double mass;
    double speed;

public:
    Animal() {}
    virtual ~Animal() {}
    // Создаём зверушку с заданной массой и скоростью
    Animal(double mass, double speed)
    {
        this->mass = mass;
        this->speed = speed;
    }
    // Получить массу зверя
    virtual double getMass() const
    {
        return mass;
    }
    // Получить скорость зверя
    virtual double getSpeed() const
    {
        return speed;
    }
    // Может ли зверушка нападать на других зверей
    // (не может, зверь мирный)
    virtual bool canAtack() const
    {
        return false;
    }
    // Съесть другого зверя, не делает ничего, мы же мирные
    virtual void eat(const Animal &a)
    {
    }
};
class Predator : public Animal
{
public:
    Predator(double mass, double speed) : Animal(mass, speed) {}

    bool canAtack() const override
    {
        return true;
    }

    void eat(const Animal &a) override
    {
        if (a.getMass() <= this->mass && a.getSpeed() <= this->speed)
        {
            this->mass += a.getMass();
        }
    }
};

int main()
{
    Animal *predator = new Predator(1, 10);
    std::cout << "Current mass: " << predator->getMass() << std::endl;

    if (predator->canAtack())
    {
        predator->eat(Animal(2, 1));
        std::cout << "Current mass: " << predator->getMass() << std::endl;

        predator->eat(Animal(1, 1));
        std::cout << "Current mass: " << predator->getMass() << std::endl;

        predator->eat(Animal(1, 20));
        std::cout << "Current mass: " << predator->getMass() << std::endl;

        predator->eat(Animal(2, 2));
        std::cout << "Current mass: " << predator->getMass() << std::endl;
    }

    delete predator;

    return 0;
}
