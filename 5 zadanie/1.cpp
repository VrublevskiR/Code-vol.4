#include <iostream>
using namespace std;

class Train
{
public:
    double TrainMass;
    double x;
    double speed = 0;
    // Создать паровоз массой m,
    // стоящий в начале координат
    Train(double m)
    {
        TrainMass = m;
        x = 0;
    }
    // Ехать с текущей скоростью в течение времени dt
    void move(double dt)
    {
        x += speed * dt;
    }
    // Изменить полный импульс паровоза (p = mv) на dp
    // Изменение может менять знак скорости
    void accelerate(double dp)
    {
        speed += dp / TrainMass;
    }
    // Получить текущую координату паровоза
    double getX()
    {
        return x;
    }
};

int main()
{
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    cout << "Current X: " << t.getX() << endl;
    return 0;
}