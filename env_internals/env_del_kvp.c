/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_del_kvp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 07:37:34 by aholster       #+#    #+#                */
/*   Updated: 2019/12/13 07:39:52 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../libft/libft.h"
#include "ft_env.h"

void	env_del_kvp(void *data, size_t size)
{
	t_env_kvp	*const kvp = data;

	(void)size;
	free(kvp->key);
	free(kvp->value);
	ft_bzero(kvp, sizeof(t_env_kvp));
	free(data);
}
