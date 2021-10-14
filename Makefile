CXX=g++
CPPFLAGS=-g -std=c++17 -Wall

test:
	rm bin/tester; clear
	$(CXX) $(CPPFLAGS) -c src/helper.cpp -o build/helper.o
	$(CXX) $(CPPFLAGS) -c src/niutron.cpp -o build/niutron.o
	$(CXX) $(CPPFLAGS) -c tests/tests.cpp -o build/tests.o
	$(CXX) $(CPPFLAGS) build/helper.o build/niutron.o build/tests.o -o bin/tester

drive:
	rm bin/driver; clear
	$(CXX) $(CPPFLAGS) -c src/helper.cpp -o build/helper.o
	$(CXX) $(CPPFLAGS) -c src/niutron.cpp -o build/niutron.o
	$(CXX) $(CPPFLAGS) -c tests/driver.cpp -o build/driver.o
	$(CXX) $(CPPFLAGS) build/helper.o build/niutron.o build/driver.o -o bin/driver 
