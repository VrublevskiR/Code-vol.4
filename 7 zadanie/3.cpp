#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
public:
    Item(const std::string &name, unsigned weight, unsigned price)
        : name(name), weight(weight), price(price)
    {
    }

    const std::string &get_name() const
    {
        return name;
    }

    unsigned get_weight() const
    {
        return weight;
    }

    unsigned get_price() const
    {
        return price;
    }

    void print(std::ostream &os) const
    {
        os << ":" << name << " " << weight << " " << price << endl;
    }

private:
    std::string name;
    unsigned weight;
    unsigned price;
};

class Inventory
{
public:
    explicit Inventory(unsigned size) : capacity(size), total_weight(0)
    {
    }

    bool put(const Item &item)
    {
        if (total_weight + item.get_weight() > capacity)
        {
            return false;
        }
        items.push_back(item);
        total_weight += item.get_weight();
        return true;
    }

    void print(std::ostream &os) const
    {
        for (const auto &item : items)
        {
            item.print(os);
        }
    }

private:
    unsigned capacity;
    unsigned total_weight;
    std::vector<Item> items;
};

class Player
{
public:
    Player(const std::string &name, unsigned strength)
        : name(name), strength(strength)
    {
    }

    const std::string &get_name() const
    {
        return name;
    }

    bool take(const Item &item)
    {
        return inventory.put(item);
    }

    void print(std::ostream &os) const
    {
        os << name << endl;
        inventory.print(os);
    }

private:
    std::string name;
    unsigned strength;
    Inventory inventory{10}; // Assuming inventory size is 10 for each player
};

class Party
{
public:
    bool add(const Player &player)
    {
        if (find(players.begin(), players.end(), player) != players.end())
        {
            return false;
        }
        players.push_back(player);
        return true;
    }

    bool give(const std::string &player_name, const Item &item)
    {
        auto it = find_if(players.begin(), players.end(),
                          [&player_name](const Player &p)
                          { return p.get_name() == player_name; });

        if (it != players.end())
        {
            return it->take(item); // Assuming take method returns true if the item was successfully added to the player's inventory
        }

        return false;
    }

    void print(std::ostream &os) const
    {
        vector<Player> sortedPlayers = players;
        sort(sortedPlayers.begin(), sortedPlayers.end(),
             [](const Player &a, const Player &b)
             { return a.get_name() < b.get_name(); });

        for (const auto &player : sortedPlayers)
        {
            player.print(os);
        }
    }

private:
    std::vector<Player> players;
};

int main()
{
    Party p;
    p.add(Player("Anti-Mage", 15));
    p.add(Player("Razor", 18));
    p.give("Razor", Item("Necronomicon", 1, 5));
    p.give("Anti-Mage", Item("Refresher_Orb", 2, 2));
    p.print(cout);
    return 0;
}
