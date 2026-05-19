/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:25:41 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/19 23:54:26 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redir	*new_redir(void)
{
	t_redir	*t;

	t = malloc(sizeof(t_redir));
	if (!t)
		return (NULL);
	t->file = NULL;
	t->type = 0;
	t->next = NULL;
	return (t);
}

void	add_back_redir(t_redir **lst, t_redir *node_to_add)
{
	t_redir	*tmp;

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

int	parse_redirs(t_token **token, t_cmd *cmd)
{
	t_redir *redir;

	redir = new_redir();
	if (!redir)
		return (1);
	redir->type = (*token)->type;
	*token = (*token)->next;
	redir->file = ft_strdup((*token)->value);
	if (!redir->file)
		return (1);
	*token = (*token)->next;
	add_back_redir(&cmd->redir, redir);
	return (0);
}