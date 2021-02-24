src = server.c
output = server
port = 12345
CC := gcc
CFLAGS := -g -Wall

all: $(output)
$(output): $(src)
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(output)
debug:
	gdb --args $(output) $(port)