/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:07:08 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/30 17:07:09 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	*list_sort(int* list, int len)
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
		list[j] = min;
		j++;
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

void	ft_sort_int_tab(int	*tab, int size)
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

void sb(int* list,int lenb)
{
	int	swap;

	if (lenb < 2)
		return ;
	swap = list[1];
	list[1] = list[0];
	list[0] = swap;
	write(1, "sb\n", 3);
}

void sa(int* list,int lena)
{
	int	swap;

	if (lena < 2)
		return ;
	swap = list[1];
	list[1] = list[0];
	list[0] = swap;
	write(1, "sa\n", 3);
}

void ss(int* lista, int* listb, int lena, int lenb)
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
	int	*listres;
	int	i;

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

void pa(int** lista, int** listb, int *lena, int *lenb)
{
	if (*lenb == 0)
		return ;
	*lista = list_add_elem_top(*lista, lena);
	*lista[0] = *listb[0];
	*listb = list_rm_elem_top(*listb, lenb);
	write(1, "pa\n", 3);
	return ;
}

void pb(int** listb, int** lista, int *lenb, int *lena)
{
	if (*lena == 0)
		return ;
	*listb = list_add_elem_top(*listb, lenb);
	*listb[0] = *lista[0];
	*lista = list_rm_elem_top(*lista, lena);
	write(1, "pb\n", 3);
	return ;
}
*/

int	*copy_list(int *lista, int lena)
{
	int	*listres;
	int	i;

	listres = malloc(sizeof(int) * lena);
	if (!listres)
		return (NULL);
	i = 0;
	while (i < lena)
	{
		listres[i] = lista[i];
		i++;
	}
	return (listres);
}

void	rrb(int *lista, int *lena)
{
	int	swap;
	int	i;
	int	first;

	if (*lena == 0 || *lena == 1)
		return ;
	i = (*lena) - 1;
	first = lista[i];
	swap = lista[i - 1];
	while (i > 0)
	{
		lista[i] = swap;
		if (i - 2 >= 0)
			swap = lista[i - 2];
		i--;
	}
	lista[0] = first;
	write(1, "rrb\n", 4);
	return ;
}

void	rra(int *lista, int *lena)
{
	int	swap;
	int	i;
	int	first;

	if (*lena == 0 || *lena == 1)
		return ;
	i = (*lena) - 1;
	first = lista[i];
	swap = lista[i - 1];
	while (i > 0)
	{
		lista[i] = swap;
		if (i - 2 >= 0)
			swap = lista[i - 2];
		i--;
	}
	lista[0] = first;
	write(1, "rra\n", 4);
	return ;
}

int	*rb(int *lista, int lena)
{
	int	swap;
	int	i;
	int	first;

	if (lena == 0 || lena == 1)
		return (lista);
	i = 0;
	first = lista[0];
	swap = lista[i + 1];
	while (i < lena - 1)
	{
		lista[i] = swap;
		if (i + 2 < lena)
			swap = lista[i + 2];
		i++;
	}
	lista[lena - 1] = first;
	write(1, "rb\n", 3);
	return (lista);
}

int	*ra(int *lista, int lena)
{
	int	swap;
	int	i;
	int	first;

	if (lena == 0 || lena == 1)
		return (lista);
	i = 0;
	first = lista[0];
	swap = lista[i + 1];
	while (i < lena - 1)
	{
		lista[i] = swap;
		if (i + 2 < lena)
			swap = lista[i + 2];
		i++;
	}
	lista[lena - 1] = first;
	write(1, "ra\n", 3);
	return (lista);
}
/*
int	main(void)
{
	int	*tabb;
	int	*tabbb;
	tabb = malloc(sizeof(int) * 10);

	int tab[10] = {5,34,2,75,45,97,3,67,45,7};
	int j = 0;	
	while (j < 10)
	{
		tabb[j] = tab[j];
		j++;
	} 
	int i = 0;
	int lena = 10;
	int	lenb = 10;
	tabbb = copy_list(tabb, lena);
	//tabbb = list_add_elem_top(tabbb, &len);
	//printlist(tabb, lena);
	//tabb = rra(&tabb, &lena);
	//pa(&tabb,&tabbb,&lena,&lenb);
	printlist(tabb, lena);
	ra(tabb, lena);
	printlist(tabb, lena);
	rrb(tabb, &lena);
	printlist(tabb, lena);
	return (0);
}
*/
/*
int *list_pa(int* list);

int *list_ra(int* list);

int	*list_rra(int* list);
*/
