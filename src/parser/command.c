/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:38:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/23 22:34:56 by nbaudoin         ###   ########.fr       */
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
		else if (is_token_redir(curr->type))
		{
			curr = curr->next->next;
			continue ;
		}
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

static int	build_command_instance(t_token **token, t_cmd **cmd)
{
	int	i;

	i = 0;
	while (*token)
	{
		if (is_token_word((*token)->type))
		{
			(*cmd)->args[i++] = ft_strdup((*token)->value);
			*token = (*token)->next;
		}
		else if (is_token_redir((*token)->type))
		{
			if (parse_redirs(token, *cmd))
			{
				(*cmd)->args[i] = NULL;
				free_cmds(cmd);
				return (1);
			}
		}
		else
			break ;
	}
	(*cmd)->args[i] = NULL;
	return (0);
}

t_cmd	*build_commands(t_token **token)
{
	t_cmd	*cmd;
	int		args_numbers;

	cmd = new_command();
	if (!cmd)
		return (NULL);
	args_numbers = count_args(*token);
	if (parse_args(&cmd, args_numbers))
	{
		free(cmd);
		return (NULL);
	}
	if (build_command_instance(token, &cmd))
		return (NULL);
	return (cmd);
}
