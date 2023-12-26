#ifndef PARSING_HPP
#define PARSING_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>

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
		std::vector<std::map<std::string, int> > getExprBeforeEqual(void) const;
		std::vector<std::map<std::string, int> > getExprAfterEqual(void) const;
	
	private:
		void extractData(char *args);
		void processExpression(std::string expr, int exprSide);
		void storeExpression(std::string expr, int exprSide);
		void calculatePolynomialDegree();

		int											_polynomialDeg;
		std::vector<std::map<std::string, int> > 	_exprBeforeEqual;
		std::vector<std::map<std::string, int> >	_exprAfterEqual;
};

#endif
