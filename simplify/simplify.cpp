#include "simplify.hpp"

Simplify::Simplify(Parser parser) {
	this->_exprBeforeEqual = parser.getExprBeforeEqual();
	this->_exprAfterEqual = parser.getExprAfterEqual();
	this->_maxExponent = parser.getPolynomialDeg();
	this->sortExpression(BEFORE_EQU);
	this->sortExpression(AFTER_EQU);
	this->reduceExpression();
}

Simplify::~Simplify() {};

std::vector<std::map<std::string, int> >	Simplify::getReducedExpression(void) const 
{
	return this->_reducedExpression;
}

bool	Simplify::compareExponent(const std::map<std::string, int> &alpha, const std::map<std::string, int> &bravo) //test
{
	return alpha.at("exponent") < bravo.at("exponent");
}

void	Simplify::sortExpression(int exprType) // test
{
	if (exprType == BEFORE_EQU) {
		std::sort(this->_exprBeforeEqual.begin(), this->_exprBeforeEqual.end(), compareExponent);
	} else {
		std::sort(this->_exprAfterEqual.begin(), this->_exprAfterEqual.end(), compareExponent);	
	}
}

void	Simplify::reduceExpression(void) // test
{
	std::vector<std::map<std::string, int> >	reducedExpr = this->_exprBeforeEqual;

	for (int i = 0; i <= this->_maxExponent && i < this->_exprAfterEqual.size(); i++) {
		reducedExpr[i]["int"] += this->_exprAfterEqual[i]["int"] * this->_exprAfterEqual[i]["sign"] * (-1); 		
	}
}
