input = client.c
output = client
ip = 127.0.0.1
port = 12345
CC := gcc
CFLAGS := -g -Wall

all: $(output)
$(output): $(input)
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(output)
debug:
	gdb --args $(output) $(ip) $(port)