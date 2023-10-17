#include <iostream>
#include <fstream>
#include <vector>
#include "Transport.h"

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addTransport(Transport* transport);
    void removeTransport(int index);
    void displayAllTransport();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    std::vector<Transport*> transports;
};
