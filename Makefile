LIBS=-lhiredis
INCDIR=/usr/local/include/hiredis
LIBDIR=/usr/local/lib
CFLAGS=-I$(INCDIR)


sender: sender.c
	gcc $(CFLAGS) sender.c -o sender $(LIBS) -L$(LIBDIR)
