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
		new Drink("Americano", 80, 30, 0, 0, 6),
		new Drink("Mocha", 140, 20, 100, 10, 7),
		new Drink("Espresso", 110, 20, 100, 10, 5),
		new Drink("HotChocolate", 200, 0, 300, 100,4),
	};

	Worker* workers[5] = {
		new Worker("Alyaksey"),
		new Worker ("Roman"),
		new Worker("Ivan"),
		new Worker("Sarvar"),
		new Worker(),
	};

	Worker* getFreeWorker() {
		for (int i = 0; i < 5; i++) {
			if (!this->workers[i]->isBusy)
				return this->workers[i];
		}
	}

	bool isAnyFree() {
		for (int i = 0; i < 5; i++) {
			if (!this->workers[i]->isBusy)
				return true;
		}
		return false;
	}

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
		while (true) {
			while (!this->controller->isEndOfDay()) {
				if (Randomizer::randomInt(0, 101) < 10) {
					this->consumers.push_back(generator->generateConsumer(this->controller->time));
					this->controller->curStat->addConsumers();
				}
				auto it = this->consumers.begin();
				while (it != this->consumers.end()) {
					if ((*it)->timeToLeave(this->controller->time))
					{
						this->consumers.erase(it);
						this->controller->curStat->addMark(0);
						break;
					}
					if(this->isAnyFree())
					{
						if (this->controller->createDrink(this->DrinkSpecByName((*it)->drinkName), this->getFreeWorker()))
						{
							this->controller->curStat->addSuccess();
							this->controller->curStat->addMark(5);
							this->consumers.erase(it);
							break;
						}
						else
							this->controller->curStat->addFail();
					}
					
					if (this->consumers.empty())
						break;
					it++;
				}
				this->controller->timeWasting(1);
				for (int i = 0; i < 5; i++) {
					this->workers[i]->checkIsDone();
				}
			}
			this->controller->reset();
			std::cin.get();
			system("cls");
		}
	}

};
