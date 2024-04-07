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
     * @return unordered map with cities' information
     */
    unordered_map<string, City> getCities();
    /**
     * @return unordered map with reservoirs' information
     */
    unordered_map<string, Reservoir> getReservoirs();
    /**
     * @return the graph
     */
    Graph<string> getGraph();

    /**
     * Creates a super-source and a super-sink and runs Edmonds-Karp algorithm through them
     * @return vector with pairs {cityCode, flow} of all cities with last pair storing the total max flow
     * @details Time Complexity: O(r*V + c*V + V*E^2 + c*V*Ec): V: number of vertices; E: number of edges;
     * r: number of reservoirs; c: number of cities; Ec: number of edges connected to each city
     */
    vector<pair<string, int>> maxFlowAll();
    /**
     * Creates a super-source and runs Edmonds-Karp algorithm from it to a city
     * @param cityCode city to which flow is directed
     * @return max flow to the city specified by cityCode
     * @details Time Complexity: O(r*V  + V*E^2): V: number of vertices; E: number of edges;
     * r: number of reservoirs
     */
    int maxFlowSingle(const string& cityCode);

    pair<vector<pair<string, int>>, vector<pair<string, int>>> flowRemoveNode(const string& node);
    bool flowRemovePipeline(const string &origin, const string &dest, vector<pair<string, int>> &resActual,vector<pair<string, int>> &resTemp, int &maxFlowActual, int &maxFlowTemp);


    //aux
    /**
     * Adds a vertex to the graph which has incoming edges from all cities (edge weight corresponding to city's demand)
     * @return Pointer to added vertex
     * @details Time Complexity: O(c * V); c: number of cities; V: number of vertices
     */
    Vertex<string>* createSuperSink();
    /**
     * Adds a vertex to the graph which has outgoing edges to all reservoirs (edge weight corresponding to reservoir's output capacity)
     * @return Pointer to added vertex
     * @details Time Complexity: O(r * V); r: number of reservoirs; V: number of vertices
     */
    Vertex<string>* createSuperSource();
    /**
     * Adds a vertex to the graph which has a single incoming edge from a city (used instead of createSuperSink() when analysing the max flow to a single city)
     * @param cityCode city from which the edge originates
     * @return Pointer to added vertex
     * @details Time Complexity: O(V); V: number of vertices
     */
    Vertex<string>* createExtractorSink(const string& cityCode);

    /**
     * Visits (i.e. sets it to visited, adds it to the queue and sets the edge as a path) a vertex if it is not already visited and residual is not 0
     * @param q queue for the BFS search
     * @param e edge that's being "travelled" through
     * @param v vertex being visited
     * @param residual residual flow through the "e" edge
     * @details Time Complexity: O(1)
     */
    void testAndVisit(std::queue< Vertex<string>*> &q, Edge<string> *e, Vertex<string> *v, double residual);
    /**
     * Finds a path though which more flow can reach the sink using BFS
     * @param source pointer to vertex that generates flow
     * @param sink pointer to vertex that consumes flow
     * @return True if an augmenting path is found, false otherwise
     * @details Time Complexity: O(V * E); V: number of vertices; E: number of edges
     */
    bool findAugmentingPath(Vertex<string> *source, Vertex<string> *sink);
    /**
     * Backtracks path from sink to source and augments flow
     * @param source pointer to source vertex
     * @param sink pointer to sink vertex
     * @param f flow that is to be added through the path
     * @details Time Complexity: O(E); E: number of edges in path
     */
    void augmentFlowAlongPath(Vertex<string> *source, Vertex<string> *sink, double f);
    /**
     * Finds the minimum residual flow backtracking path from sink to source
     * @param source pointer to source vertex
     * @param sink pointer to sink vertex
     * @return minimum residual flow
     * @details Time Complexity: O(E); E: number of edges in path
     */
    int findMinResidualAlongPath(Vertex<string> *source, Vertex<string> *sink);



};



#endif //WATERSUPPLYDA_WATERSUPPLY_H
