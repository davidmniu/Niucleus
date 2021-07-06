CXX=g++
CPPFLAGS=-g -std=c++17 -Wall

test:
	rm bin/tester; clear
	$(CXX) $(CPPFLAGS) -c src/parser.cpp -o build/parser.o
	$(CXX) $(CPPFLAGS) -c tests/tests.cpp -o build/tests.o
	$(CXX) $(CPPFLAGS) build/parser.o build/tests.o -o bin/tester

drive:
	rm bin/driver; clear
	$(CXX) $(CPPFLAGS) -c src/parser.cpp -o build/parser.o
	$(CXX) $(CPPFLAGS) -c src/driver.cpp -o build/driver.o
	$(CXX) $(CPPFLAGS) build/parser.o build/driver.o -o bin/driver 
