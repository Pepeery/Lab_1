#include "Train.h"

Train::Train() : year(0), numWagons(0), cargoVolume(0.0) {
    std::cout << " ";
}

Train::Train(const std::string& name, int year, const std::string& route, int numWagons, double cargoVolume)
    : name(name), year(year), route(route), numWagons(numWagons), cargoVolume(cargoVolume) {
    std::cout << " ";
}

void Train::display() const {
    std::cout << "Поезд - Название: " << name << ", Год: " << year << ", Маршрут: " << route << ", Количество вагонов: " << numWagons << ", Вместимость: " << cargoVolume << "\n";
}

void Train::serialize(std::ostream& os) const {
    os << "T " << name << " " << year << " " << route << " " << numWagons << " " << cargoVolume << "\n";
}

void Train::deserialize(std::istream& is) {
    is >> name >> year >> route >> numWagons >> cargoVolume;
}
