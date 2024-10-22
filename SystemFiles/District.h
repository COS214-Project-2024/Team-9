#ifndef DISTRICT_H
#define DISTRICT_H

#include "CityUnit.h";

class District : public CityUnit {

private:
	std::vector<CityUnit*> containedCityUnit;

public:
	District();

	void add(CityUnit* newUnit);

	void remove(CityUnit* unit);

	~District();

	void update();

	Iterator* createIterator();

	double getEmploymentRate();

	int payTaxes(int s);

	int evaluateHappiness();

	int countCitizens();
};

#endif
