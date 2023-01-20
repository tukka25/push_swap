NAME = push_swap

SRC =	push_swap.c \
		lists.c     \
		utils.c  	\
		moves.c     \
		moves2.c    \
		sorting.c	\
		utils2.c
   
OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf ./libft/*.o
fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re:fclean all