SRC = main.c error_checker.c utils/error_checker_utilities.c \
	  algorithms/simple_algo.c algorithms/complex_algo.c \
	  operations/rotate.c operations/reverse_rotate.c \
	  operations/push.c options_selector.c \
	  utils/utils.c utils/error_checker_utilities_2.c \
	  algorithms/medium_algo.c utils/chunk_rotate.c \
	  utils/chunk_utils.c utils/chunk_find.c utils/benchmark.c \

SRC_BONUS = bonus/checker_bonus.c bonus/error_checker_bonus.c \
	  operations/rotate.c operations/reverse_rotate.c \
	  utils/utils.c  utils/error_checker_utilities.c \
	  utils/error_checker_utilities_2.c operations/push.c \
	  operations/swap.c utils/benchmark.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

DEP = $(OBJ:.o=.d)

DEP_BONUS = $(OBJ_BONUS:.o=.d)

all: lib $(NAME)

bonus: lib $(NAME_BONUS)

lib:
	(cd libft && make)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS)  -L./libft -lft -o $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP) $(OBJ_BONUS) $(DEP_BONUS) ; (cd libft && make clean)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) ; (cd libft && make fclean)

re: fclean all

.PHONY: all clean fclean re bonus lib

-include $(DEP)