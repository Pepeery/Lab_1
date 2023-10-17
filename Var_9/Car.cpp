#include <string>
#include <sstream> 
#include "Car.h"

Car::Car() : year(0), cargoVolume(0.0) {
    std::cout << " ";
}

Car::Car(int year, const std::string& brand, const std::string& model, const std::string& deliveryCities, const std::vector<int>& deliveryTimes, double cargoVolume)
    : year(year), brand(brand), model(model), deliveryCities(deliveryCities), deliveryTimes(deliveryTimes), cargoVolume(cargoVolume) {
    std::cout << ".\n";
}

void Car::display() const {
    std::cout << "Машина - Год: " << year << ", Марка: " << brand << ", Модель: " << model << ", Города доставки: " << deliveryCities << ", Вместимость: " << cargoVolume << "\n";
}

void Car::serialize(std::ostream& os) const {
    os << "C " << year << " " << brand << " " << model << " " << deliveryCities << ",";
    for (int time : deliveryTimes) {
        os << time << " ";
    }
    os << cargoVolume << "\n";
}

void Car::deserialize(std::istream& is) {
    is >> year >> brand >> model;

    std::getline(is >> std::ws, deliveryCities, ',');

    std::string timeInput;
    std::getline(is >> std::ws, timeInput, '\n');

    std::istringstream timesStream(timeInput);
    deliveryTimes.clear();
    int time;
    while (timesStream >> time) {
        deliveryTimes.push_back(time);
    }

    if (!(is >> cargoVolume)) {
        cargoVolume = 0.0;
    }
}
