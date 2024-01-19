CC = clang
CFLAGS = -Wall

all: sender listener

listener: listener.o
	$(CC) $(CFLAGS) -o listener listener.o

sender: sender.o
	$(CC) $(CFLAGS) -o sender sender.o

clean:
	-rm -f listener sender listener.o sender.o
