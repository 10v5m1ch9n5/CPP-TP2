SUBDIRS = Trajets
DEP_TRAJETS = Trajets/trajet_simple.o
DEP = $(DEP_TRAJETS) ArbreTrajet.o chainon.o ChainonGenerique.o liste_chainee.o

CPP = $(wildcard *.cpp)
O = $(CPP:%.cpp=%.o)

all: $(O)

clean:
	@rm -v *.o

ArbreTrajet.o:ArbreTrajet.cpp ArbreTrajet.h
	g++ -c $^

chainon.o:chainon.cpp chainon.h
	g++ -c $^

ChainonGenerique.o:ChainonGenerique.cpp ChainonGenerique.h
	g++ -c $^

liste_chainee.o:liste_chainee.cpp liste_chainee.h
	g++ -c $^

$(SUBDIRS):
	$(MAKE) -C $@


.PHONY:clean all
.PHONY:$(SUBDIRS)
