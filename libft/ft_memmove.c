/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:32:53 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/11/02 14:54:05 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_cpy;
	unsigned char	*dest_cpy;
	size_t			i;
	size_t			index_n;

	if (!dest && !src)
		return (NULL);
	i = 0;
	index_n = n - 1;
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	if (dest_cpy > src_cpy && dest <= (src + n))
	{
		while (n-- > 0)
		{
			*(dest_cpy + index_n) = *(src_cpy + index_n);
			index_n--;
		}
	}
	else
	{
		while (i++ < n)
			*dest_cpy++ = *src_cpy++;
	}
	return (dest);
}
