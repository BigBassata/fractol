# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: licohen <licohen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 21:02:22 by licohen           #+#    #+#              #
#    Updated: 2024/10/07 15:31:37 by licohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -Llibft -lft
INCLUDES = -I./include -I./libft -I./minilibx-linux
SRCS = srcs/main.c srcs/julia_set.c srcs/zoom.c srcs/utils.c srcs/render.c srcs/events.c srcs/mandelbrot_set.c
OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft