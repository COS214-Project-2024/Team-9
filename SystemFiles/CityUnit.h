#ifndef CITYUNIT_H
#define CITYUNIT_H

#include <vector>
#include <map>
#include "Citizen.h"
#include "Iterator.h"

class CityUnit {

protected:
	int totalCapacity;
	int usedCapacity;
	std::vector<Citizen*> resident;
	double taxRate;

	// Protected to prevent direct instantiation of CityUnit
	CityUnit(int totalCap, int usedCap, double taxR);

public:

	virtual void add(CityUnit* newUnit) = 0;

	virtual void remove(CityUnit* unit) = 0;

	virtual ~CityUnit();

	virtual int calculateDistanceTo(CityUnit* destination) = 0;

	virtual std::vector<Citizen*>& getResidents(){
		static std::vector<Citizen*> emptyList;  // An empty list for units without residents
        return emptyList;
		};

	virtual int getRemainingCapacity() = 0;

	virtual int getUsedCapacity() = 0;

	virtual void update() = 0;

	virtual void employResidents() = 0;

	virtual Iterator* createIterator() = 0;

	virtual double getEmploymentRate() = 0;

	inline void setTaxRate(double amount){this->taxRate = amount;};

	/**
	 * Checks if the building type is residential. If it is then loop through the associated citizens and decrement their balance.
	 */
	virtual double payTaxes(double rate) = 0;

	virtual int evaluateHappiness() = 0;

	virtual int countCitizens() = 0;

	virtual std::map<std::string, int> collectResources();

};

#endif
