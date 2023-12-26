#include "./parsing.hpp"

Parser::Parser(char *args)
{
	this->extractData(args);
	this->calculatePolynomialDegree();
}

Parser::~Parser() {}

Parser::Parser(const Parser &other) {}

Parser&	Parser::operator=(const Parser &original) 
{
	if (this != &original) 
	{

	}
	return *this;
}

int	Parser::getPolynomialDeg(void) const 
{ 
	return this->_polynomialDeg; 
}

std::vector<std::map<std::string, int> >	Parser::getExprBeforeEqual(void) const 
{
	return this->_exprBeforeEqual;
}

std::vector<std::map<std::string, int> >	Parser::getExprAfterEqual(void) const
{
	return this->_exprAfterEqual;
} 

void Parser::calculatePolynomialDegree(void) // to test 
{
	int maxVal = INT_MIN;

	for (int i = 0; i < this->_exprBeforeEqual.size(); i++) {
		if (maxVal < this->_exprBeforeEqual[i]["exponent"]) {
			maxVal = this->_exprBeforeEqual[i]["exponent"];
		}
	}
	this->_polynomialDeg = maxVal;
}

void	Parser::extractData(char *args) // to test
{
	std::string input(args);
	
	size_t pos = input.find('=');
	std::string part1 = input.substr(0, pos);
	std::string part2 = input.substr(pos + 1);

	this->storeExpression(part1, BEFORE_EQU);
	this->storeExpression(part2, AFTER_EQU);
}

void	Parser::processExpression(std::string expr, int exprSide) // to test
{
	int		exprNum = 0;
	bool	firstSign = false;

	for (char c : expr) {
		if (c == '+' && exprNum == 0) {
			exprNum++;
			firstSign = true;
		}
		if (c == '+' || c == '-') {
			exprNum++;
		}
	}
	
	int	i = 0;
	while (expr[i]) {
		if (expr[i] == '-' && firstSign == true) {
			firstSign = false;
		}
		else if (expr[i] == '+' || expr[i] == '-') {
			this->storeExpression(expr.substr(0, i), exprSide);
			expr = expr.substr(i);
			i = -1;
		}
		i++;
	}
}

// compute a subexpression that takes the form a * x^p
void	Parser::storeExpression(std::string expr, int exprSide) // to test
{
	std::map<std::string, int>	exprToStore;

	exprToStore["sign"] = 1;
	exprToStore["exponent"] = -1;
	exprToStore["int"] = -1;

	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '-') {
			exprToStore["sign"] = -1;
		}
		if (expr[i] && expr[i + 1] && expr[i + 1] == '^' && expr[i + 2]) { // works only with positive exponents
			exprToStore["exponent"] = expr[i + 2] + '0';
			i += 3;
		}
		else if (expr[i] && std::isdigit(expr[i])) {
			exprToStore["int"] = expr[i];
		}
	}
	
	if (exprSide == BEFORE_EQU) {
		this->_exprBeforeEqual.push_back(exprToStore);
	} else {
		this->_exprAfterEqual.push_back(exprToStore);
	}
}
