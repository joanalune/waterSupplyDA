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

    //menu running functions
    void runDataChoiceMenu();
    void runMainMenu();
    void runServiceMetricsMenu();
    void runReliabilityFailureMenu();


    void waitForInput() const;

    void printMaxFlowAll();

};


#endif //WATERSUPPLYDA_MENU_H
