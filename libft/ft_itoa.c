/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:53:59 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/26 09:04:33 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_is_min(int *n, char *tab, int *i)
{
	tab[0] = '-';
	*n *= -1;
	*i = 1;
}

static void	ft_is_int_min(int n, char *tab)
{
	char	*intmin;
	int		len;

	intmin = "-2147483648";
	len = ft_get_len(n);
	if (n == -2147483648)
	{
		ft_memcpy(tab, intmin, len + 1);
		tab[len + 1] = '\0';
	}
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_get_len(n);
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	ft_memset(tab, '\0', len + 1);
	ft_is_int_min(n, tab);
	if (n == -2147483648)
		return (tab);
	if (n < 0)
		ft_is_min(&n, tab, &i);
	while (len-- > i)
	{
		tab[len] = n % 10 + '0';
		n = n / 10;
	}
	return (tab);
}
