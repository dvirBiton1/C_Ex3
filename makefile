.PHONY = all clean
CC = gcc
OBJ = stringProg.o
NAME = stringProg
CFLAGS = -Wall -Werror -g

all : $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
stringProg_lib.o: stringProg_lib.c stringProg_lib.h
	$(CC) $(CFLAGS) -c stringProg_lib.c
stringProg.o: stringProg.c
	$(CC) $(CFLAGS) -c stringProg.c

clean:
	rm -f *.o *.a stringProg

