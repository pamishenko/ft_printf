/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:20:20 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 16:38:52 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring_format(char *strn, t_flags **flags)
{
	long unsigned int	result;
	char				*str;

	if (!strn)
		str = "(null)";
	else
		str = strn;
	result = 0;
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
