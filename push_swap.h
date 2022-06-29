/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:40:04 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/29 09:55:38 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "./.dependencies/libft/libft.h"

# define PUSH_SWAP_ERROR -1

int		main(int argc, char **argv);
void	ft_lst_swap(t_list **lst);
void	ft_lst_push(t_list **lst_from, t_list **lst_to);
int		build_str_stack(int argc, char **argv, t_list **lst_a);
int		ft_strnbrcmp(char *s1, char *s2);
void	print_stacks(t_list *lst_l, t_list *lst_r);
void	print_stack(t_list *lst);

#endif