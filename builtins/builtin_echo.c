/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 10:21:31 by aholster       #+#    #+#                */
/*   Updated: 2020/02/05 17:38:37 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../env_internals/ft_env.h"

#include "../libft/libft.h"

#include "../minishell.h"

int		builtin_echo(int argc, char **argv, t_env *const true_env)
{
	int	index;

	(void)true_env;
	index = 1;
	while (index < argc)
	{
		if (write(1, argv[index], ft_strlen(argv[index])) == -1)
		{
			return (1);
		}
		if (index + 1 < argc && write(1, " ", 1) == -1)
		{
			return (1);
		}
		index++;
	}
	return (write(1, "\n", 1) == -1);
}
