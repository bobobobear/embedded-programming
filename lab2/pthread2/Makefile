input = pthread2.c
output = pthread2
CC := gcc
CFLAGS := -g -Wall -lpthread

all: $(output)
$(output): $(input)
	$(CC) $< -o $@ $(CFLAGS)
clean:
	rm -f $(output)
