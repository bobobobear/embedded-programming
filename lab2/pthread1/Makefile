CC := gcc
CFLAGS := -Wall -lpthread
input = pthread1.c
output = pthread1

all: $(output)
$(output): $(input)
	$(CC)  $< -o $@ $(CFLAGS)
clean:
	rm -f $(output)
