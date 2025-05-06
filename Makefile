CC = cc
CFLAGS = -Werror -Wextra -Wall -g3

NAME = push_swap

SRC = \
	main.c \
	error.c \
	normalize.c \
	parsing.c \
	sort.c \
	utils.c \
	move/pa_pb.c \
	move/ra_rb_rr.c \
	move/rra_rrb_rrr.c \
	move/sa_sb_ss.c \
	check_sorted.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@echo "\033[32m scrs compiled \033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m $(NAME) created \033[0m"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[0;31m objs removed \033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m $(NAME) removed \033[0m"

re: fclean all