/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:06:28 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/29 19:31:18 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mprintf(va_list test, const char c, int *val)
{
	if (c == 'c')
		*val += ft_putcharr(va_arg(test, int));
	else if (c == 's')
		*val += ft_putstrr(va_arg(test, char *));
	else if (c == 'p')
		ft_putvoid(va_arg(test, unsigned long), val);
	else if (c == 'd' || c == 'i')
		ft_putnbrr(va_arg(test, int), val);
	else if (c == 'u')
		ft_uputnbrr(va_arg(test, unsigned int), val);
	else if (c == 'X')
		ft_puthexaup(va_arg(test, unsigned int), val);
	else if (c == 'x')
		ft_puthexalow(va_arg(test, unsigned int), val);
	else if (c == '%')
		*val += ft_putcharr('%');
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		val;
	va_list	test;

	val = 0;
	i = 0;
	va_start(test, str);
	while (str[i])
	{
		if (str[i] == '%')
			mprintf(test, str[++i], &val);
		else
			val += ft_putcharr(str[i]);
		i++;
	}
	va_end(test);
	return (val);
}
