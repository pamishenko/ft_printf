/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:02:58 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/08 23:07:57 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef enum e_convers_type
{
	DEFAULT,
	CHARACTER,
	STRING,
	POINTER,
	DIGIT,
	IDIGIT,
	UNSIGNEDIGIT,
	XDIGIT,
	XXDIGIT,
	PERCENT
}	t_conv_name;

typedef struct s_flags_struct
{
	char			minus;
	char			zero;
	char			dot;
	char			star;
	unsigned int	width;
	t_conv_name		conversion;
}	t_flags;

int		ft_printf(const char *format, ...);
void	ft_print_param(const char **format, size_t *i, va_list *ap);
void	ft_print_element(t_flags **flags, va_list *ap);
void	ft_parse_flags(t_flags **flags, const char **format, size_t *i, va_list *ap);
int		ft_is_convesion(t_flags **flags, const char **format, size_t *i);
int		ft_count_razryad(long long int i, int base);
void	ft_flag_init(t_flags **flags);
int		ft_putchar_format(char ch, t_flags **flags);
int		ft_putstring_format(char *str, t_flags **flags);
void	ft_print_savesymbol(t_flags **flag);
char	*ft_convert_base(long long number, char base, t_flags **flag);
int		ft_putpointer_format(long long point, t_flags **flags);
int		ft_putnumber_format(long long int ap, t_flags **flags);
int		ft_unsigned_format(unsigned int ap, t_flags **flags);
int		ft_xdigit_format(long long int ap, t_flags **flags);
int		ft_putpercent_format(t_flags **flags);

#endif