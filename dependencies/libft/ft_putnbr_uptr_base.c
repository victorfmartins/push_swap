/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uptr_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:37:08 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 12:57:51 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_num(uintptr_t nbr, int base_len, char *base)
{
	int		cont;
	int		keep_cont;
	int		pos;
	char	num_inv[32];

	cont = 0;
	while (nbr != 0)
	{
		num_inv[cont] = nbr % base_len;
		nbr = nbr / base_len;
		cont++;
	}
	keep_cont = cont;
	cont = 1;
	while (cont <= keep_cont)
	{
		pos = num_inv[keep_cont - cont];
		write(1, &base[pos], 1);
		cont++;
	}
	return (keep_cont);
}

int	ft_putnbr_uptr_base(uintptr_t nbr)
{
	write(1, "0x", 2);
	if (nbr == 0)
		return (write(1, "0", 1) + 2);
	return (ft_print_num(nbr, 16, "0123456789abcdef") + 2);
}
