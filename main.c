/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/27 17:33:35 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	data->env = malloc(sizeof(char *) * (i + 1));
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
	t_token	*test;
	t_cmd	*test_cmd;
	int i;

	tokens = lexer(input);
	if (!tokens)
		return ;
	cmds = parser(tokens);
	if (!cmds)
	{
		free_token(&tokens);
		return ;
	}
	if (expander(cmds, data))
	{
		free_token(&tokens);
		free_cmds(&cmds);
		return ;
	}
	// test =============================
	test = tokens;
	test_cmd = cmds;
		printf("------tokens test-----\n");
	while (test)
	{
		printf("token value : {%s} token type {%d}\n", test->value, test->type);
		test = test->next;
	}
	printf("------CMD test-----\n");
	while (test_cmd)
	{
		printf("cmd : {%s}\n", test_cmd->args[0]);
		i = 0;
		while (test_cmd->args[i])
		{
			printf("args : {%s}\n", test_cmd->args[i]);
			i++;
		}
		test_cmd = test_cmd->next;
	}
	printf("-------ENV TEST ------\n");
	i = 0;
	while (data->env[i])
	{
		printf("Env[%d] : {%s}\n", i, data->env[i]);
		i++;
	}
	// end test ==============================
	free_token(&tokens);
	free_cmds(&cmds);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_data	data;

	av = NULL;
	if (ac > 1)
	{
		printf("No args accepted, please use : ./minishell\n");
		return (0);
	}
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
