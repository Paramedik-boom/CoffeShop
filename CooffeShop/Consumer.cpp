#include <string>

class Consumer
{
public:
	
	std::string name;
	std::string drinkName;
	int mark;
	int timeToWait;
	bool isServiced = false;

	Consumer(std::string name, std::string drinkName,int time, int mark = 100)
	{
		this->name = name;
		this->drinkName = drinkName;
		this->mark = mark;
		this->timeToWait = time;
	}

	bool timeToLeave(int curTime) { //сравнение времени прихода и ожидание покупателя если больше 30минут покупатель уходит
		return timeToWait - curTime > 30;
	}

	~Consumer()
	{
			
	}
};
