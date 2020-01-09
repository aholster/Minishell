/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 07:15:45 by aholster       #+#    #+#                */
/*   Updated: 2020/01/09 15:31:05 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <stdio.h>

#include "libft/libft.h"
#include "minishell.h"

#include "env_internals/ft_env.h"

static int	initialize_env(char **envp, t_list **const restrict aenv_lst)
{
	char	*separator;

	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		separator = ft_strchr(*envp, '=');
		if (separator == NULL)
		{
			return (-1);
		}
		else
		{
			*separator = '\0';
		}
		if (env_add_kvp(*envp, separator + 1, aenv_lst) == -1)
		{
			return (-1);
		}
		envp++;
	}
	return (1);
}

int			main(int argc, char **argv, char **envp)
{
	t_env		true_env;
	int			status;

	(void)argc;
	(void)argv;
	ft_bzero(&true_env, sizeof(t_env));
	if (initialize_env(envp, &(true_env.env_list)) == -1)
	{
		ft_lstdel(&(true_env.env_list), &env_del_kvp);
		return (-1);
	}
	status = shell_loop(&true_env);
	ft_lstdel(&(true_env.env_list), &env_del_kvp);
	return (status);
}
