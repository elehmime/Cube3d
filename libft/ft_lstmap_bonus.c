/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:13:11 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/25 17:13:16 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy_lst;
	void	*new_cont;

	if (!lst)
		return (NULL);
	new_cont = f(lst->content);
	if (!new_cont)
		return (NULL);
	cpy_lst = ft_lstnew(new_cont);
	if (!cpy_lst)
	{
		del(new_cont);
		return (NULL);
	}
	if (!lst->next)
		return (cpy_lst);
	cpy_lst->next = ft_lstmap(lst->next, f, del);
	return (cpy_lst);
}
/*prends une liste et crée une nouvelle
parcours chaque element de la liste
crée une copy de lst en ayant appliqué la fonction*/
