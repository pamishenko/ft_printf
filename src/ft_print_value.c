/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 06:55:12 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 07:33:25 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_print_value(t_flags **flag, char *str)
{
	unsigned long	result;

	result = 0;
	if ((*flag)->dot == -1)
		(*flag)->dot = ft_strlen(str);
	while ((*flag)->dot)
	{
		ft_putchar_fd(*str, 1);
		str++;
		result++;
		(*flag)->dot = (*flag)->dot -1;
	}
	return (result);
}
