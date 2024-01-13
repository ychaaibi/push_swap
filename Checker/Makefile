NAME = checker

GCC = gcc

CFLAGS = -Wextra -Wall -Werror

RM = rm -f

SRC = utils/ft_check.c utils/ft_is_instruction.c utils/ft_lstadd_back.c utils/ft_lstlast.c utils/ft_lstnew.c \
	  utils/ft_strcmp.c utils/ft_strdup.c utils/init.c utils/read_instructions.c utils/stack.c \
	  parsing/ft_atoi.c parsing/ft_parse.c parsing/ft_split.c parsing/ft_substr.c \
	  operations/operations.c operations/operations1.c \
	  checker.c \

all : $(NAME)

$(NAME) : $(SRC)
	$(GCC) $(CFLAGS) $(SRC) -o $(NAME)

clean :

fclean : 
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean
