NAME = lib.a

HEADER = ./include/

OPTION = -c -I $(HEADER)

SRC = ./src/list.c

OBJ = list.o

.PHONY: all clean fclean re
	
all: $(NAME)

$(NAME):
	@ gcc $(FLAG) $(OPTION) $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean: 
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all


