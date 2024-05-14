#include <iostream>

class Item
{
public:
    Item(std::string name, int power, int level, bool magical)
        : name(name), power(power), level(level), magical(magical) {}

    std::string name;
    int power;
    int level;
    bool magical;
};

class Player
{
public:
    virtual bool canHeal() = 0;
    virtual bool canUse(const Item &item) = 0;
    virtual bool canCast() = 0;
    virtual void setStrength(int str) = 0;
    virtual void setLevel(int lvl) = 0;
    virtual ~Player() {}
};

class Knight : public Player
{
public:
    bool canHeal() override
    {
        return false;
    }

    bool canUse(const Item &item) override
    {
        return !item.magical && level >= item.level;
    }

    bool canCast() override
    {
        return false;
    }

    void setStrength(int str) override { strength = str; }
    void setLevel(int lvl) override { level = lvl; }

private:
    int strength;
    int level;
};

class Wizard : public Player
{
public:
    bool canHeal() override
    {
        return true;
    }

    bool canUse(const Item &item) override
    {
        return level >= item.level;
    }

    bool canCast() override
    {
        return true;
    }

    void setStrength(int str) override { strength = str; }
    void setLevel(int lvl) override { level = lvl; }

private:
    int strength;
    int level;
};

int main()
{
    Item items[3] = {
        Item("Small sword", 1, 1, false),
        Item("Big sword", 5, 3, false),
        Item("Ward", 1, 3, true)};

    Player *players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Can heal: " << players[i]->canHeal() << std::endl;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "Can use: " << players[i]->canUse(items[j]) << std::endl;
        }
    }

    for (int i = 0; i < 2; i++)
        delete players[i];

    return 0;
}
