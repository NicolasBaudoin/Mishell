/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/26 15:27:26 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	g_status = 0;
// status pour les signaux des fonctions et arret programme
// execution(tokens);

void	init_env_and_data(t_data *data, char **env)
{
	int i;

	i = 0;

	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * ( + 1));
	if (!data->env)
		return ;
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
		{
			while (--i >= 0)
				free(data->env[i]);
			free(data->env);
			data->env = NULL;
			return;
		}
		i++;
	}
	data->env[i] = NULL;
}

void	mishell_is_working(char *input, t_data *data)
{
	t_token	*tokens;
	t_cmd	*cmds;

	tokens = lexer(input);
	if (!tokens)
		return ;
	cmds = parser(tokens);
	if (!cmds)
	{
		free_token(&tokens);
		return ;
	}
	if (expand_args(cmds))
		return ;
	free_token(&tokens);
	free_cmds(&cmds);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_data	data;

	setup_signals();
	init_env_and_data(&data, env);
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
		mishell_is_working(input, &data);
		free(input);
	}
	return (0);
}
