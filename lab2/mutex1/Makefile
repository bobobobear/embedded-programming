input = mutex1.c
output = mutex1
CC := gcc
CFLAGS := -g -Wall -lpthread

all: $(output)
$(output): $(input)
	$(CC) $< -o $@ $(CFLAGS)
clean:
	rm -f $(output)
