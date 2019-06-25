NAME = fillit

CC = gcc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

HEAD = fillit.h

BUILD_DIR = build/
OBJS += $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CC) $@ $(OBJS)

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -R $(BUILD_DIR)

fclean: clean
	$(RM) -R $(NAME)

re: fclean clean

.PHONY: clean fclean re
