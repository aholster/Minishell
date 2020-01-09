/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_add_kvp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 12:06:35 by aholster       #+#    #+#                */
/*   Updated: 2020/01/09 14:53:49 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_env.h"

static int	create_kvp(char const *const restrict key,\
				char const *const restrict value,\
				t_env_kvp *const restrict akvp)
{
	akvp->klen = ft_strlen(key);
	akvp->key = ft_memdup(key, akvp->klen + 1);
	if (akvp->key == NULL)
	{
		return (-1);
	}
	akvp->vlen = ft_strlen(value);
	akvp->value = ft_memdup(value, akvp->vlen + 1);
	if (akvp->value == NULL)
	{
		ft_strdel(&(akvp->key));
		return (-1);
	}
	return (1);
}

int			env_add_kvp(char const *const restrict key,\
				char const *const restrict value,\
				t_list **const aenv_lst)
{
	t_env_kvp	kvp;
	t_list		*new;

	if (create_kvp(key, value, &kvp) == -1)
	{
		return (-1);
	}
	new = ft_lstnew(&kvp, sizeof(kvp));
	if (new == NULL)
	{
		ft_strdel(&(kvp.key));
		ft_strdel(&(kvp.value));
		ft_bzero(&kvp, sizeof(t_env_kvp));
		return (-1);
	}
	ft_lstadd(aenv_lst, new);
	return (1);
}
