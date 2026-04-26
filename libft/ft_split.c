/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:24:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/30 09:28:48 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	count_len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_check(char **tab, int k)
{
	int	i;

	i = 0;
	if (!tab[k])
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab[i]);
		free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	int		k;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		count = count_len_word(s, c);
		tab[k] = ft_substr(s, 0, count);
		if (ft_check(tab, k) == 0)
			return (NULL);
		k++;
		s += count;
	}
	tab[k] = NULL;
	return (tab);
}
