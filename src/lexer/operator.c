/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:02 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/11 19:26:46 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_operator_token(t_lexer *lexer, t_token **tokens)
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
	lexer->i++;
	add_back_token(tokens, new_token(ft_strndup(lexer->input, start, end), type));
}
