/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:23 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 19:55:03 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_find_format(const char *str, int i, int *j, va_list args)
{
	if (str[i] == 'c')
		*j += ft_c(va_arg(args, int));
	else if (str[i] == 's')
		*j += ft_s(va_arg(args, char *));
	else if (str[i] == 'p')
	{
		write (1, "0x", 2);
		*j += 2 + ft_putnbr_hexa_u_printf(va_arg(args, unsigned long int));
	}
	else if (str[i] == 'i' || str[i] == 'd')
		*j += ft_putnbr_printf(va_arg(args, int));
	else if (str[i] == 'u')
		*j += ft_putnbr_u_printf(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		*j += ft_putnbr_hexa_u_printf(va_arg(args, unsigned int));
	else if (str[i] == 'X')
		*j += ft_putnbr_hexa_maj_u_printf(va_arg(args, unsigned int));
	else if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		(*j)++;
	}
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_find_format(str, i, &j, args);
		}
		else if (j++ >= 0)
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}
