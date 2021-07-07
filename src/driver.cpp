#include <iostream>
#include "parser.hpp"
#include <cmath>

int main() {
	std::string equation = "xyz+3sin(e^x)";
	std::vector<char> output = stringToPostfix(equation);
	double answer = evalPostfix(output, 1, 2, 3);
	std::cout << "The answer is: " << answer << std::endl;
	std::cout << "The correct answer is: " << (1*2*3) + 3*sin(exp(1)) << std::endl;
	return 0;
}
