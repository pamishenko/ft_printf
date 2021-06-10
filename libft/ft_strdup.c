/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:17:01 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/10 17:46:56 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	char	*dup;

	temp = (char *)s1;
	dup = (char *)malloc(ft_strlen(s1) * sizeof(char));
	if (NULL == dup)
		return (NULL);
	while (*temp)
		*dup++ = *temp++;
	*dup = '\0';
	return (dup - ft_strlen(s1));
}
