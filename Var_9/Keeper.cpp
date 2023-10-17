#include "Airplane.h"
#include "Train.h"
#include "Car.h"
#include "Keeper.h"

Keeper::Keeper() {
    std::cout << " ";
}

Keeper::~Keeper() {
    for (auto transport : transports) {
        delete transport;
    }
    std::cout << " ";
}

void Keeper::addTransport(Transport* transport) {
    transports.push_back(transport);
}

void Keeper::removeTransport(int index) {
    if (index >= 0 && index < transports.size()) {
        delete transports[index];
        transports.erase(transports.begin() + index);
        std::cout << "Транспорт с индексом " << index << " удален.\n";
    }
    else {
        std::cerr << "Неверный индекс.\n";
    }
}

void Keeper::displayAllTransport() {
    for (const auto& transport : transports) {
        transport->display();
    }
}

void Keeper::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        for (const auto& transport : transports) {
            transport->serialize(file);
        }
        file.close();
        std::cout << "Данные сохранены в файл: " << filename << "\n";
    }
    else {
        std::cerr << "Не получилось открыть файл для записи.\n";
    }
}
