#ifndef WATERSUPPLYDA_CITY_H
#define WATERSUPPLYDA_CITY_H

#include <string>
#include "Graph.h"

using namespace std;

class City {
private:
    string cityName,  cityCode, cityPopulation;
    int cityId;
    double cityDemand;
public:
    /**
     * City class constructor
     * @param cityName
     * @param cityCode
     * @param cityPopulation
     * @param cityId
     * @param cityDemand
     */
    City(string cityName, string cityCode, string cityPopulation, int cityId, double cityDemand);
    /**
     * City empty constructor
     */
    City() = default;
    /**
     * Sets a city's name
     * @param name
     */
    void setName(string name);
    /**
     * Sets a city's code
     * @param code
     */
    void setCode(string code);
    /**
     * Sets a city's population
     * @param population
     */
    void setPopulation(string population);
    /**
     * Sets a city's ID
     * @param id
     */
    void setId(int id);
    /**
     * Sets a city's demand
     * @param demand
     */
    void setDemand(double demand);
    /**
     * Gets a city's name
     * @return
     */
    string getName() const;
    /**
     * Gets a city's code
     * @return
     */
    string getCode() const;
    /**
     * Gets a city's population
     * @return
     */
    string getPopulation() const;
    /**
     * Gets a city's ID
     * @return
     */
    int getId() const;
    /**
     * Gets a city's demand
     * @return
     */
    double getDemand() const;
};


#endif //WATERSUPPLYDA_CITY_H
