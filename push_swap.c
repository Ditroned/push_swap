/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:11 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/01 14:03:46 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "push_swap.h"

/*
int     ft_atoi(const char *str)
{
        int     sign;
        int     nbr;

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

void two_chunk_move_last(
int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;

	found = 0;
	while (found < 49)
	{
		if (*lista[0] <= listacp[24 + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[24 + (*len)[1]])
		&& (*lista[0] < listacp[49 + (*len)[1]]))
		{
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void two_chunk_move(
int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;

	found = 0;
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
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void two_chunk_move_last_500(
		int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;

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
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void two_chunk_move_500(int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;

	found = 0;
	while (found < 100)
	{
		if (*lista[0] <= listacp[49 + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[49 + (*len)[1]])
				&& (*lista[0] <= listacp[99 + (*len)[1]]))
		{
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

int	check_sort(int *lista, int *listb, int len, int lena)
{
	int i;

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

void chunker3(int *lista, int *listacp, int arg, int *len)
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
	int a;
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


void chunker5_2(int *lista, int *listcp, int *listb, int *len)
{
	int biga;
	int mina;

	while ((check_sort(lista, listcp,len[0], len[0] + len[1])) == 0)	
	{
		biga = max_list(lista, len[0]);
		mina = min_list(lista, len[0]);
		if (len[1] > 1)
		{
			if (listb[0] > listb[1])
				rb(listb, len[1]);
		}
		if (max_list(lista, len[0]) < listb[0]
				&& (min_list(lista, len[0]) == lista[0]
					|| (max_list(lista, len[0]) == lista[0]
						&& biga != listcp[3])))
		{
			pa(&lista, &listb, &len[0], &len[1]);
			if (lista[0] == listcp[len[0] + len[1] - 1]
					&& ((len[0] + len[1] != 5)
						&& (lista[0] < lista[2] || lista[2] == listcp[0])))
				sa(lista, len[0]);
		}
		if (((min_list(lista, len[0]) > listb[0]
						&& min_list(lista, len[0]) == lista[0])))
			pa(&lista, &listb, &len[0], &len[1]);
		if (listb[0] < lista[0] && listb[0] > lista[len[0] - 1])
			pa(&lista, &listb, &len[0], &len[1]);
		ra(lista, len[0]);
	}
}



void chunker5(int *lista, int *listcp, int arg, int *len)
{
	int	*list3;
	int i = 0;
	int *listb;
	int biga;
	int mina;

	int *listnana = listcp;

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

void chunker100(int *lista, int *listacp, int arg, int* len)
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


void chunker500(int *lista, int *listacp, int arg, int* len)
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

void two_chunk_move_last_500_sup(
		int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;

	found = 0;
	while (lena != 1)
	{
		
		if (*lista[0] != listacp[lena + lenb - 1])
		{
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void two_chunk_move_500_sup(
		int **lista, int **listb, int **len, int *listacp)
{
	int lena;
	int lenb;
	int	found;

	found = 0;
	lena = (*len)[0];
	lenb = (*len)[1];
	while (found < ((lena + lenb) / 10))
	{
		if (*lista[0] <= listacp[(((lena + lenb) / 10) - 1)
				+ (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[(((lena + lenb) / 10) - 1)
					+ (*len)[1]])
				&& (*lista[0] <= listacp[(((lena + lenb) / 10)) + (*len)[1]]))
		{
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void chunker500_sup(int *lista, int *listacp, int arg, int* len)
{
	int	*listb;
	int	i;

	i = 0;
	listb = NULL;
	int *abc = listacp;
	int *listbde = lista;
	
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

void    ft_sort_integer_table(int *tab, int size)
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

void two_chunk_move_inf(
		int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;
	int a = (*len)[0];
	int b;

	b = 0;
	if (a % 4 == 0)
		b = 1;
	found = 0;
	while (found < (a / 2))
	{
		if (*lista[0] <= listacp[(a / 4)])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		else if ((*lista[0] > listacp[(a / 4) - b
					+ (*len)[1]]) && (*lista[0] <= listacp[(a / 2)]))
		{
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void two_chunk_move_last_inf(
		int **lista, int **listb, int **len, int *listacp)
{
	int lena = (*len)[0];
	int lenb = (*len)[1];
	int	found;
	int a = (*len)[0];
	int b = (*len)[1];
	int	c = 0;
	
	if (c % 4 == 0)
		c = 1;
	found = 0;
	int *abc = listacp;
	while (lena != 1)
	{
		if (*lista[0] <= listacp[(a / 4) - c + (*len)[1]])
		{
			pb(listb, lista, &lenb, &lena);
			rb(*listb, lenb);
			found++;
		}
		if ((*lista[0] > listacp[(a / 4) - c + (*len)[1]]) &&
			   	(*lista[0] < listacp[a + b - 1]))
		{
			pb(listb, lista, &lenb , &lena);
			found++;
		}
		ra(*lista, lena);
	}
}

void chunkerinf100(int *lista, int *listacp, int arg, int *len)
{
	int	*listb;
	int	i;
	int moy;

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
		len[1] = arg  - (arg / 2) - i;
		i++;
	}
	two_chunk_move_last_inf(&lista, &listb, &len, listacp);
	len[1] += len[0] - 1 ;
	len[0] = 1;
	ft_rev_int_tab(listacp, arg);
	last_fill(&lista, &listb, listacp, len);
}


void	ft_dispatch(int	*lista, int *listacp, int arg, int *len)
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
	long nbr;

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
		nbr = (nbr * 10) + *str - 48;
		str++;
	}
	if (sign < 0)
		nbr = -nbr;
	if (nbr == (int)nbr && *str == 0)
		return (1);
	return (0);
}

int ft_list_unique(int *tab, int len)
{
	int i;
	int j;
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

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void ft_free(int *len, int *listacp, int **lista)
{
	int **gf = lista;
	
	free(len);
	free(listacp);
}
*/

/*
int	check_arg(int argc, char **argv)
{
	char	**cpargv;
	char	**purcp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	purcp = argv;
	if (argc == 2)
	{
		if (argv[1][0] == 0)
			                                               return (0);
		cpargv = ft_split(argv[1], ' ');
		if (cpargv == NULL)
			                                    return (ft_error());
		while (cpargv[i] != NULL)
			i++;
		purcp = cpargv;
		j = 0;
	}
	return (0);
}
*/

void	end_main(int argc, int **lista)
{
	int	*listacp;
	int	*len;

	len = malloc(sizeof(int) * 2);
	if (!len)
		return ;
	len[0] = argc - 1;
	len[1] = 0;
	listacp = copy_list(*lista, len[0]);
	ft_sort_int_tab(listacp, len[0]);
	if (check_sort(*lista, listacp, argc - 1, len[0]))
	{
		free(len);
		free(listacp);
		return ;
	}
	ft_dispatch(*lista, listacp, argc - 1, len);
	free(len);
	free(listacp);
}

int	main_argc(int *i, int *j, char ***argv, int *argc)
{
	char	**cpargv;
	char	**purcp;

	cpargv = NULL;
	*i = 0;
	*j = 1;
	purcp = *argv;
	if (*argc == 2)
	{
		cpargv = ft_split((*argv)[1], ' ');
		if (cpargv == NULL)
			return (0);
		while (cpargv[*i] != NULL)
			*i += 1;
		purcp = cpargv;
		*j = 0;
	}
	if (*i > 1)
		*argc = *i + 1;
	*i = -1;
	*argv = purcp;
	return (1);
}

int	main(int argc, char **argv)
{
	int		*lista;
	int		i;
	char	**cpargv;
	int		j;	

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == 0)
		return (0);
	lista = malloc(sizeof(int) * (argc - 1));
	if (!lista)
		return (0);
	if (main_argc(&i, &j, &argv, &argc) == 0)
		return (ft_error(&lista));
	while (++i < argc - 1)
	{
		if (ft_isatoi(argv[i + j]) == 0)
			return (ft_error(&lista));
		lista[i] = ft_atoi(argv[i + j]);
	}
	if (ft_list_unique(lista, argc - 1) == 0)
		 return (ft_error(&lista));
	end_main(argc, &lista);
	return (0);
}
