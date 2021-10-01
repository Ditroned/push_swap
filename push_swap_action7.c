/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:15:22 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 17:01:22 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunker500_sup(int *lista, int *listacp, int arg, int *len)
{
	int		*listb;
	int		i;
	int		*abc;
	int		*listbde;

	i = 0;
	listb = NULL;
	abc = listacp;
	listbde = lista;
	while (i < 9)
	{
		two_chunk_move_500_sup(&lista, &listb, &len, listacp);
		len[0] -= arg / 10;
		len[1] += arg / 10;
		i++;
	}
	two_chunk_move_last_500_sup(&lista, &listb, &len, listacp);
	len[0] = 1;
	len[1] = arg - 1;
	ft_rev_int_tab(listacp, arg);
	last_fill(&lista, &listb, listacp, len);
}

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	two_chunk_move_inf(int **lista, int **listb, int **len, int *listacp)
{
	int	lena;
	int	lenb;
	int	found;
	int	a;

	a = (*len)[0];
	lena = (*len)[0];
	lenb = (*len)[1];
	found = 0;
	while (found < (a / 2))
	{
		if (*lista[0] <= listacp[(a / 4)])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		else if ((*lista[0] > listacp[(a / 4) - b(a)
					+ (*len)[1]]) && (*lista[0] <= listacp[(a / 2)]))
		{
			pb(listb, lista, &lenb, &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void	two_chunk_move_last_inf(
		int **lista, int **listb, int **len, int *listacp)
{
	int		lena;
	int		lenb;
	int		a;
	int		b;
	int		c;

	c = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	a = (*len)[0];
	b = (*len)[1];
	if (c % 4 == 0)
		c = 1;
	while (lena != 1)
	{
		if (*lista[0] <= listacp[(a / 4) - c + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
		}
		if ((*lista[0] > listacp[(a / 4) - c
					+ (*len)[1]]) && (*lista[0] < listacp[a + b - 1]))
			pb(listb, lista, &lenb, &lena);
		ra(*lista, lena);
	}
}

void	chunkerinf100(int *lista, int *listacp, int arg, int *len)
{
	int		*listb;
	int		i;
	int		moy;

	i = 0;
	moy = 0;
	listb = NULL;
	arg += 0;
	if (arg % 2 != 0)
		i = 1;
	while (i < 1)
	{
		two_chunk_move_inf(&lista, &listb, &len, listacp);
		len[0] = (arg / 2);
		len[1] = arg - (arg / 2) - i;
		i++;
	}
	two_chunk_move_last_inf(&lista, &listb, &len, listacp);
	len[1] += len[0] - 1 ;
	len[0] = 1;
	ft_rev_int_tab(listacp, arg);
	last_fill(&lista, &listb, listacp, len);
}
