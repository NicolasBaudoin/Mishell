/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:38:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/21 14:26:47 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_cmds(t_cmd **cmd)
{
	t_cmd *curr;
	t_cmd *tmp;


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

void	add_back_cmd(t_cmd **lst, t_cmd *node_to_add)
{
	t_cmd	*tmp;

	if (!*lst)
	{
		*lst = node_to_add;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node_to_add;
}

t_cmd	*build_commands(t_token **token)
{
	t_cmd *cmd;

	cmd = new_command();
	while (*token && (*token)->type != PIPE)
	{
		printf("build commands : token: %s type: %d\n", (*token)->value, (*token)->type); // debug
		if (is_token_word((*token)->type))
		{
			if (parse_args(token, cmd))
			{
				// free_cmd(cmd);
				return (NULL);
			}
		}
		else if (*token && is_token_redir((*token)->type))
		{
			if (parse_redirs(token, cmd))
			{
				// free_cmd(cmd);
				// free_redir()redir;
				return (NULL);
			}
		}
		else
			break ;
	}
	return (cmd);
}
