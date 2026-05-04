/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:03:38 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/14 23:57:34 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cpy_little;
	char	*cpy_big;
	size_t	i;
	size_t	k;

	cpy_little = (char *)little;
	cpy_big = (char *)big;
	i = 0;
	if (!cpy_little[i])
		return (&cpy_big[i]);
	k = 0;
	while ((i < len) && cpy_big[i])
	{
		if (cpy_big[i++] == cpy_little[k++])
		{
			if (cpy_little[k] == '\0')
				return (&cpy_big[i - k]);
		}
		else
		{
			i = i - k + 1;
			k = 0;
		}
	}
	return (NULL);
}
