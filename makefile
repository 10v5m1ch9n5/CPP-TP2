CPPFLAGS = -ansi -pedantic -Wall -std=c++11 $(DEBUG)

main.out:main.o chainon.o liste_chainee.o trajet_simple.o Catalogue.o trajet_compose.o
	g++ -o $@ $^

test.out:tests.o chainon.o trajet_simple.o liste_chainee.o trajet_compose.o Catalogue.o
	g++ -o $@ $^

main.o:main.cpp CouleurTTY.h
	g++ -c $(CPPFLAGS) $^

tests.o:tests.cpp
	g++ -c $(CPPFLAGS) $<

trajet_compose.o:trajet_compose.cpp trajet_compose.h CouleurTTY.h
	g++ -c $(CPPFLAGS) $^

Catalogue.o:Catalogue.cpp Catalogue.h
	g++ -c $(CPPFLAGS) $<

chainon.o:chainon.cpp chainon.h
	g++ -c $(CPPFLAGS) $<

liste_chainee.o:liste_chainee.cpp liste_chainee.h CouleurTTY.h
	g++ -c $(CPPFLAGS) $^

trajet_simple.o:trajet_simple.cpp trajet_simple.h trajet.h
	g++ -c $(CPPFLAGS) $<

debug: DEBUG = -DMAP -g
debug: all

rebuild:clean debug

clean:
	rm -vf *.o *.out *.gch

all:test.out main.out
