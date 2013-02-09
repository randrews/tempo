CC = g++
PACKAGES = taglib lua5.1
CFLAGS = `pkg-config --cflags ${PACKAGES}`
LIBS = `pkg-config --libs  ${PACKAGES}`
HEADERS = ltaglib.h

default: ltaglib.so

.cpp.o: ${HEADERS}
	${CC} $? -c -fPIC -Wl,export-dynamic -o $@ ${CFLAGS}

ltaglib.so: ltaglib.o
	${CC} *.o -o ltaglib.so ${LIBS} -shared -Wl,-soname,ltaglib

clean:
	rm -f *~
	rm -f ltaglib.so
	rm -f *.o