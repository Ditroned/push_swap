/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:06:46 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 23:45:40 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dispatch(int *lista, int *listacp, int arg, int *len)
{
	if (arg <= 3)
		chunker3(lista, listacp, arg, len);
	else if (arg <= 5)
		chunker5(lista, listacp, arg, len);
	else if (arg < 500 && arg != 100)
		chunkerinf100(lista, listacp, arg, len);
	else if (arg == 100)
		chunker100(lista, listacp, arg, len);
	else if (arg == 500)
		chunker500(lista, listacp, arg, len);
	else if (arg > 500)
		chunker500_sup(lista, listacp, arg, len);
}

int	ft_isatoi(char *str)
{
	int		sign;
	long	nbr;

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
	while ((*str >= 48 && *str <= 57)
		&& (nbr < 222147483647 || nbr > -222147483647))
	{
		nbr = (nbr * 10) + *str++ - 48;
	}
	if (sign < 0)
		nbr = -nbr;
	if (nbr == (int)nbr && *str == 0)
		return (1);
	return (0);
}

int	ft_list_unique(int *tab, int len)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	while (i < len)
	{
		a = tab[i];
		j = 0;
		while (j < len)
		{
			if (j != i && tab[j] == a)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_error(int **lista)
{
	free(*lista);
	write(2, "Error\n", 6);
	return (0);
}

void	ft_free(int *len, int *listacp, int **lista)
{
	int	**gf;

	gf = lista;
	free(len);
	free(listacp);
}
