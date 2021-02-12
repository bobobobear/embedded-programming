input = server.c
output = server
port = 12345
CC := gcc
CFLAGS := -g -Wall

all: $(output)
$(output): $(input)
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(output)
debug:
	gdb --args $(output) $(port)