#include <iostream>
#include <vector>

using namespace std;

class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size) : cpuNum(cpuNum), size(size) {}

    int getCPU() const
    {
        return cpuNum;
    }

    int getSize() const
    {
        return size;
    }
};

class Analyzer
{
private:
    vector<int> cpuLoads;

public:
    Analyzer(int numCores) : cpuLoads(numCores, 0) {}

    void analyze(const vector<Task> &tasks)
    {
        for (const Task &task : tasks)
        {
            int cpu = task.getCPU();
            int size = task.getSize();
            cpuLoads[cpu] += size;
        }
    }

    int getLoadForCPU(int cpuNum)
    {
        return cpuLoads[cpuNum];
    }
};

int main()
{
    int numberOfCores = 4;
    vector<Task> data = {{0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5}};

    Analyzer a(numberOfCores);
    a.analyze(data);

    for (int i = 0; i < numberOfCores; i++)
    {
        cout << a.getLoadForCPU(i) << endl;
    }

    return 0;
}
