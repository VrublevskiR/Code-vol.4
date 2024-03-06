#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string line;   // считывает команду
    string result; // хранит результаты подсчетов
    int Q;         // Количество операций
    cin >> Q;
    vector<int> arr;
    for (int i = 0; i < Q; i++)
    {
        int k = 0, worry = 0, total = size(arr);

        cin >> line;

        if (line == "WORRY") // 1-Волнуется, 0-Спокойный
        {
            cin >> k;
            arr[k] = 1;
            continue;
        }
        if (line == "QUIET")
        {
            cin >> k;
            arr[k] = 0;
            continue;
        }
        if (line == "COME")
        {
            cin >> k;
            if (k > 0)
            {
                arr.insert(arr.end(), k, 0);
                continue;
            }

            if (k < 0)
            {
                arr.erase(arr.end() + k, arr.end());
            }
            continue;
        }
        if (line == "WORRY_COUNT")
        {
            for (int q = 0; q < total; q++)
            {
                if (arr[q] == 1)
                {
                    worry++;
                }
            }
            result += to_string(worry) + "\n";
        }
    }
    cout << result;
}