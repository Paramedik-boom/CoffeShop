#include <string>
#include <iostream>

class Worker //класс работник
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

	void busyToggle() {//переключатель режима работника
		this->isBusy = !this->isBusy;
	}

	void setTime(int time) {//уcтановка КД(cooldown)
	 this->timeToDo = time;
	}

	void checkIsDone() {// проверка закончания работы и перевод на переключателя
		if (this->isBusy)
		{
			this->timeToDo--;
			if (timeToDo <= 0)
			this->busyToggle();
		}
	}

};
