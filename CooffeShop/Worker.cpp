#include <string>
#include <iostream>

class Worker
{
public:
	std::string name;
	bool isBusy;
	int timeToDo;



	Worker(std::string name = "Azam",int time = 0)
	{
		this->name = name;
		this->isBusy = false;
		this->timeToDo = time;
	};
	~Worker() {
		std::cout << "Destruct" << "\n";
	};

	void busyToggle() {
		this->isBusy = !this->isBusy;
	}

	void setTime(int time) {
	 this->timeToDo = time;
	}

	void checkIsDone() {
		if (this->isBusy)
		{
			this->timeToDo--;
			if (timeToDo <= 0)
			this->busyToggle();
		}
	}

};
