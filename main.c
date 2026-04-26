/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/26 02:53:12 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

int	main()
{
	char *input;


	input = readline("Prompt ?");
	if (input  == NULL)
	{
		printf("\nExiting...\n");
		return (0);
	}
	printf("%s , %d\n", input, pwd(ft_atoi(input)));
	free(input);




	return (0);
}
