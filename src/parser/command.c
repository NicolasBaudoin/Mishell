/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:38:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/19 23:44:08 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_args(t_token *token)
{
	t_token	*curr;
	int		counter;

	curr = token;
	counter = 0;
	while (curr)
	{
		if (curr->type == WORD)
			counter ++;
		else
			break ;
		curr = curr->next;
	}
	return (counter);
}

t_cmd	*new_command(void)
{
	t_cmd	*t;

	t = malloc(sizeof(t_cmd));
	if (!t)
		return (NULL);
	t->args = NULL;
	t->redir = NULL;
	t->next = NULL;
	return (t);
}

t_cmd	*build_commands(t_token **token)
{
	t_cmd *cmd;

	cmd = new_command();
	while (*token && (*token)->type != PIPE)
	{
		if (is_token_word((*token)->type))
		{
			if (parse_args(token, cmd))
			{
				// free_cmd(cmd);
				return (NULL);
			}
		}
		if (is_token_redir((*token)->type))
		{
			if (parse_redirs(token, cmd))
			{
				// free_cmd(cmd);
				// free_redir()redir;
				return (NULL);
			}
		}
	}
	return (cmd);
}