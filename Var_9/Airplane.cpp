#include <string>
#include "Airplane.h"

Airplane::Airplane() : cargoVolume(0.0) {
    std::cout << " ";
}

Airplane::Airplane(const std::string& type, const std::string& name, double cargoVolume, const std::string& dimensions, const std::string& cities)
    : type(type), name(name), cargoVolume(cargoVolume), dimensions(dimensions), cities(cities) {
    std::cout << " ";
}

void Airplane::display() const {
    std::cout << "Самолет - Тип: " << type << ", Имя: " << name << ", Вместимость: " << cargoVolume << ", Габариты: " << dimensions << ", Города: " << cities << "\n";
}

void Airplane::serialize(std::ostream& os) const {
    os << "A " << type << " " << name << " " << cargoVolume << " " << dimensions << " " << cities << "\n";
}

void Airplane::deserialize(std::istream& is) {
    is >> type >> name >> cargoVolume;

    std::getline(is >> std::ws, dimensions, ',');
    std::getline(is >> std::ws, cities, '\n');
}