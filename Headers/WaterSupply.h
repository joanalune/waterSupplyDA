#ifndef WATERSUPPLYDA_WATERSUPPLY_H
#define WATERSUPPLYDA_WATERSUPPLY_H

#include "Graph.h"
#include "City.h"
#include "Reservoir.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class WaterSupply {
private:
    Graph<string> waterSupply;
    unordered_map<string, City> cityMap;
    unordered_map<string, Reservoir> reservoirMap;
public:
    WaterSupply() = default;
    //~WaterSupply();

    //file reading
    void readSet(bool smallSet);
    void readCityCsv(const string& path);
    void readPipesCsv(const string& path);
    void readReservoirsCsv(const string& path);
    void readStationsCsv(const string& path);

    unordered_map<string, City> getCities();
    unordered_map<string, Reservoir> getReservoirs();
    Graph<string> getGraph();

};



#endif //WATERSUPPLYDA_WATERSUPPLY_H
