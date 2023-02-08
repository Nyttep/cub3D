/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:56 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/29 17:26:14 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbr(long int n)
{
	int	ret;

	ret = 1;
	if (n < 0)
	{
		ret++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			len_nbr;
	int			i;
	long int	tmp;

	tmp = n;
	i = 0;
	len_nbr = ft_len_nbr(tmp);
	ret = malloc(sizeof(char) * (len_nbr + 1));
	if (!ret)
		return (NULL);
	ret[len_nbr--] = '\0';
	if (tmp < 0)
	{
		ret[0] = '-';
		tmp *= -1;
		i = 1;
	}
	while (len_nbr >= i)
	{
		ret[len_nbr--] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
	return (ret);
}
