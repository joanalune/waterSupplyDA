#ifndef WATERSUPPLYDA_RESERVOIR_H
#define WATERSUPPLYDA_RESERVOIR_H

#include <string>
#include "Graph.h"

using namespace std;

class Reservoir {
private:
    std::string reservoirName, reservoirCode, reservoirMunicipality;
    int reservoirId;
    double reservoirDelivery;
    Vertex<string>* location;
public:
    Reservoir(std::string reservoirName, std::string reservoirCode, std::string reservoirMunicipality, int reservoirId, double reservoirDelivery);
    void setName(std::string name);
    void setCode(std::string code);
    void setMunicipality(std::string municipality);
    void setId(int id);
    void setDelivery(double delivery);
    void setLocation(Vertex<string>* location);
    string getName() const;
    string getCode() const;
    string getMunicipality() const;
    int getId() const;
    double getDelivery() const;
    Vertex<string>* getLocation() const;
};


#endif //WATERSUPPLYDA_RESERVOIR_H
