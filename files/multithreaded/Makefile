object = thread.o
TARGET = thread

all: $(TARGET) $(object)

$(TARGET) : $(object)
	gcc -o $@ $^
fork.o: fork.c
	gcc -Wall -g -c $^ 
clean:
	rm -f $(object) $(TARGET)
