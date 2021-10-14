# Eqparser

## Table of Contents
* [About](#about)
* [Usage](#usage)

## About
Eqparser is a simple equation parser in C++. It is intended for use in the numerical methods library [Niumerics](https://github.com/davidmniu/Niumerics), but may also be used separately. It implements a version of Dijkstra's [shunting-yard algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm) that has been modified to allow for variables (x, y, z), mathematical constants (e, pi), and trigonometric functions.

## Usage
As is made clear in the header file, Niucleus has two functions for the user to interact with; namely,

```
std::vector<char> stringToPostfix(std::string equation);
```

and

```
double evalPostfix(std::vector<char> postVec, double x, double y, double z);
```

The first function, `stringToPostfix`, takes in a string representation of a mathematical expression and converts it into a `vector<char>` which holds a Reverse Polish (postfix) notation representation of said expression. The second function, `evalPostfix`, takes this `vector<char>` along with the given variable values and evaluates the expression, returning a double.
