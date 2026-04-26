/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:50:30 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/11/02 15:06:34 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_when_negative(char **cpy)
{
	*cpy = ft_calloc(1, 1);
	if (!*cpy)
		*cpy = NULL;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		start;
	int		end;

	if (!s1 || (!s1 && !set))
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (end - start <= 0)
	{
		ft_when_negative(&cpy);
		return (cpy);
	}
	while (ft_strchr(set, s1[end]))
		end--;
	cpy = ft_calloc(((end - start) + 2), sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1 + start, (end - start) + 1);
	return (cpy);
}
