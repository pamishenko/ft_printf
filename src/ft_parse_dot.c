/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:32:53 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 17:14:57 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_dot(t_flags **fl, const char **format, size_t *i, va_list *ap)
{
	*i = *i + 1;
	(*fl)->dot = 0;
	while (((*format)[*i]) && !ft_is_convesion(fl, format, i))
	{
		if ((*format)[*i] >= '1' && (*format)[*i] <= '9')
		{
			(*fl)->dot = ft_atoi(&(*format)[*i]);
			*i = *i + ft_count_razryad((*fl)->dot, 10);
		}
		else if ((*format)[*i] <= '*')
			(*fl)->dot = va_arg(*ap, unsigned int);
		*i = *i + 1;
	}
}
