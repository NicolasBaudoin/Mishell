/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:02 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 14:25:46 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	create_operator_token(t_lexer *lexer, t_token **tokens)
{
	char	c;
	t_token_info info;

	info.start = lexer->i;
	info.end = info.start + 1;
	info.type = 0;
	c = lexer->input[info.start];
	if (c == '|')
		info.type = PIPE;
	else if (is_append(lexer->input, info.start))
	{
		lexer->i++;
		info.type = APPEND;
		info.end = info.start + 2;
	}
	else if (is_heredoc(lexer->input, info.start))
	{
		lexer->i++;
		info.type = HEREDOC;
		info.end = info.start + 2;
	}
	else if (c == '<')
		info.type = REDIR_IN;
	else if (c == '>')
		info.type = REDIR_OUT;
	else
		return (1);
	lexer->i++;
	if (create_token(tokens, lexer, info))
		return (1);
	return (0);
}
