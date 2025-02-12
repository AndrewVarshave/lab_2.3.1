CC = gcc
CFLAGS = -Wall -Wextra -g -I.
LDFLAGS = -lm

SOURCES = sequence.c stats.c main.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del -f *.o $(EXECUTABLE)

run: all
	./$(EXECUTABLE)