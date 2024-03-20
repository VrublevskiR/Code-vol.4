#include <iostream>
using namespace std;

class GasHolder
{
public:
    float V;
    float T;
    float P;
    // Создать газгольдер заданного объёма.
    // Температура созданного термостата равна 273 К.
    GasHolder(float v)
    {
        V = v;
        T = 273;
        P = 0;
    }
    // Уничтожить газгольдер.
    ~GasHolder()
    {
        V = 0;
        T = 0;
        P = 0;
    }
    // Впрыск порции газа массой m и молярной массой M.
    // Считать, что газ принимает текущую температуру газгольдера за пренебрежимо малое время.
    void inject(float m, float M)
    {
        P += (m * 8.31 * T) / (M * V);
    }
    // Подогреть газгольдер на dT градусов.
    // Считать, что нагрев возможен до любых значений температуры.
    void heat(float dT)
    {
        float T1 = T;
        T += dT;
        P = P * (T / T1);
    }
    // Охладить газгольдер на dT градусов.
    // При попытке охладить ниже 0 К температура становится ровно 0 К.
    void cool(float dT)
    {
        if (T - dT < 0)
        {
            T = 0;
            P = 0;
        }
        else
        {
            float T1 = T;
            T -= dT;
            P = P * (T / T1);
        }
    }
    // Получить текущее давление в газгольдере.
    // Считать, что для газа верно уравнение состояния PV = (m/M)RT.
    // Значение постоянной R принять 8.31 Дж/(моль*К).
    float getPressure()
    {
        return P;
    }
};

int main()
{
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    return 0;
}