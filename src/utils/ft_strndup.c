/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:04:25 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/22 15:36:14 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strndup(const char *s, int start, int end)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < end - start && s[start + i])
	{
		dup[i] = s[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_realloc_args(char **str)
{
	char	**new;
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (str[size])
		size++;
	// Realloc de **args
	new = ft_calloc((size + 1),  sizeof(char *));
	// copy de chaque *args et NULL terminate
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(*str);
		i++;
	}
	new[i] = NULL;
	free(str);
	return (new);
}
