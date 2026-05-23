/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:49:11 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/23 22:29:33 by nbaudoin         ###   ########.fr       */
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

void	free_cmds(t_cmd **cmd)
{
	t_cmd	*curr;
	t_cmd	*tmp;

	curr = *cmd;
	while (curr)
	{
		tmp = curr->next;
		free_args(curr->args);
		free_redir(&curr->redir);
		free(curr);
		curr = tmp;
	}
	*cmd = NULL;
}

int	parse_args(t_cmd **cmd, int args_nbr)
{
	(void)args_nbr;
	(*cmd)->args = malloc(sizeof(char *) * (args_nbr + 1));
	if (!(*cmd)->args)
		return (1);
	return (0);
}
