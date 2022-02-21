
#include <iostream>
#include<ctime>
#include "App.cpp"

int main()
{
	std::cout << "Starting app";
	srand(time(0));
	App *app = new App();
	app->start();
	return 0;
}


