# Recipe lines (for example 'rm -f...' below) MUST begin with a tab
# character.  See https://www.gnu.org/software/make/manual/html_node/Rule-Introduction.html

CC = gcc
CFLAGS += -g -Wall

all: io threads

clean:
	rm -f io threads file

io: io.c
	$(CC) $(CFLAGS) -o io io.c

threads: threads.c
	$(CC) $(CFLAGS) -o threads threads.c -pthread
