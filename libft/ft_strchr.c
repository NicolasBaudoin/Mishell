/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 07:26:14 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/13 13:36:41 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cpy_s;
	char	to_find;
	int		len;

	i = 0;
	cpy_s = (char *)s;
	to_find = (char)c;
	len = ft_strlen(cpy_s);
	while (i <= len)
	{
		if (*cpy_s == to_find)
			return (cpy_s);
		if (*cpy_s == '\0')
			return (NULL);
		i++;
		cpy_s++;
	}
	return (NULL);
}
