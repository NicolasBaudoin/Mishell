/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:12:59 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/26 09:37:05 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;
	size_t			i;

	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (cpy_s1[i] != cpy_s2[i])
			return (cpy_s1[i] - cpy_s2[i]);
		i++;
	}
	return (0);
}
