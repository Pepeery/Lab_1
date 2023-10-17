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
        std::cout << "��������� � �������� " << index << " ������.\n";
    }
    else {
        std::cerr << "�������� ������.\n";
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
        std::cout << "������ ��������� � ����: " << filename << "\n";
    }
    else {
        std::cerr << "�� ���������� ������� ���� ��� ������.\n";
    }
}
