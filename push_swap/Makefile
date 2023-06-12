
NAME = push_swap

SRCS = checker/checkerargc.c instructions/instructions.c \
	    main.c sorting/sortfor3.c checker/ft_qsort.c \
	   	checker/indexes.c sorting/sortfor5.c sorting/is_sorted.c \
		sorting/sortall.c sorting/sortfor4.c instructions/instructions2.c \
		instructions/instructions3.c instructions/instructions4.c \
		sorting/instructions.c 
	   

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
