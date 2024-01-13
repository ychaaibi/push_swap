NAME = push_swap

GCC = gcc

CFLAGS = -Wextra -Wall -Werror

RM = rm -f

SRC = stack/init.c stack/moves.c stack/stack_fill.c stack/stack_sort.c stack/valid_place.c \
	  stack/stack_sorted_circle.c \
	  parsing/ft_atoi.c parsing/ft_parse.c parsing/ft_split.c parsing/ft_substr.c \
	  operations/operations.c operations/operations1.c \
	  funcs/funcs.c funcs/funcs1.c \
	  push_swap.c

all : $(NAME)

$(NAME) : $(SRC)
	$(GCC) $(CFLAGS) $(SRC) -o $(NAME)

clean :

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean
