#include"Consumer.cpp"
#include <ctime>




class ConsumerGenerator
{
public:
	int randomInt(int left, int right) {
		return left + rand() % right;
	}

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
	 Consumer* generateConsumer() {
		return new Consumer(this->names[this->randomInt(0,6)], this->drinksName[this->randomInt(0, 11)]);
	}
	
		
};
