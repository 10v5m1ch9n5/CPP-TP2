CPPFLAGS = -ansi -pedantic -Wall -std=c++11

main.out:main.o chainon.o liste_chainee.o trajet_simple.o
	g++ -o $@ $^

test.out:tests.o chainon.o liste_chainee.o trajet_simple.o
	g++ -o $@ $^

main:main.cpp
	g++ -c $<

tests:tests.cpp
	g++ -c $<

chainon:chainon.cpp chainon.h
	g++ -c $<

liste_chainee:liste_chainee.cpp liste_chainee.h
	g++ -c $<

trajet_simple:trajet_simple.cpp trajet_simple.h trajet.h
	g++ -c $<

clean:
	rm -f *.o *.out
all:test.out main.out
