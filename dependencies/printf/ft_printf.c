/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:13:55 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 13:06:00 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type_s(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	print_type(char *str, va_list ap)
{
	char	c;

	if (*str == 'c')
	{
		c = (va_arg(ap, int));
		return (write(1, &c, 1));
	}
	else if (*str == 's')
		return (print_type_s(va_arg(ap, char *)));
	else if (*str == 'p')
		return (ft_putnbr_uptr_base(va_arg(ap, uintptr_t)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (*str == 'u')
		return (ft_putunbr_fd(va_arg(ap, unsigned int), 1));
	else if (*str == 'x' )
		return (ft_putunbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (*str == 'X' )
		return (ft_putunbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else
		return (write(1, str, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	str--;
	while (++str && *str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *(str + 1)))
			len += print_type((char *)(++str), ap);
		else
			len += write(1, str, 1);
	}
	va_end(ap);
	return (len);
}
