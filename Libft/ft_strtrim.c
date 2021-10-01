/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:50:26 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/04 16:21:52 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_check(char s1, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_check(s1[i], (char *)set))
		i++;
	j = ft_strlen((char *)s1);
	while (j > i && ft_check(s1[j - 1], (char *)set))
		j--;
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (res);
	k = i;
	l = 0;
	while (l < j - i)
	{
		res[l++] = s1[k];
		k++;
	}
	res[l] = '\0';
	return (res);
}
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	s1[50];
	char	set[50];

	strcpy(s1, "coucou les balourds");
	strcpy(set, "couds");
	puts(ft_strtrim((const char *)s1, (const char *)set));
	return (0);
}
*/
