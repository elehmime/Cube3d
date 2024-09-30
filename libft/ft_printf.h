/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:22:19 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/28 18:22:23 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putcharr(int c);
int		ft_putstrr(char *str);
void	ft_puthexalow(unsigned int n, int *i);
void	ft_uputnbrr(unsigned int n, int *i);
void	ft_puthexaup(unsigned int n, int *i);
void	ft_putvoid(unsigned long n, int *i);
void	ft_putnbrr(int n, int *i);

#endif
