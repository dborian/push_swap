.PHONY: all clean fclean re

OBJ_DIR		= .objects
INC_DIR		= headers

LST_SRCS	=	main.c \
				normalize.c \
				parsing.c \
				sort.c \
				utils.c \
				error.c \
				move/pa_pb.c \
				move/ra_rb_rr.c \
				move/sa_sb_ss.c \
				move/ rra_rrb_rrr.c
LST_INCS	=	push_swap.h
LST_OBJS	=	$(LST_SRCS:.c=.o)

INCS		=	$(addprefix $(INC_DIR)/, $(LST_INCS))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(LST_OBJS))

CC 			=	cc
NAME		=	push_swap
FLAGS 		=	-Wall -Wextra -Werror -g3

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/headers -c $< -o $@

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR) 
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all
