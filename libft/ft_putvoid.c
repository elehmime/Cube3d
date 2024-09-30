/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:10:19 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/29 19:32:13 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putvoid1(unsigned long n, int *i)
{
	if (n >= 16)
	{
		ft_putvoid1(n / 16, i);
	}
	*i += 1;
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_putvoid(unsigned long n, int *i)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*i += 5;
	}
	else
	{
		write (1, "0x", 2);
		*i += 2;
		ft_putvoid1(n, i);
	}
}
