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

#include "ft_argument.h"

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
			argument_new(aargs);
			generate_argument(&raw_arg, arg_end, aargs);
			argument_finish(aargs);
			if (aargs->err == 1)
			{
				return (-1);
			}
		}
		while (*raw_arg == ' ' && raw_arg != arg_end)
		{
			raw_arg++;
		}
	}
	return (1);
}

