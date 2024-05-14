#include <iostream>
#include <string>

class Student
{
public:
    // Задать имя студента
    void setName(std::string name)
    {
        this->name = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score)
    {
        this->score = score;
    }

    // Получить имя студента
    std::string getName() const
    {
        return name;
    }

    // Получить количество баллов студента
    unsigned int getScore() const
    {
        return score;
    }

    // Оператор ввода данных студента
    friend std::istream &operator>>(std::istream &in, Student &student)
    {
        std::getline(in, student.name);
        student.setScore(0); // Устанавливаем баллы в 0
        return in;
    }

    // Оператор вывода данных студента
    friend std::ostream &operator<<(std::ostream &out, const Student &student)
    {
        out << "'" << student.getName() << "': " << student.getScore();
        return out;
    }

private:
    std::string name;
    unsigned int score;
};

int main()
{
    Student s;
    std::cin >> s;
    s.setScore(10);
    std::cout << s;

    return 0;
}
