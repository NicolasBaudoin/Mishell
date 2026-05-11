/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/11 10:49:22 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;
// status pour les signaux des fonctions et arret programme

void	mishell_is_working(char *input)
{
	t_token	*tokens;
	t_token	*curr;


	tokens = lexer(input);
	curr = tokens;
	if (!tokens)
		return ;
	while (curr)
	{
		printf("%s %d\n", curr->value, curr->type);
		curr = curr->next;
	}
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
