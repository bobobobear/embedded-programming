bin = server server2
port = 12345
CC = gcc
CFLAGS = -Wall

all: $(bin)

$(object): %: %.c
	$(CC) -o $@ $^ $(CFLAGS) -lpthread
clean:
	rm -f $(output)
