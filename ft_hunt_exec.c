/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hunt_exec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 09:11:01 by aholster       #+#    #+#                */
/*   Updated: 2020/02/18 12:05:03 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <unistd.h>

#include "libft/libft.h"

#include "minishell.h"

#include "env_internals/ft_env.h"

static int		find_command_path(char path[PATH_MAX],\
					t_env *const true_env,\
					char const *const name)
{
	t_env_kvp	*const	sources = env_search_key("PATH", true_env->env_list);
	char				*iter;
	int					sub_len;

	if (sources != NULL)
	{
		iter = sources->value;
		while (*iter != '\0')
		{
			if (*iter == ':')
				iter++;
			if (ft_strchr(iter, ':') != NULL)
				sub_len = ft_strchr(iter, ':') - iter;
			else
				sub_len = ft_strlen(iter);
			ft_snprintf(path, PATH_MAX, "%.*s/%s", sub_len, iter, name);
			if (access(path, F_OK) == 0)
			{
				return (0);
			}
			iter += sub_len;
		}
		ft_bzero(path, PATH_MAX);
	}
	return (-1);
}

static int		find_exec_path(char path[PATH_MAX],
					t_env *true_env,
					char const *const name)
{
	if (ft_strchr(name, '/') == NULL)
	{
		if (find_command_path(path, true_env, name) == -1)
		{
			ft_puterr("minishell: %s: command not found\n", name);
			return (-1);
		}
	}
	else
	{
		if (ft_strlen(name) >= PATH_MAX)
		{
			ft_puterr("minishell: %s: File name too long\n", name);
			return (-1);
		}
		if (access(name, F_OK) != 0)
		{
			ft_puterr("minishell: %s: No such file or directory\n", name);
			return (-1);
		}
		ft_memcpy(path, name, ft_strlen(name));
	}
	return (0);
}

static int		run_executable(char exec_path[PATH_MAX],\
					t_arg_object *const args)
{
	pid_t	child_pid;
	int		status;

	child_pid = fork();
	if (child_pid == -1)
	{
		return (-255);
	}
	if (child_pid == 0)
	{
		execve(exec_path, args->argv, args->envp);
		ft_puterr("minishell: cannot execute %s\n", exec_path);
		exit(-1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}
}

int				ft_hunt_exec(t_env *const true_env,\
					t_arg_object *const args)
{
	char		exec_path[PATH_MAX];
	struct stat	info;

	ft_bzero(exec_path, PATH_MAX);
	if (find_exec_path(exec_path, true_env, args->argv[0]) == -1)
	{
		return (-1);
	}
	if (access(exec_path, X_OK) != 0)
	{
		ft_puterr("minishell: %s: No permissions\n", args->argv[0]);
		return (-1);
	}
	if (stat(exec_path, &info) == -1 || !S_ISREG(info.st_mode))
	{
		ft_puterr("minishell: %s: non-regular filetype\n", args->argv[0]);
		return (-1);
	}
	return (run_executable(exec_path, args));
}
