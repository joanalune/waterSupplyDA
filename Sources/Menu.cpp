#include <iomanip>
#include "../Headers/Menu.h"

bool comparator(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    if (a.first.length() == b.first.length()) {
        return a.first < b.first;
    }
    return a.first.length() < b.first.length();
}


Menu::Menu(WaterSupply *w) {
    waterSupply = w;
}

void Menu::waitForInput() const {
    cout << "Input any value to continue" << endl;
    string input;
    getline(cin >> input, input);
}

void Menu::printDataChoiceMenu(){
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "            Data Set Choice             " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << endl;
    cout    << "Which water supply network data set would you like to read?" << endl;
    cout    << "1. Small data set"<< endl;
    cout    << "2. Large data set" << endl;
    cout    << "3. Exit" << endl;
}

void Menu::printMainMenu(){
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "               Main Menu                " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << endl;
    cout    << "What would you like to do?" << endl;
    cout    << "1. Consult service metrics"<< endl;
    cout    << "2. Evaluate the network's resilience" << endl;
    cout    << "3. Change dataset" << endl;
    cout    << "4. Exit" << endl;
}

void Menu::printServiceMetricsMenu(){
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "            Service Metrics             " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << endl;
    cout    << "What would you like to do?" << endl;
    cout    << "1. Consult maximum flow that can reach each city"<< endl;
    cout    << "2. Consult the networks' ability to provide water to all its customers" << endl;
    cout    << "3. Balance the load across the network" << endl; //greedy strategy, no need to implement, prepare for presentation
    cout    << "4. Return to main menu" << endl;
    cout    << "5. Exit" << endl;
}

void Menu::printReliabilityFailureMenu(){
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "        Reliability and Failures        " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << endl;
    cout    << "What would you like to consult?" << endl;
    cout    << "1. Simulate water reservoir removal"<< endl;
    cout    << "2. Simulate pumping station removal" << endl;
    cout    << "3. Simulate pipe removal" << endl;
    cout    << "4. Return to main menu" << endl;
    cout    << "5. Exit" << endl;
}

void Menu::printRemoveReservoirMenu() {
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "        Reliability and Failures        " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << endl;
    cout    << "Which reservoir do you want to remove?"   << endl;

    auto reservoirMap = waterSupply->getReservoirs();
    for (int i = 1; i < reservoirMap.size()+1; i++) {
        cout << i << ". " << reservoirMap["R_" + to_string(i)].getCode() << " - " <<  reservoirMap["R_" + to_string(i)].getName() << endl;
    }

    cout    << "Select a number from 1 to " << waterSupply->getReservoirs().size() << ":";
}

void Menu::printRemovePipelineMenu() {
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "        Reliability and Failures        " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "Write the origin and the destination of the pipe you want to remove in the format: code1,code2"
               " for example: R_1,PS_1"   << endl;
    cout    << endl;
}

void Menu::printRemovePSMenu() {
    cout    << endl;
    cout    << "Which Pumping Station do you want to remove?"   << endl;

    int psNum = waterSupply->getGraph().getNumVertex() - waterSupply->getCities().size() - waterSupply->getReservoirs().size();
    for (int i = 1; i < psNum; i++) {
        cout << i << ". " << "PS_" << i << endl;
    }

    cout    << "Select a number from 1 to " << psNum - 1<< ":";
}

void Menu::runDataChoiceMenu(){

    while(true){
        system("clear");
        printDataChoiceMenu();
        int option;
        cin >> option;

        switch(option){
            case 1:
                waterSupply->clear();
                waterSupply->readSet(true);
                runMainMenu();
                return;
            case 2:
                waterSupply->clear();
                waterSupply->readSet(false);
                runMainMenu();
                return;
            case 3:
                cout << "Thank you for using our Water Supply Analysis System (˶ᵔ ᵕ ᵔ˶)"<<endl;
                return;
            default:
                cout << "Invalid Input" << endl;
        }
    }
}

void Menu::runMainMenu(){
    while(true){
        system("clear");
        printMainMenu();

        int option;
        cin >> option;

        switch(option){
            case 1:
                runServiceMetricsMenu();
                return;
            case 2:
                runReliabilityFailureMenu();
                return;
            case 3:
                runDataChoiceMenu();
                return;
            case 4:
                cout << "Thank you for using our Water Supply Analysis System (˶ᵔ ᵕ ᵔ˶)"<< endl;
                return;
            default:
                cout << "Invalid Input" << endl;

        }
    }

}


void Menu::runServiceMetricsMenu(){
    while(true){
        system("clear");
        printServiceMetricsMenu();

        int option;
        cin >> option;

        switch(option) {
            case 1: {
                auto result = waterSupply->maxFlowAll();
                sort(result.begin(), result.end(), comparator);
                for (int i = 0; i < result.size() - 1; i++) {
                    cout << "[" + result[i].first + "] " +
                            waterSupply->getCities().find(result[i].first)->second.getName() << " -> " << result[i].second
                         << '\n';
                }
                cout << "Total maximum flow = " << result[result.size() - 1].second << '\n';
                cout << "\nWriting the cities' flow to a file...\n";
                write("../output/");
                waitForInput();
                break;
            }
            case 2: {
                cout << "The network is able to satisfy the demand in all cities except for:" << endl;

                auto result = waterSupply->maxFlowAll();

                for (int i = 0; i < result.size() - 1; i++) {
                    if (waterSupply->getCities().find(result[i].first)->second.getDemand() > result[i].second) {
                        cout << "[" + result[i].first + "] " +
                                waterSupply->getCities().find(result[i].first)->second.getName() << " -> Deficit of "
                             << waterSupply->getCities().find(result[i].first)->second.getDemand() -
                                result[i].second << endl;
                    }
                }
                waitForInput();
                break;
            }
            case 3:
                //print algorithm we come up with
                waitForInput();
                break;
            case 4:
                runMainMenu();
                return;
            case 5:
                cout << "Thank you for using our Water Supply Analysis System (˶ᵔ ᵕ ᵔ˶)"<< endl;
                return;
            default:
                cout << "Invalid Input" << endl;

        }
    }
}

void Menu::runReliabilityFailureMenu(){
    while (true){
        system("clear");
        printReliabilityFailureMenu();

        int option;
        cin >> option;

        switch(option){
            case 1:
                runRemoveReservoirMenu();
                waitForInput();
                break;
            case 2:
                runRemovePSMenu();
                waitForInput();
                break;
            case 3:
                runPipelineRemoveMenu();
                waitForInput();
                break;
            case 4:
                runMainMenu();
                return;
            case 5:
                cout << "Thank you for using our Water Supply Analysis System (˶ᵔ ᵕ ᵔ˶)"<< endl;
                return;

        }
    }
}

void Menu::runRemoveReservoirMenu() {
    printRemoveReservoirMenu();

    int option;
    cin >> option;

    auto mapReservoir = waterSupply->getReservoirs();
    auto mapCity = waterSupply->getCities();

    if (option > mapReservoir.size() or option <= 0) {
        cout << "Invalid Reservoir! Please try again.\n";
        return;
    }

    auto result = waterSupply->flowRemoveNode("R_" + to_string(option));

    auto resultRemoved = result.first;
    auto resultActual = result.second;
    sort(resultRemoved.begin(), resultRemoved.end(), comparator);
    sort(resultActual.begin(), resultActual.end(), comparator);


    cout << "These cities were affected after removing R_" << option << " (" << mapReservoir["R_" + to_string(option)].getName() << "):" << endl;

    for (int i = 0; i < resultActual.size(); i++) {
        if (resultActual.at(i).first == resultRemoved.at(i).first and resultActual.at(i).second > resultRemoved.at(i).second) {
            if (resultActual.at(i).first == "MAX FLOW") {
                cout << "Maximum flow before reservoir removal: "<< resultActual.at(i).second << endl;
                cout << "Maximum flow after reservoir removal: " << resultRemoved.at(i).second << endl;
                cout << "Deficit: " << resultActual.at(i).second - resultRemoved.at(i).second << endl;
            } else {
                cout << "[" + resultActual.at(i).first + "] " << mapCity[resultActual.at(i).first].getName() << " || Old Flow: "
                << resultActual.at(i).second << " || New Flow: " << resultRemoved.at(i).second << " || Deficit: " <<
                resultActual.at(i).second - resultRemoved.at(i).second << endl;
            }
        }
    }
}

void Menu::runPipelineRemoveMenu() {
    while (true) {
        printRemovePipelineMenu();

        vector<pair<string, int>> resActual, resTemp;
        string origin, dest, input;
        int maxFlowTemp, maxFlowActual;
        bool noCitiesAffected = true;
        cin >> input;

        istringstream ss(input);

        getline(ss, origin, ',');
        getline(ss, dest);

        if (!waterSupply->flowRemovePipeline(origin, dest, resActual, resTemp, maxFlowActual, maxFlowTemp)) {
            cout << "Pipeline not found!" << endl;
            waitForInput();
        }
        else {
            cout << "These cities were affected after removing the pipeline:" << endl;

            for (int i = 0; i < resActual.size() - 1; i++) {

                if (resActual[i].second != resTemp[i].second){

                    cout << "[" + resActual[i].first + "] " +
                            waterSupply->getCities().find(resActual[i].first)->second.getName() << " || Old flow: "
                         << (resActual[i].second) << " || New flow: "
                         << (resTemp[i].second) << endl;

                    noCitiesAffected= false;

                }
            }

            if(noCitiesAffected){
                cout << "No cities affected!" << endl;
            }

            cout << "Maximum flow before pipe removal: " << maxFlowActual << endl;
            cout << "Maximum flow after pipe removal: " << maxFlowTemp << endl;
            cout << "Deficit: " << maxFlowActual - maxFlowTemp << endl;
            break;
        }
    }
}

void Menu::runRemovePSMenu() {
    printRemovePSMenu();
    int option;
    cin >> option;

    if (option >= waterSupply->getGraph().getNumVertex() - waterSupply->getCities().size() -
        waterSupply->getReservoirs().size() or option <= 0) {
            cout << "Invalid Pumping Station! Please try again.\n";
            return;
        }

    auto result = waterSupply->flowRemoveNode("PS_" + to_string(option));

    auto resultRemoved = result.first;
    auto resultActual = result.second;
    sort(resultRemoved.begin(), resultRemoved.end(), comparator);
    sort(resultActual.begin(), resultActual.end(), comparator);


    cout << "These cities were affected after removing PS_" << option << ":" << endl;
    auto mapCity = waterSupply->getCities();

    for (int i = 0; i < resultActual.size(); i++) {
        if (resultActual.at(i).first == resultRemoved.at(i).first and resultActual.at(i).second > resultRemoved.at(i).second) {
            if (resultActual.at(i).first == "MAX FLOW") {
                cout << "Maximum flow before pumping station removal: "<< resultActual.at(i).second << endl;
                cout << "Maximum flow after pumping station removal: " << resultRemoved.at(i).second << endl;
                cout << "Deficit: " << resultActual.at(i).second - resultRemoved.at(i).second << endl;
            } else {
                cout << "[" + resultActual.at(i).first + "] " << mapCity[resultActual.at(i).first].getName() << " || Old Flow: "
                     << resultActual.at(i).second << " || New Flow: " << resultRemoved.at(i).second << " || Deficit: " <<
                     resultActual.at(i).second - resultRemoved.at(i).second << endl;
            }
        }
    }
}

void Menu::write(const string &path) {
    ofstream of;
    of.open(path + "citiesFlow.csv", ofstream::out | ofstream::trunc);
    of.close();
    of.open(path + "citiesFlow.csv", ofstream::out | ofstream::app);
    of << "CityCode,CityName,Flow\n";
    auto cityMap = waterSupply->getCities();
    for (auto v: waterSupply->getGraph().getVertexSet()) {
        if (v->getInfo().at(0) == 'C') {
            double flow = 0;
            for (auto e: v->getIncoming()) {
                    flow += e->getFlow();
            }
            of << v->getInfo() << ',' << cityMap[v->getInfo()].getName() << ',' << flow << '\n';
        }
    }
}


