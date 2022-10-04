# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:09:55 by vfranco-          #+#    #+#              #
#    Updated: 2022/10/03 14:08:09 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	clang
FILES_PATH	=	src
FILES		=	main.c \
				operations.c \
				init_check.c \
				order_checkers.c \
				push_swap_utils.c \
				stack_merger.c \
				large_alg_utils.c \
				large_alg.c \
				small_alg_utils.c \
				small_alg.c
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(FILES:.c=.o)))
FLAGS 		=	-Wall -Wextra -Werror
LIBFT_PATH	=	dependencies/libft
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF_PATH	=	dependencies/printf
PRINTF		=	$(PRINTF_PATH)/libftprintf.a
RM 			=	rm -f

###################################################################

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)

$(NAME):	$(OBJS) $(LIBFT) $(PRINTF)
				$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o push_swap

$(OBJS_PATH)/%.o:	$(FILES_PATH)/%.c
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

$(LIBFT):
				make -C $(LIBFT_PATH)

$(PRINTF):
				make -C $(PRINTF_PATH)

clean:
				make clean -C $(LIBFT_PATH)
				make clean -C $(PRINTF_PATH)
				$(RM) $(OBJS)

fclean:		clean
				make fclean -C $(LIBFT_PATH)
				make fclean -C $(PRINTF_PATH)
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
