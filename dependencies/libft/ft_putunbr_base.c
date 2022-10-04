/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:37:15 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 14:11:06 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_num(unsigned int nbr, int base_len, char *base)
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

static int	ft_is_base(char *base)
{
	int	idx;
	int	idx_srch;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		idx_srch = idx + 1;
		while (base[idx_srch])
		{
			if (base[idx_srch] == base[idx])
				return (0);
			idx_srch++;
		}
		idx++;
	}
	return (1);
}

int	ft_putunbr_base(unsigned int nbr, char *base)
{
	int				base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len == 0 || base_len == 1 || !ft_is_base(base))
		return (-1);
	if (nbr == 0)
		return (write(1, "0", 1));
	return (ft_print_num(nbr, base_len, base));
}
