/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:02 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/11 10:46:08 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_operator_token(t_lexer *lexer, int start, int end, t_token **tokens)
{
	int		type;
	char	c;
	char	*input;

	input = lexer->input;
	c = input[start];
	type = 0;

	if (c  == '|')
		type = PIPE;
	else if (is_append(input, start))
	{
		lexer->i++;
		type = APPEND;
		end = start + 2;
	}
	else if (is_heredoc(input, start))
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
	// create token()
	add_back_token(tokens, new_token(ft_strndup(input, start, end), type));
}
