SONAME = libhook.so
GCC = gcc

all:
	$(GCC) -g -c -fPIC hook.c -o hook.o
	$(GCC) -g -shared -Wl,-soname,$(SONAME) -o $(SONAME) hook.o

clean:
	rm -f *.so *.o
