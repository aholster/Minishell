/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hunt_exec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 09:11:01 by aholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:54:24 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdio.h>

#include "libft/libft.h"

#include "minishell.h"

#include "env_internals/ft_env.h"

void				find_command(char path[PATH_MAX],\
					t_env *const true_env,\
					t_arg_object *const args)
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
			snprintf(path, PATH_MAX, "%.*s/%s", sub_len, iter, args->argv[0]);
			if (access(path, X_OK) == 0)
			{
				return ;
			}
			iter += sub_len;
		}
		ft_bzero(path, PATH_MAX);
	}
	ft_puterr("minishell: %s: command not found\n", args->argv[0]);
}

static int		run_executable(char exec_path[PATH_MAX],\
					t_arg_object *const args)
{
	pid_t	child_pid;
	int		ret_code;

	child_pid = fork();
	if (child_pid == -1)
	{
		return (-255);
	}
	if (child_pid == 0)
	{
		printf("child initiating program %s...\n", exec_path);
		ret_code = execve(exec_path, args->argv, args->envp);
		printf("execve returned %d\n", ret_code);
		perror("minishell: execve:");
		exit(ret_code);
	}
	else
	{
		waitpid(child_pid, &ret_code, 0);
		if (WIFEXITED(ret_code) != 0)
			return (WEXITSTATUS(ret_code));
		else
			return (999);
	}
}

int				ft_hunt_exec(t_env *const true_env,\
					t_arg_object *const args)
{
	char	exec_path[PATH_MAX];

	ft_bzero(exec_path, PATH_MAX);
	if (ft_strchr(args->argv[0], '/') == NULL)
	{
		find_command(exec_path, true_env, args);
	}
	else
	{
		if (ft_strlen(args->argv[0]) >= PATH_MAX)
		{
			ft_puterr("minishell: %s: File name too long\n", args->argv[0]);
			return (127);
		}
		if (access(args->argv[0], X_OK) == 0)
		{
			snprintf(exec_path, PATH_MAX, "%s", args->argv[0]);
		}
		else
		{
			ft_puterr("minishell: %s: No such file or directory\n", args->argv[0]);
			return (127);
		}
	}
	if (access(exec_path, X_OK) == 0)
	{
		true_env->last_ret = run_executable(exec_path, args);
		return (1);
	}
	return (0);
}
