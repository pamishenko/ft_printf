/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:01:19 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 07:58:06 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else if ((*format)[*i] == '*')
			(*flags)->width = va_arg(*ap, unsigned int);
		else if ((*format)[*i] == '.')
			ft_parse_dot(flags, format, i, ap);
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
		ft_putpointer_format((va_arg(*ap, long long)), flags);
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
