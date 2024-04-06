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
    void clear ();
    void readSet(bool smallSet);
    void readCityCsv(const string& path);
    void readPipesCsv(const string& path);
    void readReservoirsCsv(const string& path);
    void readStationsCsv(const string& path);

    unordered_map<string, City> getCities();
    unordered_map<string, Reservoir> getReservoirs();
    Graph<string> getGraph();

    vector<pair<string, int>> maxFlowAll();
    int maxFlowSingle(const string& cityCode);

    pair<vector<pair<string, int>>, vector<pair<string, int>>> flowRemoveReservoir(const string& reservoir);
    bool flowRemovePipeline(const string &origin, const string &dest, vector<pair<string, int>> &resActual,vector<pair<string, int>> &resTemp, int &maxFlowActual, int &maxFlowTemp);
    //aux
    Vertex<string>* createSuperSink();
    Vertex<string>* createSuperSource();

    void testAndVisit(std::queue< Vertex<string>*> &q, Edge<string> *e, Vertex<string> *v, double residual);
    bool findAugmentingPath(Vertex<string> *source, Vertex<string> *sink);
    void augmentFlowAlongPath(Vertex<string> *source, Vertex<string> *sink, double f);
    int findMinResidualAlongPath(Vertex<string> *source, Vertex<string> *sink);



};



#endif //WATERSUPPLYDA_WATERSUPPLY_H
