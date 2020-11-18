G++ = g++
ARGS = -ansi -pedantic -Wall -std=c++11

test:tests.cpp trajet_simple.cpp 
	$(G++) $(ARGS) -o $@ $^


trajet_simple.o:trajet_simple.cpp trajet_simple.h
	$(G++) $(ARGS) -o $@ $^
