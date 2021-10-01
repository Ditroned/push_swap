/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:17:30 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 22:43:58 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tab;
	t_list	*tabres;

	if (!f || !lst)
		return (0);
	tab = ft_lstnew(f(lst->content));
	if (!tab)
		return (0);
	tabres = tab;
	lst = lst->next;
	while (lst)
	{
		(tab)->next = ft_lstnew((*f)(lst->content));
		if (!(tab)->next)
		{
			del(lst->content);
			return (0);
		}
		lst = lst->next;
		tab = (tab)->next;
	}
	(tab)->next = NULL;
	return (tabres);
}
/*
 * le testeur ne marche pas si on return 0 si !del
 * f est utilise sans etoiles , et il va renvoyer  un void * , 
 * c4est le content par exemple dans notre cas
*/
