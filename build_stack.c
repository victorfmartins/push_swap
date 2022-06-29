/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:31:33 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/29 10:25:22 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_strnbrcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[0] == '-' && s2[0] != '-')
		return (-1);
	else if (s1[0] != '-' && s2[0] == '-')
		return (1);
	else if (ft_strlen(s1) != ft_strlen(s2))
		return (ft_strlen(s1) - ft_strlen(s2));
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{	
			if (s1[0] == '-' && s2[0] == '-')
				return (((unsigned char)s1[i] - (unsigned char)s2[i]) * -1);
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (0);
		i++;
	}
	if (i > 10 && (ft_strnbrcmp(str, "2147483647") > 0
			|| ft_strnbrcmp(str, "-2147483648") < 0))
		return (0);
	return (1);
}

int	is_duplicate(char *str, t_list *lst)
{
	t_list	*p;

	if (!lst)
		return (0);
	p = lst;
	while (p)
	{
		if (ft_strnbrcmp(str, p->content) == 0)
			return (1);
		p = p->next;
	}
	return (0);
}

int	build_str_stack(int argc, char **argv, t_list **lst_a)
{
	int		i;
	char	*str;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		str = ft_strdup(argv[i]);
		if (!str || !is_numeric(str) || is_duplicate(str, *lst_a))
		{
			printf("Error: Input must be numeric and non repeatable.\n");
			return (PUSH_SWAP_ERROR);
		}
		new = ft_lstnew(str);
		if (!new)
		{
			printf("Error: unable to create new cell.\n");
			return (PUSH_SWAP_ERROR);
		}
		ft_lstadd_back(lst_a, new);
		i++;
	}
	return (0);
}
