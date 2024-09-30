/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:18:08 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/29 19:29:15 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexaup(unsigned int n, int *i)
{
	if (n >= 16)
		ft_puthexaup(n / 16, i);
	*i += 1;
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}
