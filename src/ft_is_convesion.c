/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_convesion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:57:28 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 07:58:06 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_convesion(t_flags **flags, const char **format, size_t *i)
{
	if (ft_strchr("cspdiuxX%", (*format)[*i]))
	{
		if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'c')
			(*flags)->conversion = CHARACTER;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 's')
			(*flags)->conversion = STRING;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'p')
			(*flags)->conversion = POINTER;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'd')
			(*flags)->conversion = DIGIT;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'i')
			(*flags)->conversion = IDIGIT;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'u')
			(*flags)->conversion = UNSIGNEDIGIT;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'x')
			(*flags)->conversion = XDIGIT;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == 'X')
			(*flags)->conversion = XXDIGIT;
		else if (*ft_strchr("cspdiuxX%", (*format)[*i]) == '%')
			(*flags)->conversion = PERCENT;
		return (1);
	}
	return (0);
}
