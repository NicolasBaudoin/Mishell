/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:59:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/25 02:17:00 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpy_s;
	unsigned char	to_find;

	cpy_s = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (n--)
	{
		if (*cpy_s == to_find)
			return (cpy_s);
		cpy_s++;
	}
	return (NULL);
}
