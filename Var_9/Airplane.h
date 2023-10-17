#include "Transport.h"

class Airplane : public Transport {
public:
    Airplane();
    Airplane(const std::string& type, const std::string& name, double cargoVolume, const std::string& dimensions, const std::string& cities);

    void display() const override;
    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

private:
    std::string type;
    std::string name;
    double cargoVolume;
    std::string dimensions;
    std::string cities;
};
