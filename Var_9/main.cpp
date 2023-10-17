#include <string>
#include "Airplane.h"
#include "Train.h"
#include "Car.h"
#include "Keeper.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Keeper keeper;

    int choice;
    do {
        std::cout << "\n����:\n1. �������� �������\n2. �������� �����\n3. �������� ����������\n4. ������� ���������\n5. ������� ��� ����������\n6. ��������� � ����\n7. ��������� �� �����\n0. �����\n";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::string type, name, dimensions, cities;
            double cargoVolume;

            std::cout << "������� ��� ��������: ";
            std::getline(std::cin, type);
            std::cout << "������� ���: ";
            std::getline(std::cin, name);
            std::cout << "������� ����� ������������ �����: ";
            std::cin >> cargoVolume;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������� ��������: ";
            std::getline(std::cin, dimensions);
            std::cout << "������� ������: ";
            std::getline(std::cin, cities);

            keeper.addTransport(new Airplane(type, name, cargoVolume, dimensions, cities));
            break;
        }
        case 2: {
            std::string name, route;
            int year, numWagons;
            double cargoVolume;
            std::cout << "������� ��� ������: ";
            std::cin >> name;
            std::cout << "������� ��� �������: ";
            std::cin >> year;
            std::cout << "������� ������ ������� ���������� (����� ����� ��� ��������): ";
            std::cin >> route;
            std::cout << "������� ���������� �������: ";
            std::cin >> numWagons;
            std::cout << "������� ����� ������������ �����: ";
            std::cin >> cargoVolume;

            keeper.addTransport(new Train(name, year, route, numWagons, cargoVolume));
            break;
        }
        case 3: {
            int year;
            std::string brand, model, deliveryCities;
            std::vector<int> deliveryTimes;
            double cargoVolume;

            std::cout << "������� ��� ������� ����������: ";
            std::cin >> year;
            std::cout << "������� �����: ";
            std::cin >> brand;
            std::cout << "������� ������: ";
            std::cin >> model;
            std::cout << "������� ����� ������������ �����: ";
            std::cin >> cargoVolume;

            keeper.addTransport(new Car(year, brand, model, deliveryCities, deliveryTimes, cargoVolume));
            break;
        }
        case 4: {
            int index;
            std::cout << "������� ������ ���������� ��� ��������: ";
            std::cin >> index;
            keeper.removeTransport(index);
            break;
        }
        case 5: {
            keeper.displayAllTransport();
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "������� ��� ����� ��� ����������: ";
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "������� ��� ����� ��� ��������: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
