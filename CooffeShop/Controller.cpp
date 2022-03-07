#include <vector>
#include "Store.cpp"
#include "Drink.cpp"
#include "Worker.cpp"

class Stat
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

	double countEvmark() {
		if (marks.size() == 0) {
			return 0;
		}
		int initMark = 0;
		for (int i = 0; i < marks.size(); i++) {
			initMark += marks[i];
		}
		return initMark / marks.size();
	}

	void coutInfo() {
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
	int time = 1440;
	bool isChasiersBusy[2] = {
		false,
		false
	};
	std::vector<Stat*> stats;
	Stat* curStat = new Stat();
	Controller()
	{
		this->store = new Store(10000, 23000, 10000, 1000);
	}
	;
	~Controller() {
		delete this->store;
	};

	bool isFail(int possible) {
		if (1 + rand() % 100 < possible) {
			return true;
		};
		return false;
	}

	bool createDrink(Drink* drink, Worker* worker) {
		if (this->store->seed < drink->seedAmounth ||
			this->store->milk < drink->milkAmounth ||
			this->store->milk < drink->syrupAmounth ||
			this->isFail(drink->possibleFail)
			)
		return false;
			this->store->seed -= drink->seedAmounth;
			this->store->milk -= drink->milkAmounth;
			this->store->milk -= drink->syrupAmounth;
			worker->setTime(drink->timeTodo);
			worker->busyToggle();
		return true;
	}

	bool isAllCashiersBusy() {
		for (int i = 0; i < 2; i++) {
			if (this->isChasiersBusy[i] == false)
				return false;
		}
		return true;
	}

	void takeCashier() {
		if (!this->isChasiersBusy[0]) {
			this->isChasiersBusy[0] = true;
		}
		else
			this->isChasiersBusy[1] = true;

	}

	void freeCashier() {
		if (this->isChasiersBusy[0]) {
			this->isChasiersBusy[0] = false;
		}
		else
			this->isChasiersBusy[1] = false;
	}

	

	void timeWasting(int num) {
		this->time -= num;
	}

	bool isEndOfDay() {
		return this->time < 0;
	}

	void coutAllStats() {
			std::cout << "\n";
			std::cout << "Day No" << stats.size() << "\n";
			this->stats[stats.size()-1]->coutInfo();
			std::cout << "\n";
	}

	void reset() {
		this->day++;
		this->time = 1440;
		this->stats.push_back(this->curStat);
		//this->curStat = new Stat();
		this->coutAllStats();	
		delete this->store;
		this->store = new Store(10000, 23000, 10000, 1000);

	}


};