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

    void printRemoveReservoirMenu();

    //menu running functions
    void runDataChoiceMenu();
    void runMainMenu();
    void runServiceMetricsMenu();
    void runReliabilityFailureMenu();

    void runRemoveReservoirMenu();


    void waitForInput() const;

};


#endif //WATERSUPPLYDA_MENU_H
