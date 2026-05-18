/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:22:23 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 12:04:52 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


int	read_word(t_token **tokens, t_lexer *lexer)
{
	int	start;
	int	ret;

	start = lexer->i;
	while (lexer->input[lexer->i])
	{
		ret = read_word_loop(lexer, lexer->input[lexer->i]);
		if (ret == 2)
			break ;
		if (ret == 1)
			continue ;
	}
	if (handle_quote_unclosed(lexer))
		return (1);
	if (create_token(tokens, lexer, start, lexer->i, WORD))
		return (1);
	return (0);
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
		{
			if (create_operator_token(&lexer, &tokens))
			{
				free_token(&tokens);
				return (NULL);
			}
		}
		else if (read_word(&tokens, &lexer))
		{
			free_token(&tokens);
			tokens = NULL;
			return (NULL);
		}
	}
	return (tokens);
}
