#ifndef RESOLVER_HPP
#define RESOLVER_HPP

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "../parsing/parsing.hpp"
#include "../simplify/simplify.hpp"
#include "../main.hpp"

class Resolver
{
	
	public:

		Resolver(Parser parser, Simplify simplify);
		~Resolver();
		Resolver(const Resolver &original);
		Resolver&	operator=(const Resolver &other);

		std::vector<int>	getResults(void) const;
		
		void	test(void) const;

	private:

		void			findExprResults(void);
		std::string		replaceNullExponent(void);
		
		std::vector<int>	_results;
		std::vector<Term>	_simplifiedExpr;
		std::vector<Term>	_firstExpr;
		std::vector<Term>	_secondExpr;	
};

#endif
