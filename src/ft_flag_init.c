/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:44:53 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/31 15:28:42 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_init(t_flags **flags)
{
	*flags = malloc(sizeof(t_flags));
	ft_bzero(*flags, sizeof(t_flags));
	(*flags)->minus = 0;
	(*flags)->zero = 0;
	(*flags)->dot = 0;
	(*flags)->star = 0;
	(*flags)->width = 0;
	(*flags)->conversion = DEFAULT;
}
