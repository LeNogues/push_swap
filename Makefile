NAME = push_swap
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft
LIBFLAGS = -lft -Llibft
LIBFTDIR = ./libft

SRCS = 	push_swap.c \
		function_s.c \
		function_p.c \
		function_r.c \
		function_rr.c \
		scraping.c \
		algo.c \
		bubble_sort.c \
		clean.c \
		utils.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
