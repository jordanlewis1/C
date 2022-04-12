
# Binary Semaphores (Locks)

Simple example of semaphores as locks (binary semaphores).
Code in `count.c`.

Run `make` to build the code; run `count` to test it. Fun!

```sh
prompt> make
prompt> ./count
```

# Producer/Consumer

Code for the working producer/consumer solution from the text,
found in `pc.c`.

Run `make` to build, and `pc` to test it.
The program takes a few different arguments:
- The number of buffers between the producer/consumer
- The number of times a producer should produce something
- The number of consumer threads

```sh
prompt> make
prompt> ./pc 1 1000 1
```

The output should print each produced item once, and show which
consumer consumed each produced item.

# Zemaphores

A "zemaphore" is a semphore implemented using a mutex and a condition
variable.  The textbook code defaults to using zemaphores, rather than
semaphores, on the Apple platform.  I don't know why.  In count.c, pc.c,
and throttle.c, this is controlled by the USE_ZEMAPHORE_APPLE define.

Code in `zemaphore.c`. We bet you can figure out the rest. This is just
a small test of the Zemaphore with the fork/join problem.

# Throttle

Bonus code that shows how semaphores can be used to throttle how 
many different threads run through a certain bit of code at a time.
Code in `throttle.c`. 

