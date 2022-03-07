
#include <iostream>
#include<ctime>
#include<memory>
#include "App.cpp"

int main()
{
	srand(time(0));//обнуляет время для псевдо-случайных для генератора  пременных
	std::unique_ptr<App> app = std::make_unique<App>();
	app->start();
	return 0;
}


