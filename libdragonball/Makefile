##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## Makefile
##

TARGET		=	libdragonball.so

CC			=	gcc
CFLAGS		=	-c

LD			=	gcc
LD_FLAGS	=	-fPIC -shared

SRC			=	libdragonball.c

OBJ			=	$(SRC:.c=.o)

.RECIPEPREFIX	=	-
.PHONY: all clean fclean re

all:	$(OBJ)
-$(LD) $(LD_FLAGS) -o $(TARGET) $(OBJ)

clean:
-rm -f *.o

fclean:	clean
-rm -f $(TARGET)

re: fclean all

%.o:	%.c
-$(CC) $(CFLAGS) -o $@ $<