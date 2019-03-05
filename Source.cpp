#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* This program allows the user to learn different facts from 4 different classes of sea animals
The user can also input their own custom facts for each category
*/

//Alan McElroy
//Animal-Facts prgram


struct facts {		//Contains the arrays for the 4 categories of animals
					//as well as the 5th hidden category which allows the user to input custom fact
					//each category can hold 100 animal facts, the first 2 are already created
	string aquarium[5][100] = {

		{	//Species
			"Whale",
			"Shark",
			"Octopus",
			"Dolphin"

		},

		//Fun Facts for Whales
		{ "Blue Whales are the largest animals ever to live.",
		"Sperm Whales can dive up to 2,000 meters."
		},

		//Fun Facts for Sharks
		{ "Sharks are different from fish because they have eyelids.",
		"Sharks have been living on earth for 450 million years."
		},

		//Fun Facts for Octopuses
		{ "Octopuses have 3 hearts.",
		"Instead of swimming, octopuses walk along the sea floor."
		},

		//Fun Facts for Dolphins
		{ "The Killer Whale is actually a type of dolphin.",
		"Female dolphins are called cows, male dolphins are called bulls, and baby dolphins are called calves."
		}
	};
	int numWhales = 2, numSharks = 2, numOcto = 2, numDolph = 2;

};
//list of functions
int whichAnimal();
void outputFact(int, facts*);
void addFacts(facts*);
void saveFacts(facts*);
void loadFacts(facts*);

int main()
{
	facts* info = new facts;
	int option = 0;
	string keepgoing = "0";

	loadFacts(info);
	while (keepgoing == "0") {	//while loop to give user option of closing program or keep running
		keepgoing = -1;
		option = 0;
		option = whichAnimal();
		outputFact(option, info);

		while (keepgoing != "0" && keepgoing != "1") {
			cout << "\nDo you want to do again? 0 = yes or 1 = no\n";
			cin >> keepgoing;
		}
	}
	saveFacts(info);	//Saves user inputed facts in a file
}

int whichAnimal() {
	int option = 0;
	while (option < 1 || option > 5) {	//using a while loop to ask user their input
		cout << "What sea animal would you like to learn about?" <<
			"\n1. Whales\n2. Sharks\n3. Octopuses\n4. Dolphins\n5. Add fact" << endl;
		cin >> option;
	}
	return option;
}
void outputFact(int option, facts* aqua) {
	if (option == 1) { //Whales
		cout << aqua->aquarium[1][rand() % aqua->numWhales];
	}
	if (option == 2) { //Sharks
		cout << aqua->aquarium[2][rand() % aqua->numSharks];
	}
	if (option == 3) { //Octopi
		cout << aqua->aquarium[3][rand() % aqua->numOcto];
	}
	if (option == 4) { //Dolphins
		cout << aqua->aquarium[4][rand() % aqua->numDolph];
	}
	if (option == 5) { //allows user to add fact

		addFacts(aqua);
	}

}

void addFacts(facts* AnimalFacts) {	//If user chose add fact, allows user to choose 
	int userChoice;					//what animal the fact is for
	string userFact;
	cout << "What fact do you want to add?\n 1) Whales \n 2) Sharks \n 3) Octopus \n 4) Dolphins: ";
	cin >> userChoice;
	cout << "Please enter your fact: ";
	cin.ignore();
	getline(cin, userFact);

	//If statements below are the locations of where the user added the fact
	//num(animal)++ allows new fact to not write over old fact (only up to 100 added facts)
	if (userChoice == 1) {	//add fact to Whales
		AnimalFacts->aquarium[1][AnimalFacts->numWhales] = userFact;
		AnimalFacts->numWhales++;
	}
	if (userChoice == 2) {	//add fact to Sharks
		AnimalFacts->aquarium[2][AnimalFacts->numSharks] = userFact;
		AnimalFacts->numSharks++;
	}
	if (userChoice == 3) {	//add fact to Octopi
		AnimalFacts->aquarium[3][AnimalFacts->numOcto] = userFact;
		AnimalFacts->numOcto++;
	}
	if (userChoice == 4) {	//add fact to Dolphins
		AnimalFacts->aquarium[4][AnimalFacts->numDolph] = userFact;
		AnimalFacts->numDolph++;
	}
}

void saveFacts(facts* factArray) {		//function that saves the user added animal facts
	ofstream myfile("aquarium.facts");	//in a file called aquaium.facts (program creates file)
	if (myfile.is_open())
	{
		myfile << factArray->numWhales << " " << factArray->numSharks <<
			" " << factArray->numOcto << " " << factArray->numDolph << endl;
		for (int i = 1; i < 5; i++) {
			for (int j = 2; j < 100; j++) {	
				myfile << factArray->aquarium[i][j] << endl;
			}
		}

		myfile.close();
	}
	else cout << "Unable to open file";
}

void loadFacts(facts* funfacts) {	//loads aqaurium.facts file so user's custom facts
	string line;					//will appear when they choose animal 
	ifstream myfile("aquarium.facts");
	if (myfile.is_open())
	{for (int i = 2; i < 100; i++) {
		getline(myfile, line);
		if (line != "") {
			funfacts->aquarium[1][i] = line;
	}
}
	for (int i = 2; i < 100; i++) {
		getline(myfile, line);
		if (line != "") {
			funfacts->aquarium[2][i] = line;
	}
}
	for (int i = 2; i < 100; i++) {
		getline(myfile, line);
		if (line != "") {
			funfacts->aquarium[3][i] = line;
	}
}
	for (int i = 2; i < 100; i++) {
		getline(myfile, line);
		if (line != "") {
			funfacts->aquarium[4][i] = line;
	}
}

		myfile.close();
	}

	else cout << "Unable to open file";
}
