/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:48:06 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 16:23:10 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer_format(long long point, t_flags **flags)
{
	char	*print;
	char	*temp;

	temp = ft_strdup("1111111111111");
	print = ft_strdup("1111111111111111");
	ft_bzero(print, 17);
	ft_strlcat(print, "0x", 2);
	(*flags)->dot = 3;
	if (!point)
		ft_strlcat(print, "0", 1);
	else
	{
		temp = ft_convert_base(point, 16, flags);
		ft_strlcat(print, temp, 13);
		(*flags)->dot = 16;
	}
	ft_putstring_format(print, flags);
	free(print);
	return ((*flags)->dot);
}
