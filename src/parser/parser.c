/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:50:50 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/19 14:42:09 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parser(t_token *token)
{
	// check si premier et dernier token sont un operateur
	if (check_first_last_pipe(token))
		return (1);
	// check si 2 opérateurs se suivent
	if (check_consecutive_operator(token))
		return (1);
	// check si un REDIR est suivis d'un mot
	if (check_redir_word(token))
		return (1);
	return (0);
}