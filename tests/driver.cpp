#include <iostream>
#include "../src/niutron.hpp"
#include <cmath>

int main() {
	std::string equation = "3x+4x^2";
	std::vector<char> output = stringToPostfix(equation);
	for (char i : output) {
		std::cout << i;
	}
	std::cout << std::endl;
	return 0;
}
