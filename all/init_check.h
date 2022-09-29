/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:17:45 by vfranco-          #+#    #+#             */
/*   Updated: 2022/09/29 15:02:38 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_CHECK_H
# define INIT_CHECK_H
# include "../.dependencies/libft/libft.h"
# include "../.dependencies/printf/ft_printf.h"

# ifndef NO_ARGS
#  define NO_ARGS -1
# endif

# ifndef INIT_ERROR
#  define INIT_ERROR -1
# endif

# ifndef INIT_SUCCESS
#  define INIT_SUCCESS 1
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

int init_stack(int argc, char **argv, t_list **stack);

#endif