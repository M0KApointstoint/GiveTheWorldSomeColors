CC = cc
CFLAGS = -Wall -Wextra -O2

SRCS = main.c ppm.c filters.c
OBJS = $(SRCS:.c=.o)
TARGET = imgproc

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
