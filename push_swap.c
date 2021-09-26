#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "push_swap.h"
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
        return (nbr);
}

int	main(int argc, char **argv)
{
	int	*lista;
	int	*listacp;
	int	*listb;
	int	i;
	int	found;
	int	lena;
	int	lenb;


	lista = malloc(sizeof(int) * (argc - 1));
	if (!lista)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		lista[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	listacp = copy_list(lista, argc - 1);
	ft_sort_int_tab(listacp, argc - 1);
	i = 0;
	found = 0;
	int maxlen = argc - 1;
	lena = argc - 1;
	lenb = 0;
	listb = NULL;
	
	//ft_rev_int_tab(listacp, argc - 1);
	while (found < 10)
	{
		if (lista[0] <= listacp[4])
		{
			pb(&listb, &lista, &lenb, &lena);
			found++;
		}
		if ((lista[0] > listacp[4]) && (lista[0] <= listacp[9]))
		{
			pb(&listb, &lista, &lenb, &lena);
			rb(listb, lenb);
			found++;
		}
		ra(lista, lena);
	}
	found = 0;
	while (found < 10)
	{
		if ((lista[0] >= listacp[10]) && (lista[0] < listacp[15]))
		{
			found++;
			pb(&listb, &lista, &lenb, &lena);
		}
		if (lista[0] >= listacp[15])
		{
			found++;
			pb(&listb, &lista, &lenb, &lena);
			rb(listb, lenb);
		}
		ra(lista, lena);
	}
	/*
	while (found < maxlen - 1)
	{
		if (lista[0] != listacp[argc - 2])
		{
			found++;
			pb(&listb, &lista, &lenb, &lena);
		}
		ra(lista, lena);
	}
	*/
	ft_rev_int_tab(listacp, argc - 1);
	int	*len;
	len = malloc(sizeof(int) * 2);
	if (!len)
		return (0);
	len[0] = lena;
	len[1] = lenb;
//	printlist(listb, len[1]);
//	printlist(lista, len[0]);
	last_fill(&lista, &listb, listacp, len);
//	printlist(listb, len[1]);
//	printlist(lista, len[0]);
	return (0);
}

