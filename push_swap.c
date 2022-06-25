/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:39:47 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/25 13:36:46 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*lst;

// 	lst = malloc(sizeof(t_list));
// 	if (!lst)
// 		return (NULL);
// 	(*lst).content = content;
// 	(*lst).next = NULL;
// 	return (lst);
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	(*new).next = *lst;
// 	*lst = new;
// }

void    build_stack_a(int argc, char **argv, t_list **lst_a)
{
    int i;
    int nbr;
    t_list *new;

    i = 1;
    while (i < argc)
    {
        nbr = ft_atoi(argv[i]);
        new = ft_lstnew(&nbr);
        // if (new is NULL?)
        ft_lstadd_front(lst_a, new);
        printf("i: %d, nbr: %d, content: %d\n", i, nbr, *(int*)((*lst_a)->content));
        i++;
    }
    write(1, "\n", 1);
    return ;
}

void    print_stack(t_list *lst)
{
    t_list	*p;
    int nbr;
    char c;

	if (!lst)
		return ;
	p = lst;
    //printf("%d\n", *(int*)(p->content));
	while (p->next)
    {
        nbr = *((int*)(p->content));
        c = '0' + nbr;
        write(1, &c, 1);
        write(1, "\n", 1);
		p = p->next;
    }
    return ;
}

int is_sorted(t_list *lst)
{
    t_list	*p;
    int     max;

	if (!lst)
		return (1);
	p = lst;
    max = *((int*)(p->content));
	while (p->next)
    {
        if (max < *((int*)(p->content)))
            max = *((int*)(p->content));
        else
            return (0);
		p = p->next;
    }
    return (1);
}

// void    ft_sort(t_list **lst_a, t_list **lst_b)
// {
//     while ((*lst_a)->next)
//     {
//         if ((*lst_a)->content > (*lst_a)->next->content)
//         {
//             printf("sa\n");
//             ft_lst_swap(lst_a);
//         }
//         else if ((*lst_a)->content > (*lst_b)->content)
//         {
//             printf("pb\n");
//             ft_lst_push(lst_a, lst_b);            
//         }
//         else
//         {
//             printf("pa\n");
//             ft_lst_push(lst_b, lst_a);
//         }
//     }
//     // inverter pilhas
// }

int main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
    
    printf("Program name: %s\n", argv[0] + 2);
    lst_b = ft_lstnew(NULL);
    lst_a = ft_lstnew(NULL);
    build_stack_a(argc, argv, &lst_a);
    // ft_sort(&lst_a, &lst_b);
    // if (is_sorted(lst_b) == PUSH_SWAP_ERROR){  printf("Stack is not sorted\n");    return (PUSH_SWAP_ERROR);}
    print_stack(lst_a);
    // free stack with lstiter function
    return (0);
}
