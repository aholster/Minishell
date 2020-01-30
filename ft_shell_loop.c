/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shell_loop.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 08:27:12 by aholster       #+#    #+#                */
/*   Updated: 2020/01/30 21:24:20 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft/libft.h"

#include "minishell.h"

#include "env_internals/ft_env.h"
#include "builtins/builtin.h"

static const t_builtin_tbl	g_builtin_tbl[BUILTIN_COUNT] = {
	{"exit", &builtin_exit},
	{"cd", &builtin_cd},
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
			else
			{
				true_env->last_ret = ft_hunt_exec(true_env, &args);
			}
		}
	}
	return (1);
}
