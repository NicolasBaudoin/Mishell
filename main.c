/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/08 18:07:09 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

void	mishell_is_working(char *input)
{
	t_token	*tokens;

	tokens = lexer(input);
	if (!tokens)
		return ;
	printf("%s\n", tokens->value);
	// parser(tokens)
	// execution(tokens);
	// free(token);
}

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("Mishell> ");
		if (input == NULL)
		{
			printf("\nExiting...\n");
			return (1);
		}
		mishell_is_working(input);
		free(input);
	}
	return (0);
}
