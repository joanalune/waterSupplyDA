#ifndef WATERSUPPLYDA_RESERVOIR_H
#define WATERSUPPLYDA_RESERVOIR_H

#include <string>
#include "Graph.h"

using namespace std;

class Reservoir {
private:
    std::string reservoirName, reservoirCode, reservoirMunicipality;
    int reservoirId;
    double reservoirDelivery;
public:
    /**
     * Reservoir constructor
     * @param reservoirName
     * @param reservoirCode
     * @param reservoirMunicipality
     * @param reservoirId
     * @param reservoirDelivery
     */
    Reservoir(std::string reservoirName, std::string reservoirCode, std::string reservoirMunicipality, int reservoirId, double reservoirDelivery);
    /**
     * Reservoir empty constructor
     */
    Reservoir() = default;
    /**
     * Sets a reservoir's name
     * @param name
     */
    void setName(std::string name);
    /**
     * Sets a reservoir's code
     * @param code
     */
    void setCode(std::string code);
    /**
     * Sets a reservoir's municipality name
     * @param municipality
     */
    void setMunicipality(std::string municipality);
    /**
     * Sets a reservoir's ID
     * @param id
     */
    void setId(int id);
    /**
     * Sets a reservoir's delivery
     * @param delivery
     */
    void setDelivery(double delivery);
    /**
     * Returns a reservoir's name
     * @return
     */
    string getName() const;
    /**
     * Returns a reservoir's code
     * @return
     */
    string getCode() const;
    /**
     * Returns a reservoir's municipality name
     * @return
     */
    string getMunicipality() const;
    /**
     * Returns a reservoir's ID
     * @return
     */
    int getId() const;
    /**
     * Returns a reservoir's delivery
     * @return
     */
    double getDelivery() const;
};


#endif //WATERSUPPLYDA_RESERVOIR_H
