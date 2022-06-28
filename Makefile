# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:09:55 by vfranco-          #+#    #+#              #
#    Updated: 2022/06/28 09:43:48 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap
CC			=	clang
FILES_PATH	=	.
FILES 		=	push_swap.c \
				operations.c
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(FILES:.c=.o)))
FLAGS 		= 	-Wall -Wextra -Werror
LIBFT_PATH	= 	.dependencies/libft
LIBFT		=	$(LIBFT_PATH)/libft.a
GNL_PATH	= 	.dependencies/gnl
GNL 		= 	$(GNL_PATH)/libgnl.a
RM 			=	rm -f

###################################################################

all: $(OBJS_PATH) $(NAME)
	
$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)

$(NAME):	$(OBJS) $(LIBFT) $(GNL)
				$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(GNL) -o push_swap

$(OBJS_PATH)/%.o:	$(FILES_PATH)/%.c
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

$(LIBFT):
				make -C $(LIBFT_PATH)

$(GNL):
				make -C $(GNL_PATH)
				
clean:
				make clean -C $(LIBFT_PATH)
				make clean -C $(GNL_PATH)
				$(RM) $(OBJS)

fclean:		clean
				make fclean -C $(LIBFT_PATH)
				make fclean -C $(GNL_PATH)
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
