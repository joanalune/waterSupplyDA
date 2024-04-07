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
    /**
     * Default constructor
     */
    WaterSupply() = default;
    //~WaterSupply();

    //file reading
    /**
     * Clears current graph and hash tables
     * @details Time complexity: O(n) + O(i), n and i being the size
     * of the two unordered maps being cleared
     */
    void clear ();
    /**
     * Calls all reader functions
     * @param smallSet
     * @details Time Complexity: O(n * V * j) + O(m * V * k) + O(l * V) + O(p * V),
     * n, m, l and p being the number of lines in the cities, pipes, reservoirs and stations csv files, respectively
     * V being the number of vertices in the graph, j being the size of the cities hash table and k being the size of
     * the reservoirs hash table
     */
    void readSet(bool smallSet);
    /**
     * Reads the cities csv files located in path and inserts
     * the cities in the graph and their information in a hash table
     * @param path
     * @details Time complexity: O(n * V * j), n being the number of lines of the csv file
     * V being the number of vertices in the graph, j being the size of the cities' unordered map
     */
    void readCityCsv(const string& path);
    /**
     * Reads the pipes csv files located in path and adds an edge to the graph.
     * Can be bi-directional or not
     * @param path
     * @details Time complexity: O(n * V), n being the number of lines of the pipes csv file and
     * V being the number of vertices in the graph
     *
     */
    void readPipesCsv(const string& path);
    /**
     * Reads the reservoirs csv files located in path and inserts
     * the reservoirs in the graph and their information in a hash table
     * @param path
     * @details Time complexity: O(n * V * j), n being the number of lines of the csv file
     * V being the number of vertices in the graph, j being the size of the reservoirs' unordered map
     */
    void readReservoirsCsv(const string& path);
    /**
     * Reads the pumping station csv files located in path and inserts
     * the reservoirs in the graph
     * @param path
     * @details Time complexity: O(n * V), n being the number of lines of the csv file
     * V being the number of vertices in the graph
     */
    void readStationsCsv(const string& path);
    /**
     * Returns unordered map with cities' information
     * @return
     */
    unordered_map<string, City> getCities();
    /**
     * Returns unordered map with reservoirs' information
     * @return
     */
    unordered_map<string, Reservoir> getReservoirs();
    /**
     * Returns the graph
     * @return
     */
    Graph<string> getGraph();

    vector<pair<string, int>> maxFlowAll();
    int maxFlowSingle(const string& cityCode);

    pair<vector<pair<string, int>>, vector<pair<string, int>>> flowRemoveNode(const string& node);
    bool flowRemovePipeline(const string &origin, const string &dest, vector<pair<string, int>> &resActual,vector<pair<string, int>> &resTemp, int &maxFlowActual, int &maxFlowTemp);


    //aux
    Vertex<string>* createSuperSink();
    Vertex<string>* createSuperSource();
    Vertex<string>* createExtractorSink(const string& cityCode);

    void testAndVisit(std::queue< Vertex<string>*> &q, Edge<string> *e, Vertex<string> *v, double residual);
    bool findAugmentingPath(Vertex<string> *source, Vertex<string> *sink);
    void augmentFlowAlongPath(Vertex<string> *source, Vertex<string> *sink, double f);
    int findMinResidualAlongPath(Vertex<string> *source, Vertex<string> *sink);



};



#endif //WATERSUPPLYDA_WATERSUPPLY_H
