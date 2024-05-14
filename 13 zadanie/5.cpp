#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cout << "Введите длину последовательности: ";
    std::cin >> n;

    std::vector<int> sequence(n);
    std::cout << "Введите последовательность чисел: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> sequence[i];
    }

    int k;
    std::cout << "Введите число k: ";
    std::cin >> k;

    std::vector<int> filteredSequence;
    for (int num : sequence)
    {
        if (num <= k)
        {
            filteredSequence.push_back(num);
        }
    }

    std::cout << "Результат после фильтрации: ";
    for (int num : filteredSequence)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
