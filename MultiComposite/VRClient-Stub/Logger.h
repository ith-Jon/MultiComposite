#pragma once
#include <iostream>
#include <fstream>
#include <string>

class dlog
{
	public:
	static void Println(std::string s)
	{
		std::fstream fs("C:\\Users\\DrPotato\\Documents\\GitHub\\MultiComposite\\MultiComposite\\x64\\Debug\\log.txt", std::ios_base::app);
		fs << s << '\n';
		std::cout << s << '\n';
		fs.close();
	}
};
