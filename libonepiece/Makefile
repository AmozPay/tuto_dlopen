##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## Makefile
##

TARGET		=	libonepiece.so

CXX			=	clang++
CXXFLAGS		=	-c -fPIC

LD			=	clang++
LD_FLAGS	=	-fPIC -shared

SRC			=	libonepiece.cpp

OBJ			=	$(SRC:.cpp=.o)

.RECIPEPREFIX	=	-
.PHONY: all clean fclean re

all:	$(OBJ)
-$(LD) $(LD_FLAGS) -o $(TARGET) $(OBJ)

clean:
-rm -f *.o

fclean:	clean
-rm -f $(TARGET)

re: fclean all

%.o:	%.cpp
-$(CXX) $(CXXFLAGS) -o $@ $<