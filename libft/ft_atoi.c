/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:41:54 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/20 10:51:00 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned char	*cpy_nptr;
	int				nbr;
	int				sign;

	i = 0;
	cpy_nptr = (unsigned char *)nptr;
	nbr = 0;
	sign = 1;
	while ((cpy_nptr[i] >= 9 && cpy_nptr[i] <= 13) || cpy_nptr[i] == ' ')
		i++;
	if (cpy_nptr[i] == '-' || cpy_nptr[i] == '+')
	{
		if (cpy_nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (cpy_nptr[i] >= '0' && cpy_nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (cpy_nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}
