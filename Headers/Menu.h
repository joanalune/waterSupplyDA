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

    /**
     * Prints the menu where the user chooses the data set
     */
    void printDataChoiceMenu();
    /**
     * Prints the main menu, where user chooses between checking service metrics
     * or reliability and failures
     */
    void printMainMenu();
    /**
     * Prints the service metrics menu
     */
    void printServiceMetricsMenu();
    /**
     * Prints the reliability and failure menu
     */
    void printReliabilityFailureMenu();

    /**
     * Prints the maximum flow choice menu
     */
    void printMaxFlowSingleMenu();
    /**
     * Prints the reservoir removal menu
     */
    void printRemoveReservoirMenu();
    /**
     * Prints the pumping station removal menu
     */
    void printRemovePSMenu();
    /**
     * Prints the pipeline removal menu
     */
    void printRemovePipelineMenu();

    //menu running functions

    /**
     * Calls printDataChoiceMenu() and processes user inputs for
     * choosing dataset
     */
    void runDataChoiceMenu();
    /**
     * Calls printMainMenu() and processes user inputs for choosing the
     * next menu
     */
    void runMainMenu();
    /**
     * Calls printServiceMetricsMenu() and processes user inputs for choosing
     * which metric to consult
     */
    void runServiceMetricsMenu();
    /**
     * Calls printReliabilityFailureMenu() and processes user inputs for choosing
     * what situation to simulate
     */
    void runReliabilityFailureMenu();
    /**
     * Calls printMaxFlowSingleMenu() and processes user inputs to print maximum
     * flow operations' results
     */
    void runMaxFlowSingleMenu();
    /**
     * Calls printRemoveReservoirMenu() and processes user inputs to print reservoir
     * removal operation results
     */
    void runRemoveReservoirMenu();
    /**
     * Calls printRemovePSMenu() and processes user inputs to print pumping station
     * removal results
     */
    void runRemovePSMenu();
    /**
     * Calls printPipelineRemoveMenu() and processes user inputs to print pipeline
     * removal results
     */
    void runPipelineRemoveMenu();

    /**
     * Waits for an input from the user before terminating, used to allow the viewing
     * of results before another menu is printed
     */
    void waitForInput() const;
    /**
     *  Writes every city's names, codes and flows to file in specified path
     *  @details Time complexity: O(V * c * i), V being the number of vertices, c
     *  being the number of cities and i being the number of a city's incoming edges
     * @param path
     */
    void write(const string& path);

    /**
     * Prints the name and flow of every city in the graph and the maximum flow
     */
    void printMaxFlowAll();
    /**
     * Prints the maximum flow for the city with code cityCode
     * @param cityCode
     */
    void printMaxFlowSingle(const string& cityCode);
    void printBalanceFlow();

};


#endif //WATERSUPPLYDA_MENU_H
