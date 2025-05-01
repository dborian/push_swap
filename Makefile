NAME = push_swap
CHECKER_NAME = checker

# Source files for each directory
ALGORITHM_SRCS = sort_two.c \
				sort_three.c \
				sort_four.c \
				sort_five.c \
				sort_quick.c \
				sort_optimal.c \
				best_move_calculate.c

COMMANDS_SRCS = sa.c \
				sb.c \
				ss.c \
				pa.c \
				pb.c \
				ra.c \
				rb.c \
				rr.c \
				rra.c \
				rrb.c \
				rrr.c \

ERRORS_SRCS = 	handle_error.c \
				handle_error_n_free.c \
				free_stacks.c \
				free_stacks_n_tab.c \
				free_all.c \
				void_content.c

PARSING_SRCS = 	parser.c \
				add_arg.c \
				parse_string.c \
				cpy_lst_tab.c

UTILS_SRCS = 	rotate_both.c \
				check_dup_args.c \
				find_duplicates.c \
				sort_check.c \
				check_args.c \
				best_move_total.c \
				next_min.c \
            	best_move_init.c \
				find_min.c \
				value_max.c \
				stack_b_init.c \
				best_move_cpy.c \
				best_move_apply.c

CHECKER_SRCS =	checker.c\
				free_command_stacks.c \
				free_tab.c \
				init_stacks.c \
				parse_commands.c \
				valid_commands.c

# Add main source file
MAIN_SRCS = push_swap.c

# Prefix each source file with its directory path
ALGORITHM_SRCS := $(addprefix srcs/algorithm/, $(ALGORITHM_SRCS))
COMMANDS_SRCS := $(addprefix srcs/commands/, $(COMMANDS_SRCS))
ERRORS_SRCS := $(addprefix srcs/errors/, $(ERRORS_SRCS))
PARSING_SRCS := $(addprefix srcs/parsing/, $(PARSING_SRCS))
UTILS_SRCS := $(addprefix srcs/utils/, $(UTILS_SRCS))
MAIN_SRCS := $(addprefix srcs/main/, $(MAIN_SRCS))
CHECKER_SRCS := $(addprefix srcs_bonus/, $(CHECKER_SRCS))

# Common sources used by both push_swap and checker
COMMON_SRCS = $(ALGORITHM_SRCS) $(COMMANDS_SRCS) $(ERRORS_SRCS) $(PARSING_SRCS) $(UTILS_SRCS)

# Libft directories
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compilation flags
CC = cc
CFLAGS = -Werror -Wextra -Wall -MP -MMD -g3 -I includes
LIBS = -L$(LIBFT_DIR) -lft

# Colors for output
RED=\033[0;31m
MAGENTA=\033[0;35m
BLUE=\033[0;34m
GREEN=\033[0;32m
WHITE=\033[0;37m
NC=\033[0m

# All source files combined
SRCS = $(MAIN_SRCS) $(COMMON_SRCS)

# Objects directory and object files
OBJDIR = .objects
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
CHECKER_OBJS = $(CHECKER_SRCS:%.c=$(OBJDIR)/%.o) $(COMMON_SRCS:%.c=$(OBJDIR)/%.o)

# Default target
.PHONY: all
all: $(LIBFT) $(NAME)

# Include dependencies
-include $(OBJS:.o=.d) $(CHECKER_OBJS:.o=.d)

# Build libft first
$(LIBFT): FORCE
	@echo "$(BLUE)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

.PHONY: FORCE
FORCE:

# Link everything to create the executable
$(NAME): $(OBJDIR) $(OBJS) $(LIBFT)
	@echo "$(BLUE)Linking $(RED)$(NAME)$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "$(MAGENTA)$(NAME) is ready!$(NC)"

# Link checker executable
$(CHECKER_NAME): $(OBJDIR) $(CHECKER_OBJS)
	@echo "$(BLUE)Linking $(RED)$(CHECKER_NAME)$(NC)"
	@$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS) $(LIBS)
	@echo "$(MAGENTA)$(CHECKER_NAME) is ready!$(NC)"

# Create objects directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile source files
$(OBJDIR)/%.o: %.c Makefile
	@echo "$(GREEN)Compiling$(WHITE) $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean objects
.PHONY: clean
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR) 
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory clean

# Clean everything
.PHONY: fclean
fclean: clean
	@echo "$(RED)Removing $(NAME) and $(CHECKER_NAME)$(NC)"
	@rm -f $(NAME) $(CHECKER_NAME)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory fclean

# Rebuild everything
.PHONY: re
re: fclean all

# Bonus target - build the checker
.PHONY: bonus
bonus: $(LIBFT) $(NAME) $(CHECKER_NAME)
