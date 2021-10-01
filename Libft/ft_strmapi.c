/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:37:25 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 15:06:05 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;
	char			*str;
	unsigned int	j;

	if (!s)
		return (NULL);
	d = (char *)s;
	i = 0;
	if (!f)
		return (NULL);
	while (*d++)
		i++;
	str = malloc(i + 1);
	if (!str)
		return (str);
	j = 0;
	while (j < i)
	{
		str[j] = (*f)(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
