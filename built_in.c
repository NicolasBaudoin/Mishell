/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildt_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 02:45:56 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/26 02:47:26 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(int ac)
{
	char *pwd;

	if (ac != 1)
	{
		printf("Too much arguments\n");
		return ;
	}
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	g_status = 0;
}
