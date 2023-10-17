#ifndef TRAIN_H
#define TRAIN_H

#include "Transport.h"

class Train : public Transport {
public:
    Train();
    Train(const std::string& name, int year, const std::string& route, int numWagons, double cargoVolume);

    void display() const override;
    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

private:
    std::string name;
    int year;
    std::string route;
    int numWagons;
    double cargoVolume;
};

#endif
