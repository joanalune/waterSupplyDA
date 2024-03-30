#include "../Headers/Reservoir.h"

Reservoir::Reservoir(std::string reservoirName, std::string reservoirCode, std::string reservoirMunicipality, int reservoirId, double reservoirDelivery) {
    this->reservoirName = reservoirName;
    this->reservoirCode = reservoirCode;
    this->reservoirMunicipality = reservoirMunicipality;
    this->reservoirId = reservoirId;
    this->reservoirDelivery = reservoirDelivery;
}

void Reservoir::setName(std::string name) {
    reservoirName = name;
}

void Reservoir::setCode(std::string code) {
    reservoirCode = code;
}

void Reservoir::setMunicipality(std::string municipality) {
    reservoirMunicipality = municipality;
}

void Reservoir::setId(int id) {
    reservoirId = id;
}

void Reservoir::setDelivery(double delivery) {
    reservoirDelivery = delivery;
}

string Reservoir::getName() const{
    return reservoirName;
}

string Reservoir::getCode() const{
    return reservoirCode;
}

string Reservoir::getMunicipality() const{
    return reservoirMunicipality;
}

int Reservoir::getId() const {
    return reservoirId;
}

double Reservoir::getDelivery() const {
    return reservoirDelivery;
}

