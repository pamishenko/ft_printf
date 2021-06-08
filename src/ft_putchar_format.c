/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:41:52 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/28 20:21:47 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_format(char ch, t_flags **flags)
{
	if ((*flags)->minus != 0 && (*flags)->width > 1)
	{
		ft_putchar_fd(ch, 1);
		ft_print_savesymbol(flags);
	}
	else if ((*flags)->width > 1)
	{
		ft_print_savesymbol(flags);
		ft_putchar_fd(ch, 1);
	}
	else
		ft_putchar_fd(ch, 1);
	return (0);
}
