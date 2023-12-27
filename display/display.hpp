#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <vector>
#include <map>
#include "../parsing/parsing.hpp"
#include "../simplify/simplify.hpp"
#include "../resolver/resolver.hpp"
#include "../main.hpp"

class Display
{
	
	public:
		Display(Parser parser, Simplify simplify, Resolver resolver);
		~Display();
		Display(const Display &other);
		Display& operator=(const Display &original);

		void	displayResults(void) const;

		void	test(void) const;

	private:

		int					_polynomialDeg;
		std::vector<int>	_solutions;
		std::vector<Term>	_simplifiedExpression;
		std::vector<Term>	_firstExpression;
		std::vector<Term>	_lastExpression;
};

#endif
