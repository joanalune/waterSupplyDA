#ifndef WATERSUPPLYDA_RESERVOIR_H
#define WATERSUPPLYDA_RESERVOIR_H

#include <string>

class Reservoir {
private:
    std::string reservoirName, reservoirCode, reservoirMunicipality;
    int reservoirId;
    double reservoirDelivery;
public:
    Reservoir(std::string reservoirName, std::string reservoirCode, std::string reservoirMunicipality, int reservoirId, double reservoirDelivery);
    void setName(std::string name);
    void setCode(std::string code);
    void setMunicipality(std::string municipality);
    void setId(int id);
    void setDelivery(double delivery);
    std::string getName();
    std::string getCode();
    std::string getMunicipality();
    int getId() const;
    double getDelivery() const;
};


#endif //WATERSUPPLYDA_RESERVOIR_H
