/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_retrieve_arguments.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 17:10:03 by aholster       #+#    #+#                */
/*   Updated: 2020/02/13 19:51:50 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "../libft/libft.h"
#include "../env_internals/ft_env.h"

#include "ft_argument.h"

/*
**	generate_arg currently does not deal with the size_limit of aargs->arg_buf
*/

static int	enter_env(t_env *const true_env,\
				t_arg_object *const aargs)
{
	t_list const	*iterator;
	t_env_kvp const	*kvp;
	int				arg_offset;

	aargs->envp = aargs->argv + aargs->argc + 1;
	aargs->argc++;
	arg_offset = 1;
	iterator = true_env->env_list;
	while (iterator != NULL)
	{
		kvp = iterator->content;
		argument_new(aargs);
		argument_expand(aargs, kvp->key, kvp->klen);
		argument_expand(aargs, "=", 1);
		argument_expand(aargs, kvp->value, kvp->vlen);
		argument_finish(aargs);
		if (aargs->err == 1)
		{
			return (-1);
		}
		arg_offset++;
		iterator = iterator->next;
	}
	aargs->argc -= arg_offset;
	return (1);
}

static int	arg_lexer(char raw_arg[ARG_MAX + 2],
				ssize_t raw_arg_len,
				t_env *const true_env,
				t_arg_object *const aargs)
{
	if (raw_arg_len == 0)
	{
		ft_memcpy(raw_arg, "exit", 5);
		raw_arg_len = 4;
	}
	else if (raw_arg[raw_arg_len - 1] == '\n')
	{
		raw_arg_len--;
	}
	if (generate_all_arguments(raw_arg, raw_arg + raw_arg_len, aargs) == -1)
	{
		return (-1);
	}
	else if (enter_env(true_env, aargs) == -1)
	{
		return (-1);
	}
	return (0);
}

int			retrieve_argument(t_env *const true_env,
				t_arg_object *const aargs)
{
	char	raw_arg[ARG_MAX + 2];
	ssize_t	raw_arg_len;

	raw_arg_len = read(0, raw_arg, sizeof(raw_arg));
	if (raw_arg_len < 0)
	{
		ft_puterr("minishell: error reading arguments\n");
		true_env->last_ret = -1;
	}
	else if (raw_arg_len >= ARG_MAX)
	{
		ft_puterr("minishell: arguments given too long\n");
		true_env->last_ret = -1;
	}
	else if (raw_arg_len == 1 && raw_arg[0] == '\n')
	{
		return (1);
	}
	return (arg_lexer(raw_arg, raw_arg_len, true_env, aargs));
}
