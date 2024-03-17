#include <iostream>
#include <sstream>
#include <fstream>
#include "../Headers/WaterSupply.h"

void WaterSupply::readSet(bool smallSet) {
    if (smallSet) {
        readCityCsv("../Project1DataSetSmall/Cities_Madeira.csv");
        readReservoirsCsv("../Project1DataSetSmall/Reservoirs_Madeira.csv");
        readStationsCsv("../Project1DataSetSmall/Stations_Madeira.csv");
        readPipesCsv("../Project1DataSetSmall/Pipes_Madeira.csv");
    } else {
        readCityCsv("../Project1LargeDataSet/Cities.csv");
        readReservoirsCsv("../Project1LargeDataSet/Reservoir.csv");
        readStationsCsv("../Project1LargeDataSet/Stations.csv");
        readPipesCsv("../Project1LargeDataSet/Pipes.csv");
    }
}

void WaterSupply::readCityCsv(const string& path) {
    std::ifstream input(path);

    if (!input.is_open()) {
        cout << "Could not read Cities CSV\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {
        istringstream iss(line);
        string city, id, code, demand, population;
        getline(iss, city, ',');
        getline(iss, id, ',');
        getline(iss, code, ',');
        getline(iss, demand, ',');
        getline(iss, population, ',');

        int intId = stoi(id);
        double doubleDemand = stof(demand);

        City tempCity(city, code, population, intId, doubleDemand);
        waterSupply.addVertex(code);
        cityMap[code] = new City(tempCity);
    }
}

void WaterSupply::readStationsCsv(const std::string &path) {
    std::ifstream input(path);

    if (!input.is_open()) {
        cout << "Could not read Stations CSV\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {
        istringstream iss(line);
        string id, code;
        getline(iss, id, ',');
        getline(iss, code, ',');

        //int intId = stoi(id);

        //Criar unordered_map?
        waterSupply.addVertex(code);
    }
}

void WaterSupply::readReservoirsCsv(const std::string &path) {
    std::ifstream input(path);

    if (!input.is_open()) {
        cout << "Could not read Reservoirs CSV\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {
        istringstream iss(line);
        string name, id, code, delivery, municipality;
        getline(iss, name, ',');
        getline(iss, municipality, ',');
        getline(iss, id, ',');
        getline(iss, code, ',');
        getline(iss, delivery, ',');

        int intId = stoi(id);
        double doubleDelivery = stof(delivery);

        Reservoir tempReservoir(name, code, municipality, intId, doubleDelivery);
        waterSupply.addVertex(code);
        reservoirMap[code] = new Reservoir(tempReservoir);
    }
}

void WaterSupply::readPipesCsv(const std::string &path) {
    std::ifstream input(path);

    if (!input.is_open()) {
        cout << "Could not read Reservoirs CSV\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {
        istringstream iss(line);
        string origin, dest, capacity, direction;
        getline(iss, origin, ',');
        getline(iss, dest, ',');
        getline(iss, capacity, ',');
        getline(iss, direction, ',');

        double doubleCapacity = stod(capacity);

        if (direction == "1") {
            waterSupply.addEdge(origin, dest, doubleCapacity);
        } else {
            waterSupply.addBidirectionalEdge(origin, dest, doubleCapacity);
        }

    }
}

unordered_map<string, City *> WaterSupply::getCities() {
    return cityMap;
}

unordered_map<string, Reservoir *> WaterSupply::getReservoirs() {
    return reservoirMap;
}

WaterSupply::~WaterSupply() {
    for (const auto& city : cityMap) {
        delete city.second;
    }

    for (const auto& reservoir : reservoirMap) {
        delete reservoir.second;
    }
}

Graph<string> WaterSupply::getGraph() {
    return waterSupply;
}
