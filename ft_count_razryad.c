/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_razryad.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:47:58 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/03 22:41:09 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_razryad(long long int i, int base)
{
	int	result;

	result = 0;
	while (i > 0)
	{
		i = i / base;
		result++;
	}
	return (result);
}
