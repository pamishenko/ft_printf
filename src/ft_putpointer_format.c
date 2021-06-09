/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:48:06 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/08 23:17:36 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer_format(long long point, t_flags **flags)
{
	int 	result;
	char	*print;

	result = 3;
	ft_putstr_fd("0x", 1);
	if (!point)
		ft_putchar_fd('0', 1);
	else
	{
		print = ft_convert_base(point, 16, flags);
		result = ft_putstring_format(print, flags) - 1;
		free(print);
	}
	return (result);
}
