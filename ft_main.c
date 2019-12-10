/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 07:15:45 by aholster       #+#    #+#                */
/*   Updated: 2019/12/10 15:09:14 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <stdio.h>
#include <unistd.h>

#include "minishell.h"

static int	iter_argos(void)
{
	char	argu_space[ARG_MAX + 2];
	ssize_t	arg_len;

	while (1)
	{
		dprintf(1, "%s ", PROMPT);
		arg_len = read(1, argu_space, ARG_MAX + 2);
		if (arg_len == -1)
		{
			return (-1);
		}
		if (arg_len >= ARG_MAX)
		{
			dprintf(2, "minishell: Argument list too long");
		}
		else
		{
			write(1, argu_space, arg_len);
		}
	}
	return (1);
}

int			main(int argc, char **argv, char **envp)
{
	t_env_kvp	*true_env;

	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		envp += 1;
	}
	iter_argos();
	(void)argc;
	(void)argv;
	return (1);
}
