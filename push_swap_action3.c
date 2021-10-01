/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:07:35 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 18:19:02 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ss(int *lista, int *listb, int lena, int lenb)
{
	int	swapb;
	int	swapa;

	if (lena >= 2)
	{
		swapa = lista[1];
		lista[1] = lista[0];
		lista[0] = swapa;
		write(1, "sa\n", 3);
	}
	if (lenb >= 2)
	{
		swapb = listb[1];
		listb[1] = listb[0];
		listb[0] = swapb;
		write(1, "sb\n", 3);
	}
}

int	*list_add_elem_top(int *lista, int *lena)
{
	int		*listres;
	int		i;

	listres = malloc(sizeof(int) * (*lena + 1));
	if (!listres)
		return (NULL);
	i = 1;
	listres[0] = 0;
	while (i < (*lena + 1))
	{
		listres[i] = lista[i - 1];
		i++;
	}
	free(lista);
	lista = listres;
	*lena += 1;
	return (listres);
}

int	*list_rm_elem_top(int *lista, int *lena)
{
	int	*listres;
	int	i;

	listres = malloc(sizeof(int) * (*lena - 1));
	if (!listres)
		return (NULL);
	i = 0;
	while (i < (*lena - 1))
	{
		listres[i] = lista[i + 1];
		i++;
	}
	free(lista);
	*lena -= 1;
	return (listres);
}

void	pa(int **lista, int **listb, int *lena, int *lenb)
{
	if (*lenb == 0)
		return ;
	*lista = list_add_elem_top(*lista, lena);
	*lista[0] = *listb[0];
	*listb = list_rm_elem_top(*listb, lenb);
	write(1, "pa\n", 3);
	return ;
}

void	pb(int **listb, int **lista, int *lenb, int *lena)
{
	if (*lena == 0)
		return ;
	*listb = list_add_elem_top(*listb, lenb);
	*listb[0] = *lista[0];
	*lista = list_rm_elem_top(*lista, lena);
	write(1, "pb\n", 3);
	return ;
}
