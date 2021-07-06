#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <math.h>
#include "parser.hpp"

bool isNum(char a) {
	if (a >= '0' && a <= '9') return true;
}

bool isOp(char a) {
	std::unordered_set<char> ops = {'+', '-', '*', '/', '^'};
	std::unordered_set<char>::const_iterator got = ops.find(a);
	return (got != ops.end());
}

int opPriority(char a) {
	if (a == ')' || a == '(') return 4;
	else if (a == '^') return 3;
	else if (a == '*' || a == '/') return 2;
	else if (a == '+' || a == '-') return 1;
	else return 0;
}

std::vector<char> returnError(char a) {
	return {'e', 'r', 'r', 'o', 'r', ' ', a};
}

void print(std::vector<char> vec) {
	for (char i : vec) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

std::vector<char> stringToPostfix(std::string equation) {
	std::vector<char> output;
	std::vector<char> opStack;
	char prev;
	for (char token: equation) {
		if (token != ' ') {
			/*
			 * for debugging
			std::cout << "output: ";
			print(output);
			std::cout << "opStack: ";
			print(opStack);
			*/
			// if number, put into output queue
			if ((token >= '0' && token <= '9') || (token == '.')) {
				output.push_back(token);
			// if function, push onto opStack 
			} else if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
				opStack.push_back(token);
			// if operator, pop operators with lower precedence on opStack
			// onto output, then put token onto output as well
			} else if (isOp(token)) {
				int j = opStack.size() - 1;
				if (j >= 0) {
					while (isOp(opStack[j]) &&
						(opPriority(opStack[j]) >  opPriority(token) || 
						 (opPriority(opStack[j]) == opPriority(token) && token != '^'))) {
						output.push_back(opStack[j]);
						opStack.pop_back();
						j--;
					}
				}
				opStack.push_back(token);
			// if '(', push onto opStack
			} else if (token == '(') {
				opStack.push_back(token);
			// if ')', go back down opStack until hit '('
			} else if (token == ')') {
				int j = opStack.size() - 1;
				while (opStack[j] != '(') {
					if (!opStack.empty()) {
						output.push_back(opStack[j]);
						opStack.pop_back();
						j--;
					} else {
						return returnError('1');
					} 
				}
				if (opStack[j] == '(') {
					opStack.pop_back();
					j--;
				}
				else {
					return returnError('2');
				} 
				// take care of function
				if ((opStack[j] >= 'A' && opStack[j] <= 'Z') || (opStack[j] >= 'a' && opStack[j] <= 'z')) {
					output.push_back(opStack[j]);
					opStack.pop_back();
					j--;
				}
			}
		}
	}
	// now pop remaining elements from opStack onto output
	for (int i = opStack.size() - 1; i >= 0; i--) {
		if (opStack[i] != '(' && opStack[i] != ')') {
			output.push_back(opStack[i]);
		} else {
			return returnError('3');
		} 
	}
	return output;
}

double doOp(char op, double a, double b) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else if (op == '/') return a / b;
	else if (op == '^') return pow(a, b);
}

double evalPostfix(std::vector<char> postVec, double x, double y, double z) {
	std::vector<double> valStack = {};
	for (char token : postVec) {
		if (token >= '0' && token <= '9') {
			valStack.push_back(token - 48);
		} else {
			int len = valStack.size();
			double a = valStack[len-2];
			double b = valStack[len-1];
			valStack.pop_back();
			valStack.pop_back();
			valStack.push_back(doOp(token, a, b));			
		}
	}
	return valStack[0];
}
