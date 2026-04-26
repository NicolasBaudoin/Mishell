/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:22:41 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/20 11:54:36 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mymal;

	if (!size || !nmemb)
	{
		mymal = malloc(0);
		if (!mymal)
			return (NULL);
		return (mymal);
	}
	if (nmemb != 0 && ((nmemb * size) / nmemb) != size)
		return (NULL);
	mymal = (char *)malloc(nmemb * size);
	if (!mymal)
		return (NULL);
	ft_memset(mymal, 0, nmemb * size);
	return (mymal);
}
