#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Handler
{
public:
    virtual void preProcess() {}
    virtual void postProcess() {}
    virtual bool accessAllowed(string username) { return true; }
    virtual void run() = 0;
};

class BadHandler : public Handler
{
};

class DummyHandler : public Handler
{
public:
    void run()
    {
        cout << "DummyHandler runs" << endl;
    }
};

class SmartHandler : public Handler
{
public:
    void preProcess()
    {
        cout << "SmartHandler preprocess" << endl;
    }
    void postProcess()
    {
        cout << "SmartHandler postprocess" << endl;
    }
    bool accessAllowed(string username)
    {
        return "admin" == username;
    }
    void run()
    {
        cout << "SmartHandler runs" << endl;
    }
};

class HeavyHandler : public Handler
{
protected:
    int *data;

public:
    HeavyHandler()
    {
        data = new int[1000];
    }
    ~HeavyHandler()
    {
        delete[] data;
    }
    void run()
    {
        cout << "HeavyHandler runs" << endl;
    }
};

int main()
{
    // Проверка работы различных обработчиков
    Handler *h;

    // DummyHandler
    std::cout << "\nDummyHandler:" << std::endl;
    h = new DummyHandler();
    h->preProcess();
    h->accessAllowed("dummy_user");
    h->run();
    h->postProcess();
    delete h;

    // SmartHandler
    std::cout << "\nSmartHandler:" << std::endl;
    h = new SmartHandler();
    h->preProcess();
    h->accessAllowed("admin");
    h->run();
    h->postProcess();
    delete h;

    // HeavyHandler
    std::cout << "\nHeavyHandler:" << std::endl;
    h = new HeavyHandler();
    h->preProcess();
    h->accessAllowed("any_user");
    h->run();
    h->postProcess();
    delete h;

    return 0;
}