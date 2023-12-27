#ifndef MAIN_HPP
#define MAIN_HPP

#include "./parsing/parsing.hpp"

struct Term 
{
	int				sign;
	int				exponent;
	std::string		coef;
	bool			isInt = true;	
};

#endif
