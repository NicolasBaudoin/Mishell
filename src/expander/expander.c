/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:49:01 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/25 16:33:46 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// can refacto in is_regular_char() for the forest of if

static int	is_regular_char(t_state *status, char c)
{
	if (*status == DEFAULT && c == '\'')
		*status = SINGLE_QUOTE;
	else if (*status == DEFAULT && c == '"')
		*status = DOUBLE_QUOTE;
	else if (*status == SINGLE_QUOTE && c == '\'')
		*status = DEFAULT;
	else if (*status == DOUBLE_QUOTE && c == '"')
		*status = DEFAULT;
	else
		return (1);
	return (0);
}
int	count_no_quotes(char *str)
{
	int		i;
	int		counter;
	t_state	status;

	i = 0;
	counter = 0;
	status = DEFAULT;
	while (str[i])
	{
		if (is_regular_char(&status, str[i]))
			counter++;
		i++;
	}
	return (counter);
}

static char	*init_var_and_alloc(int *i, int *j, t_state *status, char *str)
{
	char	*alloc;

	alloc = malloc(sizeof(char) * (count_no_quotes(str) + 1));
	if (!alloc)
		return (NULL);
	*i = 0;
	*j = 0;
	*status = DEFAULT;
	return (alloc);
}

char	*remove_quotes(char *str)
{
	char	*no_quotes;
	int		i;
	int		j;
	t_state	status;

	no_quotes = init_var_and_alloc(&i, &j, &status, str);
	if (!no_quotes)
		return (NULL);
	while (str[i])
	{
		if (is_regular_char(&status, str[i]))
			no_quotes[j++] = str[i];
		i++;
	}
	no_quotes[j] = '\0';
	return (no_quotes);
}

int		expand_args(t_cmd *cmd)
{
	t_cmd	*curr;
	int		i;
	char	*new_arg;

	curr = cmd;

	while (curr)
	{
		i = 0;
		while (curr->args && curr->args[i])
		{
			new_arg = remove_quotes(curr->args[i]);
			if (!new_arg)
				return (1);
			free(curr->args[i]);
			curr->args[i] = new_arg;
			i++;
		}
		curr = curr->next;
	}
	return (0);
}
void	expander(t_cmd *cmd)
{
	// expand quotes
	expand_args(cmd);
	// expand VAR
	// expand $?
	// fix the pipeline
}
