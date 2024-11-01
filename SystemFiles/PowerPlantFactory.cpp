#include "PowerPlantFactory.h"

/**
 * @class PowerPlantFactory
 * @brief Factory class for creating Power Plant buildings in the city simulation.
 * 
 * The PowerPlantFactory class implements the factory method to create instances
 * of the Power Plant building type and provides resource cost details for building
 * power plants.
 */

/**
 * @brief Constructs a PowerPlantFactory and initializes resource costs.
 * 
 * Sets the base cost for a Power Plant building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
PowerPlantFactory::PowerPlantFactory() {
 //   std::cout << "Type: Powerplant factory" << std::endl;
    cost = 50; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Destructor for the PowerPlantFactory class.
 */
PowerPlantFactory::~PowerPlantFactory()
{
}

/**
 * @brief Gets the monetary cost to build a Power Plant structure.
 * 
 * @return The construction cost of a Power Plant building.
 */
int PowerPlantFactory::getCost() {
    return cost;
}

/**
 * @brief Retrieves the resource cost for constructing a Power Plant building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> PowerPlantFactory::getResourceCost() {
    return resourceCost;
}

/**
 * @brief Factory method to create a Power Plant building.
 * 
 * @return A pointer to a new Power Plant building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* PowerPlantFactory::factoryMethod() {
    return new Power(100, 0);
}
