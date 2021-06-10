/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:32:53 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 06:41:21 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_parse_dot(t_flags **flags, const char **format, size_t *i, va_list *ap)
{
	*i = *i + 1;
	(*flags)->dot = 0;
	while (((*format)[*i]) && !ft_is_convesion(flags, format, i))
	{
		if ((*format)[*i] >= '1' && (*format)[*i] <= '9')
		{
			(*flags)->dot = ft_atoi(&(*format)[*i]);
			*i = *i + ft_count_razryad((*flags)->dot, 10);
		}
		else if ((*format)[*i] <= '*')
			(*flags)->dot = va_arg(*ap, unsigned int);
		*i = *i + 1;
	}
}
