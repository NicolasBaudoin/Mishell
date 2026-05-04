/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:49:01 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/13 13:34:29 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence_chr;
	char	*cpy_s;
	size_t	i;
	size_t	len;
	int		found;

	last_occurence_chr = (char *)s;
	cpy_s = (char *)s;
	len = (size_t)ft_strlen(s);
	found = 0;
	i = 0;
	while (i <= len)
	{
		if (*cpy_s == (char)c)
		{
			last_occurence_chr = cpy_s;
			found = 1;
		}
		cpy_s++;
		i++;
	}
	if (found == 0)
		return (NULL);
	return (last_occurence_chr);
}
