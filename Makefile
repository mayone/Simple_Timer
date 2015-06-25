CC = gcc
CFLAGS =  -I.
LDFLAGS = -L.
SOURCES = timer.c
OBJECTS = $(notdir $(SOURCES:.c=.o))
EXECUTE = timer

all: $(OBJECTS) $(EXECUTE)

$(EXECUTE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -c

run:
	./$(EXECUTE)
clean:
	rm -rf *~ *.o $(EXECUTE)
