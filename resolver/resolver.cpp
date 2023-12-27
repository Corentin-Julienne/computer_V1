#include "resolver.hpp"

Resolver::Resolver(Parser parser, Simplify simplify)
{
	this->_firstExpr = parser.getExprBeforeEqual();
	this->_secondExpr = parser.getExprAfterEqual();
	this->_simplifiedExpr = simplify.getReducedExpression();
	this->findExprResults();
}

Resolver::~Resolver() {};

Resolver::Resolver(const Resolver &other) : _firstExpr(other._firstExpr), _secondExpr(other._secondExpr),
_simplifiedExpr(other._simplifiedExpr), _results(other._results) {};

Resolver&	Resolver::operator=(const Resolver &original)
{
	if (this != &original)
	{
		this->_firstExpr = original._firstExpr;
		this->_secondExpr = original._secondExpr;
		this->_simplifiedExpr = original._simplifiedExpr;
		this->_results = original._results;
	}
	return *this;
}

std::string		Resolver::replaceNullExponent(void)
{
	int		otherExprInt = 0;
	double	otherExprDouble = 0;
	
	for (std::vector<Term>::iterator it = this->_simplifiedExpr.begin(); it != this->_simplifiedExpr.end(); it++) {
		if (it->exponent == 0 && it->isInt == true) {
			otherExprInt += std::stoi(it->coef) * it->sign * (-1);
		} else if (it->exponent == 0 && it->isInt == false) {
			otherExprDouble += std::stod(it->coef) * it->sign * (-1); 
		}
	}
	return otherExpr;
}

void	Resolver::findExprResults(void)
{
	int		otherExpr = this->replaceNullExponent();

	
}

void	Resolver::test(void) const
{

}
