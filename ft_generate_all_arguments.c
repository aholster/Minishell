/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_generate_all_arguments.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 23:38:56 by aholster       #+#    #+#                */
/*   Updated: 2020/02/03 20:03:19 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "libft/libft.h"
#include "env_internals/ft_env.h"

static int	argument_new(t_arg_object *const aargs)
{
	if ((size_t)aargs->argc + 1 >= sizeof(aargs->argv) / sizeof(char *))
	{
		return (-1);
	}
	aargs->argv[aargs->argc] = aargs->arg_buf + aargs->tail;
	aargs->argc++;
	return (0);
}

// static int	argument_expand(t_arg_object *const aargs,
// 				char const *str,
// 				const size_t len)
// {
// 	if (sizeof(aargs->arg_buf) < aargs->tail + len + 2)
// 	{
// 		return (-1);
// 	}
// 	ft_memcpy(aargs->argv + aargs->tail, str, len);
// 	aargs->tail += len;
// 	return (0);
// }

static void	argument_finish(t_arg_object *const aargs)
{
	aargs->arg_buf[aargs->tail] = '\0';
	aargs->tail += 2;
}

static int	generate_argument(char const **const raw_arg,
				char const *const arg_end,
				t_arg_object *const aargs)
{
	char	*new_arg;

	new_arg = aargs->argv[aargs->argc - 1];
	// new_arg = aargs->arg_buf + aargs->tail;
	// aargs->argv[aargs->argc] = new_arg;
	while (*raw_arg != arg_end)
	{
		if (**raw_arg == ' ')
		{
			break ;
		}
		*new_arg = **raw_arg;
		new_arg++;
		(*raw_arg)++;
	}
	// *new_arg = '\0';
	// aargs->tail = (new_arg - aargs->arg_buf) + 1;
	aargs->tail = (new_arg - aargs->arg_buf);
	// aargs->argc++;
	return (1);
}

int			generate_all_arguments(char const *raw_arg,
				char const *const arg_end,
				t_arg_object *const aargs)
{
	while (raw_arg != arg_end)
	{
		if (*raw_arg != ' ')
		{
			if (argument_new(aargs) == -1)
			{
				return (-1);
			}
			if (generate_argument(&raw_arg, arg_end, aargs) == -1)
			{
				return (-1);
			}
			argument_finish(aargs);
		}
		while (*raw_arg == ' ' && raw_arg != arg_end)
		{
			raw_arg++;
		}
	}
	return (1);
}

