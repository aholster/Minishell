/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 13:11:45 by aholster       #+#    #+#                */
/*   Updated: 2019/12/11 17:41:06 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_del(void *data, size_t size)
{
	(void)size;
	free(data);	
}
