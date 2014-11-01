#make file for - Bungie RW

EXEC = RW
TORM = RW.o
CC = g++
CCFLAGS = -g -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings 

$(EXEC):	RW.o 
	$(CC) ${CCFLAGS} -o $(EXEC) RW.o

RW.o:	RW.cpp RW.h
		${CC} ${CCFLAGS} -c RW.cpp             

clean:
	rm -f *.o core a.out $(EXEC) ${TORM}
