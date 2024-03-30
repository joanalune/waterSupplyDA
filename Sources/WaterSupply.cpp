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

        //waterSupply.addVertex(code);
        //cityMap.insert({code, tempCity});

        addCity(tempCity);
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
        //waterSupply.addVertex(code);

        addStation(code);
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

        //waterSupply.addVertex(code);
        //reservoirMap.insert({code, tempReservoir});

        addReservoir(tempReservoir);
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

        /*
        if (direction == "1") {
            waterSupply.addEdge(origin, dest, doubleCapacity);
        } else {
            waterSupply.addBidirectionalEdge(origin, dest, doubleCapacity);
        }
         */

        addPipe(origin, dest, doubleCapacity, direction);

    }
}

unordered_map<string, City> WaterSupply::getCities() {
    return cityMap;
}

unordered_map<string, Reservoir> WaterSupply::getReservoirs() {
    return reservoirMap;
}

/*
WaterSupply::~WaterSupply() {
    for (const auto& city : cityMap) {
        delete city.second;
    }

    for (const auto& reservoir : reservoirMap) {
        delete reservoir.second;
    }
}
*/

Graph<string> WaterSupply::getGraph() {
    return waterSupply;
}

bool WaterSupply::addCity(const City& city) {

    //is checking for duplicates needed??
    locationMap.insert({city.getCode(), waterSupply.pushVertex(city.getCode())});
    cityMap.insert({city.getCode(), city});

    return true;
}

bool WaterSupply::addReservoir(const Reservoir& reservoir) {

    //is checking for duplicates needed??
    locationMap.insert({reservoir.getCode(), waterSupply.pushVertex(reservoir.getCode())});
    reservoirMap.insert({reservoir.getCode(), reservoir});

    return true;
}

bool WaterSupply::addStation(const string &stationCode) {

    //is checking for duplicates needed??
    locationMap.insert({stationCode, waterSupply.pushVertex(stationCode)});

    return true;
}

bool WaterSupply::addPipe(const string& src, const string& dest, const double& w, const string& direction) {

    auto srcPtr = locationMap.find(src)->second;
    auto destPtr = locationMap.find(dest)->second;

    srcPtr->addEdge(destPtr, w);

    if (direction == "0") {
        destPtr->addEdge(srcPtr, w);
    }

    return true;
}

unordered_map<string, Vertex<string> *> WaterSupply::getLocations() {
    return locationMap;
}


