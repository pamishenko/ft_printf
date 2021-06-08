/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xdigit_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:44:32 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/03 22:17:35 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xdigit_format(long long int ap, t_flags **flags)
{
	int	result;

	result = 0;
	if ((*flags)-> minus)
	{
		ft_putstr_fd(ft_convert_base(ap, 16, flags), 1);
		ft_print_savesymbol(flags);
		result = ft_strlen(ft_convert_base(ap, 16, flags)) + (*flags)->width;
	}
	else
	{
		ft_print_savesymbol(flags);
		ft_putstr_fd(ft_convert_base(ap, 16, flags), 1);
		result = ft_strlen(ft_convert_base(ap, 16, flags)) + (*flags)->width;
	}
	return (result);
}
