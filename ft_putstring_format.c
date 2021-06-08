/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:20:20 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/28 20:31:50 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_width_string(t_flags **flag, unsigned int len)
{
	if ((long long int)(*flag)->width - len > 0)
		(*flag)->width = (*flag)->width - len;
	else
		(*flag)->width = 0;
}

int	ft_putstring_format(char *str, t_flags **flags)
{
	long unsigned int	result;

	result = 0;
	ft_set_width_string(flags, ft_strlen(str));
	if ((*flags)-> minus)
	{
		ft_putstr_fd(str, 1);
		ft_print_savesymbol(flags);
		result = ft_strlen(str) + (*flags)->width;
	}
	else
	{
		ft_print_savesymbol(flags);
		ft_putstr_fd(str, 1);
		result = ft_strlen(str) + (*flags)->width;
	}
	return (result);
}