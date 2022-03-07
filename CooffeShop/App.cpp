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
	std::list<Consumer*> consumers; //список покупателей и название и рецепт напитков 
	Drink* drinks[5] = {
		new Drink("Capucinno", 100, 20, 100, 10, 5),
		new Drink("Americano", 80, 30, 0, 0, 6),
		new Drink("Mocha", 140, 20, 100, 10, 7),
		new Drink("Espresso", 110, 20, 100, 10, 5),
		new Drink("HotChocolate", 200, 0, 300, 100,4), 
	};

	Worker* workers[5] = { //обявление переменных работников
		new Worker("Alyaksey"),
		new Worker ("Roman"),
		new Worker("Ivan"),
		new Worker("Sarvar"),
		new Worker(),
	};

	Worker* getFreeWorker() {  // получить свободных работников
		for (int i = 0; i < 5; i++) {
			if (!this->workers[i]->isBusy)
				return this->workers[i];
		}
	}

	bool isAnyFree() { //проверка свободных работников
		for (int i = 0; i < 5; i++) {
			if (!this->workers[i]->isBusy)
				return true;
		}
		return false;
	}

	Drink* DrinkSpecByName(std::string name) { //получит характеристику заказенных напитков
		std::map <std::string, int> mapping;
		mapping["Capucinno"] = 0;
		mapping["Americano"] = 1;
		mapping["Mocha"] = 2;
		mapping["Espresso"] = 3;
		mapping["HotChocolate"] = 4;
		return this->drinks[mapping[name]];
	};

	Controller* controller; // контроллери ведётся учёт
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
			while (!this->controller->isEndOfDay()) { //проверка окончания дня
				if (Randomizer::randomInt(0, 101) < 10) { //вероятность прихода клиента каждую минуту
					this->consumers.push_back(generator->generateConsumer(this->controller->time)); // если вероятность сработал покупатель добавляется в очередь 
					this->controller->curStat->addConsumers(); // добавить покупателя в статистику
				}
				auto it = this->consumers.begin(); //начало обхода листа покупателей 
				while (it != this->consumers.end()) { 
					if ((*it)->timeToLeave(this->controller->time))// проверка ожидания покупателя (даётся 30минут после неё покупатель уходит) 
					{
						this->consumers.erase(it);//не даволный покупатель  ставит оценку 0 если он не получил свой напиток
						this->controller->curStat->addMark(0);
						break;
					}
					if(this->isAnyFree())//поверка свободных работников
					{
						if (this->controller->createDrink(this->DrinkSpecByName((*it)->drinkName), this->getFreeWorker()))//проверка, выборка и создание напитка 
						{
							this->controller->curStat->addSuccess();//если напиток был сделан в статистики добавляетя удачный напиток 
							this->controller->curStat->addMark(5);//ставится оценка работы
							this->consumers.erase(it);// удаляет покупателя
							break;
						}
						else
							this->controller->curStat->addFail();//если напиток не получается добавляетя неудача в статистике и покупатель снова идёт по циклу пока не получить напиток 
					}
					
					if (this->consumers.empty())//если покупателя нет начинается новая минута
						break;
					it++;
				}// конец обхода листа покупателей
				this->controller->timeWasting(1);
				for (int i = 0; i < 5; i++) {
					this->workers[i]->checkIsDone();//уменшение КД(cooldown)
				}
			}
			this->controller->reset();
			std::cin.get();
			system("cls");
		}
	}

};
