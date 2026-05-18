/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 10:39:50 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

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
		printf("value = [%s], type = %d\n", curr->value, curr->type);
		curr = curr->next;
	}
	// parser(tokens)
	// execution(tokens);
	free_token(&tokens);
}

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("Mishell> ");
		if (input == NULL)
		{
			rl_clear_history();
			printf("\nExiting...\n");
			return (1);
		}
		add_history(input);
		mishell_is_working(input);
		free(input);
	}
	return (0);
}
