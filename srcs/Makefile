NAME = fillit

CC = clang
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

HEAD = fillit.h

BUILD_DIR = build/
SRCS += main.c
SRCS += read.c
SRCS += check_tetri.c
SRCS += set_square.c
LIBT += libft/libft.a
OBJS += $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CC) $(OBJS) $(LIBT) -o $@

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -R $(BUILD_DIR) 

fclean: clean
	$(RM) -R $(NAME)

re: fclean all

.PHONY: clean fclean re
