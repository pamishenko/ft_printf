/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:20:20 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 08:07:16 by ttanja           ###   ########.fr       */
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

int	ft_putstring_format(char *strn, t_flags **flags)
{
	long unsigned int	result;
	char				*str;

	if (!strn)
		str = "(null)";
	else
		str = strn;
	result = 0;
	ft_set_width_string(flags, ft_strlen(str));
	if ((*flags)-> minus)
	{
		result += ft_print_value(flags, str);
		result += ft_print_savesymbol(flags);
		result = ft_strlen(str) + (*flags)->width;
	}
	else
	{
		result += ft_print_savesymbol(flags);
		result += ft_print_value(flags, str);
	}
	return (result);
}
