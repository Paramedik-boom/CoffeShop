
#include <iostream>
#include<ctime>
#include "App.cpp"

int main()
{
	srand(time(0));
	App *app = new App();
	app->start();
	return 0;
}


