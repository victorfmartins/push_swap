/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:40:59 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 14:10:56 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_num(int n, int fd)
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

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = n * (-1);
	}
	return (ft_print_num(n, fd) + count);
}
