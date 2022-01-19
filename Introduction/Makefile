# Recipe lines (for example 'rm -f...' below) MUST begin with a tab
# character.  See https://www.gnu.org/software/make/manual/html_node/Rule-Introduction.html

CC = gcc
CFLAGS += -g -Wall

all: mem threads io fs

clean:
	rm -f mem threads io fs file

mem: mem.c
	$(CC) $(CFLAGS) -o $@ mem.c

threads: threads.c common_threads.h
	$(CC) $(CFLAGS) -o $@ threads.c -pthread

io: io.c
	$(CC) $(CFLAGS) -o $@ io.c

fs: fs.c
	$(CC) $(CFLAGS) -o $@ fs.c
