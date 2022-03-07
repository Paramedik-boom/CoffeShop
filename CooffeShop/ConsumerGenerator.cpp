#include <ctime>
#include"Consumer.cpp"

class Randomizer {
public:
	static int randomInt(int left, int right) {//возврашает число от левого до правого
		return left + rand() % right;
	}
};


class ConsumerGenerator//класс генератор покупателей и напитков 
{
public:
	std::string drinksName[5] = { "Capucinno","Americano",
				   "Mocha","Espresso","HotChocolate"
	};

	std::string names[10] = {
		"Alexandr", "Kostya",
		"Roman", "Azam",
		"Sarvar", "Muslim",
		"Ivan", "Gena", "Denis",
		"Maksim"
	};
	 Consumer* generateConsumer(int time) {
		return new Consumer(this->names[Randomizer::randomInt(0,6)], this->drinksName[Randomizer::randomInt(0, 11)], time);
	}
	
		
};
