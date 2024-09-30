/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:52:36 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/21 18:52:44 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	fr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!fr)
		return (NULL);
	while (s[i])
	{
		fr[i] = (*f)(i, s[i]);
		i++;
	}
	fr[i] = 0;
	return (fr);
}
