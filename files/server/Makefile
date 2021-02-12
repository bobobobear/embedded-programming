TARGET = server
all: $(TARGET)
$(TARGET): server.c
	gcc -o $@ -g -Wall $<
clean:
	rm -f $(TARGET)
debug:
	gdb --args $(TARGET) 12345