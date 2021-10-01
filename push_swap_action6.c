/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:20:27 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 16:21:54 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunker5(int *lista, int *listcp, int arg, int *len)
{
	int	*list3;
	int	i;
	int	*listb;
	int	biga;
	int	mina;

	i = 0;
	arg += 0;
	listb = NULL;
	list3 = malloc(sizeof(int) * 3);
	if (!list3)
		return ;
	pb(&listb, &lista, &len[1], &len[0]);
	pb(&listb, &lista, &len[1], &len[0]);
	list3 = copy_list(lista, len[0]);
	ft_sort_int_tab(list3, len[0]);
	chunker3(lista, list3, len[0], len);
	chunker5_2(lista, listcp, listb, len);
}

void	chunker100(int *lista, int *listacp, int arg, int *len)
{
	int	*listb;
	int	i;

	i = 0;
	listb = NULL;
	while (i < 1)
	{
		two_chunk_move(&lista, &listb, &len, listacp);
		len[0] = 50;
		len[1] = 50;
		i++;
	}
	two_chunk_move_last(&lista, &listb, &len, listacp);
	len[0] = 1;
	len[1] = 99;
	ft_rev_int_tab(listacp, arg);
	last_fill(&lista, &listb, listacp, len);
}

void	chunker500(int *lista, int *listacp, int arg, int *len)
{
	int	*listb;
	int	i;

	i = 0;
	listb = NULL;
	while (i < 4)
	{
		two_chunk_move_500(&lista, &listb, &len, listacp);
		len[0] -= 100;
		len[1] += 100;
		i++;
	}
	two_chunk_move_last_500(&lista, &listb, &len, listacp);
	len[0] = 1;
	len[1] = 499;
	ft_rev_int_tab(listacp, arg);
	last_fill(&lista, &listb, listacp, len);
}

void	two_chunk_move_last_500_sup(
		int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;

	found = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	while (lena != 1)
	{
		if (*lista[0] != listacp[lena + lenb - 1])
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void	two_chunk_move_500_sup(
		int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;

	found = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	while (found < ((lena + lenb) / 10))
	{
		if (*lista[0] <= listacp[(((lena + lenb) / 10) - 1) + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[(((lena + lenb) / 10) - 1)
					+ (*len)[1]])
				&& (*lista[0] <= listacp[(((lena + lenb) / 10)) + (*len)[1]]))
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}
