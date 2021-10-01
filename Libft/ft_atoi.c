/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:05:50 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/02 12:27:19 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (*str == 32 || (*str <= 13 && *str >= 9))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -sign;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		nbr = (nbr * 10) + *str - 48;
		str++;
	}
	if (sign < 0)
		nbr = -nbr;
	return (nbr);
}
/*
int	main()
{
	printf("%d",ft_atoi(""));
	puts("\n");
	printf("%d",atoi(""));
	puts("\n");
	return 0;
}
*/
