/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:01:19 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 16:27:25 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(t_flags **fl, const char **fr, size_t *i,	va_list *ap)
{
	ft_flag_init(fl);
	while (((*fr)[*i]) && !ft_is_convesion(fl, fr, i))
	{
		if ((*fr)[*i] == '-')
			(*fl)->minus = 1;
		else if ((*fr)[*i] >= '1' && (*fr)[*i] <= '9')
		{
			(*fl)->width = ft_atoi(&(*fr)[*i]);
			*i = *i + ft_count_razryad((*fl)->width, 10);
			continue ;
		}
		else if (!((*fl)->minus) && (*fr)[*i] == '0')
			(*fl)->zero = 1;
		else if ((*fr)[*i] == '*')
			(*fl)->width = va_arg(*ap, unsigned int);
		else if ((*fr)[*i] == '.')
			ft_parse_dot(fl, fr, i, ap);
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
