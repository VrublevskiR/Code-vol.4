#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

// Интерфейс модуля
class Module
{
public:
    // Получить имя модуля
    virtual string getName() const = 0;
    // Запустить модуль
    virtual void run() = 0;
    virtual ~Module() {} // Виртуальный деструктор для корректного удаления из указателей на базовый класс
};

// Пример модуля A
class ModuleA : public Module
{
public:
    string getName() const override
    {
        return "moduleA";
    }
    void run() override
    {
        cout << "ModuleA runs" << endl;
    }
};

// Пример модуля B
class ModuleB : public Module
{
public:
    string getName() const override
    {
        return "moduleB";
    }
    void run() override
    {
        cout << "ModuleB runs" << endl;
    }
};

// Диспетчер модулей
class Dispatcher
{
private:
    unordered_map<string, Module *> modules;

public:
    // Зарегистрировать переданный модуль
    void registerModule(Module *m)
    {
        modules[m->getName()] = m;
    }

    // Вызвать метод run для модуля с именем moduleName
    void runModule(const string moduleName) const
    {
        if (modules.count(moduleName))
        {                                  // если содержится
            modules.at(moduleName)->run(); // at для доступа к элементу коллекции по указанному имени, это позволяет получить доступ к нужному модулю
        }
        else
        {
            cout << "Module " << moduleName << " is not registered" << endl;
        }
    }
};

int main()
{
    Module *m1 = new ModuleA();
    Module *m2 = new ModuleB();
    Dispatcher d;
    d.registerModule(m1);
    d.registerModule(m2);
    d.runModule("moduleA");
    d.runModule("moduleB");
    d.runModule("moduleC");
    delete m1;
    delete m2;
    return 0;
}