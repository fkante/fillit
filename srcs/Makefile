NAME = fillit
DEBUG = fillit_debug

CC = gcc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

HEAD = fillit.h

BUILD_DIR = build/
SRCS += main.c
SRCS += read.c
SRCS += check_tetri.c
SRCS += square_module.c
SRCS += solving_module.c
SRCS += print_square.c
SRCS += format_tetri.c
LIBT += libft/libft.a
OBJS += $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

all: $(NAME) $(DEBUG)

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CC) $(OBJS) $(LIBT) -o $@

$(DEBUG): $(SRCS)
	$(CC) $(SRCS) $(LIBT) -fsanitize=address -g3 -o $@

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -R $(BUILD_DIR)

fclean: clean
	$(RM) -R $(NAME) $(DEBUG)

re: fclean all

.PHONY: clean fclean re
