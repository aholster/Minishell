/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_retrieve_arguments.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 17:10:03 by aholster       #+#    #+#                */
/*   Updated: 2020/01/09 19:27:52 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "minishell.h"

#include "libft/libft.h"
#include "env_internals/ft_env.h"

static int	generate_arg(char const **const arg_raw,\
				char const *const arg_end,\
				t_arg_object *const restrict aargs)
{
	char	*new_arg;

	new_arg = aargs->arg_buf + aargs->tail;
	aargs->argv[aargs->argc] = new_arg;
	while (*arg_raw != arg_end)
	{
		if (**arg_raw == ' ')
		{
			break ;
		}
		*new_arg = **arg_raw;
		new_arg++;
		(*arg_raw)++;
	}
	*new_arg = '\0';
	aargs->tail = (new_arg - aargs->arg_buf) + 1;
	aargs->argc++;
	return (1);
}

static int	arg_lexer(char const *raw_arg,\
				char const *const arg_end,\
				t_env *const true_env,\
				t_arg_object *const restrict aargs)
{
	while (raw_arg != arg_end)
	{
		if (*raw_arg != ' ')
		{
			if (generate_arg(&raw_arg, arg_end, aargs) == -1)
			{
				return (-1);
			}
		}
		while (*raw_arg == ' ' && raw_arg != arg_end)
		{
			raw_arg++;
		}
	}
	(void)true_env;
	return (1);
}

int			retrieve_argument(t_env *const true_env,\
				t_arg_object *const restrict aargs)
{
	char	raw_arg[ARG_MAX + 2];
	ssize_t	raw_arg_len;

	raw_arg_len = read(0, raw_arg, sizeof(raw_arg));
	if (raw_arg_len < 0)
	{
		dprintf(2, "minishell: error retrieving arguments\n");
	}
	else if (raw_arg_len >= ARG_MAX)
	{
		dprintf(2, "minishell: arguments given too long\n");
	}
	else if (!(raw_arg_len == 1 && raw_arg[0] == '\n'))
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
		return (arg_lexer(raw_arg, raw_arg + raw_arg_len, true_env, aargs));
	}
	return (0);
}
