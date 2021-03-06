# OPTIONS
CXX      = g++
LD       = g++
CXXFLAGS = -Wall -pedantic -g -I/usr/include/libxml2/
LIBS     = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lxml2
OUT      = drbalpat

# GENERATE ALL / DELETE ALL
all: compile doc

clean:
	rm -f $(OBJ) $(DEP) $(OUT)
	find doc/ -type f -not -name '*.md' -delete ; rmdir doc/search

# CREATE
SRC     := $(shell find src -name '*.cpp')
OBJ     := $(SRC:.cpp=.o)
DEP     := $(patsubst %.cpp,%.d,$(SRC))

-include $(DEP)

compile: $(OBJ)
	$(LD) $(CXXFLAGS) $^ -o $(OUT) $(LIBS)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

doc:
	doxygen Doxyfile

# RUN / DEBUG
run: compile
	./$(OUT)

valg: compile
	valgrind ./$(OUT)

valg+: compile
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(OUT)

.PHONY: doc
	