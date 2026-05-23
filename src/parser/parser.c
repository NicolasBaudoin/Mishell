/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:50:50 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/23 21:40:03 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*parser(t_token *token)
{
	t_cmd	*cmd;
	t_cmd	*cmd_lst;

	cmd_lst = NULL;
	if (syntax_error(token))
		return (NULL);
	while (token)
	{
		cmd = build_commands(&token);
		if (!cmd)
		{
			free_cmds(&cmd_lst);
			return (NULL);
		}
		add_back_cmd(&cmd_lst, cmd);
		if (token && token->type == PIPE)
			token = token->next;
	}
	return (cmd_lst);
}
