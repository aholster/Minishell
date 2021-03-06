/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_setenv.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 23:09:22 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/28 19:11:24 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include "../env_internals/ft_env.h"

#include "../minishell.h"

static char	*find_key_limit(char *iter)
{
	if (!(ft_isdigit(iter[0]) || iter[0] == '='))
	{
		while (*iter && is_envkey_char(*iter))
		{
			iter++;
		}
		if (*iter == '=')
		{
			return (iter);
		}
	}
	return (NULL);
}

static int	split_kvp_str(char *const str, t_env *const true_env)
{
	char	*sep;

	sep = find_key_limit(str);
	if (sep == NULL)
	{
		ft_puterr("minishell: setenv: badly formatted key %s\n", str);
		return (-1);
	}
	else
	{
		*sep = '\0';
		if (set_env(str, sep + 1, &(true_env->env_list)) == -1)
		{
			ft_puterr("minishell: setenv: failed to edit env\n");
			return (-1);
		}
	}
	return (1);
}

int			builtin_setenv(int argc, char **argv, t_env *const true_env)
{
	int		index;
	int		err;

	if (argc == 1)
	{
		ft_puterr("Usage: setenv <key>=<value> ...\n");
		return (1);
	}
	err = 0;
	index = 1;
	while (index < argc)
	{
		if (split_kvp_str(argv[index], true_env) == -1)
		{
			err = 1;
		}
		index++;
	}
	return (err);
}
