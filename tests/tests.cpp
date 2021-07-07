#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cmath"
#include "../src/parser.hpp"

TEST_CASE("String to Postfix") {
	std::vector<char> out1 = stringToPostfix("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
	std::vector<char> out2 = stringToPostfix("cos(3x)");
	std::vector<char> out3 = stringToPostfix("xyz+3sin(e^x)");
	std::vector<char> ans1 = {'3', '4', '2', '*', '1', '5', '-', '2', '3', '^', '^', '/', '+'};
	std::vector<char> ans2 = {'3', 'x', '*', 'c'};
	std::vector<char> ans3 = {'x', 'y', '*', 'z', '*', '3', 'e', 'x', '^', 's', '*', '+'};
	CHECK(out1 == ans1);
	CHECK(out2 == ans2);
	CHECK(out3 == ans3);
}

TEST_CASE("Evaluate postfix") {
	std::vector<char> in1 = {'3', '4', '2', '*', '1', '5', '-', '2', '3', '^', '^', '/', '+'};
	std::vector<char> in2 = {'3', 'x', '*', 'c'};
	std::vector<char> in3 = {'x', 'y', '*', 'z', '*', '3', 'e', 'x', '^', 's', '*', '+'};
	double out1 = evalPostfix(in1, 0, 0, 0);
	double out2 = evalPostfix(in2, M_PI, 0, 0);
	double out3 = evalPostfix(in3, 1, 2, 3);
	double ans1 = 3 + 4 * 2 / pow(( 1 - 5 ), pow(2, 3));
	double ans2 = -1;
	double ans3 = (1*2*3) + 3*sin(exp(1));
	double epsilon = 0.00001;
	CHECK(fabs(out1 - ans1) <= epsilon);
	CHECK(fabs(out2 - ans2) <= epsilon);
	CHECK(fabs(out3 - ans3) <= epsilon);
}
