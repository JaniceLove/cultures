//Non-media supplies for cultures 
//Author: Janice Love
//Date: 3-3-2015

#include "otherSupplies.h"

double microscopeSlides()
{
	double price = 1082.19;
	int quantity = 3600;
	double pricePerSlide = price / quantity;
	return pricePerSlide;
}

double glovesUsed()
{
	double price = 165.40;
	int quantity = 3000;
	double pricePerGlove = price / quantity;
	return pricePerGlove;
}

double paperTowels()
{
	double price = 65.31;
	int pk = 120;
	int box = 12;
	int quantity = pk * box; 
	double pricePerTowel = price / quantity;
	return pricePerTowel; 
}

double dInnoculationLoops()
{
	double price = 110.83;
	int quantity = 1000;
	double pricePerLoop = price / quantity;
	return pricePerLoop;
}

double bacticinerator()
{
	double price = 371.42;
	int years = 10;
	double depreciation = price / years;
	double cost = depreciation / 520;
	return cost;
}

double immersionOil()
{
	double price = 371.42;
	int volume = 473; 
	double usage = volume * 10; 
	double cost = price / usage; 
	return cost;
}

double benchPads()
{
	double price = 26.9;
	int quantity = 150;
	double pricePerPad = price / quantity; 
	return pricePerPad;
}

double BSCcert()
{
	double price = 250;
	double quantity = 520;
	double cost = price / quantity;
	return cost;
}

double Gstain()
{
	double price = 104.04;
	double quantity = 40;
	double cost = price / quantity; 
	return cost;
}

double ssStain()
{
	double price = 21.45;
	double quantity = 500;
	double perML = price / quantity; 
	int usage = 3; //3mls per sample 
	double cost = perML * usage;
	return cost;
}

double bibPaper()
{
	double price = 3.55;
	double quantity = 50 * 4; //50 pages, 4 slides per page
	double cost = price / quantity;
	return cost;
}

double vwrIncubators()
{
	//germ-free, assumes each sample has BA and dextrose plate,
	//one in each incubator. 
	double price = 1601.52; //per incubator
	int years = 8;
	double depreciation = price / years;
	//double currentValue = price - depreciation; //for 2015
	double bothIncubators = depreciation * 2; 
	double samplesPerYear = 520; //average 10 samples per week 
	double cost = bothIncubators / samplesPerYear; 
	return cost;
}

double alcohol()
{
	double price = 88.80;
	int quantity = 12;
	double cost = price / quantity; 
	int qPerBottle = 32; //oz
	double costPerOz = cost / qPerBottle;
	return costPerOz;
}

double techTime()
{
	double hour = 23.38; // $23.38 per hour
	double fifteen = 4; 
	double time = hour / fifteen;
	return time;
}

double scope()
{
	double price = 15568;
	int years = 8;
	double depreciation = price / years; 
	double cost = depreciation / 520; 
	return cost;
}

double hoodCost()
{
	double price = 15000;
	int years = 8;
	double depreciation = price / years; 
	double cost = depreciation / 520; 
	return cost;
}

double filterChange()
{
	double price = 1431;
	int frequency = 4;
	double totalPrice = price * frequency;
	int years = 20;
	double costPerYear = totalPrice / years;
	double ppp = costPerYear / 520;
	return ppp;
}









