#include "SpendResources.h"
#include "SewageSystemFactory.h"
#include "WaterPlantFactory.h"
#include "WasteSiteFactory.h"
#include "PowerPlantFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "LandmarkFactory.h"

SpendResources::SpendResources() {
	this->SewageFact = new SewageSystemFactory();
	this->WaterFact = new WaterPlantFactory();
	this->WasteFact = new WasteSiteFactory();
	this->PowerFact = new PowerPlantFactory();
	this->ResidentialFact = new ResidentialFactory();
	this->CommercialFact = new CommercialFactory();
	this->LandmarkFact = new LandmarkFactory();
}

SpendResources::~SpendResources()
{
	delete this->SewageFact;
	delete this->WaterFact;
	delete this->WasteFact;
	delete this->PowerFact;
	delete this->ResidentialFact;
	delete this->CommercialFact;
	delete this->LandmarkFact;
}

void SpendResources::excecuteCommand(double employmentRate, std::map<std::string, int> resources, int& balance,int citizenSatisfaction,std::map<std::string, int> utilities) {
	//find all priority values
	int EmploymentPriority = employmentPriority(employmentRate);//0
	int citizenSatisfactionPriority = citizenPriority(citizenSatisfaction);//1
	int PowerPriority = utilPriority(utilities["PowerPlant"]);//2
	int WaterPriority = utilPriority(utilities["WaterPlant"]);//3
	int WastePriority = utilPriority(utilities["WasteSite"]);//4
	int SewagePriority = utilPriority(utilities["SewageSystem"]);//5

	//find smallest priority value, if there are values that are the same, which can only happen for utilities, it doesn't matter. They have the same priority so either one can be built
	int roulette[6] = {EmploymentPriority,citizenSatisfactionPriority,PowerPriority,WaterPriority,WastePriority,SewagePriority};
	int decisionVal =999;

	for(int i =0; i <6;i++ )
	{
		if(roulette[i] < decisionVal)
		{
			decisionVal = i;
		}
	}

	//actually build the buildings
	//still need to add the building returned to the city unit somehow, dk how yet tho probably just need to attach it to government, will see tomorow how to do it
	//Check if you have enough money to build a new building.
	//Use a helper function to check if you have enough resources to build the building.
	switch (decisionVal)
	{
	case 0:
		if(balance >= CommercialFact->getCost()&&checkResources(resources,CommercialFact->getResourceCost()))
		{
			balance -= CommercialFact->getCost();
			CityUnit* temp = this->CommercialFact->build();
			// gvmt->attach(temp);
		}
		break;
	case 1:
		if(balance >= LandmarkFact->getCost()&&checkResources(resources,LandmarkFact->getResourceCost()))
		{
			balance -= LandmarkFact->getCost();
			CityUnit* temp = this->LandmarkFact->build();
			// gvmt->attach(temp);
		}
		break;
	case 2:
		if(balance >= PowerFact->getCost()&&checkResources(resources,PowerFact->getResourceCost()))
		{
			balance -= PowerFact->getCost();
			CityUnit* temp = this->PowerFact->build();
			// gvmt->attach(temp);
		}
		break;
	case 3:
		if(balance >= WaterFact->getCost()&&checkResources(resources,WaterFact->getResourceCost()))
		{
			balance -= WaterFact->getCost();
			CityUnit* temp = this->WaterFact->build();
			// gvmt->attach(temp);
		}
		break;
	case 4: 
		if(balance >= WasteFact->getCost()&&checkResources(resources,WasteFact->getResourceCost()))
		{
			balance -= WasteFact->getCost();
			CityUnit* temp = this->WasteFact->build();
			// gvmt->attach(temp);
		}
		break;
	case 5: 
		if(balance >= SewageFact->getCost()&&checkResources(resources,SewageFact->getResourceCost()))
		{
			balance -= SewageFact->getCost();
			CityUnit* temp = this->SewageFact->build();
			// gvmt->attach(temp);
		}
		break;
	default:
		break;//idk follow a moose,they're always going somewhere nice
	}
}

int SpendResources::employmentPriority(double employmentRate)
{
	int bucket = static_cast<int>(employmentRate) / 10;
	std::map<int,int> value = {{0,1},{1,4},{2,7},{3,10},{4,13},{5,16},{6,19},{7,22},{8,25},{9,28}};//table of priorities
    return value[bucket];
}

int SpendResources::citizenPriority(double citizenSatisfacction)
{
    int bucket = static_cast<int>(citizenSatisfacction) / 10;
	std::map<int,int> value = {{0,2},{1,5},{2,8},{3,11},{4,14},{5,17},{6,20},{7,23},{8,26},{9,29}};//table of priorities
    return value[bucket];
}

int SpendResources::utilPriority(double dk)
{
    int bucket = static_cast<int>(dk) / 10;
	std::map<int,int> value = {{0,30},{1,27},{2,24},{3,21},{4,18},{5,15},{6,12},{7,9},{8,6},{9,3}};//table of priorities
    return value[bucket];
}

bool SpendResources::checkResources(std::map<std::string, int> haveResources, std::map<std::string, int> needResources)
{
    for (const auto& [resource, amount] : needResources) {
        if (haveResources[resource] < amount) {
            return false;
        }
    }
    // If check passed, subtract resources
    for (const auto& [resource, amount] : needResources) {
        haveResources[resource] -= amount;
    }
    return true;
}

