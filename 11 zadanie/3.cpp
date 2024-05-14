#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person
{
private:
    std::string surname;
    std::string name;
    std::string middleName;

public:
    Person() {}
    Person(std::string surname, std::string name, std::string middleName)
        : surname(surname), name(name), middleName(middleName) {}

    friend std::istream &operator>>(std::istream &in, Person &person)
    {
        in >> person.surname >> person.name >> person.middleName;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &person)
    {
        out << person.surname << " " << person.name << " " << person.middleName;
        return out;
    }

    bool operator<(const Person &other) const
    {
        if (surname == other.surname)
        {
            if (name == other.name)
            {
                return middleName < other.middleName;
            }
            return name < other.name;
        }
        return surname < other.surname;
    }
};

int main()
{
    std::cout << "Testing I/O" << std::endl;
    Person p;
    std::cin >> p;
    std::cout << p << std::endl;

    std::cout << "Testing sorting" << std::endl;
    std::vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));
    std::sort(people.begin(), people.end());

    for (const Person &person : people)
    {
        std::cout << person << std::endl;
    }

    return 0;
}
