/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:59:19 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/28 21:49:37 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_sep(char *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

char	*next_word(char *s, char c)
{
	char	*d;

	d = s;
	while (*d == c && *d != '\0')
		d++;
	return (d);
}

char	*ft_word(char const *s, char c)
{
	char	*str;
	char	*str1;
	int		i;
	int		j;

	j = 0;
	while (s[j] != c && s[j] != '\0')
		j++;
	i = 0;
	if (*s == '\0')
		return ((char *)s);
	str = malloc (sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	str1 = str;
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	s = &s[i];
	return (str);
}

char	*ft_splitfct(char const *s, char c)
{
	int		i;
	int		j;

	j = 0;
	while (s[j] != c && s[j] != '\0')
		j++;
	i = 0;
	if (*s == '\0')
		return ((char *)s);
	while (i < j)
		i++;
	s = &s[i];
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	**tabres;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc (sizeof(char *) * (count_sep((char *)s, c) + 1));
	if (!tab)
		return (tab);
	tabres = tab;
	while (*s)
	{
		s = next_word((char *)s, c);
		if (*s == '\0')
			break ;
		*tab++ = ft_word(s, c);
		s = ft_splitfct(s, c);
		j++;
		s = next_word((char *)s, c);
		if (*s == '\0')
			break ;
	}
	*tab = NULL;
	return (tabres);
}
/*
int	main(void)
{
	char	s[100];
	char	d;
	char	**split;

	d = ' ';
	strcpy(s,"   ");
	split = ft_split((char const *)s, d);
	//printf("%d", len_word(s, d));
	while (*split)
		puts(*split++);
	//printf("%d", count_sep(s, d));
	return (0);
}
*/
