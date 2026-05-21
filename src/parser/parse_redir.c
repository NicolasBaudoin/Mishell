/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:25:41 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/21 14:49:36 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_redir(t_redir **redir)
{
	t_redir *curr;
	t_redir *tmp;

	curr = *redir;
	while (curr)
	{
		tmp = curr->next;
		free(curr->file);
		free(curr);
		curr = tmp;
	}
	*redir = NULL;
}

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

	printf("parse_redirs: token=%s type=%d\n", (*token)->value, (*token)->type);
	redir = new_redir();
	if (!redir)
		return (1);
	redir->type = (*token)->type;
	*token = (*token)->next;
	printf("parse_redirs: file token=%s\n", (*token) ? (*token)->value : "NULL");
	redir->file = ft_strdup((*token)->value);
	printf("CMD PTR = %p\n", cmd);
	printf("REDIR PTR = %p\n", cmd->redir);
	if (!redir->file)
	{
		free(redir);
		return (1);
	}
	*token = (*token)->next;
	add_back_redir(&cmd->redir, redir);
	return (0);
}
