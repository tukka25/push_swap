NAME = push_swap

SRC =	push_swap.c \
		lists.c     \
		utils.c  
   
OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf ./libft/*.o
fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.all

re:fclean all