/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_savesymbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:21:02 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 14:15:17 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_print_savesymbol(t_flags **flag)
{
	char				r;
	long long	result;

	if ((((*flag)->width) - ((*flag)->dot)) > 0)
		(*flag)->width = ((*flag)->width) - ((*flag)->dot);
	else
		(*flag)->width = 0;
	result = (*flag)->width;VYVVdsfb 
	if ((*flag)->zero == 1 && (*flag)->conversion != POINTER)
		r = '0';
	else
		r = ' ';
	while (((*flag)->width) > 0)
	{
		ft_putchar_fd(r, 1);
		(*flag)->width = (*flag)->width - 1;
		printf("\n what is it????  %lld\n", (*flag)->width);
	}
	return (result);
}
