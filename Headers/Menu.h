#ifndef WATERSUPPLYDA_MENU_H
#define WATERSUPPLYDA_MENU_H

#include "iostream"
#include "WaterSupply.h"
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

    //menu running functions
    void runDataChoiceMenu();
    void runMainMenu();
    void runServiceMetricsMenu();
    void runReliabilityFailureMenu();

    void runMaxFlowSingleMenu();
    void runRemoveReservoirMenu();


    void waitForInput() const;

    void printMaxFlowAll();
    void printMaxFlowSingle(const string& cityCode);

};


#endif //WATERSUPPLYDA_MENU_H
