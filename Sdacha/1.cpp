#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Cat
{
    string name;         // Имя
    unsigned int weight; // Вес (в граммах)
};

class BagOfCats
{
public:
    void putCat(const Cat &c)
    {
        cats_[c.name].push_back(c);
    }

    void printStats() const
    {
        for (const auto &pair : cats_)
        {
            const string &name = pair.first;
            const vector<Cat> &catList = pair.second;

            unsigned int totalWeight = 0;
            for (const Cat &cat : catList)
            {
                totalWeight += cat.weight;
            }

            std::cout << name << " " << catList.size() << " " << totalWeight << std::endl;
        }
    }

private:
    unordered_map<string, vector<Cat>> cats_;
};

int main()
{
    Cat cats[] = {{"Barsic", 1500}, {"Murzik", 1200}, {"Gav", 500}, {"Murzik", 1800}};
    BagOfCats bag;
    for (const auto &cat : cats)
        bag.putCat(cat);

    bag.printStats();
    return 0;
}
