##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## Makefile
##

all:
	make -C libdragonball
	make -C libnaruto
	make -C libonepiece
	gcc main.c

clean:
	make clean -C libdragonball
	make clean -C libnaruto
	make clean -C libonepiece

fclean:
	make fclean -C libdragonball
	make fclean -C libnaruto
	make fclean -C libonepiece

re: fclean all