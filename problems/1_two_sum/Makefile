CC = gcc
CFLAGS = -fPIC -O3 -g0
LDFLAGS = -shared

TARGET = lib.so
SOURCE = lib.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: clean
