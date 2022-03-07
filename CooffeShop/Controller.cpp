#include <vector>
#include "Store.cpp"
#include "Drink.cpp"
#include "Worker.cpp"

class Stat// класс введение статистики считивается колиечство покупателей,неудач,удач и оценок
{
public:
	int consumers;
	int fail;
	int success;
	std::vector<int> marks;

	Stat() {
		this->consumers = 0;
		this->fail = 0;
		this->success = 0;
	}

	double countEvmark() {//подсчёт средную оценку
		if (marks.size() == 0) {
			return 0;
		}
		int initMark = 0;
		for (int i = 0; i < marks.size(); i++) {
			initMark += marks[i];
		}
		return initMark / marks.size();
	}

	void coutInfo() {//вывести информация(статистику)
		std::cout << "\n";
		std::cout << "--------------------------------------" << "\n";
		std::cout << "Consumers amounth: " << this->consumers << "\n";
		std::cout << "Everage mark: " << this->countEvmark() << "\n";
		std::cout << "Fails amounth: " << this->fail << "\n";
		std::cout << "Success amounth: " << this->success << "\n";
		std::cout << "--------------------------------------";
		std::cout << "\n";
	}

	void addMark(int num) {
		this->marks.push_back(num);
	}

	void addFail() {
		this->fail++;
	}

	void addSuccess() {
		this->success++;
	}

	void addConsumers() {
		this->consumers++;
	}

};

class Controller
{
private:
	Store* store;
public:
	int day = 1;
	int time = 1440;//в одном дне 1440 минут
	bool isChasiersBusy[2] = {//проевка свободной кассы
		false,
		false
	};
	std::vector<Stat*> stats;//переменная для сбора статистики
	Stat* curStat = new Stat();
	Controller()
	{
		this->store = new Store(10000, 23000, 10000, 1000);//количество ингридиентов
	}
	;
	~Controller() {
		delete this->store;
	};

	bool isFail(int possible) {//испортился ли напиток предел 1
		if (1 + rand() % 100 < possible) {
			return true;
		};
		return false;
	}

	bool createDrink(Drink* drink, Worker* worker) {// проверка ингридиентов и фейла
		if (this->store->seed < drink->seedAmounth ||
			this->store->milk < drink->milkAmounth ||
			this->store->milk < drink->syrupAmounth ||
			this->isFail(drink->possibleFail)
			)
		return false;
			this->store->seed -= drink->seedAmounth;//если фейл занового отнимется ингридиенты
			this->store->milk -= drink->milkAmounth;
			this->store->milk -= drink->syrupAmounth;
			worker->setTime(drink->timeTodo);// работник заного занят и отгнимается на время
			worker->busyToggle();
		return true;
	}

	bool isAllCashiersBusy() {//проверка касс
		for (int i = 0; i < 2; i++) {
			if (this->isChasiersBusy[i] == false)
				return false;
		}
		return true;
	}

	void takeCashier() {//если касса незанята принимаетя заказ
		if (!this->isChasiersBusy[0]) {
			this->isChasiersBusy[0] = true;
		}
		else
			this->isChasiersBusy[1] = true;

	}

	void freeCashier() {//провеока 2ой кассы
		if (this->isChasiersBusy[0]) {
			this->isChasiersBusy[0] = false;
		}
		else
			this->isChasiersBusy[1] = false;
	}

	

	void timeWasting(int num) {// функсия отнимает время от дня
		this->time -= num;
	}

	bool isEndOfDay() {//проверка конца дня
		return this->time < 0;
	}

	void coutAllStats() {//показ дня статистики
			std::cout << "\n";
			std::cout << "Day No" << stats.size() << "\n";
			this->stats[stats.size()-1]->coutInfo();
			std::cout << "\n";
	}

	void reset() {//обновление дня и ингридиентов
		this->day++;
		this->time = 1440;
		this->stats.push_back(this->curStat);
		//this->curStat = new Stat();
		this->coutAllStats();	
		delete this->store;
		this->store = new Store(10000, 23000, 10000, 1000);

	}


};