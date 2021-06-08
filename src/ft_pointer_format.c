/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:48:06 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/08 19:12:26 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_format(long long point, t_flags **flags)
{
	ft_putstr_fd("0x", 1);
	ft_putstring_format(ft_convert_base(point, 16, flags), flags);
	return (14);
}
