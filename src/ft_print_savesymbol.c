/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_savesymbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:21:02 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 07:35:14 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_print_savesymbol(t_flags **flag)
{
	char				r;
	unsigned long long	result;

	(*flag)->width = (*flag)->width - (*flag)->dot;
	result = (*flag)->width;
	if ((*flag)->zero == 1 && (*flag)->conversion != POINTER)
		r = '0';
	else
		r = ' ';
	while ((*flag)->width > 1)
	{
		ft_putchar_fd(r, 1);
		(*flag)->width = (*flag)->width - 1;
	}
	return (result);
}
