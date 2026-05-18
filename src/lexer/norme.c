/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:43:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 12:19:14 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	handle_default_state(t_lexer *lexer, char c)
{
	if (is_space(c) || is_operator(c))
		return (2);
	if (c == '\'')
	{
		lexer->state = SINGLE_QUOTE;
		lexer->i++;
		return (1);
	}
	if (c == '"')
	{
		lexer->state = DOUBLE_QUOTE;
		lexer->i++;
		return (1);
	}
	return (0);
}

int	handle_quote_state(t_lexer *lexer, char c)
{
	if (lexer->state == SINGLE_QUOTE && c == '\'')
	{
		lexer->state = DEFAULT;
		lexer->i++;
		return (1);
	}
	if (lexer->state == DOUBLE_QUOTE && c == '"')
	{
		lexer->state = DEFAULT;
		lexer->i++;
		return (1);
	}
	return (0);
}

int	handle_quote_unclosed(t_lexer *lexer)
{
	if (lexer->state != DEFAULT)
	{
		write(2, "minishell: unexpected quote unclosed\n",
			ft_strlen("minishell: unexpected quote unclosed\n"));
		return (1);
	}
	return (0);
}

int	read_word_loop(t_lexer *lexer, char c)
{
	int	ret;

	if (lexer->state == DEFAULT)
	{
		ret = handle_default_state(lexer, c);
		if (ret != 0)
			return (ret);
	}
	else
	{
		ret = handle_quote_state(lexer, c);
		if (ret == 1)
			return (1);
	}
	lexer->i++;
	return (0);
}
