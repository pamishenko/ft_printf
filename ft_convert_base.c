/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:55:53 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/03 22:30:55 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_base(unsigned long long int number, char base,
						t_flags **flag)
{
	char				*result;
	char				*base_format;
	int					len;
	int					size;

	len = -1;
	size = ft_count_razryad(number, base);
	if ((*flag)->conversion == XXDIGIT)
		base_format = "0123456789ABCDEF";
	else
		base_format = "0123456789abcdef";
	result = malloc(sizeof(char *) * size); // need make free()
	while (++len < size)
		result[len] = '0';
	while (number / base > 0)
	{
		result[len] = base_format[number % base];
		number /= base;
		len--;
	}
	return (result);
}
