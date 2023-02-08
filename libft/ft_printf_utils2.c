/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:52:21 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 19:56:43 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		i += ft_putnbr_printf(nbr) + 1;
	}
	else if (nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', 1);
		return (1);
	}
	else
	{
		i += ft_putnbr_printf(nbr / 10);
		i += ft_putnbr_printf(nbr % 10);
	}
	return (i);
}

int	ft_putnbr_u_printf(unsigned int nbr)
{
	int		i;

	i = 0;
	if (nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', 1);
		return (1);
	}
	else
	{
		i += ft_putnbr_u_printf(nbr / 10);
		i += ft_putnbr_u_printf(nbr % 10);
	}
	return (i);
}

int	ft_putnbr_hexa_maj_u_printf(unsigned int nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nbr <= 15)
	{
		ft_putchar_fd(base[nbr], 1);
		return (1);
	}
	else
	{
		i += ft_putnbr_hexa_maj_u_printf(nbr / 16);
		i += ft_putnbr_hexa_maj_u_printf(nbr % 16);
	}
	return (i);
}
