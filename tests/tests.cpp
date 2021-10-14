#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cmath"
#include "../src/niutron.hpp"

Niutron *expr = new Niutron();

TEST_CASE("String to Postfix") {
	expr->setExpression("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
	std::vector<char> ans1 = {'3', '4', '2', '*', '1', '5', '-', '2', '3', '^', '^', '/', '+'};
	CHECK(expr->getExpression() == ans1);

	expr->setExpression("cos(3x)");
	std::vector<char> ans2 = {'3', 'x', '*', 'c'};
	CHECK(expr->getExpression() == ans2);

	expr->setExpression("xyz+3sin(e^x)");
	std::vector<char> ans3 = {'x', 'y', '*', 'z', '*', '3', 'e', 'x', '^', 's', '*', '+'};
	CHECK(expr->getExpression() == ans3);
}

TEST_CASE("Evaluate postfix") {
	double epsilon = 0.00001;

	expr->setExpression("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
	double out1 = expr->evaluate(0, 0, 0);
	double ans1 = 3 + 4 * 2 / pow(( 1 - 5 ), pow(2, 3));
	CHECK(fabs(out1 - ans1) <= epsilon);

	expr->setExpression("cos(3x)");
	double out2 = expr->evaluate(M_PI, 0, 0);
	double ans2 = -1;
	CHECK(fabs(out2 - ans2) <= epsilon);

	expr->setExpression("xyz+3sin(e^x)");
	double out3 = expr->evaluate(1, 2, 3);
	double ans3 = (1*2*3) + 3*sin(exp(1));
	CHECK(fabs(out3 - ans3) <= epsilon);
}
