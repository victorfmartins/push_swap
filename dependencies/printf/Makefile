# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 11:45:58 by vfranco-          #+#    #+#              #
#    Updated: 2022/09/29 22:28:15 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

FILES		=	ft_printf.c

FLAGS		=	-Wall -Wextra -Werror

OBJ			=	$(FILES:.c=.o)

LIBS		= ../libft/libft.a

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBS)
			cp $(LIBS) $(NAME)
			ar rcs $(NAME) $(OBJ)

$(LIBS):
			make -C ../libft/

%.o:	%.c
			clang -c $(FLAGS) $<

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)
			make fclean -C ../libft/

re:			fclean all

.PHONY:		all clean fclean re $(LIBS)