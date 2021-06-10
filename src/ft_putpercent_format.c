/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:28:07 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 16:17:05 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	ft_print_value_percent(t_flags **flag, char str)
{
	unsigned long	result;

	result = 0;
	if ((*flag)->dot != 0)
		(*flag)->dot = 1;
	ft_putchar_fd(str, 1);
	str++;
	result++;
	(*flag)->dot = (*flag)->dot -1;
	return (result);
}

int	ft_putpercent_format(t_flags **flags)
{
	int	result;

	result = 0;
	if ((*flags)-> minus)
	{
		if ((*flags)->width > 0)
			(*flags)->width = (*flags)->width - 2;
		ft_print_value_percent(flags, '%');
		ft_print_savesymbol(flags);
		result = 1 + (*flags)->width;
	}
	else
	{
		if ((*flags)->width > 0)
			(*flags)->width = (*flags)->width - 1;
		ft_print_savesymbol(flags);
		ft_print_value_percent(flags, '%');
		result = 1 + (*flags)->width;
	}
	return (result);
}
