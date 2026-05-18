/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:19:01 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 12:15:31 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*new_token(char *value, t_token_type type)
{
	t_token	*t;

	t = malloc(sizeof(t_token));
	if (!t)
		return (NULL);
	if (!value)
	{
		free(t);
		return (NULL);
	}
	t->value = value;
	t->type = type;
	t->next = NULL;
	return (t);
}

void	add_back_token(t_token **lst, t_token *node_to_add)
{
	t_token	*tmp;

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

int	create_token(t_token **tokens, t_lexer *lexer, int start, int end,
	t_token_type type)
{
	t_token	*new;
	char	*value;

	value = ft_strndup(lexer->input, start, end);
	if (!value)
		return (1);
	new = new_token(value, type);
	if (!new)
	{
		free(value);
		return (1);
	}
	add_back_token(tokens, new);
	return (0);
}

void	free_token(t_token **tokens)
{
	t_token	*curr;
	t_token	*tmp;

	curr = *tokens;
	while (curr)
	{
		tmp = curr->next;
		free(curr->value);
		free(curr);
		curr = tmp;
	}
	*tokens = NULL;
}
