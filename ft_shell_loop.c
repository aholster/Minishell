/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shell_loop.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 08:27:12 by aholster       #+#    #+#                */
/*   Updated: 2020/01/12 03:12:56 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft/libft.h"

#include "minishell.h"

#include "env_internals/ft_env.h"
#include "builtins/builtin.h"

static const t_builtin_tbl	g_builtin_tbl[BUILTIN_COUNT] = {
	{"exit", &builtin_exit},
	// {"cd", &builtin_cd},
	{"cd", &builtin_exit},
	{"env", &builtin_env},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"echo", &builtin_echo},
};

static int			builtin_go(t_env *const true_env,\
						t_arg_object *const restrict aargs)
{
	size_t				index;
	const char *const	name = aargs->argv[0];
	t_builtin			builtin;

	index = 0;
	while (index < BUILTIN_COUNT)
	{
		if (ft_strequ(name, g_builtin_tbl[index].name) == 1)
		{
			builtin = g_builtin_tbl[index].func;
			true_env->last_ret = builtin(aargs->argc, aargs->argv, true_env);
			return (1);
		}
		index++;
	}
	return (0);
}

static int			hunt_exec(t_env *const true_env, t_arg_object *args)
{
	t_env_kvp	*const	path = env_search_key("PATH", true_env->env_list);
	char				*iter;
	char				*seq_end;

	if (path != NULL)
	{
		iter = path->value;
		while (1)
		{
			seq_end = ft_strchr(iter, ':');
			if (seq_end == NULL)
			{
				printf("%s/%s\n", iter, args->argv[0]);
				break ;
			}
			else
			{
				printf("%.*s/%s\n", (int)(seq_end - iter), iter, args->argv[0]);
				iter = seq_end + 1;
			}
		}
	}
	return (0);
}

int					shell_loop(t_env *const true_env)
{
	t_arg_object	args;

	while (1)
	{
		ft_bzero(&args, sizeof(t_arg_object));
		dprintf(1, "%s ", PROMPT);
		if (retrieve_argument(true_env, &args) != 0)
		{
			if (builtin_go(true_env, &args) == 1)
			{
				continue ;
			}
			else if (hunt_exec(true_env, &args) != 1)
			{
				continue ;
			}
			else
			{
				ft_puterr("minishell: unknown command: %s\n", args.argv[0]);
				true_env->last_ret = 127;
			}
		}
	}
	return (1);
}
