#include <string>
#include <iostream>

class Worker
{
public:
	std::string name;
	int time;



	Worker(std::string name = "Azam", int time = 5)
	{
		this->name = name;
		this->time = time;
		

	};
	~Worker() {
		std::cout << "Destruct" << "\n";
	};


};

Worker* ne = new Worker(1);
