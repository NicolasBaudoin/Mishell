/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:02 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 10:58:33 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	create_operator_token(t_lexer *lexer, t_token **tokens)
{
	int		type;
	char	c;
	int		start;
	int		end;

	start = lexer->i;
	end = start + 1;
	type = 0;
	c = lexer->input[start];

	if (c  == '|')
		type = PIPE;
	else if (is_append(lexer->input, start))
	{
		lexer->i++;
		type = APPEND;
		end = start + 2;
	}
	else if (is_heredoc(lexer->input, start))
	{
		lexer->i++;
		type = HEREDOC;
		end = start + 2;
	}
	else if (c == '<')
		type = REDIR_IN;
	else if (c == '>')
		type = REDIR_OUT;
	else
		return (1);
	lexer->i++;
	if (create_token(tokens, lexer, start, end, type))
		return (1);
	return (0);
}
