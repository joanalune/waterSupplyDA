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
    unordered_map<string, Vertex<string>*> locationMap;
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
    unordered_map<string, Vertex<string>*> getLocations();
    Graph<string> getGraph();

    bool addCity(const City& city);
    bool addReservoir(const Reservoir& reservoir);
    bool addStation(const string& stationCode);
    bool addPipe(const string& src, const string& dest, const double& w, const string& direction);



};



#endif //WATERSUPPLYDA_WATERSUPPLY_H
