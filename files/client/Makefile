input = client.c
output = client
CC := gcc
CFLAGS := -g -Wall

all: $(output)
$(output): $(input)
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(output)
debug:
	gdb --args $(output) 127.0.0.1 12345