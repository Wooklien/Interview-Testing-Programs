#make file for - Bungie Word_Search

EXEC = Word_Search
TORM = timers.o
CC = g++
CCFLAGS = -g -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings 

$(EXEC):	Word_Search.o 
	$(CC) ${CCFLAGS} -o $(EXEC) Word_Search.o

Word_Search.o:	Word_Search.cpp Word_Search.h
		${CC} ${CCFLAGS} -c Word_Search.cpp             

clean:
	rm -f *.o core a.out $(EXEC) ${TORM}
