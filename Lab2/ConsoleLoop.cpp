#include "ConsoleLoop.h"
#include <string>
#include <iostream>

void ConsoleLoop::Start() 
{
	std::string command;
	while(true)
	{
		std::cin >> command;
		if(command == "break") break;

		auto result = handlers.find(command);
		if (result != handlers.end()) 
		{
			auto f = result->second;
			f();
			continue;
		}

		std::cout << "\ncommand not found\n\n";
	}
	return;
}

void ConsoleLoop::AddHandler(const char * str, LoopHandleFunction f) 
{
	handlers[str] = f;
}
