/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arg_lexer.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 23:38:56 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/15 19:36:57 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "../env_internals/ft_env.h"

#include "../libft/libft.h"

#include <stdlib.h>
#include <stdbool.h>

static const char	g_delim_tbl[255] = {
	[' '] = 1,
	['\t'] = 1,
};

static int	expansion_env(char const **raw_arg,
				char const *const arg_end,
				t_env *const true_env,
				t_arg_object *const aargs)
{
	size_t			len;
	char			*key_copy;
	t_env_kvp const	*kvp;

	if (*raw_arg == arg_end - 1 || (*raw_arg + 1 < arg_end &&
		(ft_isdigit((*raw_arg)[1]) || is_envkey_char((*raw_arg)[1]) == 0)))
	{
		argument_expand(aargs, "$", 1);
		(*raw_arg)++;
		return (1);
	}
	(*raw_arg)++;
	len = 0;
	while (*raw_arg + len < arg_end && is_envkey_char((*raw_arg)[len]))
		len++;
	key_copy = ft_strsub(*raw_arg, 0, len);
	(*raw_arg) += len;
	if (key_copy == NULL)
		return (-1);
	kvp = env_search_key(key_copy, true_env->env_list);
	free(key_copy);
	if (kvp)
		argument_expand(aargs, kvp->value, kvp->vlen);
	return (1);
}

static void	expansion_home(char const **const raw_arg,
				t_env *const true_env,
				t_arg_object *const aargs)
{
	t_env_kvp const	*kvp;

	kvp = env_search_key("HOME", true_env->env_list);
	if (kvp == NULL)
	{
		argument_expand(aargs, "~", 1);
	}
	else
	{
		argument_expand(aargs, kvp->value, kvp->vlen);
	}
	(*raw_arg)++;
}

static int	generate_argument(char const **const raw_arg,
				char const *const arg_end,
				t_env *const true_env,
				t_arg_object *const aargs)
{
	size_t	mini_len;

	if (**raw_arg == '~' && (*raw_arg == arg_end - 1 || (*raw_arg)[1] == '/'))
		expansion_home(raw_arg, true_env, aargs);
	while (*raw_arg < arg_end && g_delim_tbl[(unsigned char)(**raw_arg)] == 0)
	{
		mini_len = 0;
		if (**raw_arg == '$')
		{
			if (expansion_env(raw_arg, arg_end, true_env, aargs) == -1)
				return (-1);
		}
		else
		{
			while (*raw_arg + mini_len < arg_end && (*raw_arg)[mini_len] != '$'\
				&& g_delim_tbl[(unsigned char)((*raw_arg)[mini_len])] == 0)
			{
				mini_len++;
			}
			argument_expand(aargs, *raw_arg, mini_len);
			(*raw_arg) += mini_len;
		}
	}
	return (1);
}

int			arg_lexer(char const *raw_arg,
				char const *const arg_end,
				t_env *const true_env,
				t_arg_object *const aargs)
{
	while (raw_arg < arg_end)
	{
		if (g_delim_tbl[(unsigned char)(*raw_arg)] == 0)
		{
			argument_new(aargs);
			if (generate_argument(&raw_arg, arg_end, true_env, aargs) == -1)
			{
				return (-1);
			}
			argument_finish(aargs);
			if (aargs->err == 1)
			{
				return (-1);
			}
		}
		while (g_delim_tbl[(unsigned char)(*raw_arg)] && raw_arg < arg_end)
		{
			raw_arg++;
		}
	}
	return (1);
}
