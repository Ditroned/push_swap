#include "push_swap.h"

int	ft_pos_elem(int a, int *list)
{
	int	i;

	i = 0;
	while (list[i] != a)
		i++;
	return (i);
}

void    ft_rev_int_tab(int      *tab, int size)
{
        int     count;
        int     swap;

        swap = '0';
        count = 0;
        while (count < (size / 2))
        {
                swap = tab[count];
                tab[count] = tab[size - 1 - count];
                tab[size - 1 - count] = swap;
                count++;
        }
}

void move(int **lista, int **listb, int *len, int pos)
{
	int	i;

	i = 0;
	/*
	if (pos > (len[1] / 2))
	{
		while (len[1] - (pos + i) != 0)
		{
			rrb(*listb, len[1]);
			i++;
		}
		pa(lista, listb, &len[0], &len[1]);
		return ;
	}
	*/
	//if (pos < (len[1] / 2))
	//{
		while (i < pos)
		{
			rb(*listb, len[1]);
			i++;
		}
		pa(lista, listb, &len[0], &len[1]);
	//}
	/*
	else
	{
		while (i < (len[1] - pos))
		{
			rrb(*listb, len[1]);
			i++;
		}
		pa(lista, listb, &len[0], &len[1]);
	}
	*/
}



void last_fill(int **lista, int **listb, int *listacp, int *len)
{
		int	found;
		int	pos;
		int maxlen;

		found = 0;
		maxlen = len[1];
		while (found < maxlen)
		{
			pos = ft_pos_elem(listacp[found], *listb);
			move(lista, listb, len, pos);
			found++;
		}
}
/*


int	main(void)
{
	int list[7] = {9, 3, 5, 6, 2, 0, 8};
	int *listcp;
	listcp = copy_list(list, 7);
	printf("%d", ft_pos_elem(6, listcp));
	return (0);
}
*/
