/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:41:47 by yonamog2          #+#    #+#             */
/*   Updated: 2022/09/23 09:45:29 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cra;

	if (lst && del)
	{
		tmp = NULL;
		while (lst)
		{
			cra = ft_lstnew((*f)(lst->content));
			if (!cra)
			{
				ft_lstclear(&cra, del);
				return (NULL);
			}
			ft_lstadd_back(&tmp, cra);
			lst = lst->next;
		}
		return (tmp);
	}
	return (NULL);
}
