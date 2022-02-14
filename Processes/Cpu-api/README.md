## CPU API

Code from OSTEP chapter [Interlude: Process API](http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf).

`pipe.c` is an example program found in the man page for `pipe()`.  In
addition to demonstrating `pipe()`, it also demonstrates `read()` and
`write()` for reading and writing files.

To compile, just type:
```
make
```

See the highly primitive `Makefile` for details.

Then run `p1`, `p2`, `p3`, `p4`, or `pipe`, as need be. Examples:

```
./p1
```

```
./p2
```

```
./p3
```

```
./p4
```
    
```
./pipe
```

To clean things up afterwards:

```
make clean
```

This is not a substitute for proper use of a .gitignore file.
