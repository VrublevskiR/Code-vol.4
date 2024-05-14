#include <iostream>
#include <vector>
#include <algorithm>

class ResultsTable
{
public:
    void addResult(unsigned int score)
    {
        results.push_back(score);
    }

    unsigned int getMinScore() const
    {
        if (results.empty())
        {
            return 0;
        }

        return *std::min_element(results.begin(), results.end());
    }

    unsigned int getScoreForPosition(unsigned int positionNumber) const
    {
        if (results.empty())
        {
            return 0;
        }

        std::vector<unsigned int> sortedResults = results;
        std::sort(sortedResults.begin(), sortedResults.end(), std::greater<>());

        if (positionNumber > sortedResults.size())
        {
            return 0;
        }

        return sortedResults[positionNumber - 1];
    }

private:
    std::vector<unsigned int> results;
};

int main()
{
    ResultsTable t;
    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);

    std::cout << "1st place score: " << t.getScoreForPosition(1) << std::endl;
    std::cout << "2nd place score: " << t.getScoreForPosition(2) << std::endl;
    std::cout << "3rd place score: " << t.getScoreForPosition(3) << std::endl;
    std::cout << "Min score during the tournament: " << t.getMinScore() << std::endl;

    return 0;
}
