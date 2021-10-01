/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:17:08 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 21:15:22 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	len_nn(int n)
{
	int	a;

	a = 0;
	if (n == -2147483648)
		return (10);
	while (n > 9)
	{
		a++;
		n = n / 10;
	}
	a++;
	return (a);
}

int	ft_sign(int n)
{
	if (n == -2147483648)
		return (1);
	if (n < 0)
		return (1);
	return (0);
}

int	ft_process(int n)
{
	if (n < 0 && n != -2147483648)
		n = n * (-1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;
	int		lentot;

	sign = ft_sign(n);
	n = ft_process(n);
	lentot = len_nn(n) + sign + 1;
	str = malloc(lentot--);
	if (!str)
		return (str);
	str[lentot--] = '\0';
	if (n == -2147483648)
	{
		str[lentot--] = '8';
		n = 214748364;
	}
	while (n > 9 || n < -9)
	{
		str[lentot--] = (n % 10 + 48);
		n = n / 10;
	}
	str[lentot--] = n + 48;
	if (sign == 1)
		str[lentot] = 45;
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char c[50];

	//printf("%s",ft_itoa(-2147483648));
	//printf("%d\n",len_n(-2147483648));

	//printf("%d",min_sign(-2147483648));
	//printf("%d\n",len_n(-1));
	//printf("%d\n",len_n(12));
	//printf("%d\n",len_n(344));
	//printf("%d\n",len_n(5443));
	//printf("%d\n",len_n(234525));
	puts(ft_itoa(-12422));
	return (0);
}
*/
