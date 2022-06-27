/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:39:47 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/27 12:22:27 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
            return (0);
        i++;
    }
    return (1);
}

int    build_stack_a(int argc, char **argv, t_list **lst_a)
{
    int i;
    char *str;
    t_list *new;

    i = 1;
    while (i < argc)
    {
        
        str = ft_strdup(argv[i]);
        if (!str || !is_numeric(str))
        {
            printf("Error: invalid input. Input must be numeric.\n");
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

void    print_stack(t_list *lst)
{
    t_list	*p;

	if (!lst)
		return ;
	p = lst;    
	while (p->next)
    {
        printf("%s\n", p->content);
		p = p->next;
    }
    return ;
}

void    print_stacks(t_list *lst_l, t_list *lst_r)
{
    t_list  *l;
    t_list	*r;
    
    l = lst_l;   
	r = lst_r;
	while (l || r)
    {
        if (l && r)
        {
            printf("%s\t%s\n", l->content, r->content);
            l = l->next;
            r = r->next;
        }
        else if (l)
        {
            printf("%s\n", l->content);
            l = l->next;
        }
        else
        {
            printf("\t%s\n", r->content);
            r = r->next;
        }
    }
    printf("__\t__\n-------------------------------\n");
    return ;
}

int is_sorted(t_list *lst)
{
    t_list	*p;
    char     *max;

	if (!lst) 
    {
        printf("is_sorted: list does not exist\n");
		return (1);
    }
	p = lst;
    max = p->content;
	while (p->next)
    {
        if (ft_strncmp(max, p->content, INT_MAX) <= 0)
            max = p->content;
        else
            return (0);
		p = p->next;
    }
    return (1);
}

void    ft_sort(t_list **lst_a, t_list **lst_b)
{
    if (lst_a == NULL || lst_b == NULL)
    {
        printf("ft_sorted: at least one list does not exist\n");
        return ;
    }
    while ((*lst_a))
    {
        if ((*lst_a)->next && ft_strncmp((*lst_a)->content, (*lst_a)->next->content, INT_MAX) > 0)
        {
            printf("sa\n");
            ft_lst_swap(lst_a);
        }
        else if ((*lst_b) == NULL || ft_strncmp((*lst_a)->content, (*lst_b)->content, INT_MAX) > 0)
        {
            printf("pb\n");
            ft_lst_push(lst_a, lst_b);
        }
        else
        {
           printf("pa\n");
            ft_lst_push(lst_b, lst_a);
        }
    }
    while ((*lst_b))
    {
        printf("pa\n");
        ft_lst_push(lst_b, lst_a);
    }
}

int main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
    
    lst_b = NULL;
    lst_a = NULL;
    build_stack_a(argc, argv, &lst_a);
    // print_stacks(lst_a, lst_b);
    ft_sort(&lst_a, &lst_b);
    if (is_sorted(lst_a) == 0)
        printf("Stack is not sorted\n");
    // print_stacks(lst_a, lst_b);
    // free stack with lstiter function
    return (0);
}
