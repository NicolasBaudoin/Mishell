/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:22:23 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/11 20:32:59 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void	read_word(t_token **tokens, t_lexer *lexer)
{
	int	start;
	char	c;

	start = lexer->i;
	while (lexer->input[lexer->i])
	{
		c = lexer->input[lexer->i];
		if (lexer->state == DEFAULT)
		{
			if (is_space(c) || is_operator(c))
				break ;

			if (c == '\'')
			{
				lexer->state = SINGLE_QUOTE;
				lexer->i++;
				continue ;
			}

			if (c == '"')
			{
				lexer->state = DOUBLE_QUOTE;
				lexer->i++;
				continue ;
			}
		}
		else if (lexer->state == SINGLE_QUOTE && c == '\'')
		{
				lexer->state = DEFAULT;
				lexer->i++;
				continue ;
		}
		else if (lexer->state == DOUBLE_QUOTE && c == '"')
		{
				lexer->state = DEFAULT;
				lexer->i++;
				continue ;
		}
		lexer->i++;
	}
	add_back_token(tokens, new_token(ft_strndup(lexer->input, start, lexer->i), WORD));
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	t_lexer	lexer;


	tokens = NULL;
	lexer.state = DEFAULT;
	lexer.input = input;
	lexer.i = 0;
	while (lexer.input[lexer.i])
	{
		while (is_space(lexer.input[lexer.i]))
			lexer.i++;
		if (!lexer.input[lexer.i])
			break ;

		if (is_operator(lexer.input[lexer.i]))
			create_operator_token(&lexer, &tokens);
		else
			read_word(&tokens, &lexer);
	}
	return (tokens);
}
