#include "../Headers/City.h"

City::City(std::string cityName, std::string cityCode, std::string cityPopulation, int cityId, double cityDemand) {
    this->cityName = cityName;
    this->cityCode = cityCode;
    this->cityPopulation = cityPopulation;
    this->cityId = cityId;
    this->cityDemand = cityDemand;
}

void City::setName(std::string name) {
    cityName = name;
}

void City::setCode(std::string code) {
    cityCode = code;
}

void City::setPopulation(std::string population) {
    cityPopulation = population;
}

void City::setId(int id) {
    cityId = id;
}

void City::setDemand(double demand) {
    cityDemand = demand;
}

std::string City::getName() const{
    return cityName;
}

std::string City::getCode() const{
    return cityCode;
}

std::string City::getPopulation() const{
    return cityPopulation;
}

int City::getId() const {
    return cityId;
}

double City::getDemand() const {
    return cityDemand;
}