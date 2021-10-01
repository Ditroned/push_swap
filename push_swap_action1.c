/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:07:25 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 17:07:27 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_sort(int *list, int len)
{
	int	min;
	int	swap;
	int	i;
	int	j;

	i = 0;
	j = 0;
	swap = 0;
	while (j < len)
	{
		min = list[j];
		while (i < len)
		{
			if (list[i] < min)
			{
				min = list[i];
				swap = i;
			}
			i++;
		}
		list[swap] = list[j];
		list[j++] = min;
		i = j;
	}
	return (list);
}

void	printlist(int *lista, int lena)
{
	int	i;

	i = 0;
	puts("caca");
	while (i < lena)
	{
		printf("|%d", lista[i]);
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	max;
	int	posmax;
	int	i;
	int	j;

	j = -1;
	max = 0;
	while (j++ <= size - 2)
	{
		max = tab[j];
		posmax = j;
		i = 0;
		while (i + j <= size - 2)
		{
			if (tab[i + j + 1] <= max)
			{
				max = tab[i + j + 1];
				posmax = i + j + 1;
			}
			i++;
		}
		tab[posmax] = tab[j];
		tab[j] = max;
	}
}

void	sb(int *list, int lenb)
{
	int	swap;

	if (lenb < 2)
		return ;
	swap = list[1];
	list[1] = list[0];
	list[0] = swap;
	write(1, "sb\n", 3);
}

void	sa(int *list, int lena)
{
	int	swap;

	if (lena < 2)
		return ;
	swap = list[1];
	list[1] = list[0];
	list[0] = swap;
	write(1, "sa\n", 3);
}
