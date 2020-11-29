CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic-errors -std=c99
OUTFILE = blr
OBJS = main.c

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)

install: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)
	cp $(OUTFILE) /usr/bin/$(OUTFILE)
