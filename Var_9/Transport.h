#include <iostream>
#include <fstream>

class Transport {
public:
    virtual ~Transport();

    virtual void display() const = 0;
    virtual void serialize(std::ostream& os) const = 0;
    virtual void deserialize(std::istream& is) = 0;
};
