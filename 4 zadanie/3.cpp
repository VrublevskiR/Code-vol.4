#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
    string line1, line2, result = ""; // 1-для считывания команды, 2-задание в add и для результата

    int Q, k = 1, j = 0; // k счетник месяцев, j для add & dumb
    cin >> Q;            // Количество операций

    vector<pair<int, string>> arr; // пары число дел - делаж
    for (int i = 0; i < 31; ++i)   // заполняем начальный месяц
    {
        arr.push_back(make_pair(0, ""));
    }

    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // дни январь-декабрь

    for (int i = 0; i < Q; i++)
    {
        cin >> line1;
        if (line1 == "ADD") // добавление задания
        {
            cin >> j;
            cin >> line2;
            arr[j - 1].first += 1;
            arr[j - 1].second += line2 + " ";
        }
        if (line1 == "DUMP") // выведение задания
        {
            cin >> j;
            result += to_string(arr[j - 1].first);
            if (!arr[j - 1].second.empty())
            {
                arr[j - 1].second.pop_back(); // убрать лишний пробел для вывода
                result += " " + arr[j - 1].second + "\n";
                arr[j - 1].second += " "; // возвращаем его
            }
            else
            {
                result += "\n";
            }
        }
        if (line1 == "NEXT") // переход на следующий месяц
        {
            if (k == 12)
            {
                k = 1;
                continue;
            }
            int dif = month[k] - month[k - 1];
            if (dif > 0) // в след. месяце больше дней, создаем их
            {
                for (int m = 0; m < dif; m++)
                {
                    arr.push_back(make_pair(0, ""));
                }
            }
            else if (dif < 0) // в след. месяце меньше дней
            {
                dif = -dif;
                for (int m = 0; m < dif; m++) // с 'лишних' дней переносим дела на последний вободный
                {
                    arr[month[k] - 1].first += arr[month[k] + m].first;
                    arr[month[k] - 1].second += arr[month[k] + m].second;
                }
                arr.erase(arr.end() - dif + 1, arr.end()); // удаляем ненужные дни
            }
            else
                ; // дни совпадают
            k++;  // для дальнейших возможных next
        }
    }
    cout << result;
}