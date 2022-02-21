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
	Drink(std::string name, int value, int seed, int milk, int syrup, int possibleFail  = 20) {
		this->name = name;
		this->value = value;
		this->seedAmounth = seed;
		this->milkAmounth = milk;
		this->syrupAmounth = syrup;
		this->possibleFail = possibleFail;
	};
	~Drink();
	
};

