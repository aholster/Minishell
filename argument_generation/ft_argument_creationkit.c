/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argument_creationkit.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:36:14 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/13 18:52:47 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include "../libft/libft.h"

void	argument_new(t_arg_object *const aargs)
{
	if (aargs->err == 0)
	{
		if ((size_t)aargs->argc + 1 >= sizeof(aargs->argv) / sizeof(char *))
		{
			aargs->err = 1;
		}
		aargs->argv[aargs->argc] = aargs->arg_buf + aargs->tail;
		aargs->argc++;
	}
}

void	argument_expand(t_arg_object *const aargs,
				char const *str,
				const size_t len)
{
	if (aargs->err == 0)
	{
		if (sizeof(aargs->arg_buf) < aargs->tail + len + 2)
		{
			aargs->err = 1;
		}
		ft_memcpy(aargs->arg_buf + aargs->tail, str, len);
		aargs->tail += len;
	}
}

void	argument_finish(t_arg_object *const aargs)
{
	if (aargs->err == 0)
	{
		aargs->arg_buf[aargs->tail] = '\0';
		aargs->tail++;
	}
}
