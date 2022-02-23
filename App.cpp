#include <iostream>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <iterator>
#include "windows.h"
#include "Controller.cpp"
#include "ConsumerGenerator.cpp"



class App
{
public:
	std::list<Consumer*> consumers;
	Drink* drinks[5] = {
		new Drink("Capucinno", 100, 20, 100, 10, 5),
		new Drink("Americano", 80, 30, 0, 0, 2),
		new Drink("Mocha", 140, 20, 100, 10, 30),
		new Drink("Espresso", 110, 20, 100, 10, 10),
		new Drink("HotChocolate", 200, 0, 300, 100),
	};

	Worker* workers[5] = {
		new Worker("Alyaksey", 7),
		new Worker ("Roman", 4),
		new Worker("Ivan", 10),
		new Worker("Sarvar", 8),
		new Worker(),
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
			this->controller->timeWasting(randomInt(0, 20));
			cin.get();	
			}*/

		while (this->controller->isEndOfDay()) {
			this->consumers.push_back(generator->generateConsumer());
			

			for (auto it = this->consumers.begin(); it != this->consumers.end(); it++) {
				this->controller->createDrink(this->DrinkSpecByName((*it)->drinkName), this->workers[Randomizer::randomInt(0, 5)]);

			}
			this->controller->timeWasting(Randomizer::randomInt(0, 20));
		}

		
	}

};
