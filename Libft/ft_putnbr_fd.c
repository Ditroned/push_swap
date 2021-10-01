/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:49:27 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 21:10:48 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	len_n(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

int	ft_topower(int a, int b)
{
	int	c;

	c = a;
	while (b-- > 1)
	{
		a *= c;
	}
	return (a);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		l;
	char	d;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	l = len_n(n);
	while (l-- > 1)
	{
		d = (n / ft_topower(10, l)) + 48;
		write(fd, &d, 1);
		n = n % ft_topower(10, l);
	}
	d = n + 48;
	write(fd, &d, 1);
}
/*
int	main(void)
{
	ft_putnbr_fd(12, 1);
	//printf("%d",ft_topower(10, 3));
	return (0);
}
*/
