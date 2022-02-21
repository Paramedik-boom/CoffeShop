#include <string>

class Consumer
{
public:
	
	std::string name;
	std::string drinkName;
	int mark;

	Consumer(std::string name, std::string drinkName, int mark = 100)
	{
		this->name = name;
		this->drinkName = drinkName;
		this->mark = mark;
	}

	~Consumer()
	{
			
	}
};
