//Base costs of cultures and sensitivities 
//Author: Janice Love
//Date: 2-20-2015
//Updated: 4-21-2015

#include <iomanip>
#include <fstream>
#include <iostream> 
#include <string>

#include "functions.h" 
#include "otherSupplies.h"


using namespace std; 

//Variables:


int main()
{
	
	ofstream myFile;
	ofstream anotherFile;
	myFile.open("prices.txt");
	anotherFile.open("components.txt");

	double a = bloodAgar();
	double b = fungalPlate();
	double c = mannitolPlate();
	double d = macConkeyPlates();
	double e = sterileSwabs();
	double f = TSBmedia();
	double g = thioMedia();
	double h = MHplates();
	
	double amp = ampicillin();
	double aC = amoxClav();
	double cefaZ = cefazolin();
	double fox = cefoxitin();
	double zone = ceftriazone();
	double doxy = doxycycline();
	double enro = enrofloxacin();
	double gent = gentamicin();
	double marbo = marbofloxacin();
	double oxa = oxacillin();
	double triMS = TrimethSulfa();
	double vanco = vancomycin();

	double sum = amp + aC + cefaZ + fox + zone + doxy + enro + gent + marbo
		+ oxa + triMS + vanco; 

	double hoodIncinerator = bacticinerator();
	double microscope = scope();
	double slides = microscopeSlides();
	double gloves = glovesUsed(); //use 6 gloves
	double pTowels = paperTowels(); //use 3 paper towels 
	double innocLoops = dInnoculationLoops(); 
	double oil = immersionOil(); 
	double pads = benchPads();
	double hoodCert = BSCcert();
	double BSCcost = hoodCost();
	double hoodFiveYears = filterChange();
		double totalBSCcost = hoodCert + BSCcost + hoodFiveYears; 
	double gramStain = Gstain();
	double sporeStain = ssStain();
	double drySlides =  bibPaper();
	double incubators = vwrIncubators();
	double cleanAlcohol =  alcohol();
	double labor = techTime(); //one 15-minute period
	
	double otherSupplies = slides + gloves + pTowels 
		+ innocLoops + oil + pads + gramStain + drySlides
		+ cleanAlcohol + e + sporeStain; 

		//equipment
	double equipCost = incubators + totalBSCcost 
		+ microscope + hoodIncinerator; 

	//anaerobic culture
	double anaerobic = g + slides + gloves + pTowels
		+ pads + gramStain + drySlides + cleanAlcohol
		+ (labor * 2) + equipCost; 
	double anaerobic2 = anaerobic - (labor); 

	//aerobic culture
	double aerobic = a + c + d + ( e * 3 ) + f + g  
		+ (slides * 2) + (gloves * 2) + pTowels + oil + pads 
		+ (gramStain * 2) + sporeStain + 
		drySlides + cleanAlcohol + (labor * 2) + equipCost;
	double aerobic2 = aerobic - (labor);

	//fungal
	double fungal = b + (e * 2) + slides + (gloves * 2) + cleanAlcohol + equipCost
		+ (labor * 2) + pads;
	double fungal2 = fungal; 

	//sensitivity 
	double sensitivity = sum + otherSupplies
		+ gramStain + (h * 2) + (labor* 3) + equipCost;
			//to add: MacFarland standards, disk dispenser, control strains + supplies?
	

	//germ-free
	double GF = a + b + c + d + (e * 4) + f + g + equipCost + (slides * 3)
		+ (pTowels * 4) + innocLoops + (oil * 3) + pads + (gramStain * 3)
		+ sporeStain + drySlides + cleanAlcohol + (labor * 2) + (gloves * 3);

	//non-BCM prices 
	double z = anaerobic; 
	double anaerobicPRICE = costNONBCM (z); 
	
	double y = aerobic;
	double aerobicPRICE = costNONBCM (y);

	double x = fungal;
	double fungalPRICE = costNONBCM (x);

	double w = sensitivity;
	double sensitivityPRICE = costNONBCM (w);

	double tripleSUM = aerobic2 + anaerobic2 + sensitivity;
	double tripleSUM_PRICE = costNONBCM (tripleSUM); 

	double doubleSUM = aerobic2 + sensitivity;
	double doubleSUM_PRICE = costNONBCM (doubleSUM);

	//outside BCM prices
	double u = anaerobic;
	double an_out = costOUTSIDE (u);

	double t = aerobic;
	double aero_out = costOUTSIDE (t);

	double s = sensitivity;
	double sens_out = costOUTSIDE (s);

	double r = fungal;
	double fungal_out = costOUTSIDE (r); 

	double tripleOUT = costOUTSIDE (tripleSUM);
	double doubleOUT = costOUTSIDE (doubleSUM);


	myFile << fixed << setprecision(2);
	myFile << "MEDIA PRICES" << endl; 
	myFile << "Blood agar: $ " << a << endl;
	myFile << "Fungal plate: $ " << b << endl;
	myFile << "Mannitol plate: $ " << c << endl;
	myFile << "MacConkey plate: $ " << d << endl;
	myFile << "TSB media: $ " << f << endl;
	myFile << "Thioglycollate media: $ " << g << endl;
	myFile << endl;
	myFile << "ANTIBOTICS PRICES" << endl;
	myFile << "Ampicillin: $ " << amp << endl;
	myFile << "Amoxicillin: $ " << aC << endl;
	myFile << "Cefazolin: $ " << cefaZ << endl;
	myFile << "Cefoxitin: $ " << fox << endl;
	myFile << "Doxycycline: $ " << doxy << endl;
	myFile << "Enrofloxacin: $ " << enro << endl;
	myFile << "Gentamicin: $ " << gent << endl;
	myFile << "Marbofloxacin: $ " << marbo << endl;
	myFile << "Oxacillin: $ " << oxa << endl;
	myFile << "Trimethaprim-Sulfamethoaxzole: $ " << triMS << endl;
	myFile << "Vancomycin: $ " << vanco << endl;
	myFile << "Total cost of disks for one sensitivity: $ " << sum << endl;
	myFile << endl;
	myFile << "OTHER PRICES" << endl;
	myFile << "Microscope slides: $ " << slides << endl;
	myFile << "Gloves: $ " << gloves << endl;
	myFile << "Paper towels: $ " << pTowels << endl;
	myFile << "Innoculation loops: $ " << innocLoops << endl;
	myFile << "Immersion Oil: $ " << oil << endl;
	myFile << "Bench pads: $ " << pads << endl;
	
	myFile << "Gram Stain: $ " << gramStain << endl;
	myFile << "Bibulous Paper: $ " << drySlides << endl;
	
	myFile << "Alcohol: $ " << cleanAlcohol << endl; 
	myFile << "Sterile Swabs: $ " << e << endl; 
	myFile << endl;
	myFile << "Total cost of non-media supplies: $ " << otherSupplies << endl;
	myFile << endl;

	myFile << "EQUIPMENT COSTS" << endl;
	myFile << "Incubators: $ " << incubators << endl;
	myFile << "Bio Safety Cabinet certification: $ " << hoodCert << endl;
	myFile << "Microscope: $" << microscope << endl;
	myFile << "BSC cost: $ " << BSCcost << endl;
	myFile << "BSC filter change: $ " << hoodFiveYears << endl;
	myFile << "Bacticinerator: $ " << hoodIncinerator << endl;
	myFile << "Total equipment costs: $ " << equipCost << endl;
	myFile << endl;
	myFile << endl;
	myFile << "GERM-FREE COSTS: " << endl;
	myFile << "Basic Germ-free cost: $ " << GF << endl;
	myFile << endl;
	myFile << "BCM CULTURE AND SENSITIVITY PRICES:" << endl;
	myFile << "Fungal culture: $ " << fungal << endl;
	myFile << "Anaerobic culture: $" << anaerobic << endl;
	myFile << "Aerobic culture: $" << aerobic << endl;
	myFile << "Sensitivity: $" << sensitivity << endl;
	myFile << "Aerobic culture, Anaerobic culture, sensitivity: $" << aerobic2 + 
		anaerobic2 + sensitivity << endl;
	myFile << "Aerobic culture and sensitivity: $" << aerobic2 + sensitivity
		<< endl;
	myFile << endl;
	myFile << "NON-BCM CULTURE AND SENSITIVITY PRICES: " << endl;
	myFile << "Fungal culture: $" << fungalPRICE << endl;
	myFile << "Anaerobic culture: $" << anaerobicPRICE << endl;
	myFile << "Aerobic culture: $" << aerobicPRICE << endl;
	myFile << "Sensitivity: $" << sensitivityPRICE << endl;
	myFile << "Aerobic, Anaerobic cultures and sensitivity: $" << tripleSUM_PRICE << endl;
	myFile << "Aerobic culture and sensitivity: $" << doubleSUM_PRICE << endl;
	myFile << endl;
	myFile << "NON-ACADEMIC CULTURE AND SENSITIVITY PRICES: " << endl;
	myFile << "Fungal culture: $" << fungal_out << endl;
	myFile << "Anaerobic culture: $" << an_out << endl;
	myFile << "Aerobic culture: $" << aero_out << endl;
	myFile << "Sensitivity culture: $" << sens_out << endl;
	myFile << "Aerobic, anaerobic cultures and sensitivity: $" << tripleOUT << endl;
	myFile << "Aerobic culture and sensitivity: $" << doubleOUT << endl;
	myFile << endl;


		anotherFile << "COMPONENTS:" << endl;
		anotherFile << endl;
		anotherFile << "Basic Germ-free cost:" << endl;
		anotherFile << "	1. blood agar" << endl;
		anotherFile << "	2. fungal plate" << endl;
		anotherFile << "	3. mannitol plate" << endl;
		anotherFile << "	4. MacConkey plate" << endl;
		anotherFile << "	5. Sterile swabs (x4)" << endl;
		anotherFile << "	6. TSB media" << endl;
		anotherFile << "	7. Thio media" << endl;
		anotherFile << "	8. Equipment cost" << endl;
		anotherFile << "	9. microscope slides (x3)" << endl;
		anotherFile << "	10. paper towels (x4)" << endl;
		anotherFile << "	11. Innoculation loops" << endl;
		anotherFile << "	12. Immersion oil (x3)" << endl;
		anotherFile << "	13. Gram stain (x3)" << endl;
		anotherFile << "	14. Spore stain" << endl;
		anotherFile << "	15. Bibulous Paper" << endl;
		anotherFile << "	16. Alcohol" << endl;
		anotherFile << "	17. Labor (x2)" << endl;
		anotherFile << "	18. Gloves (x3)" << endl;
		anotherFile << endl;
		anotherFile << "Equipment costs (#8):" << endl;
		anotherFile << "	1. incubators " << endl;
		anotherFile << "	2. total bio safety cabinet cost " << endl;
		anotherFile << "	3. microscope" << endl;
		anotherFile << "	4. hood incinerator" << endl;
		anotherFile << endl;
		anotherFile << "Total biosafety cabinet cost (#8): " << endl;
		anotherFile << "	1. BSC certification" << endl;
		anotherFile << "	2. BSC purchase price + depreciation" << endl;
		anotherFile << "	3. BSC filter change (every 5 years, x4)" << endl;
		anotherFile << endl;
		anotherFile << "Labor costs: " << endl;
		anotherFile << "	1. cost per fifteen minutes ($4)" << endl;
		anotherFile << endl;
		anotherFile << "Anaerobic culture costs: " << endl;
		anotherFile << "	1. thio media" << endl;
		anotherFile << "	2. microscope slides" << endl;
		anotherFile << "	3. gloves" << endl;
		anotherFile << "	4. paper towels" << endl;
		anotherFile << "	5. gram stain " << endl;
		anotherFile << "	6. bibulous paper" << endl;
		anotherFile << "	7. Alcohol" << endl;
		anotherFile << "	8. labor (x2)" << endl;
		anotherFile << "	9. equipment cost" << endl;
		anotherFile << endl;
		anotherFile << "Aerobic culture costs:" << endl;
		anotherFile << "	1. blood agar" << endl;
		anotherFile << "	2. mannitol plate" << endl;
		anotherFile << "	3. MacConkey plate" << endl;
		anotherFile << "	4. sterile swabs (x3)" << endl;
		anotherFile << "	5. TSB media" << endl;
		anotherFile << "	6. Thio media" << endl;
		anotherFile << "	7. microscope slides (x2)" << endl;
		anotherFile << "	8. gloves (x2)" << endl;
		anotherFile << "	9. paper towels" << endl;
		anotherFile << "	10. bench pads" << endl;
		anotherFile << "	11. gram stain (x2)" << endl;
		anotherFile << "	12. spore stain" << endl;
		anotherFile << "	13. bibulous paper" << endl;
		anotherFile << "	14. alcohol" << endl;
		anotherFile << "	15. labor (x2)" << endl;
		anotherFile << "	16. equipmet cost" << endl;
		anotherFile << endl;
		anotherFile << "Fungal culture costs: " << endl;
		anotherFile << "	1. fungal plate" << endl;
		anotherFile << "	2. sterile swabs" << endl;
		anotherFile << "	3. gloves (x2)" << endl;
		anotherFile << "	4. alcohol" << endl;
		anotherFile << "	5. equipment cost" << endl;
		anotherFile << "	6. labor (x2)" << endl;
		anotherFile << "	7. bench pads" << endl;
		anotherFile << endl;
		anotherFile << "Sensitivity costs:" << endl;
		anotherFile << "	1. sum of antibiotics" << endl;
		anotherFile << "	2. Mueller-Hinton plates" << endl;
		anotherFile << "	3. equipment cost" << endl;
		anotherFile << "	4. labor (x3)" << endl;
		anotherFile << "	5. TO-ADD: MarFarland standards, disk dispenser, control stains?" 
			<< endl;
		anotherFile << endl;







	system("pause");

	return 0;

}