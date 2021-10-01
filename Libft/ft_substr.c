/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:02:27 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/06 13:09:40 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	int				alloc;

	j = 0;
	k = ft_strlen(s);
	while (s[start + j] != '\0')
		j++;
	i = 0;
	if (j > len)
		alloc = len;
	if (j <= len)
		alloc = j;
	d = malloc(alloc + 1);
	if (!d)
		return (d);
	while (i < len && s[start + i] != '\0' && i + start < k)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/*
int	main(void)
{
	char str[50];
	char	res[50];

	strcpy(str,"tripouille");
	puts(ft_substr(str, 1, 1));
	return (0);
}
*/
