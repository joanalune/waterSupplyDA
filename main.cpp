#include <iostream>
#include "Headers/WaterSupply.h"

int main() {
    WaterSupply waterSupply;

    //True for SmallSet, False for LargeSet
    waterSupply.readSet(true);

    return 0;
}
