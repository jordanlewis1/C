
FLAGS = -Wall -pthread
INCLUDES = ../../Includes

all: t0 t1

clean:
	rm -f t0 t1

t0: t0.c
	gcc -I $(INCLUDES) -o t0 t0.c $(FLAGS)

t1: t1.c
	gcc -I $(INCLUDES) -o t1 t1.c $(FLAGS)
