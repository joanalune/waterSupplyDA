#include "../Headers/Menu.h"

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
    cout    << "1. Consult maximum amount of water that can reach a city"<< endl;
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
    cout    << "3. Display crucial pipelines for water delivery in a specific city" << endl;
    cout    << "4. Return to main menu" << endl;
    cout    << "5. Exit" << endl;
}

void Menu::runDataChoiceMenu(){

    while(true){
        system("clear");
        printDataChoiceMenu();

        int option;
        cin >> option;

        switch(option){
            case 1:
                waterSupply->readSet(true);
                runMainMenu();
                return;
            case 2:
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

        switch(option){
            case 1:
                //ask which city
                //display max amount of water
                waitForInput();
            case 2:
                //display networks ability to satisfy costumers
                waitForInput();
            case 3:
                //ask which city
                //display crucial pipes
                waitForInput();
            case 4:
                runMainMenu();
                return;
            case 5:
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
                //ask which water reservoirs
                //simulate removal
                waitForInput();
            case 2:
                //ask which pumping stations
                //simulate removal
                waitForInput();
            case 3:
                //ask which city
                //show
                waitForInput();
            case 4:
                runMainMenu();
                return;
            case 5:
                return;

        }
    }
}


