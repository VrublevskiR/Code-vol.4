#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Connection
{
public:
    string getSource() const { return source; }
    unsigned short int getPort() const { return port; }
    unsigned long long getTimestamp() const { return timestamp; }

    Connection(string source, unsigned short int port, unsigned long long timestamp) : source(source), port(port), timestamp(timestamp) {}

private:
    string source;
    unsigned short int port;
    unsigned long long timestamp;
};

class IntrusionDetector
{
public:
    void setTimeThreshold(unsigned short int timeThreshold) { this->timeThreshold = timeThreshold; }

    void setPortLimit(unsigned short int portLimit) { this->portLimit = portLimit; }

    void handleConnection(const Connection &c)
    {
        connections.push_back(c);
    }

    bool isIntruder(const string &source) const
    {
        if (addressToConnections.count(source) == 0)
            return false;

        const auto &connectionsBySource = addressToConnections.at(source);

        for (const auto &connection : connectionsBySource)
        {
            if (isPotentialIntruder(connectionsBySource, connection))
            {
                return true;
            }
        }

        return false;
    }

private:
    unsigned short int timeThreshold = 0;
    unsigned short int portLimit = 0;
    vector<Connection> connections;
    unordered_map<string, vector<Connection>> addressToConnections;

    bool isPotentialIntruder(const vector<Connection> &connections, const Connection &current) const
    {
        unsigned int count = 0;
        for (const auto &conn : connections)
        {
            if (conn.getSource() == current.getSource() && conn.getTimestamp() >= current.getTimestamp() - timeThreshold)
            {
                count++;
            }
        }
        return count >= portLimit;
    }
};

int main()
{
    IntrusionDetector id;
    id.setTimeThreshold(5);
    id.setPortLimit(3);
    id.handleConnection({"evil.com", 21, 100504});
    id.handleConnection({"evil.com", 22, 100501});
    id.handleConnection({"evil.com", 23, 100502});
    id.handleConnection({"evil.com", 24, 100503});
    id.handleConnection({"evil.com", 25, 100500});

    cout << boolalpha << "Checking if evil.com is intruder: " << id.isIntruder("evil.com") << endl;

    id.handleConnection({"load.com", 80, 100504});
    id.handleConnection({"load.com", 80, 100501});
    id.handleConnection({"load.com", 80, 100502});
    id.handleConnection({"load.com", 80, 100503});
    id.handleConnection({"load.com", 80, 100500});

    cout << boolalpha << "Checking if load.com is intruder: " << id.isIntruder("load.com") << endl;

    return 0;
}
