#include <vector>
#include "Store.cpp"
#include "Drink.cpp"
#include "Worker.cpp"

class Stat
{
public:
	int consumers;
	int evMark;
	int fail;
	int success;

	void coutInfo() {
		std::cout << "\n";
		std::cout << "--------------------------------------";
		std::cout << "Consumers amounth: " << this->consumers << "\n";
		std::cout << "Everage mark: " << this->evMark << "\n";
		std::cout << "Fails amounth: " << this->fail << "\n";
		std::cout << "Success amounth: " << this->success << "\n";
		std::cout << "--------------------------------------";
		std::cout << "\n";
	}
};

class Controller
{
public:
	int day = 1;
	int time = 1440;
	bool isChasiersBusy[2] = {
		false,
		false
	};
	Controller()
	{
		this->store = new Store(1000, 2300, 1000, 100);
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
			this->time -= worker->time;
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

	void reset() {
		this->day++;
		this->time = 1440;
	}

	void timeWasting(int num) {
		this->time -= num;
	}

	bool isEndOfDay() {
		return this->time < 0;
	}

	void addStats() {

	}

private:
	Store *store;
};