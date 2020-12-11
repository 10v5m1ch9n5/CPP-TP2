# ================================= VARIABLES =================================

#--------------------------- Parametres compilateurs ---------------------------
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 $(DEBUG)
CC = g++

#------------------------------- Fichiers source -------------------------------
CPP = $(wildcard *.cpp)
O = $(CPP:%.cpp=%.o)

# ================================ REGLES MAKE ================================

# -------------------------------- EXECUTABLES --------------------------------
main.out:main.o chainon.o liste_chainee.o trajet_simple.o Catalogue.o trajet_compose.o
	g++ -o $@ $^

test.out:tests.o chainon.o trajet_simple.o liste_chainee.o trajet_compose.o Catalogue.o
	g++ -o $@ $^

#--------------------------------- COMPILATION ---------------------------------
main.o:main.cpp CouleurTTY.h
tests.o:tests.cpp
trajet_compose.o:trajet_compose.cpp trajet_compose.h CouleurTTY.h
Catalogue.o:Catalogue.cpp Catalogue.h
chainon.o:chainon.cpp chainon.h
liste_chainee.o:liste_chainee.cpp liste_chainee.h CouleurTTY.h
trajet_simple.o:trajet_simple.cpp trajet_simple.h trajet.h

# ---------------------------------REGLES PHONY---------------------------------
debug: DEBUG = -DMAP -g
debug: all
rebuild:clean debug
clean:
	rm -vf *.o *.out *.gch

all:test.out main.out
.PHONY: all clean rebuild debug
