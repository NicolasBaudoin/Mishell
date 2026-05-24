/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:49:01 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/24 15:08:27 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_no_quotes(char *str)
{
	int	i;
	int	counter;
	t_state	status;

	i = 0;
	counter = 0;
	status = DEFAULT;
	while (str[i])
	{
		if (status == DEFAULT && str[i] == '\'')
			status = SINGLE_QUOTE;
		else if (status == DEFAULT && str[i] == '"')
			status = DOUBLE_QUOTE;
		else if (status == SINGLE_QUOTE && str[i] == '\'')
			status = DEFAULT;
		else if (status == DOUBLE_QUOTE && str[i] == '"')
			status = DEFAULT;
		else
			counter++;
		i++;
	}
	printf("counter : {%d}\n", counter);
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

char *remove_quotes(char *str)
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
		if (status == DEFAULT && str[i] == '\'')
			status = SINGLE_QUOTE;
		else if (status == DEFAULT && str[i] == '"')
			status = DOUBLE_QUOTE;
		else if (status == SINGLE_QUOTE && str[i] == '\'')
			status = DEFAULT;
		else if (status == DOUBLE_QUOTE && str[i] == '"')
			status = DEFAULT;
		else
			no_quotes[j++] = str[i];
		i++;
	}
	no_quotes[j] = '\0';
	return no_quotes;
}
