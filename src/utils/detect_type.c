/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:30:40 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/22 14:37:37 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_word(char c)
{
	int	ret;

	ret = (!is_space(c) && !is_operator(c));
	return (ret);
}
int	is_operator_type(t_token_type type)
{
	return ((type == APPEND || type == HEREDOC || type == PIPE || type == REDIR_IN || type == REDIR_OUT));
}

int	is_token_word(t_token_type type)
{

	if (!is_operator_type(type))
		return (1);

	return (0);
}

int	is_pipe(t_token_type type)
{
	if (type == PIPE)
		return (1);
	return (0);
}



int	is_token_redir(t_token_type type)
{
	return (type == APPEND || type == HEREDOC || type == REDIR_IN || type == REDIR_OUT);
}
