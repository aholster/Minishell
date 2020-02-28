/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 17:19:44 by aholster       #+#    #+#                */
/*   Updated: 2020/02/28 19:07:16 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>

#include "../env_internals/ft_env.h"

#include "../libft/libft.h"

#include "../minishell.h"

static int	retrieve_val(char apath[PATH_MAX],
				char const *const key,
				t_env *const true_env)
{
	t_env_kvp	*kvp;

	kvp = env_search_key(key, true_env->env_list);
	if (kvp == NULL)
	{
		ft_puterr("minishell: cd: %s is not set\n", key);
		return (-1);
	}
	if (kvp->vlen >= PATH_MAX)
	{
		ft_puterr("minishell: cd: %s File name too long\n", kvp->value);
		return (-1);
	}
	ft_memcpy(apath, kvp->value, kvp->vlen + 1);
	return (0);
}

static int	generate_path(char apath[PATH_MAX],
				char const *const arg,
				t_env *const true_env)
{
	size_t		len;

	if (arg == NULL)
	{
		return (retrieve_val(apath, "HOME", true_env));
	}
	else if (ft_strequ(arg, "-"))
	{
		return (retrieve_val(apath, "OLDPWD", true_env));
	}
	else
	{
		len = ft_strlen(arg);
		if (len >= PATH_MAX)
		{
			ft_puterr("minishell: cd: %s File name too long\n", arg);
			return (-1);
		}
		ft_memcpy(apath, arg, len + 1);
	}
	return (0);
}

static int	switch_directory(char path[PATH_MAX], t_env *const true_env)
{
	char	old_path[PATH_MAX + 1];

	if (access(path, F_OK) == -1)
	{
		ft_puterr("minishell: cd: %s No such file of directory\n", path);
		return (-1);
	}
	if (getcwd(old_path, sizeof(old_path)) != NULL)
		if (set_env("OLDPWD", old_path, &(true_env->env_list)) == -1)
		{
			ft_puterr("minishell: cd: error setting env\n");
			return (-1);
		}
	if (chdir(path) != 0)
	{
		ft_puterr("minishell: cd: %s Could not change directory\n", path);
		return (-1);
	}
	if (getcwd(path, PATH_MAX) != NULL)
		if (set_env("PWD", path, &(true_env->env_list)) == -1)
		{
			ft_puterr("minishell: cd: error setting env\n");
			return (-1);
		}
	return (0);
}

int			builtin_cd(int argc, char **argv, t_env *const true_env)
{
	char	path[PATH_MAX + 1];

	if (argc > 2)
	{
		ft_puterr("minishell: cd: too many arguments\n");
		return (-1);
	}
	if (generate_path(path, argv[1], true_env) != 0)
	{
		return (-1);
	}
	return (switch_directory(path, true_env));
}
