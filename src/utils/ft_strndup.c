/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:04:25 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/11 12:07:05 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strndup_to_token(const char *s, t_lexer *lexer);

{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!dup)
		return (NULL);
	i = start;
	while (i < end && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
