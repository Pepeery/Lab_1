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
        std::cout << "\nМеню:\n1. Добавить самолет\n2. Добавить поезд\n3. Добавить автомобиль\n4. Удалить транспорт\n5. Вывести все транспорты\n6. Сохранить в файл\n7. Загрузить из файла\n0. Выйти\n";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::string type, name, dimensions, cities;
            double cargoVolume;

            std::cout << "Введите тип самолета: ";
            std::getline(std::cin, type);
            std::cout << "Введите имя: ";
            std::getline(std::cin, name);
            std::cout << "Введите объем перевозимого груза: ";
            std::cin >> cargoVolume;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите габариты: ";
            std::getline(std::cin, dimensions);
            std::cout << "Введите города: ";
            std::getline(std::cin, cities);

            keeper.addTransport(new Airplane(type, name, cargoVolume, dimensions, cities));
            break;
        }
        case 2: {
            std::string name, route;
            int year, numWagons;
            double cargoVolume;
            std::cout << "Введите имя поезда: ";
            std::cin >> name;
            std::cout << "Введите год выпуска: ";
            std::cin >> year;
            std::cout << "Введите полный маршрут следования (через дефис без пробелов): ";
            std::cin >> route;
            std::cout << "Введите количество вагонов: ";
            std::cin >> numWagons;
            std::cout << "Введите объем перевозимого груза: ";
            std::cin >> cargoVolume;

            keeper.addTransport(new Train(name, year, route, numWagons, cargoVolume));
            break;
        }
        case 3: {
            int year;
            std::string brand, model, deliveryCities;
            std::vector<int> deliveryTimes;
            double cargoVolume;

            std::cout << "Введите год выпуска автомобиля: ";
            std::cin >> year;
            std::cout << "Введите марку: ";
            std::cin >> brand;
            std::cout << "Введите модель: ";
            std::cin >> model;
            std::cout << "Введите объем перевозимого груза: ";
            std::cin >> cargoVolume;

            keeper.addTransport(new Car(year, brand, model, deliveryCities, deliveryTimes, cargoVolume));
            break;
        }
        case 4: {
            int index;
            std::cout << "Введите индекс транспорта для удаления: ";
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
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
