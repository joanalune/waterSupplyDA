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
    void printRemovePSMenu();
    void printRemovePipelineMenu();

    //menu running functions
    void runDataChoiceMenu();
    void runMainMenu();
    void runServiceMetricsMenu();
    void runReliabilityFailureMenu();

    void runRemoveReservoirMenu();
    void runRemovePSMenu();
    void runPipelineRemoveMenu();


    void waitForInput() const;
    void write(const string& path);

};


#endif //WATERSUPPLYDA_MENU_H
