#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <vector>
#include <map>
#include "../parsing/parsing.hpp"

class Display
{
	
	public:
		Display(Parser parser);
		~Display();
		Display(const Display &other);
		Display& operator=(const Display &original);

	private:
		
};

#endif
