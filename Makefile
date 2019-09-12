# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkante <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 14:21:11 by fkante            #+#    #+#              #
#    Updated: 2019/09/12 17:57:10 by fkante           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

HEAD_DIR = includes
HEAD_LIB_DIR = libft
HEAD = fillit.h
HEAD_LIB = libft.h
HEAD_PATH = $(HEAD_DIR)/$(HEAD)
HEAD_PATH += $(HEAD_LIB_DIR)/$(HEAD_LIB)

INCLUDES += -I./$(HEAD_LIB_DIR)/
INCLUDES += -I./$(HEAD_DIR)/

BUILD_DIR = build/
SRCS_DIR = srcs/
SRCS = main.c
SRCS += read.c
SRCS += check_tetri.c
SRCS += square_module.c
SRCS += solving_module.c
SRCS += print_square.c
SRCS += format_tetri.c
SRCS += setup.c
LIBT += libft/libft.a
LIBFT = libft/
OBJS += $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS) Makefile libft $(HEAD_PATH)
	$(CC) $(OBJS) $(CFLAGS) $(LIBT) -o $@

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: $(SRCS_DIR)%.c Makefile $(HEAD_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft: FORCE
	make -C $(LIBFT) 

clean:
	$(RM) -R $(BUILD_DIR)

fclean: clean
	$(RM) -R $(NAME)
	$(RM) -R $(LIBT) $(HEAD_LIB_DIR)/$(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re libft
FORCE:
