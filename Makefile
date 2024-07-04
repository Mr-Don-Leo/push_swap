NAME = push_swap
CC = cc
CFLAGS = -fsanitize=address,undefined -g3

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
PURPLE=\033[0;35m
ORANGE=\033[38;5;208m
NC=\033[0m

SRCS = push_swap.c input_handling.c input_handling_utils.c \
		parse_values.c parse_values_utils.c ft_atoi.c stack_utils1.c stack_utils2.c \
		sorting_utils1.c sorting_utils2.c sorting_utils3.c \
		./RULES/push_rules.c ./RULES/swap_rules.c ./RULES/rotate_rules.c \
		./RULES/reverse_rotate_rules.c 

OBJS = $(SRCS:.c=.o)

LIBFT = ./LIBFT/libft.a
PRINTF = ./PRINTF/libftprintf.a

all: $(LIBFT) $(PRINTF) $(NAME)


$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -C libft
	@$(MAKE) bonus -C libft
	@echo "$(GREEN)Finished compiling libft.$(NC)"
	@echo

$(PRINTF):
	@echo "$(YELLOW)Compiling printf...$(NC)"
	@$(MAKE) -C printf
	@echo "$(GREEN)Finished compiling printf.$(NC)"
	@echo

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I./LIBFT -I./PRINTF
	@echo "$(GREEN)Finished compiling $<.$(NC)"
	@echo

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@echo "$(YELLOW)Compiling $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Finished compiling $(NAME).$(NC)"
	@echo

clean:
	@echo "$(ORANGE)Cleaning up object files...$(NC)"
	@$(MAKE) -C libft clean
	@rm -f $(OBJS)
	@echo "$(ORANGE)Cleanup complete.$(NC)"
	@echo

fclean: clean
	@echo "$(RED)Performing full clean...$(NC)"
	@$(MAKE) -C libft fclean
	@$(MAKE) -C printf fclean
	@rm -f $(NAME)
	@echo "$(RED)Full clean complete.$(NC)"
	@echo

re: fclean all

.PHONY: all clean fclean re 
