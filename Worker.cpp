#include <string>
#include <iostream>

class Worker
{
public:
	std::string name;
	int time;
	bool isBusy;



	Worker(std::string name = "Azam", int time = 5)
	{
		this->name = name;
		this->time = time;
		this->isBusy = false;
		

	};
	~Worker() {
		std::cout << "Destruct" << "\n";
	};

	void makeDrink(){}
	void busyToggle() {
		this->isBusy = !this->isBusy;
	}

};
