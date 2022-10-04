/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:40:59 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 14:11:14 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_num(unsigned int n, int fd)
{
	int		cont;
	int		keep_cont;
	char	num_inv[10];
	char	num[10];

	cont = 0;
	while (n != 0)
	{
		num_inv[cont] = 48 + n % 10;
		n = n / 10;
		cont++;
	}
	keep_cont = cont;
	cont = 1;
	while (cont <= keep_cont)
	{
		num[cont - 1] = num_inv[keep_cont - cont];
		cont++;
	}
	return (write(fd, num, keep_cont));
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n == 0)
		return (write(fd, "0", 1));
	return (ft_print_num(n, fd));
}
