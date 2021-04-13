all : array calculator calculator2 converter flight name randomcopy sciencecalc switch tree

dir :
	mkdir -p bin

array : dir
	c++ -o bin/array array.cpp
calculator : dir
	c++ -o bin/calculator calculator.cpp
calculator2 : dir
	c++ -o bin/calculator2 calculator2.cpp
converter : dir
	c++ -o bin/converter converter.cpp
flight : dir
	c++ -o bin/flight flight.cpp
name : dir
	c++ -o bin/name name.cpp
randomcopy : dir
	c++ -o bin/randomcopy randomcopy.cpp
sciencecalc : dir
	c++ -o bin/sciencecalc sciencecalc.cpp
switch : dir
	c++ -o bin/switch switch.cpp
tree : dir
	c++ -o bin/tree tree.cpp

clean :
	rm -r bin
