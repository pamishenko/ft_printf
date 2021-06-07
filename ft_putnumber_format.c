/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:54:21 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/01 17:35:38 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber_format(long long int ap, t_flags **flags)
{
	int	result;

	result = 0;
	if ((*flags)-> minus)
	{
		ft_putstr_fd(ft_itoa(ap), 1);
		ft_print_savesymbol(flags);
		result = ft_strlen(ft_itoa(ap)) + (*flags)->width;
	}
	else
	{
		ft_print_savesymbol(flags);
		ft_putstr_fd(ft_itoa(ap), 1);
		result = ft_strlen(ft_itoa(ap)) + (*flags)->width;
	}
	return (result);
}
