G++ = g++
ARGS = -ansi -pedantic -Wall -std=c++11

test:tests.cpp trajet_simple.cpp 
	$(G++) $(ARGS) -o $@ $^


trajet_simple.o:trajet_simple.cpp trajet_simple.h
	$(G++) $(ARGS) -o $@ $^

tlc:test_liste_chainee.cpp liste_chainee.h liste_chainee.cpp chainon.h chainon.cpp
	$(G++) $(ARGS) -o $@ $^

clean:
	rm *.o
