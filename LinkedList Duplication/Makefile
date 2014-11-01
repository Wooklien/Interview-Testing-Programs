#make file for - Bungie SLL

EXEC = SLL
TORM = SLL.o
CC = g++
CCFLAGS = -g -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings 

$(EXEC):	SLL.o 
	$(CC) ${CCFLAGS} -o $(EXEC) SLL.o

SLL.o:	SLL.cpp SLL.h
		${CC} ${CCFLAGS} -c SLL.cpp             

clean:
	rm -f *.o core a.out $(EXEC) ${TORM}
