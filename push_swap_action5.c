/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:03:29 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 16:49:30 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *lista, int *listb, int len, int lena)
{
	int	i;

	i = 0;
	if (len != lena)
		return (0);
	while (i < len)
	{
		if (lista[i] == listb[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	chunker3(int *lista, int *listacp, int arg, int *len)
{
	if (check_sort(lista, listacp, arg, len[0]))
		return ;
	if (len[0] == 2)
		ra(lista, len[0]);
	else if (lista[2] == listacp[2])
		sa(lista, len[0]);
	else if (lista[2] == listacp[0] && lista[0] == listacp[2])
	{
		ra(lista, len[0]);
		sa(lista, len[0]);
	}
	else if (lista[0] == listacp[2] && lista[1] == listacp[0])
		ra(lista, len[0]);
	else if (lista[0] == listacp[0] && lista[1] == listacp[2])
	{
		sa(lista, len[0]);
		ra(lista, len[0]);
	}
	else if (lista[1] == listacp[2] && lista[2] == listacp[0])
		rra(lista, &len[0]);
}

int	max_list(int *lista, int lena)
{
	int	a;
	int	i;

	a = lista[0];
	i = 0;
	while (i < lena)
	{
		if (a < lista[i])
			a = lista[i];
		i++;
	}
	return (a);
}

int	min_list(int *lista, int lena)
{
	int	a;
	int	i;

	a = lista[0];
	i = 0;
	while (i < lena)
	{
		if (a > lista[i])
			a = lista[i];
		i++;
	}
	return (a);
}

void	chunker5_2(int *a, int *listcp, int *b, int *l)
{
	int	biga;

	while ((check_sort(a, listcp, l[0], l[0] + l[1])) == 0)
	{
		biga = max_list(a, l[0]);
		if (l[1] > 1)
		{
			if (b[0] > b[1])
				rb(b, l[1]);
		}
		if (max_list(a, l[0]) < b[0] && (min_list(
					a, l[0]) == a[0] || (max_list(
						a, l[0]) == a[0] && biga != listcp[3])))
		{
			pa(&a, &b, &l[0], &l[1]);
			if (a[0] == listcp[l[0] + l[1] - 1] && ((l[0] + l[1] != 5)
					&& (a[0] < a[2] || a[2] == listcp[0])))
				sa(a, l[0]);
		}
		if (((min_list(a, l[0]) > b[0] && min_list(a, l[0]) == a[0])))
			pa(&a, &b, &l[0], &l[1]);
		if (b[0] < a[0] && b[0] > a[l[0] - 1])
			pa(&a, &b, &l[0], &l[1]);
		ra(a, l[0]);
	}
}
