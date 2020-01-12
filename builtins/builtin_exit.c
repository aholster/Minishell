/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_exit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 10:21:28 by aholster       #+#    #+#                */
/*   Updated: 2020/01/11 23:48:38 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../libft/libft.h"

#include "../env_internals/ft_env.h"

#include "../minishell.h"

int	builtin_exit(int argc, char **argv, t_env *const true_env)
{
	int		num;

	if (argc <= 2)
	{
		if (argc == 2)
		{
			num = ft_atoi(argv[1]);
		}
		else
		{
			num = true_env->last_ret;
		}
		ft_lstdel(&(true_env->env_list), &env_del_kvp);
		exit(num);
	}
	else
	{
		ft_puterr("minishell: exit: too many arguments\n");
		return (1);
	}
}
