/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:03:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/24 21:23:00 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*pounto_map;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	pounto_map = malloc(sizeof(char) * (len + 1));
	if (!pounto_map)
		return (NULL);
	while (i < len)
	{
		pounto_map[i] = (*f)(i, s[i]);
		i++;
	}
	pounto_map[i] = '\0';
	return (pounto_map);
}
