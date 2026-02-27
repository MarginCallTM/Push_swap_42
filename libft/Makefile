SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_isprint.c ft_strlen.c\
	ft_memset.c ft_bzero.c ft_striteri.c ft_strjoin.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	ft_printf/ft_printf.c ft_printf/utility_functions.c \
	ft_printf/utility_functions_2.c ft_printf/write_functions.c \
	ft_printf/write_functions_2.c \

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

CC = cc

CFLAGS = -Wall -Wextra -Werror 

DEP = $(OBJ:.o=.d)

DEPBONUS = $(OBJBONUS:.o=.d)

NAME = libft.a

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJBONUS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP) $(OBJBONUS) $(DEPBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:
	$(MAKE) $(NAME) SRC="$(SRC) $(BONUS)"

.PHONY: all clean fclean re bonus

-include $(DEP)