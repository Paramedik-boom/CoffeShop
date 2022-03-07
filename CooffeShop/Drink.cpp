#include<string>
class Drink
{
public:
	std::string name;
	int value;
	int seedAmounth;
	int milkAmounth;
	int syrupAmounth;
	int possibleFail;
	int timeTodo;
	Drink(std::string name, int value, int seed, int milk, int syrup,int timeTodo, int possibleFail  = 10) {
		this->name = name;
		this->value = value;
		this->seedAmounth = seed;
		this->milkAmounth = milk;
		this->syrupAmounth = syrup;
		this->possibleFail = possibleFail;
		this->timeTodo = timeTodo;
	};
	~Drink();
	
};

