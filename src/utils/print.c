/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:04:38 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/19 15:19:43 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_preset_error(int mode)
{
	char *message;

	if (mode == 0)
	{
		message = "minishell: syntax error near unexpected token `|'\n";
		write(2, message, ft_strlen(message));
		return ;
	}
	else if (mode == 1)
	{
		message = "minishell: syntax error near unexpected token `newline'\n";
		write(2, message, ft_strlen(message));
	}
	else
	{
		message = "No mode specified\n";
		write(2, message, ft_strlen(message));
		return ;
	}
}
