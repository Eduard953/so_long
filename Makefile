# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 16:43:36 by ebeiline          #+#    #+#              #
#    Updated: 2022/01/12 15:52:38 by ebeiline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 		solong.c checkmap.c end_game.c loadmap.c move.c

OBJ			= 		${SRC:.c=.o}

FRAMEWORKS	=		-framework OpenGL -framework AppKit

CC			= 		gcc
CFLAGS		= 		-Wall -Wextra -Werror

NAME		= 		solong

LIBFT		=		libft

INCLUDES	=		mlx/libmlx.a libft/libft.a

all: $(NAME)
			
$(NAME):			
		@make -C $(LIBFT)
		@make -C mlx/ all
		$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(FRAMEWORKS)

clean:
			@make -C libft/ clean
			@make -C mlx/ clean

fclean: 	clean
			/bin/rm -f $(NAME)
			@make -C libft/ fclean

re: 		fclean all