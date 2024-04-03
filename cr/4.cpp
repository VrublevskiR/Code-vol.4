#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Реализуйте класс, описывающий ломаную линию на плоскости. Прототип класса:

class Polyline
{
private:
    vector<pair<double, double>> points;

public:
    // Добавить очередную точку в ломаную
    void addPoint(double x, double y)
    {
        points.push_back(make_pair(x, y));
    }

    // Получить количество точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const
    {
        return points.size();
    }

    // Получить длину ломаной в данный момент
    double getLength() const
    {
        double length = 0.0;
        for (int i = 1; i < points.size(); i++)
        {
            double dx = points[i].first - points[i - 1].first;
            double dy = points[i].second - points[i - 1].second;
            length += sqrt(dx * dx + dy * dy);
        }
        return length;
    }

    // Получить x-координату i-ой точки ломаной
    double getX(unsigned int i) const
    {
        if (i < points.size())
        {
            return points[i].first;
        }
        // можно бросить исключение или обработать ошибку другим способом
        else
        {
            return 0.0;
        }
    }

    // Получить y-координату i-ой точки ломаной
    double getY(unsigned int i) const
    {
        if (i < points.size())
        {
            return points[i].second;
        }
        else
        {
            return 0.0;
        }
    }
};

// Для тестирования можете использовать следующий пример:

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for (unsigned int i = 0; i < p.getNumberOfPoints(); i++)
    {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}