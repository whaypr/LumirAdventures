CXX      = g++
LD       = g++
CXXFLAGS = -Wall -pedantic -g
LIBS     = -lSDL2main -lSDL2 -lSDL2_image
OUT      = bin/semestral

SRC     := $(shell find src -name '*.cpp')
OBJ     := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUT) $(LIBS)

$(OBJ): %.o : %.cpp
	$(LD) -o $@ -c $<

clean:
	rm -f $(OBJ) $(OUT)

valg: $(OUT)
	valgrind $(OUT)

valg+: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)
