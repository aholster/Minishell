/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 07:15:45 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/18 10:23:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <unistd.h>

#include "libft/libft.h"
#include "minishell.h"

#include "env_internals/ft_env.h"

static int	initialize_basic_env(t_list **const aenv_lst)
{
	char	cur_path[PATH_MAX + 1];

	if (getcwd(cur_path, PATH_MAX) == NULL)
	{
		ft_puterr("Minishell: could not retrieve path\n");
	}
	else if (set_env("PWD", cur_path, aenv_lst) == -1)
	{
		return (-1);
	}
	if (set_env("TERM_PROGRAM", "minishell", aenv_lst) == -1)
	{
		return (-1);
	}
	return (1);
}

static int	initialize_env(char **envp, t_list **const aenv_lst)
{
	char	*separator;

	while (*envp != NULL)
	{
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
	return (initialize_basic_env(aenv_lst));
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
		ft_puterr("Minishell: error mallocing env\n");
		return (-1);
	}
	status = shell_loop(&true_env);
	ft_lstdel(&(true_env.env_list), &env_del_kvp);
	return (status);
}
