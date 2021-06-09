/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_savesymbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:21:02 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/08 22:38:10 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_savesymbol(t_flags **flag)
{
	char	r;

	if ((*flag)->zero == 1 && (*flag)->conversion != POINTER)
		r = '0';
	else
		r = ' ';
	while ((*flag)->width > 1)
	{
		ft_putchar_fd(r, 1);
		(*flag)->width = (*flag)->width - 1;
	}
}
