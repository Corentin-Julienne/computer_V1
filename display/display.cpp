#include "display.hpp" 

Display::Display(Parser parser, Simplify simplify, Resolver resolver)
{
	this->_polynomialDeg = parser.getPolynomialDeg();
	this->_firstExpression = parser.getExprBeforeEqual();
	this->_lastExpression = parser.getExprAfterEqual();
	this->_simplifiedExpression = simplify.getReducedExpression();
	this->_solutions = resolver.getResults();
}

Display::~Display() {};

Display::Display(const Display &other) 
{

}

Display&	Display::operator=(const Display &original) 
{

}

void	Display::displayResults(void) const 
{

}

void	Display::test(void) const
{

}
