#include "Store.cpp"
#include "Drink.cpp"

//std::string name, int value, int seed, int milk, int syrup


class Controller
{
public:
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

	bool createDrink(Drink* drink) {
		if (this->store->seed < drink->seedAmounth ||
			this->store->milk < drink->milkAmounth ||
			this->store->milk < drink->syrupAmounth ||
			this->isFail(drink->possibleFail)
			)
		return false;
			this->store->seed -= drink->seedAmounth;
			this->store->milk -= drink->milkAmounth;
			this->store->milk -= drink->syrupAmounth;
		return true;
	}

private:
	Store *store;
};