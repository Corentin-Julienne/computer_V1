#ifndef SIMPLIFY_HPP
#define SIMPLIFY_HPP

#include <iostream>
#include <algorithm>
#include "../parsing/parsing.hpp"

#define	BEFORE_EQU	0
#define AFTER_EQU	1

class Simplify
{

	public:

		Simplify(Parser parser);
		~Simplify();

		std::vector<Term>	getReducedExpression(void) const;

		void	test(void) const;
	
	private:
	
		void	reduceExpression(void);
		bool	compareExponent(const std::map<std::string, int> &alpha, const std::map<std::string, int> &bravo);
		void    sortExpression(int exprType);
		
		std::vector<Term> 	_exprBeforeEqual;
		std::vector<Term>	_exprAfterEqual;
		std::vector<Term>	_reducedExpression;
		int					_maxExponent;
};

#endif
