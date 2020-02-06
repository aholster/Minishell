/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 20:45:12 by aholster       #+#    #+#                */
/*   Updated: 2020/02/05 17:38:33 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../env_internals/ft_env.h"

#include "../libft/libft.h"

#include "../minishell.h"

int			builtin_env(int argc, char **argv, t_env *const true_env)
{
	t_list		*iterator;
	t_env_kvp	*cur_kvp;

	(void)argc;
	(void)argv;
	iterator = true_env->env_list;
	while (iterator != NULL)
	{
		cur_kvp = iterator->content;
		if (printf("%s=%s\n", cur_kvp->key, cur_kvp->value) == -1)
		{
			return (-1);
		}
		iterator = iterator->next;
	}
	return (1);
}
