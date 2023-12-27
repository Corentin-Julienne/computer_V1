#include "./parsing.hpp"

Parser::Parser(char *args)
{
	this->extractData(args);
	this->calculatePolynomialDegree();
}

Parser::~Parser() {}

Parser::Parser(const Parser &other) : _exprBeforeEqual(other._exprBeforeEqual),
_exprAfterEqual(other._exprAfterEqual), _polynomialDeg(other._polynomialDeg) {}

Parser&	Parser::operator=(const Parser &original) 
{
	if (this != &original) 
	{
		this->_exprBeforeEqual = original._exprBeforeEqual;
		this->_exprAfterEqual = original._exprAfterEqual;
		this->_polynomialDeg = original._polynomialDeg;
	}
	return *this;
}

int	Parser::getPolynomialDeg(void) const 
{ 
	return this->_polynomialDeg; 
}

std::vector<Term>	Parser::getExprBeforeEqual(void) const 
{
	return this->_exprBeforeEqual;
}

std::vector<Term>	Parser::getExprAfterEqual(void) const
{
	return this->_exprAfterEqual;
} 

void Parser::calculatePolynomialDegree(void) // to test 
{
	int maxVal = INT_MIN;

	for (int i = 0; i < this->_exprBeforeEqual.size(); i++) {
		if (maxVal < this->_exprBeforeEqual[i].exponent) {
			maxVal = this->_exprBeforeEqual[i].exponent;
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
		else if (!expr[i + 1]) {
			this->storeExpression(expr.substr(0), exprSide);
		}
		i++;
	}
}

// compute a subexpression that takes the form a * x^p
void	Parser::storeExpression(std::string expr, int exprSide) // to test
{
	Term		exprToStore;
	std::string	coef;
	int			len = 0;

	exprToStore.sign = 1;
	exprToStore.exponent = -1;

	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '-') {
			exprToStore.sign = -1;
		}
		else if (expr[i] == 'X' && expr[i + 1] && expr[i + 1] == '^' 
			&& expr[i + 2] && std::isdigit(expr[i + 2])) {
			exprToStore.exponent = expr[i + 2] + '0';
			i += 3;
		}
		else if (expr[i] && std::isdigit(expr[i])) {

			while (expr[i] && std::isdigit(expr[i]) || expr[i] == '.') {
				if (expr[i] == '.') 
					exprToStore.isInt = false;
				len++;
				i++;
			}
			coef = expr.substr(i - len, len);
			exprToStore.coef = coef;
		}
	}
	
	if (exprSide == BEFORE_EQU) {
		this->_exprBeforeEqual.push_back(exprToStore);
	} else {
		this->_exprAfterEqual.push_back(exprToStore);
	}
}

/* tests */

void	Parser::displayExprs(std::string title, int exprSide) const
{
	std::vector<Term>		expression;

	if (exprSide == BEFORE_EQU) {
		expression = this->_exprBeforeEqual;
	} else {
		expression = this->_exprAfterEqual;
	}
	
	std::cout << "--------------" << std::endl;
	std::cout << "displaying " << title << " :" << std::endl;
	for (int i = 0; i < expression.size(); i++) {
		this->displayTerm(expression[i], i);
	}
	std::cout << "--------------" << std::endl;
}

void	Parser::displayTerm(Term term, int index) const
{
	std::cout << "--------------" << std::endl;
	std::cout << "diplaying term " << index << std::endl;
	std::cout << "sign = " << "|" << term.sign << "|" << std::endl;
	std::cout << "exponent = " << "|" << term.exponent << "|" << std::endl;
	std::cout << "coef = " << "|" << term.coef << "|" << std::endl;
	std::cout << "isInt = " << "|" << std::boolalpha << term.isInt << "|" << std::endl;
	std::cout << "--------------" << std::endl;
}

void	Parser::test(void) const
{
	this->displayExprs("before =", BEFORE_EQU);
	this->displayExprs("after =", AFTER_EQU);
}
