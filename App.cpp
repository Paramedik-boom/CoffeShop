#include <iostream>
#include <vector>
#include <map>
#include "windows.h"
#include "Controller.cpp"
#include "ConsumerGenerator.cpp"
#include "Worker.cpp"



class App
{
public:
	Drink* drinks[5] = {
	new Drink("Capucinno", 100, 20, 100, 10, 5),
	new Drink("Americano", 80, 30, 0, 0, 2),
	new Drink("Mocha", 140, 20, 100, 10, 30),
	new Drink("Espresso", 110, 20, 100, 10, 10),
	new Drink("HotChocolate", 200, 0, 300, 100),
	};

	Drink* DrinkSpecByName(std::string name) {
		std::map <std::string, int> mapping;
		mapping["Capucinno"] = 0;
		mapping["Americano"] = 1;
		mapping["Mocha"] = 2;
		mapping["Espresso"] = 3;
		mapping["HotChocolate"] = 4;
		return this->drinks[mapping[name]];
	};

	std::vector<Consumer*> consumers;
	Controller* controller;
	ConsumerGenerator* generator;
	App()
	{
		this->generator = new ConsumerGenerator();
		this->controller = new Controller();
	};
	~App()
	{
	};
	void start() {
		/*while (true) {
			Consumer* newConsumer = generator->generateConsumer();
			if (this->controller->createDrink(this->DrinkSpecByName(newConsumer->drinkName)))
			{
				std::cout << "Success!!" << "\n";
			}else
				std::cout << "Fail!!" << "\n";
			consumers.push_back(newConsumer);
			for (int i = 0; i < consumers.size(); i++) {
				std::cout << consumers[i]->name << "\n";
			}
			Sleep(3000);
		}*/
		Worker* Alesya = new Worker();
		delete Alesya;
	}

};
