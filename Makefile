# Declaration of variables
CC = gcc
CC_FLAGS = -w 
CC_LIBS = -lGL -lm -lSDL2 -lSDL2_image -lGLU
 
# File names
EXEC = game
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CC_LIBS) -o $(EXEC)
 
# To obtain object files
%.o: %.cpp
	$(CC) $(CC_FLAGS) $(CC_LIBS) -c $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
