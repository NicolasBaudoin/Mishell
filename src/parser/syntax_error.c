/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:57:34 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/19 15:16:29 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_first_last_pipe(t_token *token)
{
	t_token	*curr;

	curr = token;
	if (is_pipe(curr->type))
	{
		print_preset_error(0);
		return (1);
	}
	while (curr->next)
		curr = curr->next;
	if (is_pipe(curr->type))
	{
		print_preset_error(0);
		return (1);
	}
	return (0);
}

int	check_consecutive_operator(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr )
	{
		if (curr->next && is_operator_type(curr->type) && is_operator_type(curr->next->type))
		{
			print_preset_error(0);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

int	check_redir_word(t_token *token)
{
	t_token *curr;

	curr = token;
	while (curr)
	{
		if (curr->next && is_operator_type(curr->type) && curr->type != PIPE && !is_token_word(curr->next->type))
		{
			print_preset_error(1);
			return (1);
		}
		if (!curr->next && is_operator_type(curr->type) && curr->type != PIPE)
		{
			print_preset_error(1);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}
