CC = g++
CFLAGS = -Wall
OBJFILES = *.cpp Elements/*.cpp
TARGET = z_jogo

all: 
	$(CC) -c $(OBJFILES) 
	$(CC) *.o $(CFLAGS) -o $(TARGET) $(LDFLAGS)
	rm  -f *.o
clean:
	rm -f $(TARGET) *~ *.o
