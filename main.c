/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/26 02:12:14 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char *input;

	input = readline("Prompt ?");
	if (input  == NULL)
	{
		printf("\nExiting...\n");
		return (0);
	}
while (1)
{

	add_history(input);
	printf("Hello, %s\n", input);
	free(input);
}




	return (0);
}
