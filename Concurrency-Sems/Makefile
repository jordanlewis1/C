CC     := gcc
CFLAGS := -Wall -pthread

OS     := $(shell uname -s)
LIBS   := 
ifeq ($(OS),Linux)
	LIBS += -pthread
endif

SRCS   := count.c pc.c throttle.c zemaphore.c

OBJS   := ${SRCS:c=o}
PROGS  := ${SRCS:.c=}

.PHONY: all
all: ${PROGS}

${PROGS} : % : %.o Makefile
	${CC} $< -o $@ ${LIBS}

clean:
	rm -f ${PROGS} ${OBJS}

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $<
