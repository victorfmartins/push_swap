/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:40:04 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/27 11:47:49 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "./.dependencies/libft/libft.h"

# define PUSH_SWAP_ERROR -1
# define INT_MAX 2147483647

int		main(int argc, char **argv);
void    ft_lst_swap(t_list **lst);
void    ft_lst_push(t_list **lst_from, t_list **lst_to); 
#endif