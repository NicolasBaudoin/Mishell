/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:02 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 14:43:17 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	init_token_info(t_token_info *info, t_lexer *lexer)
{
	info->start = lexer->i;
	info->end = info->start + 1;
	info->type = 0;
}

static void	set_append(t_lexer *lexer, t_token_info *info)
{
	lexer->i++;
	info->type = APPEND;
	info->end = info->start + 2;
}

static void	set_heredoc(t_lexer *lexer, t_token_info *info)
{
	lexer->i++;
	info->type = HEREDOC;
	info->end = info->start + 2;
}

int	create_operator_token(t_lexer *lexer, t_token **tokens)
{
	char			c;
	t_token_info	info;

	init_token_info(&info, lexer);
	c = lexer->input[info.start];
	if (c == '|')
		info.type = PIPE;
	else if (is_append(lexer->input, info.start))
		set_append(lexer, &info);
	else if (is_heredoc(lexer->input, info.start))
		set_heredoc(lexer, &info);
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
