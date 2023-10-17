#ifndef CAR_H
#define CAR_H

#include "Transport.h"
#include <vector>

class Car : public Transport {
public:
    Car();
    Car(int year, const std::string& brand, const std::string& model, const std::string& deliveryCities, const std::vector<int>& deliveryTimes, double cargoVolume);

    void display() const override;
    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

private:
    int year;
    std::string brand;
    std::string model;
    std::string deliveryCities;
    std::vector<int> deliveryTimes;
    double cargoVolume;
};

#endif