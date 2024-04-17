#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Дан следующий интерфейс, описывающий поведение материала в терминах "напряжение-деформация".
class Material
{
public:
    // Принимает на вход величину деформации.
    // Возвращает величину напряжения, посчитанную с учётом реологии материала.
    virtual float getStress(float strain) = 0;
};
/*Реализуйте данный интерфейс для идеально-упругого материала и для упруго-пластического.
Идеально упругий материал должен быть описан в классе ElasticMaterial. Данный класс
должен:
• технически корректно реализовать интерфейс Material;
• иметь конструктор ElasticMaterial(float elasticModulus), где elasticModulus -
модуль Юнга;
• реализовать метод float getStress(float strain), где напряжение считается
прямо пропорциональным деформации во всём диапазоне значений.*/
class ElasticMaterial : public Material
{
private:
    float elasticModulus;

public:
    ElasticMaterial(float elasticModulus) : elasticModulus(elasticModulus) {}

    float getStress(float strain) override
    {
        return elasticModulus * strain;
    }
};

/*Упруго-пластический материал должен быть описан в классе PlasticMaterial. Данный
класс должен:
• технически корректно реализовать интерфейс Material;
• иметь конструктор PlasticMaterial(float elasticModulus, float strainLimit),
где elasticModulus - модуль Юнга, а strainLimit - предельное значение упругой деформации;
• реализовать метод float getStress(float strain), где напряжение считается
прямо пропорциональным деформации в диапазоне деформаций от нуля
до strainLimit, а при дальнейшем возрастании деформации напряжение более не
меняется (материал "течёт").*/

class PlasticMaterial : public Material
{
private:
    float elasticModulus;
    float strainLimit;

public:
    PlasticMaterial(float elasticModulus, float strainLimit) : elasticModulus(elasticModulus), strainLimit(strainLimit) {}

    float getStress(float strain) override
    {
        if (strain <= strainLimit)
        {
            return elasticModulus * strain;
        }
        else
        {
            return elasticModulus * strainLimit;
        }
    }
};

/*код для базового тестирования реализации класса:
 Material* m;
 m = new ElasticMaterial(100);
 cout << "Material stress is: " << m->getStress(0.1) << endl;
 delete m;
 m = new PlasticMaterial(100, 0.01);
 cout << "Material stress is: " << m->getStress(0.1) << endl;
 delete m;
Базовый тест должен вывести:
Material stress is: 10
Material stress is: 1 */

int main()
{
    Material *m;
    m = new ElasticMaterial(100);
    std::cout << "Material stress is: " << m->getStress(0.1) << std::endl;
    delete m;

    m = new PlasticMaterial(100, 0.01);
    std::cout << "Material stress is: " << m->getStress(0.1) << std::endl;
    delete m;

    return 0;
}
