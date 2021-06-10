/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:41:52 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 07:33:25 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_format(char ch, t_flags **flags)
{
	if ((*flags)->minus != 0 && (*flags)->width > 1)
	{
		ft_print_value(flags, &ch);
		ft_print_savesymbol(flags);
	}
	else if ((*flags)->width > 1)
	{
		ft_print_savesymbol(flags);
		ft_print_value(flags, &ch);
	}
	else
		ft_putchar_fd(ch, 1);
	return (0);
}
