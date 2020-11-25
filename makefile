G++ = g++
ARGS = -ansi -pedantic -Wall -std=c++11

test:tests.cpp trajet_simple.cpp chainon.cpp liste_chainee.cpp
	$(G++) $(ARGS) -o $@ $^

clean:
	rm -f *.o test
