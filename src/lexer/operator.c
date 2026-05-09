/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:02 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/09 11:12:57 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_operator_token(char *input, int start, int end, t_token **tokens)
{
	int		type;
	char	c;

	c = input[start];

	if (c  == '|')
		type = PIPE;
	else if (is_append(input, start))
	{
		type = APPEND;
		end = start + 1;
	}
	else if (is_heredoc(input, start))
	{
		type = HEREDOC;
		end = start + 1;
	}
	else if (c == '<')
		type = REDIR_IN;
	else if (c == '>')
		type = REDIR_OUT;
	add_back_token(tokens, new_token(ft_strndup(input, start, end), type));
}
