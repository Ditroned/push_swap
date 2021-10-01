/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:53:37 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 16:25:48 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return ((int)nbr);
}

void	two_chunk_move_last(int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;

	found = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	while (found < 49)
	{
		if (*lista[0] <= listacp[24 + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[24
					+ (*len)[1]]) && (*lista[0] < listacp[49 + (*len)[1]]))
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void	two_chunk_move(int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;

	found = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	while (found < 50)
	{
		if (*lista[0] <= listacp[24 + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[24 + (*len)[1]])
				&& (*lista[0] <= listacp[49 + (*len)[1]]))
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void	two_chunk_move_last_500(
		int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;

	lena = (*len)[0];
	lenb = (*len)[1];
	found = 0;
	while (found < 99)
	{
		if (*lista[0] <= listacp[49 + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[49 + (*len)[1]])
				&& (*lista[0] < listacp[99 + (*len)[1]]))
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void	two_chunk_move_500(int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;

	found = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	while (found < 100)
	{
		if (*lista[0] <= listacp[49 + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[49
					+ (*len)[1]]) && (*lista[0] <= listacp[99 + (*len)[1]]))
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}
