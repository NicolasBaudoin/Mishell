/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:55:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/26 09:26:24 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*dup;
	int		i;

	cpy = (char *)s;
	dup = (char *)malloc(ft_strlen(cpy) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (cpy[i])
	{
		dup[i] = cpy[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
