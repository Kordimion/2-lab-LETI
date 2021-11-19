#pragma once
#include <map>
#include <functional>
#include <string>

#define LoopHandleFunction std::function<void()>

class ConsoleLoop 
{
private:
	std::map<std::string, LoopHandleFunction> handlers;
public:
	void AddHandler(const char * trigger, LoopHandleFunction f);
	void Start();
};
