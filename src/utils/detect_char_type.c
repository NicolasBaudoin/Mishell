/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_char_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:34:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/08 18:05:55 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_operator(char c)
{
	int	ret;

	ret = (c == '|' || c == '<' || c == '>');
	return (ret);
}

int	is_space(char c)
{
	int	ret;

	ret = (c == ' ' || c == '\t' || c == '\n');
	return (ret);
}

int	is_quote(char c)
{
	int	ret;

	ret = (c == '"' || c == '\'');
	return (ret);
}
