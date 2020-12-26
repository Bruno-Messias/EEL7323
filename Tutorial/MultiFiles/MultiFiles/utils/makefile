function: MultiFiles.o utils.o
	g++ math_stuf.o math_utils.o -o utils

MultiFiles.o: MultiFiles.cpp
	g++ -c MultiFiles.cpp

utils.o: utils.cpp
	g++ -c utils.cpp

clean: 
	rm *.o utils