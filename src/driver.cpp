#include <iostream>
#include "parser.hpp"

int main() {
	std::string equation = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
	std::vector<char> output = stringToPostfix(equation);
	double answer = evalPostfix(output, 0, 0, 0);
	std::cout << "The answer is: " << answer << std::endl;
	return 0;
}
