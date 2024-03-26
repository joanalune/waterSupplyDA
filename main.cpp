#include <iostream>
#include "Headers/WaterSupply.h"
#include "Headers/Menu.h"

int main() {
    WaterSupply waterSupply;
    Menu menu(&waterSupply);

    menu.runDataChoiceMenu();

    return 0;
}
