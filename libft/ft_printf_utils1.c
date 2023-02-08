/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:51:44 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 19:52:00 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_s(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putnbr_hexa_u_printf(unsigned long int nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr <= 15)
	{
		ft_putchar_fd(base[nbr], 1);
		return (1);
	}
	else
	{
		i += ft_putnbr_hexa_u_printf(nbr / 16);
		i += ft_putnbr_hexa_u_printf(nbr % 16);
	}
	return (i);
}
