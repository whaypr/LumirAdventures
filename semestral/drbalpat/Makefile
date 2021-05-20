# OPTIONS
CXX      = g++
LD       = g++
CXXFLAGS = -Wall -pedantic -g -I/usr/include/libxml2/
LIBS     = -lSDL2main -lSDL2 -lSDL2_image -lxml2
OUT      = drbalpat

# GENERATE ALL / DELETE ALL
all: compile doc

clean:
	rm -f $(OBJ) $(OUT)

# CREATE
SRC     := $(shell find src -name '*.cpp')
OBJ     := $(SRC:.cpp=.o)

compile: $(OBJ)
	$(LD) $(CXXFLAGS) $(OBJ) -o $(OUT) $(LIBS)

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

doc:
	# todo

# RUN / DEBUG
run: compile
	./$(OUT)

valg: compile
	valgrind ./$(OUT)

valg+: compile
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(OUT)
	