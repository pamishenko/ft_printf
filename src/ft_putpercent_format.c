/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:28:07 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/08 17:07:56 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent_format(t_flags **flags)
{
	int	result;

	result = 0;
	if ((*flags)-> minus)
	{
		ft_putchar_fd('%', 1);
		ft_print_savesymbol(flags);
		result = 1 + (*flags)->width;
	}
	else
	{
		ft_print_savesymbol(flags);
		ft_putchar_fd('%', 1);
		result = 1 + (*flags)->width;
	}
	return (result);
}
