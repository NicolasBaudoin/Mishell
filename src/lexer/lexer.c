/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:22:23 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/11 12:33:16 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


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
		// handle mode
		if (is_operator(lexer.input[lexer.i]))
			create_operator_token(char *input, int start, int end, t_token **tokens)
	}
	return (tokens);
}



// t_token	*lexer(char *input)
// {
// 	t_token	*tokens;
// 	t_lexer	lexer;
// 	int		start;
// 	int		end;

// 	tokens = NULL;
// 	lexer.state = DEFAULT;
// 	lexer.input = input;
// 	lexer.i = 0;
// 	while (lexer.input[lexer.i])
// 	{
// 		while (is_space(lexer.input[lexer.i]) && lexer.state != DOUBLE_QUOTE)
// 			lexer.i++;
// 		start = lexer.i; //sauvegarde start
// 		if (is_operator(lexer.input[lexer.i]))
// 			create_operator_token(lexer.input, start, 1, &tokens);	// créer operateur token
// 		else
// 			add_back_token(&tokens, new_token(ft_strndup(input, start, end), WORD));
// 			// read word


// 		// debut d'un element, si on rencontre un operateur
// 		// separateur ou quote et qu'on est pas en mode double quote
// 		// alors on change de token
// 		// donc add_back(new_token)
// 		// sinon :
// 		lexer.i++;
// 	}
// 	return (tokens);
// }
