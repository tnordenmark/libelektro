LIBDIR = $(PREFIX)/lib
INCDIR = $(PREFIX)/include/libelektro
PREFIX = /usr

LIBS = $(shell echo lib/*.so)
HEADERS = $(shell echo include/*.h)
LIBSRC = $(shell echo src/lib/)
LIBFLAGS = -c -fPIC
OBJECTFLAGS = -shared -fPIC -o

#lib - för att bygga enbart biblioteken
lib: libresistance.o libpower.o libcomponent.o
	$(shell mkdir -p lib)
	$(CC) $(OBJECTFLAGS) lib/libresistance.so libresistance.o
	$(CC) $(OBJECTFLAGS) lib/libpower.so libpower.o
	$(CC) $(OBJECTFLAGS) lib/libcomponent.so libcomponent.o -lm
	
libresistance.o: $(LIBSRC)libresistance.c include/libresistance.h
	$(CC) $(LIBFLAGS) $(LIBSRC)libresistance.c include/libresistance.h

libpower.o: $(LIBSRC)libpower.c include/libpower.h
	$(CC) $(LIBFLAGS) $(LIBSRC)libpower.c include/libpower.h

libcomponent.o: $(LIBSRC)libcomponent.c include/libcomponent.h
	$(CC) $(LIBFLAGS) $(LIBSRC)libcomponent.c include/libcomponent.h

#all - för att kompilera biblioteken, bygga en ekekverbar fil "electrotest" och länka den till biblioteken
all: lib

#clean - för att bort samtliga objektfiler
clean:
	-rm ./*.o

#install - för att kopiera körbara filer och bibliotek till rätt katalog samt länka dem
install: lib
	install -d '$(LIBDIR)'
	install -s -t '$(LIBDIR)' $(LIBS)
	install -d '$(INCDIR)'
	install -m 644 -t '$(INCDIR)' $(HEADERS)

#distclean - återställ katalogen till dess ursprungliga form
distclean:
	-rm ./*.o
	-rm -r lib/
	-rm include/*.gch

#uninstall - för att ta bort det som gjordes av "install"
uninstall:
	-rm $(LIBDIR)/libresistance.so $(LIBDIR)/libpower.so $(LIBDIR)/libcomponent.so
	-rm -r $(INCDIR)
