#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicles
{
protected:
	string regnr;
	string brand;
	string colour;
	int wheels;
	int seats;
public:
	// Konstruktor
	Vehicles(string regnr, string brand, string colour, int wheels, int seats) : regnr(regnr), brand(brand), colour(colour), wheels(wheels), seats(seats) {};
	Vehicles() {};

	//Printar ut alla gemensamma attribut4
	void print();
	// Printar ut extra attributen
	virtual void printType() = 0;

	//Söker fram regNr,märke,färg
	string get_regNr()
	{
		return regnr;
	}
	string get_brand()
	{
		return brand;
	}
	string get_colour()
	{
		return colour;
	}

};

void Vehicles::print()
{
	cout << "* BRAND: " << brand << endl;
	cout << "* REGNR: " << regnr << endl;
	cout << "* COLOUR: " << colour << endl;
	cout << "* WHEELS: " << wheels << endl;
	cout << "* SEATS: " << seats << endl;
	cout << "--EXTRA ATTRIBUTE--" << endl;
	printType(); // Går till specifika objektets metod som skriver ut dess egna variabel
}

//-----------------------------

class Car : public Vehicles
{
private:
	bool cab;
	bool towbar;

public:
	Car(string regnr, string brand, string colour, int wheels, int seats, bool cab, bool towbar) : Vehicles(regnr, brand, colour, wheels, seats), cab(cab), towbar(towbar) {};
	Car() {};

	void printType();
};

void Car::printType()
{
	cout << "* TYPE: CAR" << endl;
	if (cab == true)
	{
		cout << "* IS A CABRIOLET" << endl;
	}
	else
	{
		cout << "* NOT CABRIOLET" << endl;
	}
	if (towbar == true)
	{
		cout << "* HAS A TOWBAR" << endl;
	}
	else
	{
		cout << "* NO TOWBAR" << endl;
	}
}

class Bus : public Vehicles
{
private:
	bool floors;
	bool roof;

public:

	Bus(string regnr, string brand, string colour, int wheels, int seats, bool floors, bool roof) : Vehicles(regnr, brand, colour, wheels, seats), floors(floors), roof(roof) {};

	void printType();
};

void Bus::printType()
{
	cout << "* TYPE: BUS" << endl;

	if (floors == true)
	{
		cout << "* HAS A SECOND FLOOR" << endl;
	}
	else
	{
		cout << "* NO SECOND FLOOR" << endl;
	}
	if (roof == true)
	{
		cout << "* HAS A ROOF" << endl;
	}
	else
	{
		cout << "* HAS NO ROOF" << endl;
	}
}

class Truck : public Vehicles
{
private:
	bool loaded;
	bool boogieWheels;

public:

	Truck(string regnr, string brand, string colour, int wheels, int seats, bool loaded, bool boogieWheels) : Vehicles(regnr, brand, colour, wheels, seats), loaded(loaded), boogieWheels(boogieWheels) {};

	void printType();
};

void Truck::printType()
{
	cout << "* TYPE: TRUCK" << endl;
	if (loaded == true)
	{
		cout << "* LOADED WITH HAPPINESS" << endl;
	}
	else
	{
		cout << "* NO HAPINESS LOADED" << endl;
	}
	if (boogieWheels == true)
	{
		cout << "* HAS BOOGIE WHEELS" << endl;
	}
	else
	{
		cout << "* HAS NO BOOGIE WHEELS" << endl;
	}
}

class Bicycle : public Vehicles
{
private:
	bool basket;
	bool rack;

public:
	Bicycle(string regnr, string brand, string colour, int wheels, int seats, bool basket, bool rack) : Vehicles(regnr, brand, colour, wheels, seats), basket(basket), rack(rack) {};

	void printType();
};

void Bicycle::printType()
{
	cout << "* TYPE: BICYCLE" << endl;
	if (basket == true)
	{
		cout << "* HAS A BASKET" << endl;
	}
	else
	{
		cout << "* NO BASKET" << endl;
	}
	if (rack == true)
	{
		cout << "* HAS A RACK" << endl;
	}
	else
	{
		cout << "* NO RACK" << endl;
	}
}

class Motorcycle : public Vehicles
{
private:
	bool sidecar;
	bool windshield;

public:

	Motorcycle(string regnr, string brand, string colour, int wheels, int seats, bool sidecar, bool windshield) : Vehicles(regnr, brand, colour, wheels, seats), sidecar(sidecar), windshield(windshield) {};

	void printType();
};

void Motorcycle::printType()
{
	cout << "* TYPE: MOTORCYCLE" << endl;
	if (sidecar == true)
	{
		cout << "* HAS A SIDECAR" << endl;
	}
	else
	{
		cout << "* NO SIDECAR" << endl;
	}

	if (windshield == true)
	{
		cout << "* HAS A WINDSHEILD" << endl;
	}
	else
	{
		cout << "* NO WINDSHEILD" << endl;
	}
}

// I headern
class Garage
{
private:
	vector<Vehicles *> inGarage;

	string garageName;
	string answer, s_answer;
	string answerreg, answerRegnr, answerColour, answerBrand;
	int answerEraseVeh;

	// Variabler till skapandet av fordon - till konstruktorn + Variaber till alla extra attribut som är booelans. (Finns säkert snyggare sett att göra det på)
	string regnr, brand, colour, s_yesno;
	int wheels, seats;
	bool answer1, answer2;

	// Quit main menyn
	bool quit = true;

	// int till createGarage metoden
	int spots;

	// variabler till garage constructor - skapa garage platser
	string licenseplate;
	bool garageSpot;

public:
	Garage() {} // en tom constructor för vårat objekt i main
	Garage(string regNr, bool garageSpot) : licenseplate(regNr), garageSpot(garageSpot) {}	// En constructor med en string för vårat garage - vi har overloadat våran constructor, vi kan välja att construct med eller utan en string
	Garage(string regnr, string brand, string colour, int wheels, int seats, bool isCab, bool isTowbar) {}

	// Program metoder
	void createGarage();
	void mainmenu();
	void printExistingVehicles();
	void printGarageSpots();
};


void Garage::createGarage()
{
	cout << "----- Name your garage: -----" << endl;
	getline(cin, garageName);
	system("cls");
	cout << "----- How many parking spots does your garage have? -----" << endl;
	cin >> spots;
	cout << endl;
	for (int i = 0; i < spots; i++)
	{
		cout << "--------------|" << endl;
		cout << " One P-Spot " << endl;
		cout << "--------------|" << endl;
	}
	cout << endl;
	mainmenu();
}


void Garage::mainmenu()
{
	do
	{
		cout << "-------- Meny -------- " << endl;
		cout << "Choose a vehicle to create and park it in the garage: " << endl << endl;
		cout << "1. Create a Car" << endl;
		cout << "2. Create a Bus" << endl;
		cout << "3. Create a Truck" << endl;
		cout << "4. Create a Bicycle" << endl;
		cout << "5. Create a Motorcycle" << endl;
		cout << "----------------------" << endl;
		cout << "6. Print Garage Spots" << endl;
		cout << "7. Print all vehicles" << endl;
		cout << "8. Search vehicle" << endl;
		cout << "9. Remove Vehicle" << endl;
		cout << "0. Exit" << endl;
		cout << "----------------------" << endl;
		cout << "Type answer : ";  cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case '1':
			// Skapa bil med gemensamma attribut
			if (inGarage.size() < spots)
			{

			system("cls");
			cout << "--- CREATING A CAR... ---\n" << endl;
			cout << "Enter license plate : ";
			cin >> regnr;
			cout << "Enter brand : ";
			cin >> brand;
			cout << "Enter colour: ";
			cin >> colour;
			cout << "Enter wheels: ";
			cin >> wheels;
			cout << "Enter seats: ";
			cin >> seats;
			do
			{
				cout << "Is the car a cabriolet.\nType Y for yes\tType N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer1 = true;
				}
				else
				{
					answer1 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			do
			{
				cout << "Has the car a Towbar?\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer2 = true;
				}
				else
				{
					answer2 = false;
				}

				cout << endl;

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			inGarage.push_back(new Car(regnr, brand, colour, wheels, seats, answer1, answer2));
			}
			else
			{
				cout << "Garage is full!!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case '2':
			// Skapa buss
			if (inGarage.size() < spots)
			{

			system("cls");
			cout << "--- CREATING A BUSS... ---" << endl;
			cout << "Enter license plate : ";
			cin >> regnr;
			cout << "Enter brand : ";
			cin >> brand;
			cout << "Enter colour: ";
			cin >> colour;
			cout << "Enter wheels: ";
			cin >> wheels;
			cout << "Enter seats: ";
			cin >> seats;

			do
			{
				//Egna attribut
				cout << "Do you want the buss to have a second floor?\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer1 = true;
				}
				else
				{
					answer1 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			do
			{
				cout << "Do you want the buss to have a roof?.\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer2 = true;
				}
				else
				{
					answer2 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			inGarage.push_back(new Bus(regnr, brand, colour, wheels, seats, answer1, answer2));
			}
			else
			{
				cout << "garage is full" << endl;
			}
			system("pause");
			system("cls");
			break;
		case '3':
			//Skapa truck
			if (inGarage.size() < spots)
			{

			system("cls");
			cout << "--- CREATING A TRUCK... ---\n" << endl;
			cout << "Enter license plate : ";
			cin >> regnr;
			cout << "Enter brand : ";
			cin >> brand;
			cout << "Enter colour: ";
			cin >> colour;
			cout << "Enter wheels: ";
			cin >> wheels;
			cout << "Enter seats: ";
			cin >> seats;
			do
			{
				//Egna attribut
				cout << "Do you want to load your truck with happiness\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer1 = true;
				}
				else
				{
					answer1 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			do
			{
				cout << "Do you want the truck to have booogie wheels?.\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer2 = true;
				}
				else
				{
					answer2 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			inGarage.push_back(new Truck(regnr, brand, colour, wheels, seats, answer1, answer2));
			}
			else
			{
				cout << "Garage is full" << endl;
			}
			system("pause");
			system("cls");
			break;
		case '4':
			//Skapa Bicycle
			if (inGarage.size() < spots)
			{

			system("cls");
			cout << "--- CREATING A BICYCLE... ---\n" << endl;
			cout << "Enter license plate : ";
			cin >> regnr;
			cout << "Enter brand : ";
			cin >> brand;
			cout << "Enter colour: ";
			cin >> colour;
			cout << "Enter wheels: ";
			cin >> wheels;
			cout << "Enter seats: ";
			cin >> seats;
			do
			{
				//Egna attribut
				cout << "Do you want the bicycle to have a basket?\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer1 = true;
				}
				else
				{
					answer1 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			do
			{
				cout << "Do you want the bicycle have a rack?.\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer2 = true;
				}
				else
				{
					answer2 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			inGarage.push_back(new Bicycle(regnr, brand, colour, wheels, seats, answer1, answer2));
			}
			else
			{
				cout << "Garage is full!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case '5':
			//Skapa motorcycle
			if (inGarage.size() < spots)
			{

			system("cls");
			cout << "--- CREATING A MOTORCYCLE... ---\n" << endl;
			cout << "Enter license plate : ";
			cin >> regnr;
			cout << "Enter brand : ";
			cin >> brand;
			cout << "Enter colour: ";
			cin >> colour;
			cout << "Enter wheels: ";
			cin >> wheels;
			cout << "Enter seats: ";
			cin >> seats;
			do
			{
				//Egna attribut
				cout << "Do you want the motorcycle have a sidecar?.\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer1 = true;
				}
				else
				{
					answer1 = false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			do
			{
				cout << "Do you want the motorcycle have a windsheild?.\n Y for yes\t N for no : ";
				cin >> s_yesno;
				s_yesno[0] = toupper(s_yesno[0]);
				if (s_yesno[0] == 'Y')
				{
					answer2 = true;
				}
				else
				{
					answer2= false;
				}

			} while (s_yesno[0] != 'Y' && s_yesno[0] != 'N');

			inGarage.push_back(new Motorcycle(regnr, brand, colour, wheels, seats, answer1, answer2));
			
			}
			else
			{
				cout << "Garage is full!!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case '6':
			printGarageSpots();
			system("pause");
			system("cls");
			break;
		case '7':
			printExistingVehicles();
			cout << endl;
			system("pause");
			system("cls");
			break;
		case '8':
			cout << "What do you want to search for?" << endl;
			cout << "1. Regno\n2. Brand\n3. Colour" << endl;
			cout << "Type answer : ";  cin >> s_answer;
			cout << endl;
			switch (s_answer[0])
			{
			case '1':
				cout << "Case 1" << endl;
				cout << "Enter regnr: ";
				cin >> answerRegnr;
				cout << endl;
				for (int i = 0; i < inGarage.size(); i++)
				{
					if (inGarage[i]->get_regNr() == answerRegnr)
					{
						cout << "Regnr found!!" << endl;
						inGarage[i]->print();
					}
					else
					{
						cout << "-----------------|" << endl;
						cout << "Regnr not found.." << endl;
						cout << "-----------------|" << endl;
					}
				}
				break;
			case '2':
				cout << "Case 2" << endl;
				cout << "Enter brand: ";
				cin >> answerBrand;
				cout << endl;
				for (int i = 0; i < inGarage.size(); i++)
				{
					if (inGarage[i]->get_brand() == answerBrand)
					{
						cout << "Brand found!!" << endl;
						inGarage[i]->print();
					}
					else
					{
						cout << "-----------------|" << endl;
						cout << "Brand not found" << endl;
						cout << "-----------------|" << endl;
					}
				}
				break;
			case '3':
				cout << "Case 3" << endl;
				cout << "Enter colour: ";
				cin >> answerColour;
				cout << endl;
				for (int i = 0; i < inGarage.size(); i++)
				{
					if (inGarage[i]->get_colour() == answerColour)
					{
						cout << "Colour found!!" << endl;
						inGarage[i]->print();
					}
					else
					{
						cout << "-----------------|" << endl;
						cout << "Colour not found" << endl;
						cout << "-----------------|" << endl;
					}
				}
				break;
			default:
				cout << "default" << endl;
			}
			system("pause");
			system("cls");
			mainmenu();
				break;

		case '9':
			cout << "Enter the vehicles regNR to unpark the vehicle: ";
			cin >> answerreg;

			for (int i = 0; i < inGarage.size(); i++) {
				if (inGarage[i]->get_regNr() == answerreg)
				{
					cout << "-----------------|" << endl;
					cout << "Vehicle found!!" << endl;
					inGarage[i]->print();

					swap(inGarage[i], inGarage.back());
					inGarage.pop_back();
					cout << endl;
					cout << "-----------------|" << endl;
				}
				else
				{
					cout << "-----------------|" << endl;
					cout << "Vehicle not found" << endl;
					cout << "-----------------|" << endl;
					cout << endl << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case '0':
			quit = false;
			break;
		default:
			break;
		}
	} while (quit == true);
}

void Garage::printExistingVehicles()
{
	for (int i = 0; i < inGarage.size(); i++)
	{
		cout << "----" << endl;
		inGarage[i]->print();
		cout << "----" << endl;
	}
}

void Garage::printGarageSpots()
{
	for (int i = 0; i < inGarage.size(); i++)
	{
		cout << "------------|" << endl;
		cout << i + 1 << ". " << inGarage[i]->get_regNr() << endl;
		cout << "------------|" << endl;
	}
	cout << endl;

}


int main()
{
	Garage start;


	start.createGarage();

	return 0;
}


