/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:49:11 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/22 14:50:29 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	parse_args(t_token **token, t_cmd *cmd, int *i)
{
	int	counter;

	if (!cmd->args)
		cmd->args = malloc(sizeof(char *) * (counter + 1));
	else
	 	ft_realloc(*cmd->args, *i + 1, *i + 2);
	if (!cmd->args)
		return (1);
	cmd->args[*i] = ft_strdup((*token)->value);
	if (!cmd->args[*i])
	{
		free_args(cmd->args);
		return (1);
	}
	*token = (*token)->next;
	(*i)++;
	cmd->args[*i] = NULL;
	return (0);
}
