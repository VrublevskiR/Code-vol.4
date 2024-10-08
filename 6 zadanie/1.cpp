#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/*Пишем класс, который умеет взаимодействовать с другими классами. Причём другие
классы могут быть очень разные - иерархия наследования у них может оказаться очень раз-
весистой. Но наш класс общается с ними через единый интерфейс, благодаря чему отдель-
ной обработки всех случаев писать не требуется.
У вас есть зоопарк разных классов. У них есть общий интерфейс. Вот такой:*/
class Animal
{
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};
/*Сколько и каких конкретных зверей будет потом создано - вы не знаете. Но для вас ин-
терфейс к ним всем будет таким.
Нужно написать класс смотрителя зоопарка. Классу передают на вход зверей, он их
всех последовательно осматривает и пересчитывает, сколько из них было опасных. Прототип
класса вот такой:*/
class ZooKeeper
{
private:
    int N;

public:
    // Создаём смотрителя зоопарка

    ZooKeeper()
    {
        cout << " created" << endl;
        this->N = 0;
    }
    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal *a)
    {
        if (a->isDangerous()) // с помощью -> указатель на класс выполняет свой метод
        {
            N++;
        }
    }
    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount()
    {
        return N;
    }
};
/*Публичные методы должны быть ровно такие. Необходимую protected / private часть
класса можете создать себе любую.
Пример ожидаемого сценария работы всей конструкции:*/
/*int main()
{
    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;
    return 0
}
Должно напечатать 1, так как зверей было 3, но опасный среди них только лев. */