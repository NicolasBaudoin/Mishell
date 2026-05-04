/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:40:30 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/13 13:29:07 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_malloc(char const *s, unsigned int start, size_t len)
{
	int	size;
	int	size_is_valid;

	size = ft_strlen(s);
	size_is_valid = len;
	if (len > (size - start))
		size_is_valid = size - start;
	return (size_is_valid + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;
	char	*nulmal;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		nulmal = malloc(1);
		if (!nulmal)
			return (NULL);
		nulmal[0] = '\0';
		return (nulmal);
	}
	substr = (char *)malloc(size_malloc(s, start, len));
	if (!substr)
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (&substr[0]);
}
