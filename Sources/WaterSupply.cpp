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
        cityMap.insert({code, tempCity});
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
        reservoirMap.insert({code, tempReservoir});

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

vector<pair<string, int>> WaterSupply::maxFlowAll() {
    vector<pair<string, int>> result;

    Vertex<string>* superSource = createSuperSource();
    Vertex<string>* superSink = createSuperSink();

    for (auto v : waterSupply.getVertexSet()) {
        for (auto e : v->getAdj()) e->setFlow(0);
    }

    int minRes;
    while (findAugmentingPath(superSource, superSink)) {
        minRes = findMinResidualAlongPath(superSource, superSink);
        augmentFlowAlongPath(superSource, superSink, minRes);
    }

    string cityCode;
    Vertex<string>* cityV;
    int flow;
    int totalMaxFlow = 0;
    for (auto p : cityMap) {
        cityCode = p.first;
        cityV = waterSupply.findVertex(cityCode);

        for (auto e : cityV->getAdj()) {
            if (e->getDest()->getInfo() == superSink->getInfo()) {
                flow = e->getFlow();
                totalMaxFlow += flow;
            }
        }
        result.push_back({cityCode, flow});
    }

    result.push_back({"MAX FLOW", totalMaxFlow});  //vector now in the form {{city, flow}, {city, flow}, ..., {"MAX FLOW", maxFlow}}

    waterSupply.removeVertex(superSource->getInfo());
    waterSupply.removeVertex(superSink->getInfo());

    return result;
}

bool WaterSupply::findAugmentingPath(Vertex<string> *source, Vertex<string> *sink) {

    for(auto v : waterSupply.getVertexSet()) {
        v->setVisited(false);
    }

    source->setVisited(true);
    queue<Vertex<string> *> q;
    q.push(source);
    //BFS
    while( ! q.empty() && ! sink->isVisited()) {
        auto v = q.front();
        q.pop();

        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }

        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }

    return sink->isVisited();
}

void WaterSupply::testAndVisit(queue<Vertex<string>*> &q, Edge<string> *e, Vertex<string> *v, double residual) {

    if (! v->isVisited() && residual > 0) {

        v->setVisited(true);
        v->setPath(e);
        q.push(v);
    }
}

void WaterSupply::augmentFlowAlongPath(Vertex<string> *source, Vertex<string> *sink, double f) {

    Vertex<string>* v = sink;
    while (v != source) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

int WaterSupply::findMinResidualAlongPath(Vertex<string> *source, Vertex<string> *sink) {
    int minRes = INF;

    for (auto v = sink; v != source; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            minRes = min(minRes, (int)(e->getWeight() - e->getFlow()));
            v = e->getOrig();
        }
        else {
            minRes = min(minRes, (int)e->getFlow());
            v = e->getDest();
        }
    }

    return minRes;
}



Vertex<string>* WaterSupply::createSuperSink() {
    waterSupply.addVertex("SINK");

    City city;
    for (const auto& p : cityMap) {
        city = p.second;
        waterSupply.addEdge(city.getCode(), "SINK", city.getDemand());
    }

    return waterSupply.findVertex("SINK");
}

Vertex<string>* WaterSupply::createSuperSource() {
    waterSupply.addVertex("SOURCE");

    Reservoir reservoir;
    for (const auto p : reservoirMap) {
        reservoir = p.second;
        waterSupply.addEdge("SOURCE", reservoir.getCode(), reservoir.getDelivery());
    }

    return waterSupply.findVertex("SOURCE");
}


void WaterSupply::clear() {
    waterSupply= Graph<string>();
    cityMap.clear();
    reservoirMap.clear();
}

pair<vector<pair<string, int>>, vector<pair<string, int>>> WaterSupply::flowRemoveNode(const string& node) {
    Vertex<string>* v = waterSupply.findVertex(node);
    unordered_map<string,double> temp;
    for (auto e : v->getAdj()) {
        temp.insert({e->getDest()->getInfo(), e->getWeight()});
        e->setWeight(0);
    }

    for (auto e : v->getIncoming()) {
        temp.insert({e->getOrig()->getInfo(), e->getWeight()});
        e->setWeight(0);
    }

    vector<pair<string,int>> resultTemp = maxFlowAll();

    for (auto e : v->getAdj()) {
        e->setWeight(temp[e->getDest()->getInfo()]);
    }

    for (auto e : v->getIncoming()) {
        e->setWeight(temp[e->getOrig()->getInfo()]);
    }

    vector<pair<string,int>> resultActual = maxFlowAll();

    return make_pair(resultTemp, resultActual);
}

int WaterSupply::maxFlowSingle(const string &cityCode) {

    Vertex<string>* superSource = createSuperSource();
    Vertex<string>* sink = waterSupply.findVertex(cityCode);
    Vertex<string>* extractorSink = createExtractorSink(cityCode);  //vertex with an edge from the city; is used as sink in algorithm so that we can get the flow to the city by examining this edge

    for (auto v : waterSupply.getVertexSet()) {
        for (auto e : v->getAdj()) e->setFlow(0);
    }

    int minRes;
    while (findAugmentingPath(superSource, extractorSink)) {
        minRes = findMinResidualAlongPath(superSource, extractorSink);
        augmentFlowAlongPath(superSource, extractorSink, minRes);
    }

    int result;

    for (auto e : sink->getAdj()) {
        if (e->getDest()->getInfo() == extractorSink->getInfo()) {
            result = e->getFlow();
        }
    }

    waterSupply.removeVertex(superSource->getInfo());
    waterSupply.removeVertex(extractorSink->getInfo());

    return result;
}

Vertex<string> *WaterSupply::createExtractorSink(const string& cityCode) {

    waterSupply.addVertex("EXTRACTOR SINK");

    Vertex<string>* supposedSink = waterSupply.findVertex(cityCode);

    waterSupply.addEdge(cityCode, "EXTRACTOR SINK", cityMap.find(supposedSink->getInfo())->second.getDemand());


    return waterSupply.findVertex("EXTRACTOR SINK");
}



bool WaterSupply::flowRemovePipeline(const string& origin, const string& dest, vector<pair<string,int>>& resActual, vector<pair<string,int>>& resTemp, int &maxFlowActual, int &maxFlowTemp){
    resActual = maxFlowAll();
    maxFlowActual = resActual[resActual.size()-1].second;

    if(!waterSupply.findVertex(origin))return false;
    if(!waterSupply.findVertex(dest))return false;
    Vertex<string>* v = waterSupply.findVertex(origin);
    Vertex<string>* u = waterSupply.findVertex(dest);
    double weight;

    for(auto n : v->getAdj()){
        if(n->getDest()==u){
            weight=n->getWeight();
        }
    }

    if(!waterSupply.removeEdge(origin,dest)){
       return false;
    }

    resTemp = maxFlowAll();
    maxFlowTemp = resTemp[resTemp.size()-1].second;

    if(!waterSupply.addEdge(origin,dest,weight)){
        return false;
    }

    return true;
}




