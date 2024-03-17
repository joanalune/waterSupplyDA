#ifndef WATERSUPPLYDA_CITY_H
#define WATERSUPPLYDA_CITY_H

#include <string>
using namespace std;

class City {
private:
    string cityName,  cityCode, cityPopulation;
    int cityId;
    double cityDemand;
public:
    City(string cityName, string cityCode, string cityPopulation, int cityId, double cityDemand);
    void setName(string name);
    void setCode(string code);
    void setPopulation(string population);
    void setId(int id);
    void setDemand(double demand);
    string getName();
    string getCode();
    string getPopulation();
    int getId() const;
    double getDemand() const;
};


#endif //WATERSUPPLYDA_CITY_H
