# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: licohen <licohen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:08:00 by licohen           #+#    #+#              #
#    Updated: 2024/09/30 22:08:17 by licohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU = \033[0;34m
GRN = \033[0;32m
RST = \033[0m
END = \e[0m

SRCS = 	ft_error.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_free_split.c ft_atoll.c \
		ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_substr.c \
		ft_strtrim.c ft_perror.c ft_get_next_line.c ft_strjoin.c ft_atoi.c \
		ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_strdup.c ft_calloc.c ft_strcpy.c ft_free.c ft_countchr.c \
		ft_atod.c
SRCSB = ft_lstmap.c ft_lstadd_back.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c \
		ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstnew.c ft_lstadd_front.c $(SRCS)

HEADER = libft.h

NAME = libft.a

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf "\033[2K\r$(BLU)[BUILD - $(NAME)]$(RST) '$<' $(END)"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(HEADER)
	@printf "\033[2K\r$(GRN)[END]$(RST) $(NAME)$(END)"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJSB)

fclean: clean
	@rm -f $(NAME)

bonus: $(OBJSB)
	@ar rcs $(NAME) $(OBJSB)
	@printf "\033[2K\r$(GRN)[END]$(RST) $(NAME)$(END)"

re: fclean all

.PHONY: all clean fclean re bonus