#include "Airplane.h"
#include "Train.h"
#include "Car.h"
#include "Keeper.h"

Keeper::Keeper() {
    std::cout << "Keeper constructor called.\n";
}

Keeper::~Keeper() {
    for (auto transport : transports) {
        delete transport;
    }
    std::cout << "Keeper destructor called.\n";
}

void Keeper::addTransport(Transport* transport) {
    transports.push_back(transport);
}

void Keeper::removeTransport(int index) {
    if (index >= 0 && index < transports.size()) {
        delete transports[index];
        transports.erase(transports.begin() + index);
        std::cout << "Transport at index " << index << " removed.\n";
    }
    else {
        std::cerr << "Invalid index.\n";
    }
}

void Keeper::displayAllTransport() {
    for (const auto& transport : transports) {
        transport->display();
    }
}

    else {
        std::cerr << "Unable to open file for reading.\n";
    }
}
