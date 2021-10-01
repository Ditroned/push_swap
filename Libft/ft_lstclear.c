/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:50:38 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 17:51:28 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*second;
	t_list	*first;

	if (!del || !lst || !*lst)
		return ;
	first = *lst;
	while (first->next)
	{
		second = first->next;
		(del)(first->content);
		free(first);
		first = second;
	}
	(del)(first->content);
	free(first);
	*lst = NULL;
}
