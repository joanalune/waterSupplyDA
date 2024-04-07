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
     * Set a city's name
     * @param name
     */
    void setName(string name);
    /**
     * Set a city's code
     * @param code
     */
    void setCode(string code);
    /**
     * Set a city's population
     * @param population
     */
    void setPopulation(string population);
    /**
     * Set a city's ID
     * @param id
     */
    void setId(int id);
    /**
     * Set a city's demand
     * @param demand
     */
    void setDemand(double demand);
    /**
     * Get city's name
     * @return
     */
    string getName() const;
    /**
     * Get a city's code
     * @return
     */
    string getCode() const;
    /**
     * Get a city's population
     * @return
     */
    string getPopulation() const;
    /**
     * Get a city's ID
     * @return
     */
    int getId() const;
    /**
     * Get a city's demand
     * @return
     */
    double getDemand() const;
};


#endif //WATERSUPPLYDA_CITY_H
