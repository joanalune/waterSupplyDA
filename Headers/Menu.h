#ifndef WATERSUPPLYDA_MENU_H
#define WATERSUPPLYDA_MENU_H

#include "iostream"
#include "WaterSupply.h"
#include <iomanip>
#include <cmath>
using namespace std;


class Menu {
private:
    WaterSupply *waterSupply;
public:
    Menu(WaterSupply *w);

    //menu printing functions
    void printDataChoiceMenu();
    void printMainMenu();
    void printServiceMetricsMenu();
    void printReliabilityFailureMenu();

    void printMaxFlowSingleMenu();
    void printRemoveReservoirMenu();
    void printRemovePSMenu();
    void printRemovePipelineMenu();

    //menu running functions
    void runDataChoiceMenu();
    void runMainMenu();
    void runServiceMetricsMenu();
    void runReliabilityFailureMenu();

    void runMaxFlowSingleMenu();
    void runRemoveReservoirMenu();
    void runRemovePSMenu();
    void runPipelineRemoveMenu();


    void waitForInput() const;
    void write(const string& path);

    void printMaxFlowAll();
    void printMaxFlowSingle(const string& cityCode);
    void printBalanceFlow();

};


#endif //WATERSUPPLYDA_MENU_H
