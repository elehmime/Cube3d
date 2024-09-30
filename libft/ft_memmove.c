/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:27:58 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/09 20:28:14 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	a = dest;
	b = src;
	if (dest == src)
		return (NULL);
	if (a < b)
	{
		while (n--)
			*a++ = *b++;
	}
	else
	{
		while (n--)
			a[n] = b[n];
	}
	return (dest);
}
