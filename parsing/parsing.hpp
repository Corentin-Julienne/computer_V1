#ifndef PARSING_HPP
#define PARSING_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "../main.hpp"

#define	BEFORE_EQU	0
#define AFTER_EQU	1

class Parser
{
	public:

		Parser(char *args);
		~Parser();
		Parser(const Parser &other);
		Parser& operator=(const Parser &original);

		int	getPolynomialDeg(void) const;
		std::vector<Term>	getExprBeforeEqual(void) const;
		std::vector<Term>	getExprAfterEqual(void) const;

		void	test(void) const;
	
	private:

		void	extractData(char *args);
		void	processExpression(std::string expr, int exprSide);
		void	storeExpression(std::string expr, int exprSide);
		void	calculatePolynomialDegree();

		void	displayTerm(Term term, int index) const;
		void	displayExprs(std::string title, int exprSide) const;

		int					_polynomialDeg;
		std::vector<Term> 	_exprBeforeEqual;
		std::vector<Term>	_exprAfterEqual;
};

#endif
