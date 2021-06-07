/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:48:06 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/03 22:38:28 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_format(unsigned long long int point, t_flags **flags)
{
	ft_putstr_fd("0x", 1);
	ft_putstring_format(ft_convert_base(point, 16, flags), flags);
	return (14);
}
