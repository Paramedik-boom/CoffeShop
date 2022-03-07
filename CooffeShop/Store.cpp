#include <iostream>

enum INGRIDIENTS {
	seedIngridient,
	milkIngridient,
	syrupIngridient,
	desertIngridient,
};

class Store //класс склад
{	
public:
	int seed;
	int milk;
	int syrup;
	int desert;
	Store(int seed, int milk, int syrup, int desert)
	{
		this->seed = seed;
		this->milk = milk;
		this->syrup = syrup;
		this->desert = desert;
	}
	~Store() {
		this->seed = 0;
		this->milk = 0;
		this->syrup = 0;
		this->desert = 0;
	};

	void add(int ingridient, int value) {
		switch (ingridient)
		{
					
			case seedIngridient: {
				this->seed += value;
			}break;

			case milkIngridient: {
				this->milk += value;
			}break;

			case syrupIngridient: {
				this->syrup += value;
			}break;

			case desertIngridient: {
				this->desert += value;
			}break;
		

		default:
			break;
		}
	}

	void removeVal(int ingridient, int value) {
		switch (ingridient)
		{

		case seedIngridient: {
			this->seed -= value;
		}break;

		case milkIngridient: {
			this->milk -= value;
		}break;

		case syrupIngridient: {
			this->syrup -= value;
		}break;

		case desertIngridient: {
			this->desert -= value;
		}break;


		default:
			break;
		}
	}

};
