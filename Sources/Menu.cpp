#include "../Headers/Menu.h"


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
    cout    << "1. Consult maximum amount of water that can reach a city"<< endl;
    cout    << "2. Consult the networks' ability to provide water to all its customers" << endl;
    cout    << "3. Balance the load across the network" << endl; //greedy strategy, may not be possible to implement
    cout    << "4. Check the network's resilience" << endl; //go to reliabilty and failure menu
    cout    << "5. Return to main menu" << endl;
    cout    << "6. Exit" << endl;
}

void Menu::printReliabilityMetricsMenu(){
    cout << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << "     Water Supply Network Analysis      " << endl;
    cout    << "        Reliability and Failures        " << endl;
    cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout    << endl;
    cout    << "What would you like to consult?" << endl;
    cout    << "1. Simulate water reservoir removal"<< endl;
    cout    << "2. Simulate pumping station removal" << endl;
    cout    << "3. Display crucial pipelines for water delivery in a specific city" << endl;
    cout    << "4. Return to main menu" << endl;
    cout    << "5. Exit" << endl;
}

