cc = gcc
CFLAGS = -Wall -Wextra

ALL = mycp.c copy_files.c get_buffer.c make_report.c

OBJ = $(ALL:.c=.o)

TARGET = mycp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)