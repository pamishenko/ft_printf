/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:01:19 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/08 19:13:09 by ttanja           ###   ########.fr       */
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

void	ft_parse_flags(t_flags **flags, const char **format, size_t *i, va_list *ap)
{
	ft_flag_init(flags);
	while (((*format)[*i]) && !ft_is_convesion(flags, format, i))
	{
		if ((*format)[*i] == '-')
			(*flags)->minus = 1;
		else if ((*format)[*i] >= '1' && (*format)[*i] <= '9')
		{
			(*flags)->width = ft_atoi(&(*format)[*i]);
			*i = *i + ft_count_razryad((*flags)->width, 10);
			continue ;
		}
		else if (!((*flags)->minus) && (*format)[*i] == '0')
			(*flags)->zero = 1;
		else if ((*format)[*i] == '.')
			(*flags)->dot = 1;
		else if ((*format)[*i] == '*')
			(*flags)->width = va_arg(*ap, unsigned int);
		*i = *i + 1;
	}
}

void	ft_print_element(t_flags **flags, va_list *ap)
{
	if ((*flags)->conversion == CHARACTER)
		ft_putchar_format(va_arg(*ap, int), flags);
	else if ((*flags)->conversion == STRING)
		ft_putstring_format(va_arg(*ap, char *), flags);
	else if ((*flags)->conversion == POINTER)
		ft_pointer_format((va_arg(*ap, long long)), flags);
	else if ((*flags)->conversion == DIGIT)
		ft_putnumber_format(va_arg(*ap, int), flags);
	else if ((*flags)->conversion == IDIGIT)
		ft_putnumber_format(va_arg(*ap, int), flags);
	else if ((*flags)->conversion == UNSIGNEDIGIT)
		ft_unsigned_format(va_arg(*ap, int), flags);
	else if ((*flags)->conversion == XDIGIT)
		ft_xdigit_format(va_arg(*ap, int), flags);
	else if ((*flags)->conversion == XXDIGIT)
		ft_xdigit_format(va_arg(*ap, int), flags);
	else if ((*flags)->conversion == PERCENT)
		ft_putpercent_format(flags);
	ft_bzero(*flags, sizeof(t_flags));
}

void	ft_print_param(const char **format, size_t *i, va_list *ap)
{
	t_flags		*flags;

	*i = *i + 1;
	ft_parse_flags(&flags, format, i, ap);
	ft_print_element(&flags, ap);
	free((t_flags *) flags);
}

int	ft_printf(const char *format, ...)
{
	size_t				i;
	va_list				ap;

	va_start(ap, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		else
			ft_print_param(&format, &i, &ap);
	}
	return (i);
}
