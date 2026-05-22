/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:49:11 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/22 15:36:10 by nbaudoin         ###   ########.fr       */
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
	if (!cmd->args)
		cmd->args = ft_calloc( 1,sizeof(char *));
	else
	 	cmd->args = ft_realloc_args(cmd->args);
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
	free(str);
	return (0);
}
