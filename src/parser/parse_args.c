/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:49:11 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/22 12:51:22 by nbaudoin         ###   ########.fr       */
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

int	parse_args(t_token **token, t_cmd *cmd)
{
	int	counter;
	int	i;

	counter = count_args(*token);
	i = 0;
	cmd->args = malloc(sizeof(char *) * (counter + 1));
	if (!cmd->args)
		return (1);
	while (*token)
	{
		if ((*token)->type == WORD)
		{
			cmd->args[i] = ft_strdup((*token)->value);
			if (!cmd->args[i])
			{
				free_args(cmd->args);
				return (1);
			}
			*token = (*token)->next;
			i++;
		}
		else if (is_token_redir((*token)->type))
		{
			if (parse_redirs(token, cmd))
			{
				free_args(cmd->args);
				return (1);
			}
			*token = (*token)->next->next;
		}
		else
			break ;
	}
	cmd->args[i] = NULL;
	return (0);
}
