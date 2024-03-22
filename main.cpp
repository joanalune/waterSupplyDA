#include <iostream>
#include "Headers/WaterSupply.h"

int main() {
    WaterSupply waterSupply;

    //True for SmallSet, False for LargeSet
    waterSupply.readSet(true);


    for (auto cityIdCity : waterSupply.getCities()) {
        cout << cityIdCity.second.getName() << '\n';
    }
    cout << '\n';
    for (auto reservoirIdReservoir : waterSupply.getReservoirs()) {
        cout << reservoirIdReservoir.second.getName() << '\n';
    }


    return 0;
}
